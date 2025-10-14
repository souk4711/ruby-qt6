# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qsize.html
    class QSize
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QSize]
      #
      # @overload initialize
      #
      # @overload initialize(width, height)
      #   @param width [Integer]
      #   @param height [Integer]
      def initialize(*args)
        _initialize(*args)
      end

      # @!visibility private
      def ==(other)
        return false unless other.is_a?(QtCore::QSize) || other.is_a?(QtCore::QSizeF)
        self.class._operator_equal(self, other)
      end

      # @!visibility private
      def inspect
        T.q_inspect(self, width:, height:)
      end
    end
  end
end
