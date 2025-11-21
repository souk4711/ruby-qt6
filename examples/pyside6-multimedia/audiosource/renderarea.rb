# frozen_string_literal: true

class RenderArea < RubyQt6::Bando::QWidget
  def initialize(parent = nil)
    super(parent)

    @m_level = 0
    set_background_role(QPalette::Base)
    set_auto_fill_background(true)
    set_minimum_height(30)
    set_minimum_width(200)
  end

  def set_level(value)
    @m_level = value
    update
  end

  def paint_event(_event)
    painter = QPainter.new(self)
    painter.set_pen(QColor.new(Qt::GlobalColor::Black))

    frame = painter.viewport - QMargins.new(10, 10, 10, 10)
    painter.draw_rect(frame)

    return if @m_level == 0.0

    pos = ((frame.width - 1) * @m_level).round
    painter.fill_rect(frame.left + 1, frame.top + 1, pos, frame.height - 1, Qt::GlobalColor::Red)
  ensure
    painter.end
  end
end
