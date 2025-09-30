# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qlistwidget.html
    class QListWidget < RubyQt6::QtWidgets::QListView
      # @!parse
      q_object do
        signal "currentItemChanged(QListWidgetItem*,QListWidgetItem*)"
        signal "currentRowChanged(int)"
        signal "currentTextChanged(QString)"
        signal "itemActivated(QListWidgetItem*)"
        signal "itemChanged(QListWidgetItem*)"
        signal "itemClicked(QListWidgetItem*)"
        signal "itemDoubleClicked(QListWidgetItem*)"
        signal "itemEntered(QListWidgetItem*)"
        signal "itemPressed(QListWidgetItem*)"
        signal "itemSelectionChanged()"
        slot "clear()"
        slot "scrollToItem(const QListWidgetItem*)"
        slot "scrollToItem(const QListWidgetItem*,QAbstractItemView::ScrollHint)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QListWidget]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
