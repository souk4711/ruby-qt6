# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qstandardpaths.html
    class QStandardPaths
      # @!parse class LocateOption    ; end
      # @!parse class LocateOptions   ; end
      # @!parse class StandardLocation; end
      rubyqt6_declare_enum_under QStandardPaths, QStandardPaths::LocateOption
      rubyqt6_declare_enum_under QStandardPaths, QStandardPaths::StandardLocation
      rubyqt6_declare_qflags QStandardPaths::LocateOptions, QStandardPaths::LocateOption
    end
  end
end
