# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstyleoptiongraphicsitem.html
    class QStyleOptionGraphicsItem < RubyQt6::QtWidgets::QStyleOption
      # @!parse class StyleOptionType   ; end
      # @!parse class StyleOptionVersion; end
      rubyqt6_declare_enum_under QStyleOptionGraphicsItem, QStyleOptionGraphicsItem::StyleOptionType
      rubyqt6_declare_enum_under QStyleOptionGraphicsItem, QStyleOptionGraphicsItem::StyleOptionVersion
    end
  end
end
