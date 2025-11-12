# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qgradient.html
    class QGradient
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QGradient]
      #
      # @overload initialize
      #
      # @overload initialize(preset)
      #   @param preset [QGradient::Preset]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
