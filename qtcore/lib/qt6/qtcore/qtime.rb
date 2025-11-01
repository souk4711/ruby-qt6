# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qtime.html
    class QTime
      include Comparable

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QTime]
      #
      # @overload initialize(h, m)
      #   @param h [Integer]
      #   @param m [Integer]
      #
      # @overload initialize(h, m, s)
      #   @param h [Integer]
      #   @param m [Integer]
      #   @param s [Integer]
      def initialize(*args)
        _initialize(*args)
      end

      # @!visibility private
      def to_string(*args)
        T.args_nth_to_qstr(args, 0)
        _to_string(*args)
      end

      # @!visibility private
      def to_s
        _to_string(QtCore::Qt::RFC2822Date).to_s
      end

      # @!visibility private
      def <=>(other)
        return nil unless other.is_a?(QtCore::QTime)
        self.class._operator_compare(self, other)
      end

      # @!visibility private
      def inspect
        T.inspect_struct(self, hour:, minute:, second:, msec:)
      end
    end
  end
end
