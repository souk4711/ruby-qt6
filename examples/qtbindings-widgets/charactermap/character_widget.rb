# frozen_string_literal: true

class CharacterWidget < RubyQt6::Bando::QWidget
  q_object do
    signal 'character_selected(QString)'
    slot 'update_font(QString)'
    slot 'update_style(QString)'
  end

  def initialize(parent = nil)
    super(parent)

    @last_key = -1
    @display_font = QFont.new
    set_mouse_tracking(true)
  end

  def update_font(font_family)
    @display_font.set_family(font_family)
    @display_font.set_pixel_size(16)
    update
  end

  def update_style(font_style)
    @display_font = QFontDatabase.font(@display_font.family, font_style, 12)
    @display_font.set_pixel_size(16)
    update
  end

  def size_hint
    QSize.new(32 * 24, (65536 / 32) * 24)
  end

  def mouse_move_event(event)
    widget_position = map_from_global(event.global_position)
    key = (widget_position.y / 24) * 32 + widget_position.x / 24
    QToolTip.show_text(event.global_position.to_point, key.to_s, self)
  end

  def mouse_press_event(event)
    if event.button == Qt::LeftButton
      pos = event.position.to_point
      @last_key = (pos.y / 24) * 32 + pos.x / 24
      character_selected.emit(QChar.new(@last_key).to_s)
      update
    else
      _mouse_press_event(event)
    end
  end

  def paint_event(event)
    painter = QPainter.new(self)
    painter.fill_rect(event.rect, QBrush.new(Qt::White))
    painter.set_font(@display_font)

    redraw_rect = event.rect
    begin_row = redraw_rect.top / 24
    end_row = redraw_rect.bottom / 24
    begin_column = redraw_rect.left / 24
    end_column = redraw_rect.right / 24

    painter.set_pen QColor.new(Qt::Gray)
    (begin_row..end_row).each do |row|
      (begin_column..end_column).each do |column|
        painter.draw_rect(column * 24, row * 24, 24, 24)
      end
    end

    font_metrics = QFontMetrics.new(@display_font)
    painter.set_pen QColor.new(Qt::Black)
    (begin_row..end_row).each do |row|
      (begin_column..end_column).each do |column|
        key = row * 32 + column
        char = QChar.new(key)
        painter.set_clip_rect(column * 24, row * 24, 24, 24)
        painter.fill_rect(column * 24, row * 24, 24, 24, QBrush.new(Qt::Red)) if key == @last_key
        painter.draw_text(column * 24 + 12 - font_metrics.horizontal_advance(char) / 2, row * 24 + 4 + font_metrics.ascent, char.to_s) if key != 0
      end
    end
    painter.end
  end
end
