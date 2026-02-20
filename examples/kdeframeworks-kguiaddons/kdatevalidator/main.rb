# frozen_string_literal: true

require 'qt6/kdeframeworks'

class MyWidget < RubyQt6::Bando::QWidget
  q_object do
    slot "on_edit_finished()"
  end

  def initialize
    super

    input = QLineEdit.new
    input.editing_finished.connect(self, :on_edit_finished)

    validator = KDateValidator.new
    input.set_validator(validator)

    layout = QVBoxLayout.new(self)
    layout.add_widget(input)
  end

  def on_edit_finished
    puts "Got valid input"
  end
end

app = QApplication.new
widget = MyWidget.new
widget.resize(800, 600)
widget.show
app.exec
