# frozen_string_literal: true

require "qt6/qtwidgets"

include(*RubyQt6.qt_modules)

# @Slot()
def say_hello
 print("Button clicked, Hello!")
end

app = QApplication.new
button = QPushButton.new("Click me")
# button.clicked.connect(say_hello)
button.show
app.exec
