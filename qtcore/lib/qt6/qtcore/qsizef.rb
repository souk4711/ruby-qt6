# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qsizef.html
    class QSizeF
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QSizeF]
      #
      # @overload initialize(width, height)
      #   @param width [Float]
      #   @param height [Float]
      #
      # @overload initialize(size)
      #   @param size [QSize]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
