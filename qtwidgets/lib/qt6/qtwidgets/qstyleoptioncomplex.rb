# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstyleoptioncomplex.html
    class QStyleOptionComplex < RubyQt6::QtWidgets::QStyleOption
      # @!parse class StyleOptionType   ; end
      # @!parse class StyleOptionVersion; end
      rubyqt6_declare_enum_under QStyleOptionComplex, QStyleOptionComplex::StyleOptionType
      rubyqt6_declare_enum_under QStyleOptionComplex, QStyleOptionComplex::StyleOptionVersion
    end
  end
end
