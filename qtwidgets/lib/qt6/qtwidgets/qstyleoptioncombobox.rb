# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstyleoptioncombobox.html
    class QStyleOptionComboBox < RubyQt6::QtWidgets::QStyleOptionComplex
      # @!parse class StyleOptionType   ; end
      # @!parse class StyleOptionVersion; end
      rubyqt6_declare_enum_under QStyleOptionComboBox, QStyleOptionComboBox::StyleOptionType
      rubyqt6_declare_enum_under QStyleOptionComboBox, QStyleOptionComboBox::StyleOptionVersion
    end
  end
end
