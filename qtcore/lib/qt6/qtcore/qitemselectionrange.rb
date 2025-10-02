# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qitemselectionrange.html
    class QItemSelectionRange
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QItemSelectionRange]
      #
      # @overload initialize
      #
      # @overload initialize(index)
      #   @param index [QModelIndex]
      #
      # @overload initialize(top_left, bottom_right)
      #   @param top_left [QModelIndex]
      #   @param bottom_right [QModelIndex]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
