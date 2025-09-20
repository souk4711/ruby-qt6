require 'qt6/all'

a = QApplication.new(ARGV)
quit = QPushButton.new('Quit')
quit.resize(75, 30)
quit.set_font(QFont.new('Times', 18, QFont::Bold))
quit.clicked.connect(a, :quit)
quit.show
a.exec
