require 'qt6/all'

class LCDRange < QWidget
  q_object do
    signal 'valueChanged(int)'
    slot 'setValue(int)'
    slot 'setRange(int, int)'
    slot 'setText(QString)'
  end

  def initialize(s, parent = nil)
    super(parent)
    init
    set_text(s)
  end

  def init
    lcd = QLCDNumber.new(2)
    @slider = QSlider.new(Qt::Horizontal)
    @slider.set_range(0, 99)
    @slider.set_value(0)
    @slider.value_changed.connect(lcd, :display)
    @slider.value_changed.connect(self, :value_changed)

    @label = QLabel.new(" ")
    @label.set_alignment(Qt::AlignHCenter | Qt::AlignTop)
    # @label.set_size_policy(QSizePolicy::Preferred, QSizePolicy::Fixed)

    layout = QVBoxLayout.new
    layout.add_widget(lcd)
    layout.add_widget(@slider)
    layout.add_widget(@label)
    set_layout(layout)
    set_focus_proxy(@slider)
  end

  def set_value(value)
    @slider.set_value(value)
  end

  def set_range(min, max)
    @slider.set_range(min, max)
  end

  def set_text(s)
    @label.set_text(s)
  end
end
