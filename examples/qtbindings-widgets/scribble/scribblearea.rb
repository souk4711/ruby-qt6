# frozen_string_literal: true

class ScribbleArea < RubyQt6::Bando::QWidget
  q_object do
    slot 'clear_image()'
  end

  def initialize(parent = nil)
    super(parent)

    set_attribute(Qt::WA_StaticContents)

    @modified = false
    @scribbling = false
    @my_pen_width = 1
    @my_pen_color = QColor.new(Qt::Blue)
    @image = QImage.new
    @last_point = QPoint.new(0, 0)
  end

  def open_image(file_name)
    loaded_image = QImage.new
    return false unless loaded_image.load(file_name)

    new_size = loaded_image.size.expanded_to(size)
    resize_image(loaded_image, new_size)
    @image = loaded_image
    @modified = false
    update
    true
  end

  def save_image(file_name, file_format)
    visible_image = @image
    resize_image(visible_image, size)
    return false unless visible_image.save(file_name, file_format.to_s)

    @modified = false
    true
  end

  def modified?
    @modified
  end

  def pen_color
    @my_pen_color
  end

  def pen_color=(new_color)
    @my_pen_color = new_color
  end

  def pen_width
    @my_pen_width
  end

  def pen_width=(new_width)
    @my_pen_width = new_width
  end

  def clear_image
    @image.fill(QColor.new(255, 255, 255))
    @modified = true
    update
  end

  def mouse_press_event(event)
    return unless event.button == Qt::LeftButton

    @last_point = event.position.to_point
    @scribbling = true
  end

  def mouse_move_event(event)
    return unless (event.buttons & Qt::LeftButton).to_i.nonzero? && @scribbling

    draw_line_to(event.position.to_point)
  end

  def mouse_release_event(event)
    return unless event.button == Qt::LeftButton && @scribbling

    draw_line_to(event.position.to_point)
    @scribbling = false
  end

  def paint_event(_event)
    painter = QPainter.new(self)
    painter.draw_image(QPoint.new(0, 0), @image)
    painter.end
  end

  def resize_event(event)
    if width > @image.width || height > @image.height
      new_width = [width + 128, @image.width].max
      new_height = [height + 128, @image.height].max
      resize_image(@image, QSize.new(new_width, new_height))
      update
    end
    _resize_event(event)
  end

  def draw_line_to(end_point)
    painter = QPainter.new(@image)
    painter.set_pen QPen.new(QBrush.new(@my_pen_color), @my_pen_width, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin)
    painter.draw_line(@last_point, end_point)
    @modified = true

    rad = @my_pen_width / 2
    update(QRect.new(@last_point, end_point).normalized.adjusted(-rad, -rad, +rad, +rad))
    @last_point = end_point
    painter.end
  end

  def resize_image(image, new_size)
    return if image.size == new_size

    new_image = QImage.new(new_size, QImage::Format_RGB32)
    new_image.fill(QColor.new(255, 255, 255))
    painter = QPainter.new(new_image)
    painter.draw_image(QPoint.new(0, 0), image)
    @image = new_image
    painter.end
  end
end
