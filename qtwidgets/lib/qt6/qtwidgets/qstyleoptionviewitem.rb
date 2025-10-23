# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstyleoptionviewitem.html
    class QStyleOptionViewItem < RubyQt6::QtWidgets::QStyleOption
      # @!parse class StyleOptionType   ; end
      # @!parse class StyleOptionVersion; end
      # @!parse class Position          ; end
      # @!parse class ViewItemFeature   ; end
      # @!parse class ViewItemPosition  ; end
      rubyqt6_declare_enum_under QStyleOptionViewItem, QStyleOptionViewItem::StyleOptionType
      rubyqt6_declare_enum_under QStyleOptionViewItem, QStyleOptionViewItem::StyleOptionVersion
      rubyqt6_declare_enum_under QStyleOptionViewItem, QStyleOptionViewItem::Position
      rubyqt6_declare_enum_under QStyleOptionViewItem, QStyleOptionViewItem::ViewItemFeature
      rubyqt6_declare_enum_under QStyleOptionViewItem, QStyleOptionViewItem::ViewItemPosition
    end
  end
end
