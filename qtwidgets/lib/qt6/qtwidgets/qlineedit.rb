# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qlineedit.html
    class QLineEdit < RubyQt6::QtWidgets::QWidget
      INITIALIZE_ARG_ERROR_MESSAGE =
        "Could not resolve method call for #{name}#initialize\n" \
        "  2 overload(s) were evaluated based on the types of Ruby parameters provided:\n" \
        "    initialize(QWidget)\n" \
        "    initialize(QString, QWidget)\n"

      # @!parse class ActionPosition; end
      # @!parse class EchoMode      ; end
      rubyqt6_declare_enum_under QLineEdit, QLineEdit::ActionPosition
      rubyqt6_declare_enum_under QLineEdit, QLineEdit::EchoMode

      # @!parse
      q_object do
        signal "cursorPositionChanged(int,int)"
        signal "editingFinished()"
        signal "inputRejected()"
        signal "returnPressed()"
        signal "selectionChanged()"
        signal "textChanged(QString)"
        signal "textEdited(QString)"
        slot "clear()"
        slot "copy()"
        slot "cut()"
        slot "paste()"
        slot "redo()"
        slot "selectAll()"
        slot "setText(QString)"
        slot "undo()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QLineEdit]
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
        _take_ownership_from_ruby(self) if parent
      end

      # @!visibility private
      def set_alignment(alignment)
        _set_alignment(T.to_qflags(alignment))
      end

      # @!visibility private
      def set_input_mask(input_mask)
        _set_input_mask(T.to_qstr(input_mask))
      end

      # @!visibility private
      def set_text(text)
        _set_text(T.to_qstr(text))
      end
    end
  end
end
