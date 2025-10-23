# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstyleoptionsizegrip.html
    class QStyleOptionSizeGrip < RubyQt6::QtWidgets::QStyleOptionComplex
      # @!parse class StyleOptionType   ; end
      # @!parse class StyleOptionVersion; end
      rubyqt6_declare_enum_under QStyleOptionSizeGrip, QStyleOptionSizeGrip::StyleOptionType
      rubyqt6_declare_enum_under QStyleOptionSizeGrip, QStyleOptionSizeGrip::StyleOptionVersion
    end
  end
end
