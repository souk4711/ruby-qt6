# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qframe.html
    class QFrame < RubyQt6::QtWidgets::QWidget
      # @!parse class Shadow; end
      # @!parse class Shape ; end
      rubyqt6_include_constants QFrame, QFrame::Shadow
      rubyqt6_include_constants QFrame, QFrame::Shape

      # @return [QRect]
      #
      # This property holds the frame's rectangle.
      #
      # The frame's rectangle is the rectangle the frame is drawn in. By
      # default, this is the entire widget. Setting the rectangle doesn't
      # cause a widget update. The frame rectangle is automatically adjusted
      # when the widget changes size.
      #
      # If you set the rectangle to a null rectangle (for example,
      # QRect(0, 0, 0, 0)), then the resulting frame rectangle is equivalent
      # to the widget rectangle.
      def frame_rect
        _frame_rect
      end

      # @return [QFrame::Shadow]
      #
      # This property holds the frame shadow value from the frame style.
      def frame_shadow
        _frame_shadow
      end

      # @return [QFrame::Shape]
      #
      # This property holds the frame shape value from the frame style.
      def frame_shape
        _frame_shape
      end

      # @return [Integer]
      #
      # This property holds the width of the frame that is drawn.
      #
      # Note that the frame width depends on the frame style, not only the
      # line width and the mid-line width. For example, the style specified
      # by NoFrame always has a frame width of 0, whereas the style Panel
      # has a frame width equivalent to the line width.
      def frame_width
        _frame_width
      end

      # @return [Integer]
      #
      # Returns the frame style.
      #
      # The default value is QFrame::Plain.
      def frame_style
        _frame_style
      end

      # @return [Integer]
      #
      # This property holds the line width.
      #
      # Note that the total line width for frames used as separators (HLine
      # and VLine) is specified by frameWidth.
      #
      # The default value is 1.
      def line_width
        _line_width
      end

      # @return [Integer]
      #
      # This property holds the width of the mid-line.
      #
      # The default value is 0.
      def mid_line_width
        _mid_line_width
      end

      # @param rect [QRect]
      # @return [void]
      #
      # Sets the frame's rect.
      def set_frame_rect(rect)
        _set_frame_rect(rect)
      end

      # @param shadow [QFrame::Shadow]
      # @return [void]
      #
      # Sets the frame's shadow.
      def set_frame_shadow(shadow)
        _set_frame_shadow(shadow)
      end

      # @param shape [QFrame::Shape]
      # @return [void]
      #
      # Sets the frame's shape.
      def set_frame_shape(shape)
        _set_frame_shape(shape)
      end

      # @param style [Integer]
      # @return [void]
      #
      # Sets the frame style to style.
      #
      # The style is the bitwise OR between a frame shape and a frame shadow
      # style. See the picture of the frames in the main class documentation.
      #
      # The frame shapes are given in QFrame::Shape and the shadow styles in
      # QFrame::Shadow.
      #
      # If a mid-line width greater than 0 is specified, an additional line
      # is drawn for Raised or Sunken Box, HLine, and VLine frames. The
      # mid-color of the current color group is used for drawing middle lines.
      def set_frame_style(style)
        _set_frame_style(style)
      end

      # @param width [Integer]
      # @return [void]
      #
      # Sets the frame's lineWidth property.
      def set_line_width(width)
        _set_line_width(width)
      end

      # @param width [Integer]
      # @return [void]
      #
      # Sets the frame's midLineWidth property.
      def set_mid_line_width(width)
        _set_mid_line_width(width)
      end
    end
  end
end
