require "qt6/all"

class PushButton < QPushButton
  q_object do
    slot "say_hello()"
  end

  def say_hello
    puts "Button clicked, Hello!"
  end
end

app = QApplication.new(ARGV)
button = PushButton.new("Click me")
button.clicked.connect(button, :say_hello)
button.show
app.exec
