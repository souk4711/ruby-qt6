# frozen_string_literal: true

module RubyQt6
  module KWidgetsAddons
    # @see https://api.kde.org/kseparator.html
    class KSeparator < RubyQt6::QtWidgets::QFrame
      # @!parse
      q_object do
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param orientation [Qt::Orientation]
      # @param parent [QWidget]
      # @return [KSeparator]
      def initialize(orientation, parent = nil)
        _initialize(orientation, parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
