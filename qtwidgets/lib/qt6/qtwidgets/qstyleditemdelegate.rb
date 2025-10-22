# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstyleditemdelegate.html
    class QStyledItemDelegate < RubyQt6::QtWidgets::QAbstractItemDelegate
      # @!parse
      q_object do
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QStyledItemDelegate]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
