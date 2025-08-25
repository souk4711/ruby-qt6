# frozen_string_literal: true

require "qt6"

include(*RubyQt6.qt_modules)

app = QApplication.new
label = QLabel.new("Hello World!")
label.show
app.exec
