# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qstandarditemmodel.html
    class QStandardItemModel < RubyQt6::QtCore::QAbstractItemModel
      # @!parse
      q_object do
        signal "itemChanged(QStandardItem*)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QStandardItemModel]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end

      # @!visibility private
      def append_column(*items)
        _append_column(to_qstandarditemlist(items))
      end

      # @!visibility private
      def append_row(*items)
        _append_row(to_qstandarditemlist(items))
      end

      # @!visibility private
      def insert_column(column, *items)
        _insert_column(column, to_qstandarditemlist(items))
      end

      # @!visibility private
      def insert_row(row, *items)
        _insert_row(row, to_qstandarditemlist(items))
      end

      private

      def to_qstandarditemlist(array)
        array.each_with_object(T::QList≺QStandardItem∗≻.new) { |o, memo| memo << o }
      end
    end
  end
end
