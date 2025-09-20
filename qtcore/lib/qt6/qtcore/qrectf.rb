# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qrectf.html
    class QRectF
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param w [Float]
      # @param y [Float]
      # @param width [Float]
      # @param height [Float]
      # @return [QRectF]
      def initialize(x, y, width, height)
        _initialize(x, y, width, height)
      end
    end
  end
end
