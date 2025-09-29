# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qkeysequenceedit.html
    class QKeySequenceEdit < RubyQt6::QtWidgets::QWidget
      # @!parse
      q_object do
        signal "editingFinished()"
        signal "keySequenceChanged(QKeySequence)"
        slot "clear()"
        slot "setKeySequence(QKeySequence)"
        slot "setMaximumSequenceLength(qsizetype)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param key [QKeySequence]
      # @param parent [QWidget]
      # @return [QKeySequenceEdit]
      def initialize(key, parent = nil)
        _initialize(key, parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
