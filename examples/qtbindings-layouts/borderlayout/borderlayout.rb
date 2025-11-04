# frozen_string_literal: true

class BorderLayout < RubyQt6::Bando::QLayout
  WEST   = 0
  NORTH  = 1
  SOUTH  = 2
  EAST   = 3
  CENTER = 4

  MINIMUM_SIZE = 0
  SIZE_HINT = 1

  ItemWrapper = Struct.new :item, :position

  def initialize(parent = nil, margin = 0, spacing = -1)
    super(parent)

    @list = []
    set_contents_margins(QMargins.new(margin, margin, margin, margin))
    set_spacing(spacing)
  end

  def add_item(item)
    add(item, WEST)
  end

  def add_widget(widget, position)
    add(QWidgetItem.new(widget), position)
    _take_ownership_from_ruby(widget)
  end

  def expanding_directions
    Qt::Horizontal | Qt::Vertical
  end

  def has_height_for_width
    false
  end

  def count
    @list.length
  end

  def item_at(index)
    wrapper = @list[index]
    return wrapper.item unless wrapper.nil?

    nil
  end

  def minimum_size
    calculate_size(MINIMUM_SIZE)
  end

  def set_geometry(rect)
    super

    center = 0
    east_width = 0
    west_width = 0
    north_height = 0
    south_height = 0

    (0...@list.length).each do |i|
      wrapper = @list[i]
      item = wrapper.item
      position = wrapper.position

      case position
      when NORTH
        item.set_geometry QRect.new(rect.x, north_height, rect.width, item.size_hint.height)
        north_height += item.geometry.height + spacing
      when SOUTH
        item.set_geometry QRect.new(item.geometry.x, item.geometry.y, rect.width, item.size_hint.height)
        south_height += item.geometry.height + spacing
        item.set_geometry QRect.new(rect.x, rect.y + rect.height - south_height + spacing, item.geometry.width,
                                    item.geometry.height)
      when CENTER
        center = wrapper
      end
    end

    center_height = rect.height - north_height - south_height

    (0...@list.length).each do |i|
      wrapper = @list[i]
      item = wrapper.item
      position = wrapper.position

      if position == WEST
        item.set_geometry QRect.new(rect.x + west_width, north_height, item.size_hint.width, center_height)
        west_width += item.geometry.width + spacing
      elsif position == EAST
        item.set_geometry QRect.new(item.geometry.x, item.geometry.y, item.size_hint.width, center_height)
        east_width += item.geometry.width + spacing
        item.set_geometry QRect.new(rect.x + rect.width - east_width + spacing, north_height, item.geometry.width,
                                    item.geometry.height)
      end
    end

    return if center.nil?

    center.item.set_geometry QRect.new(west_width, north_height, rect.width - east_width - west_width, center_height)
  end

  def size_hint
    calculate_size(SIZE_HINT)
  end

  def take_at(index)
    if index >= 0 && index < @list.length
      layout_struct = @list.delete_at(index)
      return layout_struct.item
    end
    nil
  end

  def add(item, position)
    @list << ItemWrapper.new(item, position)
  end

  def calculate_size(size_type)
    total_size = QSize.new

    (0...@list.length).each do |i|
      wrapper = @list[i]
      position = wrapper.position

      item_size = size_type == MINIMUM_SIZE ? wrapper.item.minimum_size : wrapper.item.size_hint
      total_size.set_height(total_size.height + item_size.height) if [NORTH, SOUTH, CENTER].include?(position)
      total_size.set_width(total_size.width + item_size.width) if [WEST, EAST, CENTER].include?(position)
    end
    total_size
  end
end
