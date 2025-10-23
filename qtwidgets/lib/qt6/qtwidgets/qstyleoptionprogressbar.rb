# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstyleoptionprogressbar.html
    class QStyleOptionProgressBar < RubyQt6::QtWidgets::QStyleOption
      # @!parse class StyleOptionType   ; end
      # @!parse class StyleOptionVersion; end
      rubyqt6_declare_enum_under QStyleOptionProgressBar, QStyleOptionProgressBar::StyleOptionType
      rubyqt6_declare_enum_under QStyleOptionProgressBar, QStyleOptionProgressBar::StyleOptionVersion
    end
  end
end
