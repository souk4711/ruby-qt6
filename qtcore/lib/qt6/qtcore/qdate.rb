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
    end
  end
end
