# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qprogressdialog.html
    class QProgressDialog < RubyQt6::QtWidgets::QDialog
      # @!parse
      q_object do
        signal "canceled()"
        slot "cancel()"
        slot "reset()"
        slot "setCancelButtonText(QString)"
        slot "setLabelText(QString)"
        slot "setMaximum(int)"
        slot "setMinimum(int)"
        slot "setMinimumDuration(int)"
        slot "setRange(int,int)"
        slot "setValue(int)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param label_text [String, QString]
      # @param cancel_button_text [String, QString]
      # @param minimum [Integer]
      # @param maximum [Integer]
      # @param parent [QWidget]
      # @return [QProgressDialog]
      def initialize(label_text, cancel_button_text, minimum, maximum, parent = nil)
        _initialize(label_text, cancel_button_text, minimum, maximum, parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
