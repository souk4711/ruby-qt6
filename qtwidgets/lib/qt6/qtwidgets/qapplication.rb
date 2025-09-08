# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qapplication.html
    class QApplication < RubyQt6::QtGui::QGuiApplication
      # @!visibility private
      q_object do
        signal "focusChanged(QWidget*,QWidget*)"
        slot "aboutQt()"
        slot "closeAllWindows()"
        slot "setAutoSipEnabled(bool)"
        slot "setStyleSheet(QString)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param argv [Array<String>]
      # @return [QApplication]
      def initialize(argv)
        argv = Rice::Buffer≺char∗≻.new(argv.map(&:bytes))
        _initialize(argv.size, argv)
        _initialize_qApp
      end
    end
  end
end
