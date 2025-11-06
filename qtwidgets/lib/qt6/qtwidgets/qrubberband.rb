# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qrubberband.html
    class QRubberBand < RubyQt6::QtWidgets::QWidget
      # @!parse class Shape; end
      rubyqt6_declare_enum_under QRubberBand, QRubberBand::Shape

      # @!parse
      q_object do
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param shape [QRubberBand::Shape]
      # @param parent [QWidget]
      # @return [QRubberBand]
      def initialize(shape, parent = nil)
        _initialize(shape, parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
