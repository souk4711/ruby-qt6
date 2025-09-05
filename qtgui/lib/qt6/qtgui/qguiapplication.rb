# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qguiapplication.html
    class QGuiApplication < RubyQt6::QtCore::QCoreApplication
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param argv [Array<String>]
      # @return [QGuiApplication]
      def initialize(argv)
        argv = Rice::Buffer≺char∗≻.new(argv.map(&:bytes))
        _initialize(argv.size, argv)
        _initialize_qApp
      end
    end
  end
end
