# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qlineedit.html
    class QLineEdit < RubyQt6::QtWidgets::QWidget
      # @!parse class ActionPosition; end
      # @!parse class EchoMode      ; end
      rubyqt6_include_constants QLineEdit, QLineEdit::ActionPosition
      rubyqt6_include_constants QLineEdit, QLineEdit::EchoMode

      # @!parse
      q_object do
        signal "textChanged(QString)"
        signal "textEdited(QString)"
        signal "cursorPositionChanged(int,int)"
        signal "returnPressed()"
        signal "editingFinished()"
        signal "selectionChanged()"
        signal "inputRejected()"
        slot "setText(QString)"
        slot "clear()"
        slot "selectAll()"
        slot "undo()"
        slot "redo()"
        slot "cut()"
        slot "copy()"
        slot "paste()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param contents [String, QString]
      # @param parent [QWidget]
      # @return [QLineEdit]
      def initialize(contents, parent = nil)
        _initialize(T.to_qstr(contents), parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
