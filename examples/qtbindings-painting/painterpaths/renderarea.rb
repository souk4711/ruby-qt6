# frozen_string_literal: true

class RenderArea < RubyQt6::Bando::QWidget
  q_object do
    slot 'set_fill_rule(Qt::FillRule)'
    slot 'set_fill_gradient(QColor,QColor)'
    slot 'set_pen_width(int)'
    slot 'set_pen_color(QColor)'
    slot 'set_rotation_angle(int)'
  end

  def initialize(path, parent = nil)
    super(parent)

    @pen_width = 1
    @rotation_angle = 0
    @path = path
    @fill_color_1 = QColor.new
    @fill_color_2 = QColor.new
    @pen_width = 0
    @pen_color = QColor.new
    set_background_role(QPalette::Base)
  end

  def minimum_size_hint
    QSize.new(50, 50)
  end

  def size_hint
    QSize.new(100, 100)
  end

  def set_fill_rule(rule)
    @path.set_fill_rule rule
    update
  end

  def set_fill_gradient(color1, color2)
    @fill_color_1 = color1
    @fill_color_2 = color2
    update
  end

  def set_pen_width(width)
    @pen_width = width
    update
  end

  def set_pen_color(color)
    @pen_color = color
    update
  end

  def set_rotation_angle(degrees)
    @rotation_angle = degrees
    update
  end

  def paint_event(_event)
    painter = QPainter.new(self)
    painter.set_render_hint QPainter::Antialiasing
    painter.scale(width / 100.0, height / 100.0)
    painter.translate(50.0, 50.0)
    painter.rotate(-@rotation_angle)
    painter.translate(-50.0, -50.0)

    painter.set_pen QPen.new(QBrush.new(@pen_color), @pen_width, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin)
    gradient = QLinearGradient.new(0, 0, 0, 100)
    gradient.set_color_at(0.0, @fill_color_1)
    gradient.set_color_at(1.0, @fill_color_2)
    painter.set_brush QBrush.new(gradient)
    painter.draw_path(@path)
    painter.end
  end
end
