# frozen_string_literal: true

require_relative 'borderlayout'

class Window < RubyQt6::Bando::QWidget
  def initialize(parent = nil)
    super

    central_widget = QTextBrowser.new
    central_widget.set_plain_text tr('Central widget')

    layout = BorderLayout.new
    layout.add_widget(central_widget, BorderLayout::CENTER)
    layout.add_widget(create_label('North'), BorderLayout::NORTH)
    layout.add_widget(create_label('West'), BorderLayout::WEST)
    layout.add_widget(create_label('East 1'), BorderLayout::EAST)
    layout.add_widget(create_label('East 2'), BorderLayout::EAST)
    layout.add_widget(create_label('South'), BorderLayout::SOUTH)
    set_layout(layout)

    set_window_title(tr('Border Layout'))
  end

  def create_label(text)
    label = QLabel.new(text)
    label.set_frame_style QFrame::Box.to_i | QFrame::Raised.to_i
    label
  end
end
