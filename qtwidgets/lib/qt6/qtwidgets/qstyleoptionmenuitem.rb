# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstyleoptionmenuitem.html
    class QStyleOptionMenuItem < RubyQt6::QtWidgets::QStyleOption
      # @!parse class StyleOptionType   ; end
      # @!parse class StyleOptionVersion; end
      # @!parse class MenuItemType      ; end
      # @!parse class CheckType         ; end
      rubyqt6_declare_enum_under QStyleOptionMenuItem, QStyleOptionMenuItem::StyleOptionType
      rubyqt6_declare_enum_under QStyleOptionMenuItem, QStyleOptionMenuItem::StyleOptionVersion
      rubyqt6_declare_enum_under QStyleOptionMenuItem, QStyleOptionMenuItem::MenuItemType
      rubyqt6_declare_enum_under QStyleOptionMenuItem, QStyleOptionMenuItem::CheckType
    end
  end
end
