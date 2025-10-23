# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstyleoptiondockwidget.html
    class QStyleOptionDockWidget < RubyQt6::QtWidgets::QStyleOption
      # @!parse class StyleOptionType   ; end
      # @!parse class StyleOptionVersion; end
      rubyqt6_declare_enum_under QStyleOptionDockWidget, QStyleOptionDockWidget::StyleOptionType
      rubyqt6_declare_enum_under QStyleOptionDockWidget, QStyleOptionDockWidget::StyleOptionVersion
    end
  end
end
