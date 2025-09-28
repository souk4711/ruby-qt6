# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qabstractspinbox.html
    class QAbstractSpinBox < RubyQt6::QtWidgets::QWidget
      # @!parse class ButtonSymbols  ; end
      # @!parse class CorrectionMode ; end
      # @!parse class StepEnabledFlag; end
      # @!parse class StepType       ; end
      rubyqt6_include_constants QAbstractSpinBox, QAbstractSpinBox::ButtonSymbols
      rubyqt6_include_constants QAbstractSpinBox, QAbstractSpinBox::CorrectionMode
      rubyqt6_include_constants QAbstractSpinBox, QAbstractSpinBox::StepEnabledFlag
      rubyqt6_include_constants QAbstractSpinBox, QAbstractSpinBox::StepType

      # @!parse
      q_object do
        signal "editingFinished()"
        slot "stepUp()"
        slot "stepDown()"
        slot "selectAll()"
        slot "clear()"
      end
    end
  end
end
