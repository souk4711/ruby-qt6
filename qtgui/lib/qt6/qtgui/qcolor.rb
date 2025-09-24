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

      # @return [QColor]
      #
      # @overload initialize(r, g, b, a = 255)
      #   @param r [Integer]
      #   @param g [Integer]
      #   @param b [Integer]
      #   @param a [Integer]
      #
      # @overload initialize(color)
      #   @param color [String]
      #
      # @overload initialize(color)
      #   @param color [Qt::GlobalColor]
      #
      # @overload initialize(color)
      #   @param color [QString]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
