# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qfontdialog.html
    class QFontDialog < RubyQt6::QtWidgets::QDialog
      # @!parse class FontDialogOption; end
      rubyqt6_declare_enum_under QFontDialog, QFontDialog::FontDialogOption

      # @!parse
      q_object do
        signal "currentFontChanged(QFont)"
        signal "fontSelected(QFont)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param initial [QFont]
      # @param parent [QWidget]
      # @return [QFontDialog]
      def initialize(initial, parent = nil)
        _initialize(initial, parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
