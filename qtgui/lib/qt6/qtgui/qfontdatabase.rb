# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qfontdatabase.html
    class QFontDatabase
      # @!parse class WritingSystem; end
      # @!parse class SystemFont   ; end
      rubyqt6_declare_enum_under QFontDatabase, QFontDatabase::WritingSystem
      rubyqt6_declare_enum_under QFontDatabase, QFontDatabase::SystemFont
    end
  end
end
