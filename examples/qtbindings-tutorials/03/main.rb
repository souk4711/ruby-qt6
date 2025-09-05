# frozen_string_literal: true

require 'qt6/all'

app = QApplication.new(ARGV)

window = QWidget.new
window.resize(200, 120)

quit = QPushButton.new('Quit', window)
quit.set_font(QFont.new('Times', 18, QFont::Bold))
quit.set_geometry(10, 40, 180, 40)
QObject.connect(quit, SIGNAL('clicked()'), app, SLOT('quit()'))

window.show
app.exec
