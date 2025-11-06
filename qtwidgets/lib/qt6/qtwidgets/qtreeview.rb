# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qtreeview.html
    class QTreeView < RubyQt6::QtWidgets::QAbstractItemView
      # @!parse
      q_object do
        signal "collapsed(QModelIndex)"
        signal "expanded(QModelIndex)"
        slot "collapse(QModelIndex)"
        slot "collapseAll()"
        slot "expand(QModelIndex)"
        slot "expandAll()"
        slot "expandRecursively(QModelIndex)"
        slot "expandRecursively(QModelIndex,int)"
        slot "expandToDepth(int)"
        slot "hideColumn(int)"
        slot "resizeColumnToContents(int)"
        slot "showColumn(int)"
        slot "sortByColumn(int,Qt::SortOrder)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QTreeView]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
