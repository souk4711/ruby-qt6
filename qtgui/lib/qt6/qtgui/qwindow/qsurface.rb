# frozen_string_literal: true

module RubyQt6
  module QtGui
    class QWindow < RubyQt6::QtCore::QObject
      # @return [QSurfaceFormat]
      #
      # Returns the actual format of this window.
      #
      # After the window has been created, this function will return the
      # actual surface format of the window. It might differ from the
      # requested format if the requested format could not be fulfilled by
      # the platform. It might also be a superset, for example certain buffer
      # sizes may be larger than requested.
      def format
        _format
      end

      # @return [QSize]
      #
      # Returns the size of the window excluding any window frame.
      def size
        _size
      end

      # @return [Boolean]
      #
      # Returns true if the surface is OpenGL compatible and can be used in
      # conjunction with QOpenGLContext; otherwise returns false.
      def supports_open_gl?
        _supports_open_gl?
      end

      # @return [QSurface::SurfaceClass]
      #
      # Returns the surface class of this surface.
      def surface_class
        _surface_class
      end

      # @return [QSurface::SurfaceType]
      #
      # Returns the surface type of the window.
      def surface_type
        _surface_type
      end

      # @param format [QSurfaceFormat]
      # @return [nil]
      #
      # Sets the window's surface format.
      #
      # The format determines properties such as color depth, alpha, depth
      # and stencil buffer size, etc. For example, to give a window a
      # transparent background (provided that the window system supports
      # compositing, and provided that other content in the window does not
      # make it opaque again):
      #
      #   QSurfaceFormat format;
      #   format.setAlphaBufferSize(8);
      #   window.setFormat(format);
      #
      # The surface format will be resolved in the create() function. Calling
      # this function after create() has been called will not re-resolve the
      # surface format of the native surface.
      #
      # When the format is not explicitly set via this function, the format
      # returned by QSurfaceFormat::defaultFormat() will be used. This means
      # that when having multiple windows, individual calls to this function
      # can be replaced by one single call to
      # QSurfaceFormat::setDefaultFormat() before creating the first window.
      def set_format(format)
        _set_format(format)
      end

      # @param type [QSurface::SurfaceType]
      # @return [nil]
      #
      # Sets the surfaceType of the window.
      #
      # Specifies whether the window is meant for raster rendering with
      # QBackingStore, or OpenGL rendering with QOpenGLContext.
      #
      # The surfaceType will be used when the native surface is created in
      # the create() function. Calling this function after the native
      # surface has been created requires calling destroy() and create() to
      # release the old native surface and create a new one.
      def set_surface_type(type)
        _set_surface_type(type)
      end
    end
  end
end
