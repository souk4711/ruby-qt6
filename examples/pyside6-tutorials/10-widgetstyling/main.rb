# frozen_string_literal: true

require 'qt6/all'

class Widget < RubyQt6::Bando::QWidget
  def initialize
    super

    menu_widget = QListWidget.new
    Range.new(0, 9).each do |i|
      item = QListWidgetItem.new("Item #{i}")
      item.set_text_alignment(Qt::AlignCenter)
      menu_widget.add_item(item)
    end

    text_widget = QLabel.new('This is a placeholder text')
    button = QPushButton.new('Something')
    content_layout = QVBoxLayout.new
    content_layout.add_widget(text_widget)
    content_layout.add_widget(button)
    main_widget = QWidget.new
    main_widget.set_layout(content_layout)

    layout = QHBoxLayout.new
    layout.add_widget(menu_widget, 1)
    layout.add_widget(main_widget, 4)
    set_layout(layout)
  end
end

app = QApplication.new
app.set_style_sheet(File.read(File.join(__dir__, 'style.qss')))
widget = Widget.new
widget.show
app.exec
