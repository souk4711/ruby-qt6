# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qguiapplication.html
    class QGuiApplication < RubyQt6::QtCore::QCoreApplication
      # @!visibility private
      alias_method :_initialize, :initialize

      # @!visibility private
      def initialize
        _initialize
        _initialize_qApp
      end
    end
  end
end
