# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qfileiconprovider.html
    class QFileIconProvider < RubyQt6::QtGui::QAbstractFileIconProvider
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QFileIconProvider]
      def initialize
        _initialize
      end
    end
  end
end
