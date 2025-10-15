# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qmargins.html
    class QMargins
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QMargins]
      #
      # @overload initialize
      #
      # @overload initialize(left, top, right, bottom)
      #   @param left [Integer]
      #   @param top [Integer]
      #   @param right [Integer]
      #   @param bottom [Integer]
      def initialize(*args)
        _initialize(*args)
      end

      # @!visibility private
      def ==(other)
        return false unless [QtCore::QMargins, QtCore::QMarginsF].include?(other.class)
        self.class._operator_equal(self, other)
      end

      # @!visibility private
      def inspect
        T.inspect_struct(self, left:, top:, right:, bottom:)
      end
    end
  end
end
