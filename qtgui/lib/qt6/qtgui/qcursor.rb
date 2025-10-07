# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qcursor.html
    class QCursor
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QCursor]
      #
      # @overload initialize
      #
      # @overload initialize(shape)
      #   @param shape [Qt::CursorShape]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
