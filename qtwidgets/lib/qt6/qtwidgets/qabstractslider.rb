# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qabstractslider.html
    class QAbstractSlider < RubyQt6::QtWidgets::QWidget
      # @!parse class SliderAction; end
      rubyqt6_include_constants QAbstractSlider, QAbstractSlider::SliderAction
    end
  end
end
