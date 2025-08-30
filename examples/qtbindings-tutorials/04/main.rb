# frozen_string_literal: true

require 'qt6/all'

class MyWidget < QWidget
  def initialize
    super
    set_fixed_size(200, 120)

    quit = QPushButton.new('Quit', self)
    quit.set_font(QFont.new('Times', 18, QFont::Bold))
    quit.set_geometry(62, 40, 75, 30)
    QObject.connect(quit, SIGNAL('clicked()'), $qApp, SLOT('quit()'))
  end
end

app = QApplication.new
widget = MyWidget.new
widget.show
app.exec
