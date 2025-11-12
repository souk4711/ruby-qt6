# frozen_string_literal: true

require_relative 'renderarea'

class Window < RubyQt6::Bando::QWidget
  q_object do
    slot 'operation_changed()'
    slot 'shape_selected(int)'
  end

  NumTransformedAreas = 3

  def initialize(parent = nil)
    super

    @original_render_area = RenderArea.new

    @shape_combobox = QComboBox.new
    @shape_combobox.add_item(tr('Clock'))
    @shape_combobox.add_item(tr('House'))
    @shape_combobox.add_item(tr('Text'))
    @shape_combobox.add_item(tr('Truck'))

    layout = QGridLayout.new
    layout.add_widget(@original_render_area, 0, 0)
    layout.add_widget(@shape_combobox, 1, 0)

    @transformed_render_areas = []
    @operation_comboboxes = []
    (0...NumTransformedAreas).each do |i|
      @transformed_render_areas[i] = RenderArea.new

      @operation_comboboxes[i] = QComboBox.new
      @operation_comboboxes[i].add_item(tr('No transformation'))
      @operation_comboboxes[i].add_item(tr('Rotate by 60'))
      @operation_comboboxes[i].add_item(tr('Scale to 75%'))
      @operation_comboboxes[i].add_item(tr('Translate by (50, 50)'))
      @operation_comboboxes[i].activated.connect(self, :operation_changed)

      layout.add_widget(@transformed_render_areas[i], 0, i + 1)
      layout.add_widget(@operation_comboboxes[i], 1, i + 1)
    end

    set_layout(layout)
    setup_shapes
    shape_selected(0)

    set_window_title(tr('Transformations'))
  end

  def setup_shapes
    truck = QPainterPath.new
    truck.set_fill_rule Qt::WindingFill
    truck.move_to(0.0, 87.0)
    truck.line_to(0.0, 60.0)
    truck.line_to(10.0, 60.0)
    truck.line_to(35.0, 35.0)
    truck.line_to(100.0, 35.0)
    truck.line_to(100.0, 87.0)
    truck.line_to(0.0, 87.0)
    truck.move_to(17.0, 60.0)
    truck.line_to(55.0, 60.0)
    truck.line_to(55.0, 40.0)
    truck.line_to(37.0, 40.0)
    truck.line_to(17.0, 60.0)
    truck.add_ellipse(17.0, 75.0, 25.0, 25.0)
    truck.add_ellipse(63.0, 75.0, 25.0, 25.0)

    clock = QPainterPath.new
    clock.add_ellipse(-50.0, -50.0, 100.0, 100.0)
    clock.add_ellipse(-48.0, -48.0, 96.0, 96.0)
    clock.move_to(0.0, 0.0)
    clock.line_to(-2.0, -2.0)
    clock.line_to(0.0, -42.0)
    clock.line_to(2.0, -2.0)
    clock.line_to(0.0, 0.0)
    clock.move_to(0.0, 0.0)
    clock.line_to(2.732, -0.732)
    clock.line_to(24.495, 14.142)
    clock.line_to(0.732, 2.732)
    clock.line_to(0.0, 0.0)

    house = QPainterPath.new
    house.move_to(-45.0, -20.0)
    house.line_to(0.0, -45.0)
    house.line_to(45.0, -20.0)
    house.line_to(45.0, 45.0)
    house.line_to(-45.0, 45.0)
    house.line_to(-45.0, -20.0)
    house.add_rect(15.0, 5.0, 20.0, 35.0)
    house.add_rect(-35.0, -15.0, 25.0, 25.0)

    text = QPainterPath.new
    font = QFont.new
    font.set_pixel_size 50
    font_bounding_rect = QFontMetrics.new(font).bounding_rect(tr('Qt'))
    text.add_text(-QPointF.new(font_bounding_rect.center), font, tr('Qt'))

    @shapes = []
    @shapes.push(clock)
    @shapes.push(house)
    @shapes.push(text)
    @shapes.push(truck)
    @shape_combobox.activated.connect(self, :shape_selected)
  end

  def operation_changed
    operation_table = [RenderArea::NoTransformation, RenderArea::Rotate, RenderArea::Scale, RenderArea::Translate]
    operations = []
    (0...NumTransformedAreas).each do |i|
      index = @operation_comboboxes[i].current_index
      operations.push(operation_table[index])
      @transformed_render_areas[i].operations = operations
    end
  end

  def shape_selected(index)
    shape = @shapes[index]
    @original_render_area.shape = shape
    (0...NumTransformedAreas).each do |i|
      @transformed_render_areas[i].shape = shape
    end
  end
end
