# frozen_string_literal: true

require_relative 'flowlayout'

class Window < QWidget
  def initialize(parent = nil)
    super

    layout = FlowLayout.new
    layout.add_widget(QPushButton.new(tr('Short')))
    layout.add_widget(QPushButton.new(tr('Longer')))
    layout.add_widget(QPushButton.new(tr('Different text')))
    layout.add_widget(QPushButton.new(tr('More text')))
    layout.add_widget(QPushButton.new(tr('Even longer button text')))
    set_layout(layout)

    set_window_title(tr('Flow Layout'))
  end
end
