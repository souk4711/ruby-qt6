# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qcolor.html
    class QColor
      # @!parse class NameFormat; end
      # @!parse class Spec      ; end
      rubyqt6_include_constants QColor, QColor::NameFormat
      rubyqt6_include_constants QColor, QColor::Spec

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param r [Integer]
      # @param g [Integer]
      # @param b [Integer]
      # @param a [Integer]
      # @return [QColor]
      def initialize(r, g, b, a = 255)
        _initialize(r, g, b, a)
      end
    end
  end
end
