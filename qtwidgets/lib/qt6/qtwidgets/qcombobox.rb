# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qcombobox.html
    class QComboBox < RubyQt6::QtWidgets::QWidget
      # @!parse class InsertPolicy    ; end
      # @!parse class LabelDrawingMode; end
      # @!parse class SizeAdjustPolicy; end
      rubyqt6_declare_enum_under QComboBox, QComboBox::InsertPolicy
      rubyqt6_declare_enum_under QComboBox, QComboBox::LabelDrawingMode
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
        _take_ownership_from_ruby(self) if parent
      end

      # @!visibility private
      def add_item(*args)
        case args.size
        when 2 then _add_item(T.to_qstr(args[-2]), args[-1])
        when 3 then _add_item(args[-3], T.to_qstr(args[-2]), args[-1])
        else _add_item(*args)
        end
      end
    end
  end
end
