# frozen_string_literal: true

require "semantic_logger"

module RubyQt6
  def self.load_defaults
    mods = [::RubyQt6::Bando]
    mods += ::RubyQt6.constants.grep(/^Qt/).map { |const| ::RubyQt6.const_get(const) }
    mods.each do |mod|
      mod.constants.each do |const|
        next if ::Object.const_defined?(const)
        ::Object.const_set(const, mod.const_get(const)) if const.start_with?("Q")
      end
    end

    ::SemanticLogger.add_appender(io: $stdout, formatter: :color)
  end

  def self.logger
    @logger ||= ::SemanticLogger["RubyQt6"]
  end
end
