# frozen_string_literal: true

class FlowLayout < RubyQt6::Bando::QLayout
  MARGIN = 11

  def initialize(parent = nil, spacing = -1)
    super(parent)

    @items = []
    set_spacing(spacing)
  end

  def add_item(item)
    @items << item
  end

  def count
    @items.length
  end

  def item_at(index)
    @items[index]
  end

  def take_at(index)
    return @items.delete_at(index) if index >= 0 && index < @items.length

    nil
  end

  def expanding_directions
    Qt::Orientations.new
  end

  def has_height_for_width
    true
  end

  def height_for_width(width)
    do_layout(QRect.new(0, 0, width, 0), true)
  end

  def set_geometry(rect)
    super
    do_layout(rect, false)
  end

  def size_hint
    minimum_size
  end

  def minimum_size
    size = QSize.new
    @items.each { |item| size = size.expanded_to(item.minimum_size) }
    size += QSize.new(2 * MARGIN, 2 * MARGIN)
    size
  end

  def do_layout(rect, test_only)
    x = rect.x
    y = rect.y
    line_height = 0

    @items.each do |item|
      next_x = x + item.size_hint.width + spacing
      if next_x - spacing > rect.right && line_height.positive?
        x = rect.x
        y = y + line_height + spacing
        next_x = x + item.size_hint.width + spacing
        line_height = 0
      end

      item.set_geometry(QRect.new(QPoint.new(x, y), item.size_hint)) unless test_only
      x = next_x
      line_height = [line_height, item.size_hint.height].max
    end
    y + line_height - rect.y
  end
end
