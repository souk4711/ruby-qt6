# frozen_string_literal: true

require 'qt6/all'

a = QApplication.new(ARGV)
quit = QPushButton.new('Quit')
quit.resize(75, 30)
quit.set_font(QFont.new('Times', 18, QFont::Bold))
QObject.connect(quit, SIGNAL('clicked()'), a, SLOT('quit()'))
quit.show
a.exec
