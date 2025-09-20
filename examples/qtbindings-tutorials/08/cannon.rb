require 'qt6/all'

class CannonField < QWidget
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

    repaint()
    angle_changed.emit(@current_angle)
  end

  def paint_event(event)
    p = QPainter.new(self)
    p.draw_text(200, 200, QString.new("Angle = %d" % @current_angle))
    p.end
  end
end
