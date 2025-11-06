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
      def self.about(parent, title, text)
        _about(parent, T.to_qstr(title), T.to_qstr(text))
      end

      # @!visibility private
      def self.about_qt(parent, title = "")
        _about_qt(parent, T.to_qstr(title))
      end

      # @!visibility private
      def self.critical(parent, title, text, buttons = nil, default_button = nil)
        buttons ||= QtWidgets::QMessageBox::Ok
        default_button ||= QtWidgets::QMessageBox::NoButton
        _critical(parent, T.to_qstr(title), T.to_qstr(text), T.to_qflags(buttons), default_button)
      end

      # @!visibility private
      def self.information(parent, title, text, buttons = nil, default_button = nil)
        buttons ||= QtWidgets::QMessageBox::Ok
        default_button ||= QtWidgets::QMessageBox::NoButton
        _information(parent, T.to_qstr(title), T.to_qstr(text), T.to_qflags(buttons), default_button)
      end

      # @!visibility private
      def self.question(parent, title, text, buttons = nil, default_button = nil)
        buttons ||= QtWidgets::QMessageBox::Yes || QtWidgets::QMessageBox::No
        default_button ||= QtWidgets::QMessageBox::NoButton
        _question(parent, T.to_qstr(title), T.to_qstr(text), T.to_qflags(buttons), default_button)
      end

      # @!visibility private
      def self.warning(parent, title, text, buttons = nil, default_button = nil)
        buttons ||= QtWidgets::QMessageBox::Ok
        default_button ||= QtWidgets::QMessageBox::NoButton
        _warning(parent, T.to_qstr(title), T.to_qstr(text), T.to_qflags(buttons), default_button)
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
        _take_ownership_from_ruby(self)
      end
    end
  end
end
