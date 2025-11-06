# frozen_string_literal: true

require_relative 'shapeitem'

class SortingBox < RubyQt6::Bando::QWidget
  q_object do
    slot 'create_new_circle()'
    slot 'create_new_square()'
    slot 'create_new_triangle()'
  end

  RAND_MAX = 2_147_483_647

  def initialize(parent = nil)
    super(parent)

    set_attribute(Qt::WA_StaticContents)
    set_mouse_tracking(true)
    set_background_role(QPalette::Base)

    @item_in_motion = nil
    @shape_items = []
    @circle_path = QPainterPath.new
    @square_path = QPainterPath.new
    @triangle_path = QPainterPath.new

    @new_circle_button = create_tool_button(tr('New Circle'), QIcon.new('images/circle.png'), :create_new_circle)
    @new_square_button = create_tool_button(tr('New Square'), QIcon.new('images/square.png'), :create_new_square)
    @new_triangle_button = create_tool_button(tr('New Triangle'), QIcon.new('images/triangle.png'),
                                              :create_new_triangle)

    @circle_path.add_ellipse(QRectF.new(0.0, 0.0, 100.0, 100.0))
    @square_path.add_rect(QRectF.new(0.0, 0.0, 100.0, 100.0))

    x = @triangle_path.current_position.x
    y = @triangle_path.current_position.y
    @triangle_path.move_to(x + 120 / 2, y)
    @triangle_path.line_to(0, 100)
    @triangle_path.line_to(120, 100)
    @triangle_path.line_to(x + 120 / 2, y)

    set_window_title(tr('Tooltips'))
    resize(500, 300)

    create_shape_item(@circle_path, tr('Circle'), initial_item_position(@circle_path), initial_item_color)
    create_shape_item(@square_path, tr('Square'), initial_item_position(@square_path), initial_item_color)
    create_shape_item(@triangle_path, tr('Triangle'), initial_item_position(@triangle_path), initial_item_color)
  end

  def event(event)
    if event.type == QEvent::ToolTip
      index = item_at(event.pos)
      if index != -1
        QToolTip.show_text(event.global_pos, @shape_items[index].tool_tip)
      else
        QToolTip.show_text(event.global_pos, '')
      end
    end
    _event(event)
  end

  def resize_event(_event)
    margin = style.pixel_metric(QStyle::PM_ButtonMargin)
    x = width - margin
    y = height - margin

    y = update_button_geometry(@new_circle_button, x, y)
    y = update_button_geometry(@new_square_button, x, y)
    update_button_geometry(@new_triangle_button, x, y)
  end

  def paint_event(_event)
    painter = QPainter.new(self)
    @shape_items.each do |shape_item|
      painter.translate(shape_item.position)
      painter.set_brush QBrush.new(shape_item.color)
      painter.draw_path(shape_item.path)
      painter.translate(- shape_item.position)
    end
    painter.end
  end

  def mouse_press_event(event)
    return unless event.button == Qt::LeftButton

    index = item_at(event.position.to_point)
    return unless index != -1

    @item_in_motion = @shape_items[index]
    @previous_position = event.position.to_point
    @shape_items.push @shape_items.delete_at(index)
    update
  end

  def mouse_move_event(event)
    return if (event.buttons & Qt::LeftButton).to_i.zero?
    return if @item_in_motion.nil?

    move_item_to(event.position.to_point)
  end

  def mouse_release_event(event)
    return if event.button != Qt::LeftButton
    return if @item_in_motion.nil?

    move_item_to(event.position.to_point)
    @item_in_motion = nil
  end

  def create_new_circle
    create_shape_item(@circle_path, tr('Circle'), random_item_position, random_item_color)
  end

  def create_new_square
    create_shape_item(@square_path, tr('Square'), random_item_position, random_item_color)
  end

  def create_new_triangle
    create_shape_item(@triangle_path, tr('Triangle'), random_item_position, random_item_color)
  end

  def item_at(pos)
    (@shape_items.length - 1).downto(0) do |i|
      item = @shape_items[i]
      return i if item.path.contains((pos - item.position).to_point_f)
    end
    -1
  end

  def move_item_to(pos)
    offset = pos - @previous_position
    @item_in_motion.position = @item_in_motion.position + offset
    @previous_position = pos
    update
  end

  def update_button_geometry(button, x, y)
    size = button.size_hint
    button.set_geometry(x - size.rwidth, y - size.rheight, size.rwidth, size.rheight)
    y - size.rheight - style.pixel_metric(QStyle::PM_LayoutVerticalSpacing)
  end

  def create_shape_item(path, tool_tip, pos, color)
    shape_item = ShapeItem.new
    shape_item.path = path
    shape_item.tool_tip = tool_tip
    shape_item.position = pos
    shape_item.color = color
    @shape_items.push(shape_item)
    update
  end

  def create_tool_button(tool_tip, icon, member)
    button = QToolButton.new(self)
    button.set_tool_tip(tool_tip)
    button.set_icon(icon)
    button.set_icon_size(QSize.new(32, 32))
    button.clicked.connect(self, member)
    button
  end

  def initial_item_position(path)
    y = (height - path.control_point_rect.height) / 2
    x =
      if @shape_items.empty?
        ((3 * width) / 2 - path.control_point_rect.width) / 2
      else
        (width / @shape_items.size - path.control_point_rect.width) / 2
      end
    QPoint.new(x, y)
  end

  def random_item_position
    QPoint.new(rand(RAND_MAX) % (width - 120), rand(RAND_MAX) % (height - 120))
  end

  def initial_item_color
    QColor.from_hsv(((@shape_items.size + 1) * 85) % 256, 255, 190)
  end

  def random_item_color
    QColor.from_hsv(rand(RAND_MAX) % 256, 255, 190)
  end
end
