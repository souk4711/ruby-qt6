# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qwindow.html
    class QWindow < RubyQt6::QtCore::QObject
      # @!parse class Visibility; end
      rubyqt6_include_constants QWindow, QWindow::Visibility
    end
  end
end
