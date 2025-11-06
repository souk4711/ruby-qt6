# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qtextedit.html
    class QTextEdit < RubyQt6::QtWidgets::QAbstractScrollArea
      INITIALIZE_ARG_ERROR_MESSAGE =
        "Could not resolve method call for #{name}#initialize\n" \
        "  2 overload(s) were evaluated based on the types of Ruby parameters provided:\n" \
        "    initialize(QWidget)\n" \
        "    initialize(QString, QWidget)\n"

      # @!parse class AutoFormattingFlag; end
      # @!parse class AutoFormatting    ; end
      # @!parse class LineWrapMode      ; end
      rubyqt6_declare_enum_under QTextEdit, QTextEdit::AutoFormattingFlag
      rubyqt6_declare_enum_under QTextEdit, QTextEdit::LineWrapMode
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

      # @return [QTextEdit]
      #
      # @overload initialize(parent = nil)
      #   @param parent [QWidget]
      #
      # @overload initialize(text, parent = nil)
      #   @param text [String, QString]
      #   @param parent [QWidget]
      def initialize(*args)
        parent = T.args_nth_delete_qwidget(args, -1)
        case args.size
        when 0 then _initialize(T.to_qstr(""), parent)
        when 1 then _initialize(T.to_qstr(args[-1]), parent)
        else raise ArgumentError, INITIALIZE_ARG_ERROR_MESSAGE
        end
        _take_ownership_from_ruby(self)
      end

      # @!visibility private
      def set_alignment(alignment)
        _set_alignment(T.to_qflags(alignment))
      end

      # @!visibility private
      def set_html(text)
        _set_html(T.to_qstr(text))
      end

      # @!visibility private
      def set_markdown(text)
        _set_markdown(T.to_qstr(text))
      end

      # @!visibility private
      def set_plain_text(text)
        _set_plain_text(T.to_qstr(text))
      end

      # @!visibility private
      def set_text(text)
        _set_text(T.to_qstr(text))
      end
    end
  end
end
