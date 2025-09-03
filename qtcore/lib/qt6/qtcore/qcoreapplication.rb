# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qcoreapplication.html
    class QCoreApplication < RubyQt6::QtCore::QObject
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QCoreApplication]
      def initialize
        _initialize
        _initialize_qApp
      end

      private

      def _initialize_qApp
        $qApp = self
      end
    end
  end
end
