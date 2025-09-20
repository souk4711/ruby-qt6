# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qpainter.html
    class QPainter
      # @!parse class CompositionMode   ; end
      # @!parse class PixmapFragmentHint; end
      # @!parse class RenderHint        ; end
      rubyqt6_include_constants QPainter, QPainter::CompositionMode
      rubyqt6_include_constants QPainter, QPainter::PixmapFragmentHint
      rubyqt6_include_constants QPainter, QPainter::RenderHint

      # @!visibility private
      def self.new(device)
        return device._new_painter if device.respond_to?(:_new_painter)
        allocate.tap { |o| o.__send__(:initialize, device) }
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param device [QPaintDevice]
      # @return [QPainter]
      def initialize(device)
        _initialize(device)
      end
    end
  end
end
