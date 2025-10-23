# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstyleoptionrubberband.html
    class QStyleOptionRubberBand < RubyQt6::QtWidgets::QStyleOption
      # @!parse class StyleOptionType   ; end
      # @!parse class StyleOptionVersion; end
      rubyqt6_declare_enum_under QStyleOptionRubberBand, QStyleOptionRubberBand::StyleOptionType
      rubyqt6_declare_enum_under QStyleOptionRubberBand, QStyleOptionRubberBand::StyleOptionVersion
    end
  end
end
