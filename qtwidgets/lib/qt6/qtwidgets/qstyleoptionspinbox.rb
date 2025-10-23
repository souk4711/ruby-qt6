# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstyleoptionspinbox.html
    class QStyleOptionSpinBox < RubyQt6::QtWidgets::QStyleOptionComplex
      # @!parse class StyleOptionType   ; end
      # @!parse class StyleOptionVersion; end
      rubyqt6_declare_enum_under QStyleOptionSpinBox, QStyleOptionSpinBox::StyleOptionType
      rubyqt6_declare_enum_under QStyleOptionSpinBox, QStyleOptionSpinBox::StyleOptionVersion
    end
  end
end
