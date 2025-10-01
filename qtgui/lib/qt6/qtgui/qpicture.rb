# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qpicture.html
    class QPicture < RubyQt6::QtGui::QPaintDevice
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QPicture]
      #
      # @overload initialize
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
