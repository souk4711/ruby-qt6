# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qsize.html
    class QSize
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QSize]
      #
      # @overload initialize(width, height)
      #   @param width [Integer]
      #   @param height [Integer]
      def initialize(*args)
        _initialize(*args)
      end

      # @!visibility private
      def inspect
        T.q_inspect(self, width: width, height: height)
      end
    end
  end
end
