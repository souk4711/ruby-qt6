# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qfontmetrics.html
    class QFontMetrics
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QFontMetrics]
      #
      # @overload initialize(font)
      #   @param font [QFont]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
