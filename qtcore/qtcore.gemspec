# frozen_string_literal: true

require_relative "lib/qt6/qtcore/version"

Gem::Specification.new do |spec|
  spec.name = "ruby-qt6-qtcore"
  spec.version = RubyQt6::QtCore::QTCORE_RUBYGEM_VERSION
  spec.authors = ["John Doe"]
  spec.email = ["johndoe@example.com"]

  spec.summary = "Ruby Bindings for libQt6Core"
  spec.description = "Ruby Bindings for libQt6Core"
  spec.homepage = "https://github.com/souk4711/ruby-qt6/qtcore"
  spec.required_ruby_version = ">= 3.1.0"

  spec.metadata["homepage_uri"] = spec.homepage
  spec.metadata["source_code_uri"] = "https://github.com/souk4711/ruby-qt6/qtcore"
  spec.metadata["changelog_uri"] = "https://github.com/souk4711/ruby-qt6/qtcore"

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
  spec.extensions = ["ext/qt6/qtcore/extconf.rb"]

  spec.add_runtime_dependency("dry-inflector", "~> 1.2")
  spec.add_runtime_dependency("rice", "~> 4.6")
  spec.add_runtime_dependency("semantic_logger", "~> 4.17")

  # For more information and examples about making a new gem, check out our
  # guide at: https://bundler.io/guides/creating_gem.html
end
