# frozen_string_literal: true

class CircleWidget < RubyQt6::Bando::QWidget
  q_object do
    slot 'next_animation_frame()'
  end

  def initialize(parent = nil)
    super(parent)

    @float_based = false
    @antialiased = false
    @frame_no = 0

    set_background_role(QPalette::Base)
    set_size_policy(QSizePolicy::Expanding, QSizePolicy::Expanding)
  end

  def set_float_based(float_based)
    @float_based = float_based
    update
  end

  def set_antialiased(antialiased)
    @antialiased = antialiased
    update
  end

  def minimum_size_hint
    QSize.new(50, 50)
  end

  def size_hint
    QSize.new(180, 180)
  end

  def next_animation_frame
    @frame_no += 1
    update
  end

  def paint_event(_event)
    painter = QPainter.new(self)
    painter.set_render_hint(QPainter::Antialiasing, @antialiased)
    painter.translate(width / 2, height / 2)

    diameter = 0
    while diameter < 256
      delta = ((@frame_no % 128) - diameter / 2).abs
      alpha = 255 - (delta * delta) / 4 - diameter
      if alpha.positive?
        painter.set_pen QPen.new(QBrush.new(QColor.new(0, diameter / 2, 127, alpha)), 3)

        if @float_based
          painter.draw_ellipse(QRectF.new(-diameter / 2.0, -diameter / 2.0, diameter, diameter))
        else
          painter.draw_ellipse(QRect.new(-diameter / 2, -diameter / 2, diameter, diameter))
        end
      end
      diameter += 9
    end
    painter.end
  end
end
