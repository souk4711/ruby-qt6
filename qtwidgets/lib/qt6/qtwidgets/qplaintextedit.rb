# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qplaintextedit.html
    class QPlainTextEdit < RubyQt6::QtWidgets::QAbstractScrollArea
      # @!parse class LineWrapMode; end
      rubyqt6_declare_enum_under QPlainTextEdit, QPlainTextEdit::LineWrapMode

      # @!parse
      q_object do
        signal "blockCountChanged(int)"
        signal "copyAvailable(bool)"
        signal "cursorPositionChanged()"
        signal "modificationChanged(bool)"
        signal "redoAvailable(bool)"
        signal "selectionChanged()"
        signal "textChanged()"
        signal "undoAvailable(bool)"
        signal "updateRequest(QRect,int)"
        slot "appendHtml(QString)"
        slot "appendPlainText(QString)"
        slot "centerCursor()"
        slot "clear()"
        slot "copy()"
        slot "cut()"
        slot "insertPlainText(QString)"
        slot "paste()"
        slot "redo()"
        slot "selectAll()"
        slot "setPlainText(QString)"
        slot "undo()"
        slot "zoomIn(int)"
        slot "zoomIn()"
        slot "zoomOut(int)"
        slot "zoomOut()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param text [String, QString]
      # @param parent [QWidget]
      # @return [QPlainTextEdit]
      def initialize(text, parent = nil)
        _initialize(T.to_qstr(text), parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
