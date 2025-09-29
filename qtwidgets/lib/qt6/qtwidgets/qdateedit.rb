# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qdateedit.html
    class QDateEdit < RubyQt6::QtWidgets::QDateTimeEdit
      # @!parse
      q_object do
        signal "userDateChanged(QDate)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param date [QDate]
      # @param parent [QWidget]
      # @return [QDateEdit]
      def initialize(date, parent = nil)
        _initialize(date, parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
