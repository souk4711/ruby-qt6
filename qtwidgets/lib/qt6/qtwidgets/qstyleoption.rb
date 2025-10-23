# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstyleoption.html
    class QStyleOption
      # @!parse class OptionType        ; end
      # @!parse class StyleOptionType   ; end
      # @!parse class StyleOptionVersion; end
      rubyqt6_declare_enum_under QStyleOption, QStyleOption::OptionType
      rubyqt6_declare_enum_under QStyleOption, QStyleOption::StyleOptionType
      rubyqt6_declare_enum_under QStyleOption, QStyleOption::StyleOptionVersion
    end
  end
end
