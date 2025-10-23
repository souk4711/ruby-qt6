# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstyleoptionbutton.html
    class QStyleOptionButton < RubyQt6::QtWidgets::QStyleOption
      # @!parse class StyleOptionType   ; end
      # @!parse class StyleOptionVersion; end
      # @!parse class ButtonFeature     ; end
      rubyqt6_declare_enum_under QStyleOptionButton, QStyleOptionButton::StyleOptionType
      rubyqt6_declare_enum_under QStyleOptionButton, QStyleOptionButton::StyleOptionVersion
      rubyqt6_declare_enum_under QStyleOptionButton, QStyleOptionButton::ButtonFeature
    end
  end
end
