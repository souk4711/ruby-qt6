# frozen_string_literal: true

require 'qt6/all'

class KillerFilter < RubyQt6::Bando::QWidget
  def initialize
    super

    resize(230, 130)

    pb = QPushButton.new('pushbutton', self)
    pb.set_geometry(10, 10, 100, 50)
    pb.install_event_filter(self)

    le = QLineEdit.new('lineedit', self)
    le.set_geometry(10, 70, 100, 50)
    le.install_event_filter(self)

    cb = QCheckBox.new('checkbox', self)
    cb.set_geometry(120, 10, 100, 50)
    cb.install_event_filter(self)

    rb = QRadioButton.new('radiobutton', self)
    rb.set_geometry(120, 70, 100, 50)
    rb.install_event_filter(self)
  end

  def event_filter(watched, event)
    return false unless event.type == QEvent::MouseButtonPress
    return false unless event.button == Qt::RightButton

    watched.close
    true
  end
end

app = QApplication.new(ARGV)
widget = KillerFilter.new
widget.show
app.exec
