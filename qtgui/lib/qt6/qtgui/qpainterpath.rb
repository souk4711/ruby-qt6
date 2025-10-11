# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qpainterpath.html
    class QPainterPath
      # @!parse class ElementType; end
      rubyqt6_declare_enum_under QPainterPath, QPainterPath::ElementType

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QPainterPath]
      #
      # @overload initialize
      #
      # @overload initialize(start_point)
      #   @param start_point [QPointF]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
