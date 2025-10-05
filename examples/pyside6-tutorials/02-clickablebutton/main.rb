# frozen_string_literal: true

require 'qt6/all'

class Greetings < RubyQt6::Bando::QObject
  q_object do
    slot 'say_hello()'
  end

  def say_hello
    puts 'Button clicked, Hello!'
  end
end

app = QApplication.new(ARGV)
button = QPushButton.new('Click me')
button.clicked.connect(Greetings.new, :say_hello)
button.show
app.exec
