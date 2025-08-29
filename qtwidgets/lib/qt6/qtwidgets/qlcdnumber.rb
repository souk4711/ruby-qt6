# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qlcdnumber.html
    class QLCDNumber < RubyQt6::QtWidgets::QFrame
      # @!visibility private
      alias_method :_initialize, :initialize

      # @!parse class Mode        ; end
      # @!parse class SegmentStyle; end
      rubyqt6_include_constants QLCDNumber, QLCDNumber::Mode
      rubyqt6_include_constants QLCDNumber, QLCDNumber::SegmentStyle

      # @param num [Integer]
      # @param parent [QWidget]
      # @return [QLCDNumber]
      #
      # Constructs an LCD number, sets the number of digits to numDigits, the
      # base to decimal, the decimal point mode to 'small' and the frame style
      # to a raised box. The segmentStyle() is set to Filled.
      def initialize(num, parent = nil)
        _initialize(num, parent)
        _take_ownership_from_rice(self) if parent
      end

      # @return [Integer]
      #
      # This property holds the current number of digits displayed.
      #
      # Corresponds to the current number of digits. If
      # QLCDNumber::smallDecimalPoint is false, the decimal point occupies
      # one digit position.
      #
      # By default, this property contains a value of 5.
      def digit_count
        _digit_count
      end

      # @return [Integer]
      #
      # This property holds the displayed value rounded to the nearest integer.
      #
      # This property corresponds to the nearest integer to the current value
      # displayed by the LCDNumber. This is the value used for hexadecimal,
      # octal and binary modes.
      #
      # If the displayed value is not a number, the property has a value of 0.
      #
      # By default, this property contains a value of 0.
      def int_value
        _int_value
      end

      # @return [QLCDNumber::Mode]
      #
      # This property holds the current display mode (number base).
      #
      # Corresponds to the current display mode, which is one of Bin, Oct,
      # Dec (the default) and Hex. Dec mode can display floating point
      # values, the other modes display the integer equivalent.
      def mode
        _mode
      end

      # @return [QLCDNumber::SegmentStyle]
      #
      # This property holds the style of the LCDNumber.
      def segment_style
        _segment_style
      end

      # @return [Boolean]
      #
      # This property holds the style of the decimal point.
      #
      # If true the decimal point is drawn between two digit positions.
      # Otherwise it occupies a digit position of its own, i.e. is drawn
      # in a digit position. The default is false.
      #
      # The inter-digit space is made slightly wider when the decimal point
      # is drawn between the digi
      def small_decimal_point?
        _small_decimal_point?
      end

      # @return [Float]
      #
      # This property holds the displayed value.
      #
      # This property corresponds to the current value displayed by the
      # LCDNumber.
      #
      # If the displayed value is not a number, the property has a value of 0.
      #
      # By default, this property contains a value of 0.
      def value
        _value
      end

      # @param num [Integer]
      # @return [nil]
      #
      # Sets the current number of digits to numDigits. Must be in the range
      # 0..99.
      def set_digit_count(num)
        _set_digit_count(num)
      end

      # @param num [Integer, Float]
      # @return [nil]
      #
      # Displays the number num.
      def display(num)
        _display(num)
      end

      # @param str [QString]
      # @return [nil]
      #
      # Displays the number represented by the string str.
      #
      # This version of the function disregards mode() and
      # smallDecimalPoint().
      #
      # These digits and other symbols can be shown: 0/O, 1, 2, 3, 4, 5/S, 6,
      # 7, 8, 9/g, minus, decimal point, A, B, C, D, E, F, h, H, L, o, P, r,
      # u, U, Y, colon, degree sign (which is specified as single quote in
      # the string) and space. QLCDNumber substitutes spaces for illegal
      # characters.
      def display_str(str)
        _display_str(QtCore::QString.new(str))
      end

      # @param mode [QLCDNumber::Mode]
      # @return [nil]
      #
      # Sets the lcdnumber's mode property.
      def set_mode(mode)
        _set_mode(mode)
      end

      # @return [nil]
      #
      # Calls setMode(Hex). Provided for convenience (e.g. for connecting
      # buttons to it).
      def set_hex_mode
        _set_hex_mode
      end

      # @return [nil]
      #
      # Calls setMode(Dec). Provided for convenience (e.g. for connecting
      # buttons to it).
      def set_dec_mode
        _set_dec_mode
      end

      # @return [nil]
      #
      # Calls setMode(Oct). Provided for convenience (e.g. for connecting
      # buttons to it).
      def set_oct_mode
        _set_oct_mode
      end

      # @return [nil]
      #
      # Calls setMode(Bin). Provided for convenience (e.g. for connecting
      # buttons to it).
      def set_bin_mode
        _set_bin_mode
      end

      # @param style [QLCDNumber::SegmentStyle]
      # @return [nil]
      #
      # Sets the lcdnumber's segmentStyle property.
      def set_segment_style(style)
        _set_segment_style(style)
      end

      # @param enabled [Boolean]
      # @return [nil]
      #
      # Sets the lcdnumber's smallDecimalPoint property.
      def set_small_decimal_point(enabled)
        _set_small_decimal_point(enabled)
      end

      # @param num [Integer, Float]
      # @return [Boolean]
      #
      # Returns true if num is too big to be displayed in its entirety;
      # otherwise returns false.
      def check_overflow(num)
        _check_overflow(num)
      end
    end
  end
end
