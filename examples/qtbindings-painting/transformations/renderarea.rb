# frozen_string_literal: true

class RenderArea < RubyQt6::Bando::QWidget
  NoTransformation = 0
  Translate = 1
  Rotate = 2
  Scale = 3

  def initialize(parent = nil)
    super(parent)

    new_font = font
    new_font.set_pixel_size 12
    set_font(new_font)

    font_metrics = QFontMetrics.new(new_font)
    @x_bounding_rect = font_metrics.bounding_rect(tr('x'))
    @y_bounding_rect = font_metrics.bounding_rect(tr('y'))
    @operations = []
    @shape = QPainterPath.new
  end

  def operations=(operations)
    @operations = Array.new(operations)
    update
  end

  def shape=(shape)
    @shape = shape
    update
  end

  def minimum_size_hint
    QSize.new(50, 50)
  end

  def size_hint
    QSize.new(232, 232)
  end

  def paint_event(event)
    painter = QPainter.new(self)
    painter.set_render_hint QPainter::Antialiasing
    painter.fill_rect(event.rect, QBrush.new(Qt::White))

    painter.translate(66, 66)

    painter.save
    transform_painter(painter)
    draw_shape(painter)
    painter.restore

    draw_outline(painter)

    painter.save
    transform_painter(painter)
    draw_coordinates(painter)
    painter.restore
    painter.end
  end

  def draw_coordinates(painter)
    painter.set_pen QPen.new(QColor.new(Qt::Red))

    painter.draw_line(0, 0, 50, 0)
    painter.draw_line(48, -2, 50, 0)
    painter.draw_line(48, 2, 50, 0)
    painter.draw_text(60 - @x_bounding_rect.width / 2, 0 + @x_bounding_rect.height / 2, tr('x'))

    painter.draw_line(0, 0, 0, 50)
    painter.draw_line(-2, 48, 0, 50)
    painter.draw_line(2, 48, 0, 50)
    painter.draw_text(0 - @y_bounding_rect.width / 2, 60 + @y_bounding_rect.height / 2, tr('y'))
  end

  def draw_outline(painter)
    painter.set_pen QPen.new(QColor.new(Qt::DarkGreen))
    painter.set_pen QPen.new(Qt::DashLine)
    painter.set_brush Qt::NoBrush
    painter.draw_rect(0, 0, 100, 100)
  end

  def draw_shape(painter)
    painter.fill_path(@shape, QBrush.new(Qt::Blue))
  end

  def transform_painter(painter)
    (0...@operations.length).each do |i|
      case @operations[i]
      when Translate
        painter.translate(50, 50)
      when Scale
        painter.scale(0.75, 0.75)
      when Rotate
        painter.rotate(60)
      when NoTransformation
      end
    end
  end
end
