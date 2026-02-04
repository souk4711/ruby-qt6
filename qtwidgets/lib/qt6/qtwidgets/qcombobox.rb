# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qcombobox.html
    class QComboBox < RubyQt6::QtWidgets::QWidget
      # @!parse class InsertPolicy    ; end
      # @!parse class LabelDrawingMode; end
      # @!parse class SizeAdjustPolicy; end
      rubyqt6_declare_enum_under QComboBox, QComboBox::InsertPolicy
      rubyqt6_declare_enum_under QComboBox, QComboBox::LabelDrawingMode, alias: false
      rubyqt6_declare_enum_under QComboBox, QComboBox::SizeAdjustPolicy

      # @!parse
      q_object do
        signal "activated(int)"
        signal "currentIndexChanged(int)"
        signal "currentTextChanged(QString)"
        signal "editTextChanged(QString)"
        signal "highlighted(int)"
        signal "textActivated(QString)"
        signal "textHighlighted(QString)"
        slot "clear()"
        slot "clearEditText()"
        slot "setCurrentIndex(int)"
        slot "setCurrentText(QString)"
        slot "setEditText(QString)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QComboBox]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end

      # @!visibility private
      def add_item(*args)
        _add_item(*args.map { |arg| T.to_qstr(arg) })
      end

      # @!visibility private
      def find_text(text, flags = nil)
        flags ||= Qt::MatchExactly | Qt::MatchCaseSensitive
        _find_text(T.to_qstr(text), T.to_qflags(flags))
      end
    end
  end
end
