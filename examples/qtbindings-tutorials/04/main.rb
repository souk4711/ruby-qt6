# frozen_string_literal: true

require 'qt6/all'

class MyWidget < QWidget
  def initialize(parent: nil, app:)
    super(parent)
    set_fixed_size(200, 120)

    quit = QPushButton.new('Quit', self)
    quit.set_font(QFont.new('Times', 18, QFont::Bold))
    quit.set_geometry(62, 40, 75, 30)
    QObject.connect(quit, SIGNAL('clicked()'), app, SLOT('quit()'))
  end
end

app = QApplication.new
widget = MyWidget.new(app:)
widget.show
app.exec
