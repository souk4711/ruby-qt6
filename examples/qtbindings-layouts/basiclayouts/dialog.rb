# frozen_string_literal: true

class Dialog < RubyQt6::Bando::QDialog
  NumGridRows = 3
  NumButtons = 4

  def initialize
    super

    @labels = []
    @lineEdits = []
    @buttons = []

    createMenu
    createHorizontalGroupBox
    createGridGroupBox

    @bigEditor = QTextEdit.new('')
    @bigEditor.set_plain_text(tr('This widget takes up all the remaining space in the top-level layout.'))

    @okButton = QPushButton.new(tr('OK'))
    @cancelButton = QPushButton.new(tr('Cancel'))
    @okButton.set_default(true)

    @okButton.clicked.connect(self, :accept)
    @cancelButton.clicked.connect(self, :reject)

    b = QHBoxLayout.new
    b.add_stretch(1)
    b.add_widget(@okButton)
    b.add_widget(@cancelButton)

    m = QVBoxLayout.new
    m.set_menu_bar(@menuBar)
    m.add_widget(@horizontalGroupBox)
    m.add_widget(@gridGroupBox)
    m.add_widget(@bigEditor)
    m.add_layout(b)
    set_layout(m)

    set_window_title(tr('Basic Layouts'))
  end

  def createMenu
    @menuBar = QMenuBar.new

    @fileMenu = QMenu.new(tr('&File'), self)
    @exitAction = @fileMenu.add_action(tr('E&xit'))
    @menuBar.add_menu(@fileMenu)

    @exitAction.triggered.connect(self, :accept)
  end

  def createHorizontalGroupBox
    @horizontalGroupBox = QGroupBox.new(tr('Horizontal layout'))
    layout = QHBoxLayout.new

    (0...NumButtons).each do |i|
      @buttons[i] = QPushButton.new(tr(format('Button %d', i + 1)))
      layout.add_widget(@buttons[i])
    end
    @horizontalGroupBox.set_layout(layout)
  end

  def createGridGroupBox
    @gridGroupBox = QGroupBox.new(tr('Grid layout'))
    layout = QGridLayout.new

    (0...NumGridRows).each do |i|
      @labels[i] = QLabel.new(tr(format('Line %d:', i + 1)))
      @lineEdits[i] = QLineEdit.new('')
      layout.add_widget(@labels[i], i, 0)
      layout.add_widget(@lineEdits[i], i, 1)
    end

    @smallEditor = QTextEdit.new('')
    @smallEditor.set_plain_text(tr('This widget takes up about two thirds of the grid layout.'))
    layout.add_widget(@smallEditor, 0, 2, 3, 1)

    layout.set_column_stretch(1, 10)
    layout.set_column_stretch(2, 20)
    @gridGroupBox.set_layout(layout)
  end
end
