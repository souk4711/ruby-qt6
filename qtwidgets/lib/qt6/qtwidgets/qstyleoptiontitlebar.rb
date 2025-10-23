# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstyleoptiontitlebar.html
    class QStyleOptionTitleBar < RubyQt6::QtWidgets::QStyleOptionComplex
      # @!parse class StyleOptionType   ; end
      # @!parse class StyleOptionVersion; end
      rubyqt6_declare_enum_under QStyleOptionTitleBar, QStyleOptionTitleBar::StyleOptionType
      rubyqt6_declare_enum_under QStyleOptionTitleBar, QStyleOptionTitleBar::StyleOptionVersion
    end
  end
end
