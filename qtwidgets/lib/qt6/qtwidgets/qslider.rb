# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qslider.html
    class QSlider < RubyQt6::QtWidgets::QAbstractSlider
      # @!parse class TickPosition; end
      rubyqt6_declare_enum_under QSlider, QSlider::TickPosition

      # @!parse
      q_object do
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param orientation [Qt::Orientation]
      # @param parent [QWidget]
      # @return [QSlider]
      def initialize(orientation, parent = nil)
        _initialize(orientation, parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
