# frozen_string_literal: true

require_relative 'circlewidget'

class Window < RubyQt6::Bando::QWidget
  def initialize(parent = nil)
    super

    @aliased_label = create_label(tr('Aliased'))
    @antialiased_label = create_label(tr('Antialiased'))
    @int_label = create_label(tr('Int'))
    @float_label = create_label(tr('Float'))
    @circle_widgets = Array.new(2, Array.new(2))

    layout = QGridLayout.new
    layout.add_widget(@aliased_label, 0, 1)
    layout.add_widget(@antialiased_label, 0, 2)
    layout.add_widget(@int_label, 1, 0)
    layout.add_widget(@float_label, 2, 0)

    timer = QTimer.new(self)

    (0...2).each do |i|
      (0...2).each do |j|
        @circle_widgets[i][j] = CircleWidget.new
        @circle_widgets[i][j].set_float_based i != 0
        @circle_widgets[i][j].set_antialiased j != 0
        timer.timeout.connect(@circle_widgets[i][j], :next_animation_frame)
        layout.add_widget(@circle_widgets[i][j], i + 1, j + 1)
      end
    end
    timer.start(100)

    set_layout(layout)
    set_window_title(tr('Concentric Circles'))
  end

  def create_label(text)
    label = QLabel.new(text)
    label.set_alignment Qt::AlignCenter
    label.set_margin 2
    label.set_frame_style QFrame::Box.to_i | QFrame::Sunken.to_i
    label
  end
end
