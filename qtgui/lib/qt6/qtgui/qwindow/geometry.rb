# frozen_string_literal: true

module RubyQt6
  module QtGui
    class QWindow < RubyQt6::QtCore::QObject
      # @return [QPoint]
      #
      # Returns the position of the window on the desktop excluding any
      # window frame.
      def position
        _position
      end

      # @return [Integer]
      #
      # This property holds the x position of the window's geometry.
      def x
        _x
      end

      # @return [Integer]
      #
      # This property holds the y position of the window's geometry.
      def y
        _y
      end

      # @return [Integer]
      #
      # This property holds the width of the window's geometry.
      def width
        _width
      end

      # @return [Integer]
      #
      # This property holds the height of the window's geometry.
      def height
        _height
      end

      # @return [QRect]
      #
      # Returns the geometry of the window, excluding its window frame.
      #
      # The geometry is in relation to the virtualGeometry() of its screen.
      def geometry
        _geometry
      end

      # @return [QSize]
      #
      # Returns the maximum size of the window.
      def maximum_size
        _maximum_size
      end

      # @return [Integer]
      #
      # This property holds the maximum width of the window's geometry.
      def maximum_width
        _maximum_width
      end

      # @return [Integer]
      #
      # This property holds the maximum height of the window's geometry.
      def maximum_height
        _maximum_height
      end

      # @return [QSize]
      #
      # Returns the minimum size of the window.
      def minimum_size
        _minimum_size
      end

      # @return [Integer]
      #
      # This property holds the minimum width of the window's geometry.
      def minimum_width
        _minimum_width
      end

      # @return [Integer]
      #
      # This property holds the minimum height of the window's geometry.
      def minimum_height
        _minimum_height
      end

      # @return [QSize]
      #
      # Returns the base size of the window.
      def base_size
        _base_size
      end

      # @return [QSize]
      #
      # Returns the size increment of the window.
      def size_increment
        _size_increment
      end

      # @return [QMargins]
      #
      # Returns the window frame margins surrounding the window.
      def frame_margins
        _frame_margins
      end

      # @return [QRect]
      #
      # Returns the geometry of the window, including its window frame.
      #
      # The geometry is in relation to the virtualGeometry() of its screen.
      def frame_geometry
        _frame_geometry
      end

      # @return [QPoint]
      #
      # Returns the top left position of the window, including its window
      # frame.
      #
      # This returns the same value as frameGeometry().topLeft().
      def frame_position
        _frame_position
      end

      # @return [nil]
      # @overload set_position(pos)
      #   @param pos [QPoint]
      # @overload set_position(x, y)
      #   @param x [Integer]
      #   @param y [Integer]
      #
      # Set the position of the window on the desktop to posx, posy.
      #
      # The position is in relation to the virtualGeometry() of its screen.
      def set_position(*args)
        _set_position(*args)
      end

      # @param x [Integer]
      # @return [nil]
      #
      # Sets the window's x property.
      def set_x(x)
        _set_x(x)
      end

      # @param y [Integer]
      # @return [nil]
      #
      # Sets the window's y property.
      def set_y(y)
        _set_y(y)
      end

      # @param w [Integer]
      # @return [nil]
      #
      # Sets the window's width property.
      def set_width(w)
        _set_width(w)
      end

      # @param h [Integer]
      # @return [nil]
      #
      # Sets the window's height property.
      def set_height(h)
        _set_height(h)
      end

      # @return [nil]
      # @overload resize(size)
      #   @param size [QSize]
      # @overload resize(w, h)
      #   @param w [Integer]
      #   @param h [Integer]
      #
      # Set the size of the window, excluding any window frame, to newSize.
      def resize(*args)
        _resize(*args)
      end

      # @return [nil]
      # @overload set_geometry(rect)
      #   @param rect [QRect]
      # @overload set_geometry(x, y, w, h)
      #   @param x [Integer]
      #   @param y [Integer]
      #   @param w [Integer]
      #   @param h [Integer]
      #
      # Sets the geometry of the window, excluding its window frame, to rect.
      #
      # The geometry is in relation to the virtualGeometry() of its screen.
      def set_geometry(*args)
        _set_geometry(*args)
      end

      # @param w [Integer]
      # @return [nil]
      #
      # Sets the maximum size of the window.
      #
      # This is a hint to the window manager to prevent resizing above the
      # specified size.
      def set_maximum_width(w)
        _set_maximum_width(w)
      end

      # @param h [Integer]
      # @return [nil]
      #
      # Sets the window's maximumHeight property.
      def set_maximum_height(h)
        _set_maximum_height(h)
      end

      # @param w [Integer]
      # @return [nil]
      #
      # Sets the window's minimumWidth property.
      def set_minimum_width(w)
        _set_minimum_width(w)
      end

      # @param h [Integer]
      # @return [nil]
      #
      # Sets the window's minimumHeight property.
      def set_minimum_height(h)
        _set_minimum_height(h)
      end

      # @param size [QSize[
      # @return [nil]
      #
      # Sets the base size of the window.
      #
      # The base size is used to calculate a proper window size if the window
      # defines sizeIncrement().
      def set_base_size(size)
        _set_base_size(size)
      end

      # @param size [QSize[
      # @return [nil]
      #
      # Sets the size increment (size) of the window.
      #
      # When the user resizes the window, the size will move in steps of
      # sizeIncrement().width() pixels horizontally and
      # sizeIncrement().height() pixels vertically, with baseSize() as
      # the basis.
      #
      # By default, this property contains a size with zero width and height.
      #
      # The windowing system might not support size increments.
      def set_size_increment(size)
        _set_size_increment(size)
      end

      # @param positon [QPoint]
      # @return [nil]
      #
      # Sets the upper left position of the window (point) including its
      # window frame.
      #
      # The position is in relation to the virtualGeometry() of its screen.
      def set_frame_position(positon)
        _set_frame_position(positon)
      end
    end
  end
end
