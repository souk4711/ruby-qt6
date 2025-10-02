# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qmodelindex.html
    class QModelIndex
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QModelIndex]
      def initialize
        _initialize
      end
    end
  end
end
