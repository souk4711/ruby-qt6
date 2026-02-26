# frozen_string_literal: true

require_relative "lib/qt6/version"

Gem::Specification.new do |spec|
  spec.name = "ruby-qt6"
  spec.version = RubyQt6::RUBYGEM_VERSION
  spec.authors = ["John Doe"]
  spec.email = ["johndoe@example.com"]

  spec.summary = "Ruby Bindings for Qt."
  spec.description = "Ruby Bindings for Qt."
  spec.homepage = "https://github.com/souk4711/ruby-qt6"
  spec.required_ruby_version = ">= 3.3.0"

  spec.metadata["homepage_uri"] = spec.homepage
  spec.metadata["source_code_uri"] = "https://github.com/souk4711/ruby-qt6"
  spec.metadata["changelog_uri"] = "https://github.com/souk4711/ruby-qt6"

  # Specify which files should be added to the gem when it is released.
  # The `git ls-files -z` loads the files in the RubyGem that have been added into git.
  gemspec = File.basename(__FILE__)
  spec.files = IO.popen(%w[git ls-files -z], chdir: __dir__, err: IO::NULL) do |ls|
    ls.readlines("\x0", chomp: true).reject do |f|
      (f == gemspec) ||
        f.start_with?(*%w[bin/ test/ spec/ features/ .git appveyor Gemfile])
    end
  end
  spec.bindir = "exe"
  spec.executables = spec.files.grep(%r{\Aexe/}) { |f| File.basename(f) }
  spec.require_paths = ["lib"]

  spec.add_runtime_dependency("ruby-qt6-rice", "= 6.0.0")
  spec.add_runtime_dependency("ruby-qt6-qtcore", "~> 6.0.0")
  spec.add_runtime_dependency("ruby-qt6-qtgui", "~> 6.0.0")
  spec.add_runtime_dependency("ruby-qt6-qtwidgets", "~> 6.0.0")
  spec.add_runtime_dependency("ruby-qt6-qtdbus", "~> 6.0.0")
  spec.add_runtime_dependency("ruby-qt6-qtnetwork", "~> 6.0.0")
  spec.add_runtime_dependency("ruby-qt6-qtprintsupport", "~> 6.0.0")
  spec.add_runtime_dependency("ruby-qt6-qttest", "~> 6.0.0")
  spec.add_runtime_dependency("ruby-qt6-qtqml", "~> 6.0.0")
  spec.add_runtime_dependency("ruby-qt6-qtquick", "~> 6.0.0")
  spec.add_runtime_dependency("ruby-qt6-qtquickcontrols2", "~> 6.0.0")
  spec.add_runtime_dependency("ruby-qt6-qtquickwidgets", "~> 6.0.0")
  spec.add_runtime_dependency("ruby-qt6-qtmultimedia", "~> 6.0.0")
  spec.add_runtime_dependency("ruby-qt6-qtmultimediawidgets", "~> 6.0.0")
  spec.add_runtime_dependency("ruby-qt6-qtwebenginecore", "~> 6.0.0")
  spec.add_runtime_dependency("ruby-qt6-qtwebenginewidgets", "~> 6.0.0")
  spec.add_runtime_dependency("ruby-qt6-qtwebview", "~> 6.0.0")
  spec.add_runtime_dependency("ruby-qt6-qtuitools", "~> 6.0.0")

  # For more information and examples about making a new gem, check out our
  # guide at: https://bundler.io/guides/creating_gem.html
end
