# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qlcdnumber.html
    class QLCDNumber < RubyQt6::QtWidgets::QFrame
      # @!parse class Mode        ; end
      # @!parse class SegmentStyle; end
      rubyqt6_declare_enum_under QLCDNumber, QLCDNumber::Mode
      rubyqt6_declare_enum_under QLCDNumber, QLCDNumber::SegmentStyle

      # @!parse
      q_object do
        signal "overflow()"
        slot "display(QString)"
        slot "display(double)"
        slot "display(int)"
        slot "setBinMode()"
        slot "setDecMode()"
        slot "setHexMode()"
        slot "setOctMode()"
        slot "setSmallDecimalPoint(bool)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param num [Integer]
      # @param parent [QWidget]
      # @return [QLCDNumber]
      def initialize(num, parent = nil)
        _initialize(num, parent)
        _take_ownership_from_ruby(self)
      end

      # @!visibility private
      def display(*args)
        T.args_nth_to_qstr(args, 0)
        _display(*args)
      end
    end
  end
end
