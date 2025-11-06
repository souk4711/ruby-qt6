# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qtimeedit.html
    class QTimeEdit < RubyQt6::QtWidgets::QDateTimeEdit
      # @!parse
      q_object do
        signal "userTimeChanged(QTime)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param time [QTime]
      # @param parent [QWidget]
      # @return [QTimeEdit]
      def initialize(time, parent = nil)
        _initialize(time, parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
