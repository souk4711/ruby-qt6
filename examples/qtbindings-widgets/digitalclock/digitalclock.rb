# frozen_string_literal: true

class DigitalClock < RubyQt6::Bando::QLCDNumber
  q_object do
    slot 'show_time()'
  end

  def initialize(parent = nil)
    super(5, parent)

    set_segment_style(Filled)

    @timer = QTimer.new(self)
    @timer.timeout.connect(self, :show_time)
    @timer.start(1000)

    show_time

    set_window_title(tr('Digital Clock'))
    resize(150, 60)
  end

  def show_time
    time = QTime.current_time
    text = time.to_string('hh:mm')
    text[2] = ' ' if time.second.even?
    display(text)
  end
end
