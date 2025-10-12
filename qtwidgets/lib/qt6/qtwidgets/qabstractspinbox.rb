# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qabstractspinbox.html
    class QAbstractSpinBox < RubyQt6::QtWidgets::QWidget
      # @!parse class ButtonSymbols  ; end
      # @!parse class CorrectionMode ; end
      # @!parse class StepEnabledFlag; end
      # @!parse class StepType       ; end
      rubyqt6_declare_enum_under QAbstractSpinBox, QAbstractSpinBox::ButtonSymbols
      rubyqt6_declare_enum_under QAbstractSpinBox, QAbstractSpinBox::CorrectionMode
      rubyqt6_declare_enum_under QAbstractSpinBox, QAbstractSpinBox::StepEnabledFlag
      rubyqt6_declare_enum_under QAbstractSpinBox, QAbstractSpinBox::StepType

      # @!parse class StepEnabled; end
      rubyqt6_declare_qflags QAbstractSpinBox::StepEnabled, QAbstractSpinBox::StepEnabledFlag

      # @!parse
      q_object do
        signal "editingFinished()"
        slot "clear()"
        slot "selectAll()"
        slot "stepDown()"
        slot "stepUp()"
      end
    end
  end
end
