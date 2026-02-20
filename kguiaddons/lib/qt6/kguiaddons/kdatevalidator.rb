# frozen_string_literal: true

module RubyQt6
  module KGuiAddons
    # @see https://api.kde.org/kdatevalidator.html
    class KDateValidator < RubyQt6::QtGui::QValidator
      # @!parse
      q_object do
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [KDateValidator]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
