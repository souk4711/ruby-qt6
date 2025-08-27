# frozen_string_literal: true

require 'qt6/all'

app = QApplication.new

window = QWidget.new
window.resize(200, 120)

quit = QPushButton.new('Quit', window)
quit.font = QFont.new('Times', 18, QFont::Bold)
quit.geometry = QRect.new(10, 40, 180, 40)
QObject.connect(quit, SIGNAL('clicked()'), app, SLOT('quit()'))

window.show
app.exec
