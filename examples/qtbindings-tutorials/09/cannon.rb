require 'qt6/all'

class CannonField < RubyQt6::Bando::QWidget
  q_object do
    signal 'angleChanged(int)'
    slot 'setAngle(int)'
  end

  def initialize(parent = nil)
    super

    @current_angle = 45
    set_palette(QPalette.new(QColor.new(250, 250, 200)))
    set_auto_fill_background(true)
  end

  def set_angle(degrees)
    degrees = 5 if degrees < 5
    degrees = 70 if degrees > 70

    return if @current_angle == degrees
    @current_angle = degrees

    repaint
    angle_changed.emit(@current_angle)
  end

  def paint_event(event)
    painter = QPainter.new(self)
    painter.set_pen(Qt::NoPen)
    painter.set_brush(QBrush.new(Qt::Blue))
    painter.translate(0, rect.bottom)
    painter.draw_pie(QRect.new(-35, -35, 70, 70), 0, 90 * 16)
    painter.rotate(- @current_angle)
    painter.draw_rect(QRect.new(33, -4, 15, 8))
    painter.end
  end
end
