# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qabstractitemdelegate.html
    class QAbstractItemDelegate < RubyQt6::QtCore::QObject
      # @!parse class EndEditHint; end
      rubyqt6_declare_enum_under QAbstractItemDelegate, QAbstractItemDelegate::EndEditHint

      # @!parse
      q_object do
        signal "closeEditor(QWidget*,QAbstractItemDelegate::EndEditHint)"
        signal "closeEditor(QWidget*)"
        signal "commitData(QWidget*)"
        signal "sizeHintChanged(QModelIndex)"
      end
    end
  end
end
