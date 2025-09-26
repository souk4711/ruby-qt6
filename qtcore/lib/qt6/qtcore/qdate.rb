# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qdate.html
    class QDate
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
        to_string(Qt::RFC2822Date).to_s
      end

      # @!visibility private
      def inspect
        T.q_inspect(self, str: to_s)
      end
    end
  end
end
