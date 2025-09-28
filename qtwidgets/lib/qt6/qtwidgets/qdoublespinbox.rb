# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qdoublespinbox.html
    class QDoubleSpinBox < RubyQt6::QtWidgets::QAbstractSpinBox
      # @!parse
      q_object do
        signal "textChanged(QString)"
        signal "valueChanged(double)"
        slot "setValue(double)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QDoubleSpinBox]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
