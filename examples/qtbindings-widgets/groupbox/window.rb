# frozen_string_literal: true

class Window < RubyQt6::Bando::QWidget
  def initialize(parent = nil)
    super(parent)

    grid = QGridLayout.new
    grid.add_widget(create_first_exclusive_group, 0, 0)
    grid.add_widget(create_second_exclusive_group, 1, 0)
    grid.add_widget(create_non_exclusive_group, 0, 1)
    grid.add_widget(create_push_button_group, 1, 1)
    set_layout(grid)

    set_window_title(tr('Group Box'))
    resize(480, 320)
  end

  def create_first_exclusive_group
    group_box = QGroupBox.new(tr('Exclusive Radio Buttons'))

    radio1 = QRadioButton.new(tr('&Radio button 1'))
    radio2 = QRadioButton.new(tr('R&adio button 2'))
    radio3 = QRadioButton.new(tr('Ra&dio button 3'))
    radio1.set_checked true

    vbox = QVBoxLayout.new
    vbox.add_widget(radio1)
    vbox.add_widget(radio2)
    vbox.add_widget(radio3)
    vbox.add_stretch(1)
    group_box.set_layout vbox

    group_box
  end

  def create_second_exclusive_group
    group_box = QGroupBox.new(tr('E&xclusive Radio Buttons'))
    group_box.set_checkable true
    group_box.set_checked false

    radio1 = QRadioButton.new(tr('Rad&io button 1'))
    radio2 = QRadioButton.new(tr('Radi&o button 2'))
    radio3 = QRadioButton.new(tr('Radio &button 3'))
    radio1.set_checked true

    check_box = QCheckBox.new(tr('Ind&ependent checkbox'))
    check_box.set_checked true

    vbox = QVBoxLayout.new
    vbox.add_widget(radio1)
    vbox.add_widget(radio2)
    vbox.add_widget(radio3)
    vbox.add_widget(check_box)
    vbox.add_stretch(1)
    group_box.set_layout vbox

    group_box
  end

  def create_non_exclusive_group
    group_box = QGroupBox.new(tr('Non-Exclusive Checkboxes'))
    group_box.set_flat true

    check_box1 = QCheckBox.new(tr('&Checkbox 1'))
    check_box2 = QCheckBox.new(tr('C&heckbox 2'))
    check_box2.set_checked true

    tristate_box = QCheckBox.new(tr('Tri-&state button'))
    tristate_box.set_tristate true
    tristate_box.set_check_state Qt::PartiallyChecked

    vbox = QVBoxLayout.new
    vbox.add_widget(check_box1)
    vbox.add_widget(check_box2)
    vbox.add_widget(tristate_box)
    vbox.add_stretch(1)
    group_box.set_layout vbox

    group_box
  end

  def create_push_button_group
    group_box = QGroupBox.new(tr('&Push Buttons'))
    group_box.set_checkable true
    group_box.set_checked true

    push_button = QPushButton.new(tr('&Normal Button'))
    toggle_button = QPushButton.new(tr('&Toggle Button'))
    toggle_button.set_checkable true
    toggle_button.set_checked true

    flat_button = QPushButton.new(tr('&Flat Button'))
    flat_button.set_flat true

    popup_button = QPushButton.new(tr('Pop&up Button'))
    menu = QMenu.new('', self)
    menu.add_action(tr('&First Item'))
    menu.add_action(tr('&Second Item'))
    menu.add_action(tr('&Third Item'))
    menu.add_action(tr('F&ourth Item'))
    popup_button.set_menu menu

    vbox = QVBoxLayout.new
    vbox.add_widget(push_button)
    vbox.add_widget(toggle_button)
    vbox.add_widget(flat_button)
    vbox.add_widget(popup_button)
    vbox.add_stretch(1)
    group_box.set_layout vbox

    group_box
  end
end
