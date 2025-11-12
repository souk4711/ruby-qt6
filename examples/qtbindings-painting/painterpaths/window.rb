# frozen_string_literal: true

require_relative 'renderarea'

class Window < RubyQt6::Bando::QWidget
  q_object do
    slot 'fille_rule_changed()'
    slot 'fill_gradient_changed()'
    slot 'pen_color_changed()'
  end

  NumRenderAreas = 9

  def initialize(parent = nil)
    super

    @render_areas = Array(NumRenderAreas)

    rect_path = QPainterPath.new.tap do |r|
      r.move_to(20.0, 30.0)
      r.line_to(80.0, 30.0)
      r.line_to(80.0, 70.0)
      r.line_to(20.0, 70.0)
      r.close_subpath
    end

    round_rect_path = QPainterPath.new.tap do |r|
      r.move_to(80.0, 35.0)
      r.arc_to(70.0, 30.0, 10.0, 10.0, 0.0, 90.0)
      r.line_to(25.0, 30.0)
      r.arc_to(20.0, 30.0, 10.0, 10.0, 90.0, 90.0)
      r.line_to(20.0, 65.0)
      r.arc_to(20.0, 60.0, 10.0, 10.0, 180.0, 90.0)
      r.line_to(75.0, 70.0)
      r.arc_to(70.0, 60.0, 10.0, 10.0, 270.0, 90.0)
      r.close_subpath
    end

    ellipse_path = QPainterPath.new.tap do |e|
      e.move_to(80.0, 50.0)
      e.arc_to(20.0, 30.0, 60.0, 40.0, 0.0, 360.0)
    end

    pie_path = QPainterPath.new.tap do |p|
      p.move_to(50.0, 50.0)
      p.line_to(65.0, 32.6795)
      p.arc_to(20.0, 30.0, 60.0, 40.0, 60.0, 240.0)
      p.close_subpath
    end

    polygon_path = QPainterPath.new.tap do |p|
      p.move_to(10.0, 80.0)
      p.line_to(20.0, 10.0)
      p.line_to(80.0, 30.0)
      p.line_to(90.0, 70.0)
      p.close_subpath
    end

    group_path = QPainterPath.new.tap do |g|
      g.move_to(60.0, 40.0)
      g.arc_to(20.0, 20.0, 40.0, 40.0, 0.0, 360.0)
      g.move_to(40.0, 40.0)
      g.line_to(40.0, 80.0)
      g.line_to(80.0, 80.0)
      g.line_to(80.0, 40.0)
      g.close_subpath
    end

    text_path = QPainterPath.new.tap do |t|
      font = QFont.new('Times', 50)
      font.set_style_strategy QFont::ForceOutline
      t.add_text(10, 70, font, tr('Qt'))
    end

    bezier_path = QPainterPath.new.tap do |b|
      b.move_to(20, 30)
      b.cubic_to(80, 0, 50, 50, 80, 80)
    end

    star_path = QPainterPath.new.tap do |s|
      s.move_to(90, 50)
      (1...5).each do |i|
        s.line_to(50 + 40 * Math.cos(0.8 * i * Math::PI), 50 + 40 * Math.sin(0.8 * i * Math::PI))
      end
      s.close_subpath
    end

    @render_areas[0] = RenderArea.new(rect_path)
    @render_areas[1] = RenderArea.new(round_rect_path)
    @render_areas[2] = RenderArea.new(ellipse_path)
    @render_areas[3] = RenderArea.new(pie_path)
    @render_areas[4] = RenderArea.new(polygon_path)
    @render_areas[5] = RenderArea.new(group_path)
    @render_areas[6] = RenderArea.new(text_path)
    @render_areas[7] = RenderArea.new(bezier_path)
    @render_areas[8] = RenderArea.new(star_path)

    @fill_rule_combobox = QComboBox.new.tap do |f|
      f.add_item(tr('Odd Even'), QVariant.new(Qt::OddEvenFill))
      f.add_item(tr('Winding'), QVariant.new(Qt::WindingFill))
    end

    @fill_rule_label = QLabel.new(tr('Fill &Rule:'))
    @fill_rule_label.set_buddy @fill_rule_combobox

    @fill_color1_combobox = QComboBox.new
    populate_with_colors(@fill_color1_combobox)
    @fill_color1_combobox.set_current_index(@fill_color1_combobox.find_text('mediumslateblue'))

    @fill_color2_combobox = QComboBox.new
    populate_with_colors(@fill_color2_combobox)
    @fill_color2_combobox.set_current_index(@fill_color2_combobox.find_text('cornsilk'))

    @fill_gradient_label = QLabel.new(tr('&Fill Gradient:'))
    @fill_gradient_label.set_buddy @fill_color1_combobox

    @fill_to_label = QLabel.new(tr('to'))
    @fill_to_label.set_size_policy(QSizePolicy::Fixed, QSizePolicy::Fixed)

    @pen_width_spinbox = QSpinBox.new
    @pen_width_spinbox.set_range 0, 20

    @pen_width_label = QLabel.new(tr('&Pen Width:'))
    @pen_width_label.set_buddy @pen_width_spinbox

    @pen_color_combobox = QComboBox.new
    populate_with_colors(@pen_color_combobox)
    @pen_color_combobox.set_current_index(@pen_color_combobox.find_text('darkslateblue'))

    @pen_color_label = QLabel.new(tr('Pen &Color:'))
    @pen_color_label.set_buddy @pen_color_combobox

    @rotation_angle_spinbox = QSpinBox.new.tap do |r|
      r.set_range 0, 359
      r.set_wrapping true
      r.set_suffix '°'
    end

    @rotation_angle_label = QLabel.new(tr('&Rotation Angle:'))
    @rotation_angle_label.set_buddy @rotation_angle_spinbox

    @fill_rule_combobox.activated.connect(self, :fille_rule_changed)
    @fill_color1_combobox.activated.connect(self, :fill_gradient_changed)
    @fill_color2_combobox.activated.connect(self, :fill_gradient_changed)
    @pen_color_combobox.activated.connect(self, :pen_color_changed)

    (0...NumRenderAreas).each do |i|
      @pen_width_spinbox.value_changed.connect(@render_areas[i], :set_pen_width)
      @rotation_angle_spinbox.value_changed.connect(@render_areas[i], :set_rotation_angle)
    end

    top_layout = QGridLayout.new
    (0...NumRenderAreas).each do |i|
      top_layout.add_widget(@render_areas[i], i / 3, i % 3)
    end

    layout = QGridLayout.new.tap do |m|
      m.add_layout(top_layout, 0, 0, 1, 4)
      m.add_widget(@fill_rule_label, 1, 0)
      m.add_widget(@fill_rule_combobox, 1, 1, 1, 3)
      m.add_widget(@fill_gradient_label, 2, 0)
      m.add_widget(@fill_color1_combobox, 2, 1)
      m.add_widget(@fill_to_label, 2, 2)
      m.add_widget(@fill_color2_combobox, 2, 3)
      m.add_widget(@pen_width_label, 3, 0)
      m.add_widget(@pen_width_spinbox, 3, 1, 1, 3)
      m.add_widget(@pen_color_label, 4, 0)
      m.add_widget(@pen_color_combobox, 4, 1, 1, 3)
      m.add_widget(@rotation_angle_label, 5, 0)
      m.add_widget(@rotation_angle_spinbox, 5, 1, 1, 3)
    end
    set_layout(layout)

    fille_rule_changed
    fill_gradient_changed
    pen_color_changed
    @pen_width_spinbox.set_value 2

    set_window_title(tr('Painter Paths'))
  end

  def fille_rule_changed
    rule = current_item_data(@fill_rule_combobox).value
    (0...NumRenderAreas).each do |i|
      @render_areas[i].set_fill_rule rule
    end
  end

  def fill_gradient_changed
    color1 = current_item_data(@fill_color1_combobox).value
    color2 = current_item_data(@fill_color2_combobox).value

    (0...NumRenderAreas).each do |i|
      @render_areas[i].set_fill_gradient(color1, color2)
    end
  end

  def pen_color_changed
    color = current_item_data(@pen_color_combobox).value
    (0...NumRenderAreas).each do |i|
      @render_areas[i].set_pen_color color
    end
  end

  def populate_with_colors(combobox)
    names = QColor.color_names
    names.each do |name|
      combobox.add_item(name, QVariant.new(QColor.new(name)))
    end
  end

  def current_item_data(combobox)
    combobox.item_data(combobox.current_index)
  end
end
