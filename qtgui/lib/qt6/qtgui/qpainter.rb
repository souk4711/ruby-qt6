# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qpainter.html
    class QPainter
      # @!parse class CompositionMode    ; end
      # @!parse class PixmapFragmentHint ; end
      # @!parse class PixmapFragmentHints; end
      # @!parse class RenderHint         ; end
      # @!parse class RenderHints        ; end
      rubyqt6_declare_enum_under QPainter, QPainter::CompositionMode
      rubyqt6_declare_enum_under QPainter, QPainter::PixmapFragmentHint
      rubyqt6_declare_enum_under QPainter, QPainter::RenderHint
      rubyqt6_declare_qflags QPainter::PixmapFragmentHints, QPainter::PixmapFragmentHint
      rubyqt6_declare_qflags QPainter::RenderHints, QPainter::RenderHint

      # @!visibility private
      def self.new(device)
        return device._ioc_qpainter_new if device.respond_to?(:_ioc_qpainter_new)
        allocate.tap { |o| o.__send__(:initialize, device) }
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param device [QPaintDevice]
      # @return [QPainter]
      def initialize(device)
        _initialize(device)
      end

      # @!visibility private
      def begin(device)
        return device._ioc_qpainter_begin(self) if device.respond_to?(:_ioc_qpainter_begin)
        _begin(device)
      end

      # @!visibility private
      def draw_text(*args)
        args.each_with_index { |_, index| T.args_nth_to_qstr(args, index) }
        _draw_text(*args)
      end
    end
  end
end
