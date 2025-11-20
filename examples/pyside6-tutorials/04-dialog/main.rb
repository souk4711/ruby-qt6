# frozen_string_literal: true

require 'qt6/all'

class Form < RubyQt6::Bando::QDialog
  q_object do
    slot 'greetings()'
  end

  def initialize
    super

    @edit = QLineEdit.new('Write my name here')
    @button = QPushButton.new('Show Greetings')
    @button.clicked.connect(self, :greetings)

    layout = QVBoxLayout.new
    layout.add_widget(@edit)
    layout.add_widget(@button)
    set_layout(layout)
  end

  def greetings
    puts @edit.text
  end
end

app = QApplication.new
form = Form.new
form.show
app.exec
