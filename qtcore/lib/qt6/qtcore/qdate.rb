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
      def to_s
        to_string(QtCore::Qt::RFC2822Date).to_s
      end

      # @!visibility private
      def <=>(other)
        return nil unless other.is_a?(QtCore::QDate)
        self.class._operator_compare(self, other)
      end

      # @!visibility private
      def inspect
        T.inspect_struct(self, year:, month:, day:)
      end
    end
  end
end
