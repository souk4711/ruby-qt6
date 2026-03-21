# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qpersistentmodelindex.html
    class QPersistentModelIndex
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param index [QModelIndex]
      # @return [QPersistentModelIndex]
      def initialize(index)
        _initialize(index)
      end
    end
  end
end
