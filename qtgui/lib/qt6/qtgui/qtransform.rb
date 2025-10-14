# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qtransform.html
    class QTransform
      # @!parse class TransformationType; end
      rubyqt6_declare_enum_under QTransform, QTransform::TransformationType

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QTransform]
      #
      # @overload initialize
      #
      # @overload initialize(m11, m12, m21, m22, dx, dy)
      #   @param m11 [Float]
      #   @param m12 [Float]
      #   @param m21 [Float]
      #   @param m22 [Float]
      #   @param dx [Float]
      #   @param dy [Float]
      #
      # @overload initialize(m11, m12, m13, m21, m22, m23, m31, m32, m33)
      #   @param m11 [Float]
      #   @param m12 [Float]
      #   @param m13 [Float]
      #   @param m21 [Float]
      #   @param m22 [Float]
      #   @param m23 [Float]
      #   @param m31 [Float]
      #   @param m32 [Float]
      #   @param m33 [Float]
      def initialize(*args)
        _initialize(*args)
      end

      # @!visibility private
      def inspect
        T.inspect_struct(self, m11:, m12:, m13:, m21:, m22:, m23:, m31:, m32:, m33:)
      end
    end
  end
end
