# frozen_string_literal: true

LIBS = %w[
  QtCore QtGui QtWidgets QtNetwork QtPrintSupport QtTest
  QtQml QtQuick QtQuickControls2 QtQuickWidgets
  QtMultimedia QtMultimediaWidgets
  QtWebEngineCore QtWebEngineWidgets QtWebView
  QtUiTools
  QtDBus
  KCoreAddons KGuiAddons KWidgetsAddons
].freeze

namespace :bindgen do
  def bindgen(extension:)
    require "ruby-bindgen"

    clang_args = []
    clang_args << "-I/usr/lib/clang/21/include"
    clang_args << "-I./vendor/include"
    clang_args << "-I./vendor/include/#{extension}"
    clang_args << "-xc++"

    if extension.start_with?("K")
      clang_args << "-I./vendor/include/QtCore"
      clang_args << "-I./vendor/include/QtGui"
      clang_args << "-I./vendor/include/QtWidgets"
    end

    inputter = RubyBindgen::Inputter.new("vendor/include/#{extension}", "[qk][a-z]*.h", ["*impl.h", "*helpers.h", "qwindowdefs.h"])
    outputter = RubyBindgen::Outputter.new("vendor/rice/#{extension}")
    parser = RubyBindgen::Parser.new(inputter, clang_args)
    format = RubyBindgen::Visitors::Rice.new(extension.downcase, outputter)
    parser.generate(format, parallel: true)
  end

  LIBS.each do |lib|
    desc "Generate Rice bindings for #{lib}"
    task lib.downcase do
      FileUtils.mkdir_p("vendor/rice")
      FileUtils.rm_rf("vendor/rice/#{lib}")
      bindgen(extension: lib)
      sh("clang-format -i -style=file --verbose vendor/rice/#{lib}/*{hpp,cpp}")
    end
  end

  desc "Generate Rice bindings"
  task :all do
    LIBS.each { |lib| system("rake bindgen:#{lib.downcase}") }
  end

  desc "Update extension file"
  task :rbext, [:qlass] do |_, args|
    name = args.qlass.to_s
    Dir["vendor/rice/*/#{name.downcase}-rb.*"].each do |file|
      m = file.match("/(Qt.*)/(.*)")
      submod = m[1]
      copied = "#{submod.downcase}/ext/qt6/#{submod.downcase}/#{m[2]}"
      sh("cp #{file} #{copied}")
      sh("sed -i 's/Init_Q#{name.downcase[1..]}(/Init_#{name.downcase}(Module rb_mQt6#{submod}/' #{copied}")
      sh("sed -i 's/define_class<#{name}\\(.*\\)>(/define_class_under<#{name}\\1>(rb_mQt6#{submod}, /' #{copied}")
    end
  end

  desc "Update header files"
  task :upinc do
    def upinc(pkg:)
      url = "https://mirror.rackspace.com/archlinux/extra/os/x86_64/#{pkg}-x86_64.pkg.tar.zst"
      inf = "tmp/downloads/#{pkg}.pkg.tar.zst"
      out = "tmp/downloads/#{pkg}"

      if File.exist?(inf)
        puts "found #{inf}"
      else
        sh "mkdir -p tmp/downloads"
        sh "curl -L --progress-bar -o #{inf} #{url}"
      end

      sh "mkdir -p #{out} && rm -rf #{out}/*"
      sh "tar --zstd -xf #{inf} --directory=#{out}"

      dir = pkg.start_with?("k") ? "KF6" : "qt6"
      sh "cp -r #{out}/usr/include/#{dir}/. vendor/include"
    end

    FileUtils.rm_rf("vendor/include")
    FileUtils.mkdir_p("vendor/include")
    upinc(pkg: "qt6-base-6.10.1-1")
    upinc(pkg: "qt6-declarative-6.10.1-2")
    upinc(pkg: "qt6-multimedia-6.10.1-1")
    upinc(pkg: "qt6-speech-6.10.1-1")
    upinc(pkg: "qt6-tools-6.10.1-1")
    upinc(pkg: "qt6-webengine-6.10.1-1")
    upinc(pkg: "qt6-webview-6.10.1-1")
    upinc(pkg: "kcoreaddons-6.23.0-1")
    upinc(pkg: "kguiaddons-6.23.0-1")
    upinc(pkg: "kwidgetsaddons-6.23.0-1")
    upinc(pkg: "ktexteditor-6.23.0-1")
    upinc(pkg: "ktextwidgets-6.23.0-1")
  end
end

desc "Run Rake compile task to compile all the extensions"
task :compile, [:clobber] do |_, args|
  compile = lambda do |lib|
    Dir.chdir(lib.downcase) do
      puts "cd #{lib.downcase}"
      sh "rm -rf tmp" if args.clobber
      sh "bundle check || bundle install"
      sh "bundle exec rake compile"
    end
  end

  if args.clobber
    require "parallel"
    sh "rm -rf extensions"
    Bundler.with_unbundled_env { Parallel.each(LIBS, &compile) }
  else
    Bundler.with_unbundled_env { LIBS.each(&compile) }
  end
end

desc "Run Rubocop linter"
task :rubocop do
  rubocop = lambda do |lib|
    Dir.chdir(lib.downcase) do
      puts "cd #{lib.downcase}"
      sh "bundle check || bundle install"
      sh "bundle exec rubocop -A"
    end
  end

  libs = LIBS + ["qt", "k"]
  Bundler.with_unbundled_env { libs.each(&rubocop) }
end

desc "Run RSpec code examples"
task :spec do
  rspec = lambda do |lib|
    Dir.chdir(lib.downcase) do
      puts "cd #{lib.downcase}"
      sh "bundle check || bundle install"
      sh "bundle exec rspec"
    end
  end

  libs = LIBS + ["qt", "k"]
  Bundler.with_unbundled_env { libs.each(&rspec) }
end

desc "Run YARD documentation"
task :yard, [:server] do |_, args|
  src = "tmp/tasks/yardoc/src"

  sh "rm -rf #{src} && mkdir -p #{src}"
  sh "cp -rv qt[a-z]*/lib #{src}"
  sh "cp -rv k[a-z]*/lib #{src}"

  Dir.chdir(src) do
    yardopts = []
    yardopts << "-n"
    yardopts << "--exclude lib/mkmf-*.rb"
    sh "yard #{yardopts.join(" ")}"
    sh "yard server" if args.server
  end
end

task :default do
  system("rake --tasks")
end
