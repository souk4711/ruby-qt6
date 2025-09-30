# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qundoview.html
    class QUndoView < RubyQt6::QtWidgets::QListView
      # @!parse
      q_object do
        slot "setGroup(QUndoGroup*)"
        slot "setStack(QUndoStack*)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QUndoView]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
