# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qtimer.html
    class QTimer < RubyQt6::QtCore::QObject
      # @!parse
      q_object do
        signal "timeout()"
        slot "start(int)"
        slot "start()"
        slot "stop()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QTimer]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
