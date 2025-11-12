# frozen_string_literal: true

require_relative 'renderarea'

class Window < RubyQt6::Bando::QWidget
  q_object do
    slot 'shape_changed()'
    slot 'pen_changed()'
    slot 'brush_changed()'
  end

  def initialize(parent = nil)
    super

    @id_role = Qt::UserRole
    @render_area = RenderArea.new

    @shape_combobox = QComboBox.new.tap do |s|
      s.add_item(tr('Rectangle'), QVariant.new(RenderArea::Rect))
      s.add_item(tr('Round Rectangle'), QVariant.new(RenderArea::RoundRect))
      s.add_item(tr('Ellipse'), QVariant.new(RenderArea::Ellipse))
      s.add_item(tr('Pie'), QVariant.new(RenderArea::Pie))
      s.add_item(tr('Chord'), QVariant.new(RenderArea::Chord))
      s.add_item(tr('Polygon'), QVariant.new(RenderArea::Polygon))
      s.add_item(tr('Path'), QVariant.new(RenderArea::Path))
      s.add_item(tr('Line'), QVariant.new(RenderArea::Line))
      s.add_item(tr('Polyline'), QVariant.new(RenderArea::Polyline))
      s.add_item(tr('Arc'), QVariant.new(RenderArea::Arc))
      s.add_item(tr('Points'), QVariant.new(RenderArea::Points))
      s.add_item(tr('Text'), QVariant.new(RenderArea::Text))
      s.add_item(tr('Pixmap'), QVariant.new(RenderArea::Pixmap))
    end

    @shape_label = QLabel.new(tr('&Shape:'))
    @shape_label.set_buddy @shape_combobox

    @pen_width_spinbox = QSpinBox.new
    @pen_width_spinbox.set_range(0, 20)

    @pen_width_label = QLabel.new(tr('Pen &Width:'))
    @pen_width_label.set_buddy @pen_width_spinbox

    @pen_style_combobox = QComboBox.new.tap do |p|
      p.add_item(tr('Solid'), QVariant.new(Qt::SolidLine))
      p.add_item(tr('Dash'), QVariant.new(Qt::DashLine))
      p.add_item(tr('Dot'), QVariant.new(Qt::DotLine))
      p.add_item(tr('Dash Dot'), QVariant.new(Qt::DashDotLine))
      p.add_item(tr('Dash Dot Dot'), QVariant.new(Qt::DashDotDotLine))
      p.add_item(tr('None'), QVariant.new(Qt::NoPen))
    end

    @pen_style_label = QLabel.new(tr('&Pen Style:'))
    @pen_style_label.set_buddy @pen_style_combobox

    @pen_cap_combobox = QComboBox.new.tap do |p|
      p.add_item(tr('Flat'), QVariant.new(Qt::FlatCap))
      p.add_item(tr('Square'), QVariant.new(Qt::SquareCap))
      p.add_item(tr('Round'), QVariant.new(Qt::RoundCap))
    end

    @pen_cap_label = QLabel.new(tr('Pen &Cap:'))
    @pen_cap_label.set_buddy @pen_cap_combobox

    @pen_join_combobox = QComboBox.new.tap do |p|
      p.add_item(tr('Miter'), QVariant.new(Qt::MiterJoin))
      p.add_item(tr('Bevel'), QVariant.new(Qt::BevelJoin))
      p.add_item(tr('Round'), QVariant.new(Qt::RoundJoin))
    end

    @pen_join_label = QLabel.new(tr('Pen &Join:'))
    @pen_join_label.set_buddy @pen_join_combobox

    @brush_style_combobox = QComboBox.new.tap do |b|
      b.add_item(tr('Linear Gradient'), QVariant.new(Qt::LinearGradientPattern))
      b.add_item(tr('Radial Gradient'), QVariant.new(Qt::RadialGradientPattern))
      b.add_item(tr('Conical Gradient'), QVariant.new(Qt::ConicalGradientPattern))
      b.add_item(tr('Texture'), QVariant.new(Qt::TexturePattern))
      b.add_item(tr('Solid'), QVariant.new(Qt::SolidPattern))
      b.add_item(tr('Horizontal'), QVariant.new(Qt::HorPattern))
      b.add_item(tr('Vertical'), QVariant.new(Qt::VerPattern))
      b.add_item(tr('Cross'), QVariant.new(Qt::CrossPattern))
      b.add_item(tr('Backward Diagonal'), QVariant.new(Qt::BDiagPattern))
      b.add_item(tr('Forward Diagonal'), QVariant.new(Qt::FDiagPattern))
      b.add_item(tr('Diagonal Cross'), QVariant.new(Qt::DiagCrossPattern))
      b.add_item(tr('Dense 1'), QVariant.new(Qt::Dense1Pattern))
      b.add_item(tr('Dense 2'), QVariant.new(Qt::Dense2Pattern))
      b.add_item(tr('Dense 3'), QVariant.new(Qt::Dense3Pattern))
      b.add_item(tr('Dense 4'), QVariant.new(Qt::Dense4Pattern))
      b.add_item(tr('Dense 5'), QVariant.new(Qt::Dense5Pattern))
      b.add_item(tr('Dense 6'), QVariant.new(Qt::Dense6Pattern))
      b.add_item(tr('Dense 7'), QVariant.new(Qt::Dense7Pattern))
      b.add_item(tr('None'), QVariant.new(Qt::NoBrush))
    end

    @brush_style_label = QLabel.new(tr('&Brush Style:'))
    @brush_style_label.set_buddy @brush_style_combobox

    @antialiasing_checkbox = QCheckBox.new(tr('&Antialiasing'))
    @transformations_checkbox = QCheckBox.new(tr('&Transformations'))

    @shape_combobox.activated.connect(self, :shape_changed)
    @pen_width_spinbox.value_changed.connect(self, :pen_changed)
    @pen_style_combobox.activated.connect(self, :pen_changed)
    @pen_cap_combobox.activated.connect(self, :pen_changed)
    @pen_join_combobox.activated.connect(self, :pen_changed)
    @brush_style_combobox.activated.connect(self, :brush_changed)
    @antialiasing_checkbox.toggled.connect(@render_area, :set_antialiased)
    @transformations_checkbox.toggled.connect(@render_area, :set_transformed)

    checkbox_layout = QHBoxLayout.new.tap do |c|
      c.add_widget(@antialiasing_checkbox)
      c.add_widget(@transformations_checkbox)
    end

    layout = QGridLayout.new.tap do |l|
      l.add_widget(@render_area, 0, 0, 1, 2)
      l.add_widget(@shape_label, 1, 0)
      l.add_widget(@shape_combobox, 1, 1)
      l.add_widget(@pen_width_label, 2, 0)
      l.add_widget(@pen_width_spinbox, 2, 1)
      l.add_widget(@pen_style_label, 3, 0)
      l.add_widget(@pen_style_combobox, 3, 1)
      l.add_widget(@pen_cap_label, 4, 0)
      l.add_widget(@pen_cap_combobox, 4, 1)
      l.add_widget(@pen_join_label, 5, 0)
      l.add_widget(@pen_join_combobox, 5, 1)
      l.add_widget(@brush_style_label, 6, 0)
      l.add_widget(@brush_style_combobox, 6, 1)
      l.add_layout(checkbox_layout, 7, 0, 1, 2)
    end
    set_layout(layout)

    shape_changed
    pen_changed
    brush_changed
    @render_area.set_antialiased false
    @render_area.set_transformed false

    set_window_title(tr('Basic Drawing'))
  end

  def shape_changed
    shape = @shape_combobox.item_data(@shape_combobox.current_index, @id_role).value
    @render_area.set_shape shape
  end

  def pen_changed
    width = @pen_width_spinbox.value
    style = @pen_style_combobox.item_data(@pen_style_combobox.current_index, @id_role).value
    cap = @pen_cap_combobox.item_data(@pen_cap_combobox.current_index, @id_role).value
    join = @pen_join_combobox.item_data(@pen_join_combobox.current_index, @id_role).value
    @render_area.set_pen QPen.new(QBrush.new(Qt::Blue), width, style, cap, join)
  end

  def brush_changed
    style = @brush_style_combobox.item_data(@brush_style_combobox.current_index, @id_role).value

    if style == Qt::LinearGradientPattern
      gradient = QLinearGradient.new(0, 0, 100, 100)
      gradient.set_color_at(0.0, QColor.new(Qt::White))
      gradient.set_color_at(0.2, QColor.new(Qt::Green))
      gradient.set_color_at(1.0, QColor.new(Qt::Black))
      @render_area.set_brush QBrush.new(gradient)
    elsif style == Qt::RadialGradientPattern
      gradient = QRadialGradient.new(50, 50, 50, 50, 50)
      gradient.set_color_at(0.0, QColor.new(Qt::White))
      gradient.set_color_at(0.2, QColor.new(Qt::Green))
      gradient.set_color_at(1.0, QColor.new(Qt::Black))
      @render_area.set_brush QBrush.new(gradient)
    elsif style == Qt::ConicalGradientPattern
      gradient = QConicalGradient.new(50, 50, 150)
      gradient.set_color_at(0.0, QColor.new(Qt::White))
      gradient.set_color_at(0.2, QColor.new(Qt::Green))
      gradient.set_color_at(1.0, QColor.new(Qt::Black))
      @render_area.set_brush QBrush.new(gradient)
    elsif style == Qt::TexturePattern
      @render_area.set_brush QBrush.new(QPixmap.new('images/brick.png'))
    else
      @render_area.set_brush QBrush.new(Qt::Green, style)
    end
  end
end
