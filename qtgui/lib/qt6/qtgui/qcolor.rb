# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qcolor.html
    class QColor
      # @!parse class NameFormat; end
      # @!parse class Spec      ; end
      rubyqt6_declare_enum_under QColor, QColor::NameFormat
      rubyqt6_declare_enum_under QColor, QColor::Spec

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QColor]
      #
      # @overload initialize(r, g, b)
      #   @param r [Integer]
      #   @param g [Integer]
      #   @param b [Integer]
      #
      # @overload initialize(r, g, b, a)
      #   @param r [Integer]
      #   @param g [Integer]
      #   @param b [Integer]
      #   @param a [Integer]
      #
      # @overload initialize(color)
      #   @param color [Qt::GlobalColor]
      #
      # @overload initialize(color)
      #   @param color [String]
      #
      # @overload initialize(color)
      #   @param color [QString]
      def initialize(*args)
        _initialize(*args)
      end

      # @!visibility private
      def inspect
        rgb = name(QColor::NameFormat::HexRgb).to_s
        T.q_inspect(self, rgb:)
      end
    end
  end
end
