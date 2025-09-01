# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qpaintdevice.html
    class QPaintDevice
      # @return [Integer]
      #
      # Returns the number of different colors available for the paint
      # device. If the number of colors available is too great to be
      # represented by the int data type, then INT_MAX will be returned
      # instead.
      def color_count
        _color_count
      end

      # @return [Integer]
      #
      # Returns the bit depth (number of bit planes) of the paint device.
      def depth
        _depth
      end

      # @return [Float]
      #
      # Returns the device pixel ratio for device.
      #
      # Common values are 1 for normal-dpi displays and 2 for high-dpi
      # "retina" displays.
      def device_pixel_ratio
        _device_pixel_ratio
      end

      # @return [Float]
      #
      # Returns the device pixel ratio for the device as a floating point
      # number.
      def device_pixel_ratio_f
        _device_pixel_ratio_f
      end

      # @return [Integer]
      #
      # Returns the height of the paint device in default coordinate
      # system units (e.g. pixels for QPixmap and QWidget).
      def height
        _height
      end

      # @return [Integer]
      #
      # Returns the height of the paint device in millimeters. Due to
      # platform limitations it may not be possible to use this function to
      # determine the actual physical size of a widget on the screen.
      def height_mm
        _height_mm
      end

      # @return [Integer]
      #
      # Returns the width of the paint device in default coordinate system
      # units (e.g. pixels for QPixmap and QWidget).
      def width
        _width
      end

      # @return [Integer]
      #
      # Returns the width of the paint device in millimeters. Due to
      # platform limitations it may not be possible to use this function to
      # determine the actual physical size of a widget on the screen.
      def width_mm
        _width_mm
      end

      # @return [Integer]
      #
      # Returns the horizontal resolution of the device in dots per inch,
      # which is used when computing font sizes. For X11, this is usually
      # the same as could be computed from widthMM().
      #
      # Note that if the logicalDpiX() doesn't equal the physicalDpiX(), the
      # corresponding QPaintEngine must handle the resolution mapping.
      def logical_dpi_x
        _logical_dpi_x
      end

      # @return [Integer]
      #
      # Returns the vertical resolution of the device in dots per inch,
      # which is used when computing font sizes. For X11, this is usually
      # the same as could be computed from heightMM().
      #
      # Note that if the logicalDpiY() doesn't equal the physicalDpiY(), the
      # corresponding QPaintEngine must handle the resolution mapping.
      def logical_dpi_y
        _logical_dpi_y
      end

      # @return [Integer]
      #
      # Returns the horizontal resolution of the device in dots per inch.
      # For example, when printing, this resolution refers to the physical
      # printer's resolution. The logical DPI on the other hand, refers to
      # the resolution used by the actual paint engine.
      #
      # Note that if the physicalDpiX() doesn't equal the logicalDpiX(),
      # the corresponding QPaintEngine must handle the resolution mapping.
      def physical_dpi_x
        _physical_dpi_x
      end

      # @return [Integer]
      #
      # Returns the horizontal resolution of the device in dots per inch.
      # For example, when printing, this resolution refers to the physical
      # printer's resolution. The logical DPI on the other hand, refers to
      # the resolution used by the actual paint engine.
      #
      # Note that if the physicalDpiY() doesn't equal the logicalDpiY(), the
      # corresponding QPaintEngine must handle the resolution mapping.
      def physical_dpi_y
        _physical_dpi_y
      end

      # @return [Boolean]
      #
      # Returns true if the device is currently being painted on, i.e.
      # someone has called QPainter::begin() but not yet called
      # QPainter::end() for this device; otherwise returns false.
      def painting_active?
        _painting_active?
      end

      # @return [QPaintEngine]
      #
      # Returns a pointer to the paint engine used for drawing on the device.
      def paint_engine
        _paint_engine
      end
    end
  end
end
