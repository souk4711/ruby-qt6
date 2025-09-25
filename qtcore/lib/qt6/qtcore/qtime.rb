# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qtime.html
    class QTime
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param h [Integer]
      # @param m [Integer]
      # @param s [Integer]
      # @param ms [Integer]
      # @return [QTime]
      def initialize(h, m, s = 0, ms = 0)
        _initialize(h, m, s, ms)
      end

      # @!visibility private
      def inspect
        T.q_inspect(self, hour: hour, minute: minute, second: second, msec: msec)
      end
    end
  end
end
