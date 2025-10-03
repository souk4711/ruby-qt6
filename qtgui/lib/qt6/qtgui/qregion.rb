# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qregion.html
    class QRegion
      # @!parse class RegionType; end
      rubyqt6_declare_enum_under QRegion, QRegion::RegionType

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QRegion]
      #
      # @overload initialize(x, y, w, h)
      #   @param x [Integer]
      #   @param y [Integer]
      #   @param w [Integer]
      #   @param h [Integer]
      #
      # @overload initialize(x, y, w, h, t)
      #   @param x [Integer]
      #   @param y [Integer]
      #   @param w [Integer]
      #   @param h [Integer]
      #   @param t [QRegion::RegionType]
      #
      # @overload initialize(r)
      #   @param r [QRect]
      #
      # @overload initialize(r, t)
      #   @param r [QRect]
      #   @param t [QRegion::RegionType]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
