require 'qt6/all'

class CannonField < QWidget
  q_object do
    signal 'angleChanged(int)'
    signal 'forceChanged(int)'
    slot 'setAngle(int)'
    slot 'setForce(int)'
  end

  def initialize(parent = nil)
    super

    @ang = 45
    @f = 0
    set_palette(QPalette.new(QColor.new(250, 250, 200)))
    set_auto_fill_background(true)
  end

  def set_angle(degrees)
    degrees = 5 if degrees < 5
    degrees = 70 if degrees > 70

    return if @ang == degrees
    @ang = degrees

    repaint
    angle_changed.emit(@ang)
  end

  def set_force(newton)
    newton = 0 if newton.negative?
    return if @f == newton

    @f = newton
    force_changed.emit(@f)
  end

  def paint_event(e)
    return unless e.rect.intersects(cannon_rect)

    cr = cannon_rect
    pix = QPixmap.new(cr.size)
    pix.fill(QColor.new(250, 250, 200))

    painter = QPainter.new(pix)
    painter.set_pen(Qt::NoPen)
    painter.set_brush(QBrush.new(Qt::Blue))
    painter.translate(0, pix.height - 1)
    painter.draw_pie(QRect.new(-35, -35, 70, 70), 0, 90 * 16)
    painter.rotate(- @ang)
    painter.draw_rect(QRect.new(33, -4, 15, 8))
    painter.end

    painter.begin(self)
    painter.draw_pixmap(cr.top_left, pix)
    painter.end
  end

  def cannon_rect
    r = QRect.new(0, 0, 50, 50)
    r.move_bottom_left(rect.bottom_left)
    r
  end
end
