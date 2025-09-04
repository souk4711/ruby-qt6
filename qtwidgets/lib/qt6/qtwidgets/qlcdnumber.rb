# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qlcdnumber.html
    class QLCDNumber < RubyQt6::QtWidgets::QFrame
      # @!parse class Mode        ; end
      # @!parse class SegmentStyle; end
      rubyqt6_include_constants QLCDNumber, QLCDNumber::Mode
      rubyqt6_include_constants QLCDNumber, QLCDNumber::SegmentStyle

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param num [Integer]
      # @param parent [QWidget]
      # @return [QLCDNumber]
      def initialize(num, parent = nil)
        _initialize(num, parent)
        _take_ownership_from_rubyrice(self) if parent
      end
    end
  end
end
