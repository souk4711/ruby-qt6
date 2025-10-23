# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstyleoptionfocusrect.html
    class QStyleOptionFocusRect < RubyQt6::QtWidgets::QStyleOption
      # @!parse class StyleOptionType   ; end
      # @!parse class StyleOptionVersion; end
      rubyqt6_declare_enum_under QStyleOptionFocusRect, QStyleOptionFocusRect::StyleOptionType
      rubyqt6_declare_enum_under QStyleOptionFocusRect, QStyleOptionFocusRect::StyleOptionVersion
    end
  end
end
