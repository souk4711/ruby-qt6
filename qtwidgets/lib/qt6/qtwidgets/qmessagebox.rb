# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qmessagebox.html
    class QMessageBox < RubyQt6::QtWidgets::QDialog
      # @!parse class ButtonRole     ; end
      # @!parse class Icon           ; end
      # @!parse class Option         ; end
      # @!parse class StandardButton ; end
      # @!parse class StandardButtons; end
      rubyqt6_declare_enum_under QMessageBox, QMessageBox::ButtonRole
      rubyqt6_declare_enum_under QMessageBox, QMessageBox::Icon
      rubyqt6_declare_enum_under QMessageBox, QMessageBox::Option
      rubyqt6_declare_enum_under QMessageBox, QMessageBox::StandardButton
      rubyqt6_declare_qflags QMessageBox::StandardButtons, QMessageBox::StandardButton

      # @!parse
      q_object do
        signal "buttonClicked(QAbstractButton*)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param icon [QMessageBox::Icon]
      # @param title [String, QString]
      # @param text [String, QString]
      # @param buttons [QMessageBox::StandardButtons]
      # @param parent [QWidget]
      # @return [QMessageBox]
      def initialize(icon, title, text, buttons, parent = nil)
        _initialize(icon, title, text, buttons, parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
