# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qtablewidget.html
    class QTableWidget < RubyQt6::QtWidgets::QTableView
      # @!parse
      q_object do
        signal "cellActivated(int,int)"
        signal "cellChanged(int,int)"
        signal "cellClicked(int,int)"
        signal "cellDoubleClicked(int,int)"
        signal "cellEntered(int,int)"
        signal "cellPressed(int,int)"
        signal "currentCellChanged(int,int,int,int)"
        signal "currentItemChanged(QTableWidgetItem*,QTableWidgetItem*)"
        signal "itemActivated(QTableWidgetItem*)"
        signal "itemChanged(QTableWidgetItem*)"
        signal "itemClicked(QTableWidgetItem*)"
        signal "itemDoubleClicked(QTableWidgetItem*)"
        signal "itemEntered(QTableWidgetItem*)"
        signal "itemPressed(QTableWidgetItem*)"
        signal "itemSelectionChanged()"
        slot "clear()"
        slot "clearContents()"
        slot "insertColumn(int)"
        slot "insertRow(int)"
        slot "removeColumn(int)"
        slot "removeRow(int)"
        slot "scrollToItem(const QTableWidgetItem*,QAbstractItemView::ScrollHint)"
        slot "scrollToItem(const QTableWidgetItem*)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param rows [Integer]
      # @param columns [Integer]
      # @param parent [QWidget]
      # @return [QTableWidget]
      def initialize(rows, columns, parent = nil)
        _initialize(rows, columns, parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
