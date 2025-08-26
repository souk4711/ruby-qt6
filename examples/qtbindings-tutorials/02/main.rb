# frozen_string_literal: true

require 'qt6'

include(*RubyQt6.qt_modules)

a = QApplication.new
quit = QPushButton.new('Quit', nil)
quit.resize(75, 30)
quit.font = QFont.new('Times', 18, QFont::Bold)
QObject.connect(quit, SIGNAL('clicked()'), a, SLOT('quit()'))
quit.show
a.exec
