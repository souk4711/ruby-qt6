# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qabstractitemmodel.html
    class QAbstractItemModel < RubyQt6::QtCore::QObject
      # @!parse class CheckIndexOption; end
      # @!parse class LayoutChangeHint; end
      rubyqt6_declare_enum_under QAbstractItemModel, QAbstractItemModel::CheckIndexOption, alias: false
      rubyqt6_declare_enum_under QAbstractItemModel, QAbstractItemModel::LayoutChangeHint

      # @!parse
      q_object do
        signal "columnsAboutToBeInserted(QModelIndex,int,int)"
        signal "columnsAboutToBeMoved(QModelIndex,int,int,QModelIndex,int)"
        signal "columnsAboutToBeRemoved(QModelIndex,int,int)"
        signal "columnsInserted(QModelIndex,int,int)"
        signal "columnsMoved(QModelIndex,int,int,QModelIndex,int)"
        signal "columnsRemoved(QModelIndex,int,int)"
        signal "dataChanged(QModelIndex,QModelIndex)"
        signal "dataChanged(QModelIndex,QModelIndex,QList<int>)"
        signal "headerDataChanged(Qt::Orientation,int,int)"
        signal "layoutAboutToBeChanged()"
        signal "layoutAboutToBeChanged(QList<QPersistentModelIndex>)"
        signal "layoutAboutToBeChanged(QList<QPersistentModelIndex>,QAbstractItemModel::LayoutChangeHint)"
        signal "layoutChanged()"
        signal "layoutChanged(QList<QPersistentModelIndex>)"
        signal "layoutChanged(QList<QPersistentModelIndex>,QAbstractItemModel::LayoutChangeHint)"
        signal "modelAboutToBeReset()"
        signal "modelReset()"
        signal "rowsAboutToBeInserted(QModelIndex,int,int)"
        signal "rowsAboutToBeMoved(QModelIndex,int,int,QModelIndex,int)"
        signal "rowsAboutToBeRemoved(QModelIndex,int,int)"
        signal "rowsInserted(QModelIndex,int,int)"
        signal "rowsMoved(QModelIndex,int,int,QModelIndex,int)"
        signal "rowsRemoved(QModelIndex,int,int)"
        slot "revert()"
        slot "submit()"
      end
    end
  end
end
