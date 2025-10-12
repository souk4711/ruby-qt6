# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qtextedit.html
    class QTextEdit < RubyQt6::QtWidgets::QAbstractScrollArea
      # @!parse class AutoFormattingFlag; end
      # @!parse class LineWrapMode      ; end
      rubyqt6_declare_enum_under QTextEdit, QTextEdit::AutoFormattingFlag
      rubyqt6_declare_enum_under QTextEdit, QTextEdit::LineWrapMode

      # @!parse class AutoFormatting; end
      rubyqt6_declare_qflags QTextEdit::AutoFormatting, QTextEdit::AutoFormattingFlag

      # @!parse
      q_object do
        signal "copyAvailable(bool)"
        signal "currentCharFormatChanged(QTextCharFormat)"
        signal "cursorPositionChanged()"
        signal "redoAvailable(bool)"
        signal "selectionChanged()"
        signal "textChanged()"
        signal "undoAvailable(bool)"
        slot "append(QString)"
        slot "clear()"
        slot "copy()"
        slot "cut()"
        slot "insertHtml(QString)"
        slot "insertPlainText(QString)"
        slot "paste()"
        slot "redo()"
        slot "scrollToAnchor(QString)"
        slot "selectAll()"
        slot "setAlignment(Qt::Alignment)"
        slot "setCurrentFont(QFont)"
        slot "setFontFamily(QString)"
        slot "setFontItalic(bool)"
        slot "setFontPointSize(double)"
        slot "setFontUnderline(bool)"
        slot "setFontWeight(int)"
        slot "setHtml(QString)"
        slot "setMarkdown(QString)"
        slot "setPlainText(QString)"
        slot "setTextBackgroundColor(QColor)"
        slot "setTextColor(QColor)"
        slot "setText(QString)"
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
      # @return [QTextEdit]
      def initialize(text = "", parent = nil)
        _initialize(T.to_qstr(text), parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
