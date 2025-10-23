# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstyleoptiontabbarbase.html
    class QStyleOptionTabBarBase < RubyQt6::QtWidgets::QStyleOption
      # @!parse class StyleOptionType   ; end
      # @!parse class StyleOptionVersion; end
      rubyqt6_declare_enum_under QStyleOptionTabBarBase, QStyleOptionTabBarBase::StyleOptionType
      rubyqt6_declare_enum_under QStyleOptionTabBarBase, QStyleOptionTabBarBase::StyleOptionVersion
    end
  end
end
