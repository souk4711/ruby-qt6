# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qabstractbutton.html
    class QAbstractButton < RubyQt6::QtWidgets::QWidget
      # @!parse
      q_object do
        signal "clicked(bool)"
        signal "clicked()"
        signal "pressed()"
        signal "released()"
        signal "toggled(bool)"
        slot "animateClick()"
        slot "click()"
        slot "setChecked(bool)"
        slot "setIconSize(QSize)"
        slot "toggle()"
      end
    end
  end
end
