# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qclipboard.html
    class QClipboard < RubyQt6::QtCore::QObject
      # @!parse class Mode; end
      rubyqt6_declare_enum_under QClipboard, QClipboard::Mode

      # @!parse
      q_object do
        signal "changed(QClipboard::Mode)"
        signal "dataChanged()"
        signal "findBufferChanged()"
        signal "selectionChanged()"
      end
    end
  end
end
