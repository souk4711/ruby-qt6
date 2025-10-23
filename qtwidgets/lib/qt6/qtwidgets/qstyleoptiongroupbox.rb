# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstyleoptiongroupbox.html
    class QStyleOptionGroupBox < RubyQt6::QtWidgets::QStyleOptionComplex
      # @!parse class StyleOptionType   ; end
      # @!parse class StyleOptionVersion; end
      rubyqt6_declare_enum_under QStyleOptionGroupBox, QStyleOptionGroupBox::StyleOptionType
      rubyqt6_declare_enum_under QStyleOptionGroupBox, QStyleOptionGroupBox::StyleOptionVersion
    end
  end
end
