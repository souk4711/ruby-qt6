# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qcolumnview.html
    class QColumnView < RubyQt6::QtWidgets::QAbstractItemView
      # @!parse
      q_object do
        signal "updatePreviewWidget(QModelIndex)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QColumnView]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
