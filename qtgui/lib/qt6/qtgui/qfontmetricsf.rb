# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qfontmetricsf.html
    class QFontMetricsF
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QFontMetricsF]
      #
      # @overload initialize(font)
      #   @param font [QFont]
      #
      # @overload initialize(font_metrics)
      #   @param font_metrics [QFontMetrics]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
