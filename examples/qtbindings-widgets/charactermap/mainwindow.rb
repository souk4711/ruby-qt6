# frozen_string_literal: true

require_relative 'character_widget'

class MainWindow < RubyQt6::Bando::QMainWindow
  q_object do
    slot 'find_styles()'
    slot 'insert_character(QString)'
    slot 'update_clipboard()'
  end

  def initialize
    super

    central_widget = QWidget.new

    @font_label = QLabel.new(tr('Font:'))
    @font_combo = QComboBox.new
    @style_label = QLabel.new(tr('Style:'))
    @style_combo = QComboBox.new

    @scroll_area = QScrollArea.new
    @character_widget = CharacterWidget.new
    @scroll_area.set_widget @character_widget

    find_fonts
    find_styles

    @line_edit = QLineEdit.new
    @clipboard_button = QPushButton.new(tr('&To clipboard'))
    @clipboard = QApplication.clipboard

    @font_combo.activated.connect(self, :find_styles)
    @font_combo.current_text_changed.connect(@character_widget, :update_font)
    @style_combo.current_text_changed.connect(@character_widget, :update_style)
    @character_widget.character_selected.connect(self, :insert_character)
    @clipboard_button.clicked.connect(self, :update_clipboard)

    controls_layout = QHBoxLayout.new
    controls_layout.add_widget(@font_label)
    controls_layout.add_widget(@font_combo, 1)
    controls_layout.add_widget(@style_label)
    controls_layout.add_widget(@style_combo, 1)
    controls_layout.add_stretch(1)

    lineLayout = QHBoxLayout.new
    lineLayout.add_widget(@line_edit, 1)
    lineLayout.add_spacing(12)
    lineLayout.add_widget(@clipboard_button)

    central_layout = QVBoxLayout.new
    central_layout.add_layout(controls_layout)
    central_layout.add_widget(@scroll_area, 1)
    central_layout.add_spacing(4)
    central_layout.add_layout(lineLayout)
    central_widget.set_layout(central_layout)

    set_central_widget(central_widget)
    set_window_title(tr('Character Map'))
  end

  def find_fonts
    @font_combo.clear
    QFontDatabase.families.each do |family|
      @font_combo.add_item(family)
    end
  end

  def find_styles
    current_item = @style_combo.current_text
    @style_combo.clear

    QFontDatabase.styles(@font_combo.current_text).each { |style| @style_combo.add_item(style) }
    return unless @style_combo.find_text(current_item) == -1

    @style_combo.set_current_index(0)
  end

  def insert_character(character)
    @line_edit.insert(character)
  end

  def update_clipboard
    @clipboard.set_text(@line_edit.text, QClipboard::Clipboard)
    @clipboard.set_text(@line_edit.text, QClipboard::Selection)
  end
end
