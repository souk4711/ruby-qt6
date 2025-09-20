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
    end
  end
end
