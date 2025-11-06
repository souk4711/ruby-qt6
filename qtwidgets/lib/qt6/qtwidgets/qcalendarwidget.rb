# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qcalendarwidget.html
    class QCalendarWidget < RubyQt6::QtWidgets::QWidget
      # @!parse class HorizontalHeaderFormat; end
      # @!parse class VerticalHeaderFormat  ; end
      # @!parse class SelectionMode         ; end
      rubyqt6_declare_enum_under QCalendarWidget, QCalendarWidget::HorizontalHeaderFormat
      rubyqt6_declare_enum_under QCalendarWidget, QCalendarWidget::VerticalHeaderFormat
      rubyqt6_declare_enum_under QCalendarWidget, QCalendarWidget::SelectionMode

      # @!parse
      q_object do
        signal "activated(QDate)"
        signal "clicked(QDate)"
        signal "currentPageChanged(int,int)"
        signal "selectionChanged()"
        slot "setCurrentPage(int,int)"
        slot "setDateRange(QDate,QDate)"
        slot "setGridVisible(bool)"
        slot "setNavigationBarVisible(bool)"
        slot "setSelectedDate(QDate)"
        slot "showNextMonth()"
        slot "showNextYear()"
        slot "showPreviousMonth()"
        slot "showPreviousYear()"
        slot "showSelectedDate()"
        slot "showToday()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QCalendarWidget]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
