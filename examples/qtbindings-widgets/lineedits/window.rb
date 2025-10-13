# frozen_string_literal: true

class Window < RubyQt6::Bando::QWidget
  q_object do
    slot 'slot_echo_changed(int)'
    slot 'slot_validator_changed(int)'
    slot 'slot_alignment_changed(int)'
    slot 'slot_input_mask_changed(int)'
    slot 'slot_access_changed(int)'
  end

  def initialize(parent = nil)
    super(parent)

    echo_group = QGroupBox.new(tr('Echo'))

    echo_label = QLabel.new(tr('Mode:'))
    echo_combobox = QComboBox.new
    echo_combobox.add_item(tr('Normal'))
    echo_combobox.add_item(tr('Password'))
    echo_combobox.add_item(tr('No Echo'))

    @echo_lineedit = QLineEdit.new
    @echo_lineedit.set_focus

    validator_group = QGroupBox.new(tr('Validator'))

    validator_label = QLabel.new(tr('Type:'))
    validator_combobox = QComboBox.new
    validator_combobox.add_item(tr('No validator'))
    validator_combobox.add_item(tr('Integer validator'))
    validator_combobox.add_item(tr('Double validator'))

    @validator_line_edit = QLineEdit.new

    alignment_group = QGroupBox.new(tr('Alignment'))

    alignment_label = QLabel.new(tr('Type:'))
    alignment_combobox = QComboBox.new
    alignment_combobox.add_item(tr('Left'))
    alignment_combobox.add_item(tr('Centered'))
    alignment_combobox.add_item(tr('Right'))

    @alignmentLineEdit = QLineEdit.new

    input_mask_group = QGroupBox.new(tr('Input mask'))

    input_mask_label = QLabel.new(tr('Type:'))
    input_mask_combobox = QComboBox.new
    input_mask_combobox.add_item(tr('No mask'))
    input_mask_combobox.add_item(tr('Phone number'))
    input_mask_combobox.add_item(tr('ISO date'))
    input_mask_combobox.add_item(tr('License key'))

    @input_mask_lineedit = QLineEdit.new

    access_group = QGroupBox.new(tr('Access'))

    access_label = QLabel.new(tr('Read-only:'))
    access_combobox = QComboBox.new
    access_combobox.add_item(tr('False'))
    access_combobox.add_item(tr('True'))

    @access_lineedit = QLineEdit.new

    echo_combobox.activated.connect(self, :slot_echo_changed)
    validator_combobox.activated.connect(self, :slot_validator_changed)
    alignment_combobox.activated.connect(self, :slot_alignment_changed)
    input_mask_combobox.activated.connect(self, :slot_input_mask_changed)
    access_combobox.activated.connect(self, :slot_access_changed)

    echo_layout = QGridLayout.new
    echo_layout.add_widget(echo_label, 0, 0)
    echo_layout.add_widget(echo_combobox, 0, 1)
    echo_layout.add_widget(@echo_lineedit, 1, 0, 1, 2)
    echo_group.set_layout echo_layout

    validator_layout = QGridLayout.new
    validator_layout.add_widget(validator_label, 0, 0)
    validator_layout.add_widget(validator_combobox, 0, 1)
    validator_layout.add_widget(@validator_line_edit, 1, 0, 1, 2)
    validator_group.set_layout validator_layout

    alignment_layout = QGridLayout.new
    alignment_layout.add_widget(alignment_label, 0, 0)
    alignment_layout.add_widget(alignment_combobox, 0, 1)
    alignment_layout.add_widget(@alignmentLineEdit, 1, 0, 1, 2)
    alignment_group.set_layout alignment_layout

    input_mask_layout = QGridLayout.new
    input_mask_layout.add_widget(input_mask_label, 0, 0)
    input_mask_layout.add_widget(input_mask_combobox, 0, 1)
    input_mask_layout.add_widget(@input_mask_lineedit, 1, 0, 1, 2)
    input_mask_group.set_layout input_mask_layout

    access_layout = QGridLayout.new
    access_layout.add_widget(access_label, 0, 0)
    access_layout.add_widget(access_combobox, 0, 1)
    access_layout.add_widget(@access_lineedit, 1, 0, 1, 2)
    access_group.set_layout access_layout

    layout = QVBoxLayout.new
    layout.add_widget(echo_group)
    layout.add_widget(validator_group)
    layout.add_widget(alignment_group)
    layout.add_widget(input_mask_group)
    layout.add_widget(access_group)
    set_layout(layout)

    set_window_title(tr('Line Edits'))
  end

  def slot_echo_changed(index)
    case index
    when 0 then @echo_lineedit.set_echo_mode QLineEdit::Normal
    when 1 then @echo_lineedit.set_echo_mode QLineEdit::Password
    when 2 then @echo_lineedit.set_echo_mode QLineEdit::NoEcho
    end
  end

  def slot_validator_changed(index)
    case index
    when 0 then @validator_line_edit.set_validator nil
    when 1 then @validator_line_edit.set_validator QIntValidator.new(@validator_line_edit)
    when 2 then @validator_line_edit.set_validator QDoubleValidator.new(-999.0, 999.0, 2, @validator_line_edit)
    end
    @validator_line_edit.set_text ''
  end

  def slot_alignment_changed(index)
    case index
    when 0 then @alignmentLineEdit.set_alignment Qt::AlignLeft.to_qflags
    when 1 then @alignmentLineEdit.set_alignment Qt::AlignCenter.to_qflags
    when 2 then @alignmentLineEdit.set_alignment Qt::AlignRight.to_qflags
    end
  end

  def slot_input_mask_changed(index)
    case index
    when 0
      @input_mask_lineedit.set_input_mask ''
    when 1
      @input_mask_lineedit.set_input_mask '+99 99 99 99 99;_'
    when 2
      @input_mask_lineedit.set_input_mask '0000-00-00'
      @input_mask_lineedit.set_text '00000000'
      @input_mask_lineedit.set_cursor_position 0
    when 3
      @input_mask_lineedit.set_input_mask '>AAAAA-AAAAA-AAAAA-AAAAA-AAAAA;#'
    end
  end

  def slot_access_changed(index)
    case index
    when 0 then @access_lineedit.set_read_only false
    when 1 then @access_lineedit.set_read_only true
    end
  end
end
