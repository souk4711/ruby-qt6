# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qapplication.html
    class QApplication < RubyQt6::QtGui::QGuiApplication
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QApplication]
      #
      # Initializes the window system and constructs an application object with
      # argc command line arguments in argv.
      #
      # The global qApp pointer refers to this application object. Only one
      # application object should be created.
      #
      # This application object must be constructed before any paint devices
      # (including widgets, pixmaps, bitmaps etc.).
      def initialize
        _initialize
      end
    end
  end
end
