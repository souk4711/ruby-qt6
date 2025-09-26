# frozen_string_literal: true

require "semantic_logger/sync"

module RubyQt6
  # @!visibility private
  def self.load_defaults
    mods = [::RubyQt6::Bando]
    mods.each do |mod|
      mod.constants.each do |const|
        ::Object.const_set(const, mod.const_get(const)) if const.start_with?("Q")
      end
    end

    mods = ::RubyQt6.constants.grep(/^Qt/).map { |const| ::RubyQt6.const_get(const) }
    mods.each do |mod|
      mod.constants.each do |const|
        next if ::RubyQt6::Bando.const_defined?(const)
        next if const.match?("VERSION")
        ::Object.const_set(const, mod.const_get(const)) if const.start_with?("Q")
      end
    end

    ::SemanticLogger.add_appender(io: $stdout, formatter: :color)
  end

  # @!visibility private
  def self.logger
    @logger ||= ::SemanticLogger["RubyQt6"]
  end
end
