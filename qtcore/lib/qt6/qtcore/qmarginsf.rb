# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qmarginsf.html
    class QMarginsF
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QMarginsF]
      #
      # @overload initialize(left, top, right, bottom)
      #   @param left [Float]
      #   @param top [Float]
      #   @param right [Float]
      #   @param bottom [Float]
      #
      # @overload initialize(margins)
      #   @param margins [QMargins]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
