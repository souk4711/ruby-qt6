# frozen_string_literal: true

class Dialog < RubyQt6::Bando::QDialog
  NUM_GRID_ROWS = 3
  NUM_BUTTONS = 4

  def initialize
    super

    @labels = []
    @line_edits = []
    @buttons = []

    create_menu
    create_horizontal_group_box
    create_grid_group_box

    @big_editor = QTextEdit.new
    @big_editor.set_plain_text(tr('This widget takes up all the remaining space in the top-level layout.'))

    @ok_button = QPushButton.new(tr('OK'))
    @ok_button.set_default(true)
    @ok_button.clicked.connect(self, :accept)

    @cancel_button = QPushButton.new(tr('Cancel'))
    @cancel_button.clicked.connect(self, :reject)

    b = QHBoxLayout.new
    b.add_stretch(1)
    b.add_widget(@ok_button)
    b.add_widget(@cancel_button)

    m = QVBoxLayout.new
    m.set_menu_bar(@menu_bar)
    m.add_widget(@horizontal_group_box)
    m.add_widget(@grid_group_box)
    m.add_widget(@big_editor)
    m.add_layout(b)
    set_layout(m)

    set_window_title(tr('Basic Layouts'))
  end

  def create_menu
    @menu_bar = QMenuBar.new

    @file_menu = QMenu.new(tr('&File'), self)
    @exit_action = @file_menu.add_action(tr('E&xit'))
    @menu_bar.add_menu(@file_menu)

    @exit_action.triggered.connect(self, :accept)
  end

  def create_horizontal_group_box
    @horizontal_group_box = QGroupBox.new(tr('Horizontal layout'))
    layout = QHBoxLayout.new

    (0...NUM_BUTTONS).each do |i|
      @buttons[i] = QPushButton.new(tr(format('Button %d', i + 1)))
      layout.add_widget(@buttons[i])
    end
    @horizontal_group_box.set_layout(layout)
  end

  def create_grid_group_box
    @grid_group_box = QGroupBox.new(tr('Grid layout'))
    layout = QGridLayout.new

    (0...NUM_GRID_ROWS).each do |i|
      @labels[i] = QLabel.new(tr(format('Line %d:', i + 1)))
      @line_edits[i] = QLineEdit.new
      layout.add_widget(@labels[i], i, 0)
      layout.add_widget(@line_edits[i], i, 1)
    end

    @small_editor = QTextEdit.new
    @small_editor.set_plain_text(tr('This widget takes up about two thirds of the grid layout.'))
    layout.add_widget(@small_editor, 0, 2, 3, 1)

    layout.set_column_stretch(1, 10)
    layout.set_column_stretch(2, 20)
    @grid_group_box.set_layout(layout)
  end
end
