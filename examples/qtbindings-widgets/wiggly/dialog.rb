# frozen_string_literal: true

require_relative 'wigglywidget'

class Dialog < RubyQt6::Bando::QDialog
  def initialize(parent = nil)
    super(parent)

    wiggly_widget = WigglyWidget.new
    line_edit = QLineEdit.new ''

    layout = QVBoxLayout.new
    layout.add_widget(wiggly_widget)
    layout.add_widget(line_edit)
    set_layout(layout)

    line_edit.text_changed.connect(wiggly_widget, :set_text)
    line_edit.set_text(tr('Hello world!'))

    set_window_title(tr('Wiggly'))
    resize(360, 145)
  end
end
