# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qframe.html
    class QFrame < RubyQt6::QtWidgets::QWidget
      # @!parse class Shadow; end
      # @!parse class Shape ; end
      rubyqt6_include_constants QFrame, QFrame::Shadow
      rubyqt6_include_constants QFrame, QFrame::Shape

      # @!visibility private
      q_object do
      end
    end
  end
end
