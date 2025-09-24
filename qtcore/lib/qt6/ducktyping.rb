# frozen_string_literal: true

module RubyQt6
  # @!visibility private
  module T
    def self.to_qstr(str)
      QtCore::QString.new(str)
    end
  end
end
