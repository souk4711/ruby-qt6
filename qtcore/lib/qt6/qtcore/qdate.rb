# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qdate.html
    class QDate
      include Comparable

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param y [Integer]
      # @param m [Integer]
      # @param d [Integer]
      # @return [QDate]
      def initialize(y, m, d)
        _initialize(y, m, d)
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
        return nil unless other.is_a?(self.class)
        self.class._operator_compare(self, other)
      end

      # @!visibility private
      def inspect
        T.inspect_struct(self, year:, month:, day:)
      end
    end
  end
end
