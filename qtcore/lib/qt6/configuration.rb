# frozen_string_literal: true

module RubyQt6
  # @!visibility private
  def self.load_defaults
    mods = RubyQt6.constants.grep(/^Qt[A-Z]/).map { |const| RubyQt6.const_get(const) }
    mods.each do |mod|
      mod.constants.each do |const|
        next if const.match?("VERSION")
        Object.const_set(const, mod.const_get(const)) if const.start_with?("Q")
      end
    end

    true
  end
end
