# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstyleoptiontabwidgetframe.html
    class QStyleOptionTabWidgetFrame < RubyQt6::QtWidgets::QStyleOption
      # @!parse class StyleOptionType   ; end
      # @!parse class StyleOptionVersion; end
      rubyqt6_declare_enum_under QStyleOptionTabWidgetFrame, QStyleOptionTabWidgetFrame::StyleOptionType
      rubyqt6_declare_enum_under QStyleOptionTabWidgetFrame, QStyleOptionTabWidgetFrame::StyleOptionVersion
    end
  end
end
