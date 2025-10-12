# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qtextoption.html
    class QTextOption
      # @!parse class Flag    ; end
      # @!parse class TabType ; end
      # @!parse class WrapMode; end
      rubyqt6_declare_enum_under QTextOption, QTextOption::Flag
      rubyqt6_declare_enum_under QTextOption, QTextOption::TabType
      rubyqt6_declare_enum_under QTextOption, QTextOption::WrapMode

      # @!parse class Flags; end
      rubyqt6_declare_qflags QTextOption::Flags, QTextOption::Flag
    end
  end
end
