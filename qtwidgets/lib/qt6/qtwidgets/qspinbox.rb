# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qspinbox.html
    class QSpinBox < RubyQt6::QtWidgets::QAbstractSpinBox
      # @!parse
      q_object do
        signal "valueChanged(int)"
        signal "textChanged(QString)"
        slot "setValue(int)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QSpinBox]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
