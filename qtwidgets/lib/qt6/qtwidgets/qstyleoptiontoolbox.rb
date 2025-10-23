# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstyleoptiontoolbox.html
    class QStyleOptionToolBox < RubyQt6::QtWidgets::QStyleOption
      # @!parse class StyleOptionType   ; end
      # @!parse class StyleOptionVersion; end
      # @!parse class TabPosition       ; end
      # @!parse class SelectedPosition  ; end
      rubyqt6_declare_enum_under QStyleOptionToolBox, QStyleOptionToolBox::StyleOptionType
      rubyqt6_declare_enum_under QStyleOptionToolBox, QStyleOptionToolBox::StyleOptionVersion
      rubyqt6_declare_enum_under QStyleOptionToolBox, QStyleOptionToolBox::TabPosition
      rubyqt6_declare_enum_under QStyleOptionToolBox, QStyleOptionToolBox::SelectedPosition
    end
  end
end
