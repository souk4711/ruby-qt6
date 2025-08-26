# frozen_string_literal: true

require 'qt6/all'

app = QApplication.new
label = QLabel.new('Hello World!')
label.show
app.exec
