# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qabstractitemview.html
    class QAbstractItemView < RubyQt6::QtWidgets::QAbstractScrollArea
      # @!parse class DragDropMode     ; end
      # @!parse class EditTrigger      ; end
      # @!parse class EditTriggers     ; end
      # @!parse class ScrollHint       ; end
      # @!parse class ScrollMode       ; end
      # @!parse class SelectionBehavior; end
      # @!parse class SelectionMode    ; end
      rubyqt6_declare_enum_under QAbstractItemView, QAbstractItemView::DragDropMode
      rubyqt6_declare_enum_under QAbstractItemView, QAbstractItemView::EditTrigger
      rubyqt6_declare_enum_under QAbstractItemView, QAbstractItemView::ScrollHint
      rubyqt6_declare_enum_under QAbstractItemView, QAbstractItemView::ScrollMode
      rubyqt6_declare_enum_under QAbstractItemView, QAbstractItemView::SelectionBehavior
      rubyqt6_declare_enum_under QAbstractItemView, QAbstractItemView::SelectionMode
      rubyqt6_declare_qflags QAbstractItemView::EditTriggers, QAbstractItemView::EditTrigger

      # @!parse
      q_object do
        signal "activated(QModelIndex)"
        signal "clicked(QModelIndex)"
        signal "doubleClicked(QModelIndex)"
        signal "entered(QModelIndex)"
        signal "iconSizeChanged(QSize)"
        signal "pressed(QModelIndex)"
        signal "viewportEntered()"
        slot "clearSelection()"
        slot "edit(QModelIndex)"
        slot "reset()"
        slot "scrollToBottom()"
        slot "scrollToTop()"
        slot "selectAll()"
        slot "setCurrentIndex(QModelIndex)"
        slot "setRootIndex(QModelIndex)"
        slot "update(QModelIndex)"
      end
    end
  end
end
