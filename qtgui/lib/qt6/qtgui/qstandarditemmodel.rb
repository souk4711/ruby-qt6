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
    end
  end
end
