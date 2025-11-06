# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qitemselectionmodel.html
    class QItemSelectionModel < RubyQt6::QtCore::QObject
      # @!parse class SelectionFlag ; end
      # @!parse class SelectionFlags; end
      rubyqt6_declare_enum_under QItemSelectionModel, QItemSelectionModel::SelectionFlag
      rubyqt6_declare_qflags QItemSelectionModel::SelectionFlags, QItemSelectionModel::SelectionFlag

      # @!parse
      q_object do
        signal "currentChanged(QModelIndex,QModelIndex)"
        signal "currentColumnChanged(QModelIndex,QModelIndex)"
        signal "currentRowChanged(QModelIndex,QModelIndex)"
        signal "modelChanged(QAbstractItemModel*)"
        signal "selectionChanged(QItemSelection,QItemSelection)"
        slot "clear()"
        slot "clearCurrentIndex()"
        slot "clearSelection()"
        slot "reset()"
        slot "select(QModelIndex,QItemSelectionModel::SelectionFlags)"
        slot "select(QItemSelection,QItemSelectionModel::SelectionFlags)"
        slot "setCurrentIndex(QModelIndex,QItemSelectionModel::SelectionFlags)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param model [QAbstractItemModel]
      # @param parent [QObject]
      # @return [QItemSelectionModel]
      def initialize(model = nil, parent = nil)
        _initialize(model, parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
