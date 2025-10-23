# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstyleoptionslider.html
    class QStyleOptionSlider < RubyQt6::QtWidgets::QStyleOptionComplex
      # @!parse class StyleOptionType   ; end
      # @!parse class StyleOptionVersion; end
      rubyqt6_declare_enum_under QStyleOptionSlider, QStyleOptionSlider::StyleOptionType
      rubyqt6_declare_enum_under QStyleOptionSlider, QStyleOptionSlider::StyleOptionVersion
    end
  end
end
