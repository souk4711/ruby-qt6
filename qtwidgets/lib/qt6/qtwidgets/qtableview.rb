# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qtableview.html
    class QTableView < RubyQt6::QtWidgets::QAbstractItemView
      # @!parse
      q_object do
        slot "hideColumn(int)"
        slot "hideRow(int)"
        slot "resizeColumnToContents(int)"
        slot "resizeColumnsToContents()"
        slot "resizeRowToContents(int)"
        slot "resizeRowsToContents()"
        slot "selectColumn(int)"
        slot "selectRow(int)"
        slot "setShowGrid(bool)"
        slot "showColumn(int)"
        slot "showRow(int)"
        slot "sortByColumn(int,Qt::SortOrder)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QTableView]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
