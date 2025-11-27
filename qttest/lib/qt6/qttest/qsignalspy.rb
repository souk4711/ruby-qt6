# frozen_string_literal: true

module RubyQt6
  module QtTest
    # @see https://doc.qt.io/qt-6/qsignalspy.html
    class QSignalSpy
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param receiver [QObject]
      # @param signal [String]
      # @return [QSignalSpy]
      def initialize(receiver, signal)
        _initialize(receiver, "2#{signal}")
      end
    end
  end
end
