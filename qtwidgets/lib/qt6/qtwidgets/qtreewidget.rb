# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qtreewidget.html
    class QTreeWidget < RubyQt6::QtWidgets::QTreeView
      # @!parse
      q_object do
        signal "currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)"
        signal "itemActivated(QTreeWidgetItem*,int)"
        signal "itemChanged(QTreeWidgetItem*,int)"
        signal "itemClicked(QTreeWidgetItem*,int)"
        signal "itemCollapsed(QTreeWidgetItem*)"
        signal "itemDoubleClicked(QTreeWidgetItem*,int)"
        signal "itemEntered(QTreeWidgetItem*,int)"
        signal "itemExpanded(QTreeWidgetItem*)"
        signal "itemPressed(QTreeWidgetItem*,int)"
        signal "itemSelectionChanged()"
        slot "clear()"
        slot "collapseItem(const QTreeWidgetItem*)"
        slot "expandItem(const QTreeWidgetItem*)"
        slot "scrollToItem(const QTreeWidgetItem*,QAbstractItemView::ScrollHint)"
        slot "scrollToItem(const QTreeWidgetItem*)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QTreeWidget]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
