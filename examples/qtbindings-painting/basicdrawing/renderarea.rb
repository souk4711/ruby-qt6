# frozen_string_literal: true

class RenderArea < RubyQt6::Bando::QWidget
  Line = 0
  Points = 1
  Polyline = 3
  Polygon = 4
  Rect = 5
  RoundRect = 6
  Ellipse = 7
  Arc = 8
  Chord = 9
  Pie = 10
  Path = 11
  Text = 12
  Pixmap = 13

  q_object do
    slot 'set_shape(int)'
    slot 'set_pen(QPen)'
    slot 'set_brush(QBrush)'
    slot 'set_antialiased(bool)'
    slot 'set_transformed(bool)'
  end

  def initialize(parent = nil)
    super(parent)

    @shape = Polygon
    @antialiased = false
    @pen = QPen.new
    @brush = QBrush.new
    @pixmap = QPixmap.new
    @pixmap.load('images/qt-logo.png')

    set_background_role(QPalette::Base)
  end

  def minimum_size_hint
    QSize.new(100, 100)
  end

  def size_hint
    QSize.new(400, 200)
  end

  def set_shape(shape)
    @shape = shape
    update
  end

  def set_pen(pen)
    @pen = pen
    update
  end

  def set_brush(brush)
    @brush = brush
    update
  end

  def set_antialiased(antialiased)
    @antialiased = antialiased
    update
  end

  def set_transformed(transformed)
    @transformed = transformed
    update
  end

  def paint_event(_event)
    points = QPolygon.new << QPoint.new(10, 80) << QPoint.new(20, 10) << QPoint.new(80, 30) << QPoint.new(90, 70)
    rect = QRect.new(10, 20, 80, 60)

    path = QPainterPath.new
    path.move_to(20, 80)
    path.line_to(20, 30)
    path.cubic_to(80, 0, 50, 50, 80, 80)

    start_angle = 30 * 16
    arc_length = 120 * 16

    painter = QPainter.new(self)
    painter.set_pen @pen

    painter.set_brush @brush
    painter.set_render_hint QPainter::Antialiasing if @antialiased

    x = 0
    while x < width
      y = 0
      while y < height
        painter.save
        painter.translate(x, y)
        if @transformed
          painter.translate(50, 50)
          painter.rotate(60.0)
          painter.scale(0.6, 0.9)
          painter.translate(-50, -50)
        end

        case @shape
        when Line
          painter.draw_line(rect.bottom_left, rect.top_right)
        when Points
          painter.draw_points(points)
        when Polyline
          painter.draw_polyline(points)
        when Polygon
          painter.draw_polygon(points)
        when Rect
          painter.draw_rect(rect)
        when RoundRect
          painter.draw_rounded_rect(rect, 10, 10)
        when Ellipse
          painter.draw_ellipse(rect)
        when Arc
          painter.draw_arc(rect, start_angle, arc_length)
        when Chord
          painter.draw_chord(rect, start_angle, arc_length)
        when Pie
          painter.draw_pie(rect, start_angle, arc_length)
        when Path
          painter.draw_path(path)
        when Text
          painter.draw_text(rect, Qt::AlignCenter, tr("Qt by\nTrolltech"))
        when Pixmap
          painter.draw_pixmap(10, 10, @pixmap)
        end
        painter.restore
        y += 100
      end
      x += 100
    end
    painter.end
  end
end
