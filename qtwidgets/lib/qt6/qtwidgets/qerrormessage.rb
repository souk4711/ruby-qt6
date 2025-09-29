# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qerrormessage.html
    class QErrorMessage < RubyQt6::QtWidgets::QDialog
      # @!parse
      q_object do
        slot "showMessage(QString)"
        slot "showMessage(QString,QString)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QErrorMessage]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
