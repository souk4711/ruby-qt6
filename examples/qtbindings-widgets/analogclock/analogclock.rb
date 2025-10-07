# frozen_string_literal: true

class AnalogClock < RubyQt6::Bando::QWidget
  def initialize(parent = nil)
    super(parent)

    @timer = QTimer.new(self)
    @timer.timeout.connect(self, :update)
    @timer.start(1000)

    set_window_title(tr('Analog Clock'))
    resize(200, 200)
  end

  def paint_event(_e)
    hour_hand = QPolygon.new << QPoint.new(7, 8) << QPoint.new(-7, 8) << QPoint.new(0, -40)
    minute_hand = QPolygon.new << QPoint.new(7, 8) << QPoint.new(-7, 8) << QPoint.new(0, -70)
    hour_color = QColor.new(127, 0, 127)
    minute_color = QColor.new(0, 127, 127, 191)

    side = width < height ? width : height
    time = QTime.current_time

    painter = QPainter.new(self)
    painter.set_render_hint QPainter::Antialiasing
    painter.translate(width / 2, height / 2)
    painter.scale(side / 200.0, side / 200.0)

    painter.set_pen Qt::NoPen
    painter.set_brush QBrush.new(hour_color)

    painter.save
    painter.rotate(30.0 * (time.hour + time.minute / 60.0))
    painter.draw_convex_polygon(hour_hand)
    painter.restore

    painter.set_pen hour_color
    (0...12).each do |_i|
      painter.draw_line(88, 0, 96, 0)
      painter.rotate(30.0)
    end

    painter.set_pen Qt::NoPen
    painter.set_brush QBrush.new(minute_color)

    painter.save
    painter.rotate(6.0 * (time.minute + time.second / 60.0))
    painter.draw_convex_polygon(minute_hand)
    painter.restore

    painter.set_pen minute_color
    (0...60).each do |j|
      painter.draw_line(92, 0, 96, 0) if (j % 5) != 0
      painter.rotate(6.0)
    end

    painter.end
  end
end
