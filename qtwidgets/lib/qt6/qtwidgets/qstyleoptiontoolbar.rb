# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstyleoptiontoolbar.html
    class QStyleOptionToolBar < RubyQt6::QtWidgets::QStyleOption
      # @!parse class StyleOptionType   ; end
      # @!parse class StyleOptionVersion; end
      # @!parse class ToolBarPosition   ; end
      # @!parse class ToolBarFeature    ; end
      rubyqt6_declare_enum_under QStyleOptionToolBar, QStyleOptionToolBar::StyleOptionType
      rubyqt6_declare_enum_under QStyleOptionToolBar, QStyleOptionToolBar::StyleOptionVersion
      rubyqt6_declare_enum_under QStyleOptionToolBar, QStyleOptionToolBar::ToolBarPosition
      rubyqt6_declare_enum_under QStyleOptionToolBar, QStyleOptionToolBar::ToolBarFeature
    end
  end
end
