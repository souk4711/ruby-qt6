# frozen_string_literal: true

class WigglyWidget < RubyQt6::Bando::QWidget
  q_object do
    slot 'set_text(QString)'
  end

  def initialize(parent = nil)
    super(parent)

    set_background_role(QPalette::Midlight)

    new_font = font
    new_font.set_point_size new_font.point_size + 20
    set_font(new_font)

    @step = 0
    @timer = QBasicTimer.new
    @timer.start(60, self)
  end

  def set_text(text)
    @text = text
  end

  def paint_event(_event)
    sine_table = [
      0, 38, 71, 92, 100, 92, 71, 38,
      0, -38, -71, -92, -100, -92, -71, -38
    ]

    metrics = QFontMetrics.new(font)
    x = (width - metrics.horizontal_advance(@text)) / 2
    y = (height + metrics.ascent - metrics.descent) / 2
    color = QColor.new(Qt::White)

    painter = QPainter.new(self)
    (0...@text.size).each do |i|
      index = (@step + i) % 16
      color.set_hsv((15 - index) * 16, 255, 191)
      painter.set_pen color
      painter.draw_text(x, y - ((sine_table[index] * metrics.height) / 400), @text[i, 1])
      x += metrics.horizontal_advance(@text[i, 1])
    end
    painter.end
  end

  def timer_event(event)
    if event.timer_id == @timer.timer_id
      @step += 1
      update
    else
      _timer_event(event)
    end
  end
end
