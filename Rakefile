# frozen_string_literal: true

QT6_LIBS = %w[
  QtCore QtGui QtWidgets
  QtQml QtQuick QtQuickControls2 QtQuickWidgets
  QtUiTools
].freeze

namespace :bindgen do
  def bindgen(extension:)
    require "ruby-bindgen"

    clang_args = []
    clang_args << "-I/usr/lib/clang/20/include"
    clang_args << "-I./vendor/qt6include"
    clang_args << "-I./vendor/qt6include/#{extension}"
    clang_args << "-xc++"
    inputter = RubyBindgen::Inputter.new("vendor/qt6include/#{extension}", "q[a-z]*.h", ["*impl.h", "*helpers.h", "qwindowdefs.h"])
    outputter = RubyBindgen::Outputter.new("vendor/qt6rice/#{extension}")
    parser = RubyBindgen::Parser.new(inputter, clang_args)
    format = RubyBindgen::Visitors::Rice.new(extension.downcase, outputter)
    parser.generate(format, parallel: true)
  end

  QT6_LIBS.each do |lib|
    desc "Generate Rice bindings for #{lib.sub("Qt", "libQt6")}"
    task lib.downcase do
      FileUtils.mkdir_p("vendor/qt6rice")
      FileUtils.rm_rf("vendor/qt6rice/#{lib}")
      bindgen(extension: lib)
      sh("clang-format -i -style=file --verbose vendor/qt6rice/#{lib}/*{hpp,cpp}")
    end
  end

  desc "Generate Rice bindings for libQt6"
  task :all do
    qt6libs.each { |lib| system("rake bindgen:#{lib.downcase}") }
  end

  desc "Generate Rice bindings for qlass"
  task :rbext, [:qlass] do |_, args|
    name = args.qlass.to_s
    Dir["vendor/qt6rice/*/#{name.downcase}-rb.*"].each do |file|
      m = file.match("/(Qt.*)/(.*)")
      submod = m[1]
      copied = "#{submod.downcase}/ext/qt6/#{submod.downcase}/#{m[2]}"
      sh("cp #{file} #{copied}")
      sh("sed -i 's/Init_Q#{name.downcase[1..]}(/Init_#{name.downcase}(Rice::Module rb_mQt6#{submod}/' #{copied}")
      sh("sed -i 's/define_class<#{name}\\(.*\\)>(/define_class_under<#{name}\\1>(rb_mQt6#{submod}, /' #{copied}")
    end
  end

  desc "Update libQt6 headers"
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
      sh "cp -r #{out}/usr/include/qt6/. vendor/qt6include"
    end

    FileUtils.rm_rf("vendor/qt6include")
    upinc(pkg: "qt6-base-6.9.2-1")
    upinc(pkg: "qt6-declarative-6.9.2-1")
    upinc(pkg: "qt6-tools-6.9.2-1")
  end
end

desc "Run Rake compiler"
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
    Bundler.with_unbundled_env { Parallel.each(QT6_LIBS, &compile) }
  else
    Bundler.with_unbundled_env { QT6_LIBS.each(&compile) }
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

  Bundler.with_unbundled_env { (QT6_LIBS + ["Qt"]).each(&rubocop) }
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

  Bundler.with_unbundled_env { (QT6_LIBS + ["Qt"]).each(&rspec) }
end

desc "Run YARD documentation"
task :yard, [:server] do |_, args|
  src = "tmp/tasks/yardoc/src"

  sh "rm -rf #{src} && mkdir -p #{src}"
  sh "cp -rv qt*/lib #{src}"

  Dir.chdir(src) do
    yardopts = []
    yardopts << "-n"
    yardopts << "--exclude lib/mkmf-rubyqt6.rb"
    sh "yard #{yardopts.join(" ")}"
    sh "yard server" if args.server
  end
end

task :default do
  system("rake --tasks")
end
