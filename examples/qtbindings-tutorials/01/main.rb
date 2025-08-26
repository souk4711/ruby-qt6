# frozen_string_literal: true

require 'qt6/all'

a = QApplication.new
hello = QPushButton.new('Hello World!')
hello.resize(100, 30)
hello.show
a.exec
