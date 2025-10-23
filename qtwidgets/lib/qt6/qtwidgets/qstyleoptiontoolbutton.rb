# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstyleoptiontoolbutton.html
    class QStyleOptionToolButton < RubyQt6::QtWidgets::QStyleOptionComplex
      # @!parse class StyleOptionType   ; end
      # @!parse class StyleOptionVersion; end
      # @!parse class ToolButtonFeature ; end
      rubyqt6_declare_enum_under QStyleOptionToolButton, QStyleOptionToolButton::StyleOptionType
      rubyqt6_declare_enum_under QStyleOptionToolButton, QStyleOptionToolButton::StyleOptionVersion
      rubyqt6_declare_enum_under QStyleOptionToolButton, QStyleOptionToolButton::ToolButtonFeature
    end
  end
end
