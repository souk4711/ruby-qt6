# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qapplication.html
    class QApplication < RubyQt6::QtGui::QGuiApplication
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QApplication]
      def initialize
        _initialize
        _initialize_qApp
      end
    end
  end
end
