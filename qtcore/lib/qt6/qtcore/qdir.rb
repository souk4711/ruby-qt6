# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qdir.html
    class QDir
      # @!parse class Filter  ; end
      # @!parse class SortFlag; end
      rubyqt6_include_constants QDir, QDir::Filter
      rubyqt6_include_constants QDir, QDir::SortFlag
    end
  end
end
