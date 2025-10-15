# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qline.html
    class QLine
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QLine]
      #
      # @overload initialize
      #
      # @overload initialize(x1, y1, x2, y2)
      #   @param x1 [Integer]
      #   @param y1 [Integer]
      #   @param x2 [Integer]
      #   @param y2 [Integer]
      #
      # @overload initialize(p1, p2)
      #   @param p1 [QPoint]
      #   @param p2 [QPoint]
      def initialize(*args)
        case args.size
        when 4 then _initialize(*args.map(&:to_i))
        else _initialize(*args)
        end
      end

      # @!visibility private
      def ==(other)
        return false unless other.is_a?(QtCore::QLine) || other.is_a?(QtCore::QLineF)
        self.class._operator_equal(self, other)
      end

      # @!visibility private
      def inspect
        T.inspect_struct(self, x1:, y1:, x2:, y2:)
      end
    end
  end
end
