# frozen_string_literal: true

module RubyQt6
  # @!visibility private
  def self.initialize!(mod)
    mod.constants.each do |const|
      next if const.match?("VERSION")
      Object.const_set(const, mod.const_get(const)) if const.start_with?("Q", "K")
    end
  end
end
