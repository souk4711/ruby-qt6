# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qfontcombobox.html
    class QFontComboBox < RubyQt6::QtWidgets::QComboBox
      # @!parse class FontFilter; end
      rubyqt6_declare_enum_under QFontComboBox, QFontComboBox::FontFilter

      # @!parse
      # @!parse
      q_object do
        signal "currentFontChanged(QFont)"
        slot "setCurrentFont(QFont)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QFontComboBox]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
