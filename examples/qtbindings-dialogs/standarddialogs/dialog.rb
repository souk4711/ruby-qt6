# frozen_string_literal: true

class Dialog < RubyQt6::Bando::QDialog
  q_object do
    slot 'set_int()'
    slot 'set_double()'
    slot 'set_item()'
    slot 'set_text()'
    slot 'set_color()'
    slot 'set_font()'
    slot 'set_existing_directory()'
    slot 'set_open_file_name()'
    slot 'set_open_file_names()'
    slot 'set_save_file_name()'
    slot 'critical_message()'
    slot 'information_message()'
    slot 'question_message()'
    slot 'warning_message()'
    slot 'error_message()'
  end

  def initialize(parent = nil)
    super(parent)

    @message = tr('<p>Message boxes have a caption, a text, and up to three buttons, each with standard or custom texts.<p>Click a button or press Esc.')
    @error_message_dialog = QErrorMessage.new(self)

    frame_style = QFrame::Sunken.to_i | QFrame::Panel.to_i
    @integer_label = QLabel.new
    @integer_label.set_frame_style frame_style
    integer_button = QPushButton.new(tr('QInputDialog.get&Integer()'))

    @double_label = QLabel.new
    @double_label.set_frame_style frame_style
    double_button = QPushButton.new(tr('QInputDialog.get&Double()'))

    @item_label = QLabel.new
    @item_label.set_frame_style frame_style
    item_button = QPushButton.new(tr('QInputDialog.getIte&m()'))

    @text_label = QLabel.new
    @text_label.set_frame_style frame_style
    text_button = QPushButton.new(tr('QInputDialog.get&Text()'))

    @color_label = QLabel.new
    @color_label.set_frame_style frame_style
    color_button = QPushButton.new(tr('QColorDialog.get&Color()'))

    @font_label = QLabel.new
    @font_label.set_frame_style frame_style
    font_button = QPushButton.new(tr('QtFontDialog.get&Font()'))

    @directory_label = QLabel.new
    @directory_label.set_frame_style frame_style
    directory_button = QPushButton.new(tr('QFileDialog.getE&xistingDirectory()'))

    @open_file_name_label = QLabel.new
    @open_file_name_label.set_frame_style frame_style
    open_file_name_button = QPushButton.new(tr('QFileDialog.get&OpenFileName()'))

    @open_file_names_label = QLabel.new
    @open_file_names_label.set_frame_style frame_style
    open_file_names_button = QPushButton.new(tr('QFile&Dialog.getOpenFileNames()'))

    @save_file_name_label = QLabel.new
    @save_file_name_label.set_frame_style frame_style
    save_file_name_button = QPushButton.new(tr('QFileDialog.get&SaveFileName()'))

    @critical_label = QLabel.new
    @critical_label.set_frame_style frame_style
    critical_button = QPushButton.new(tr('QMessageBox.critica&l()'))

    @information_label = QLabel.new
    @information_label.set_frame_style frame_style
    informationButton = QPushButton.new(tr('QMessageBox.i&nformation()'))

    @question_label = QLabel.new
    @question_label.set_frame_style frame_style
    question_button = QPushButton.new(tr('QMessageBox.&question()'))

    @warning_label = QLabel.new
    @warning_label.set_frame_style frame_style
    warning_button = QPushButton.new(tr('QMessageBox.&warning()'))

    @error_label = QLabel.new
    @error_label.set_frame_style frame_style
    error_button = QPushButton.new(tr('QErrorMessage.show&M&essage()'))

    integer_button.clicked.connect(self, :set_int)
    double_button.clicked.connect(self, :set_double)
    item_button.clicked.connect(self, :set_item)
    text_button.clicked.connect(self, :set_text)
    color_button.clicked.connect(self, :set_color)
    font_button.clicked.connect(self, :set_font)
    directory_button.clicked.connect(self, :set_existing_directory)
    open_file_name_button.clicked.connect(self, :set_open_file_name)
    open_file_names_button.clicked.connect(self, :set_open_file_names)
    save_file_name_button.clicked.connect(self, :set_save_file_name)
    critical_button.clicked.connect(self, :critical_message)
    informationButton.clicked.connect(self, :information_message)
    question_button.clicked.connect(self, :question_message)
    warning_button.clicked.connect(self, :warning_message)
    error_button.clicked.connect(self, :error_message)

    l = QGridLayout.new
    l.set_column_stretch(1, 1)
    l.set_column_minimum_width(1, 250)
    l.add_widget(integer_button, 0, 0)
    l.add_widget(@integer_label, 0, 1)
    l.add_widget(double_button, 1, 0)
    l.add_widget(@double_label, 1, 1)
    l.add_widget(item_button, 2, 0)
    l.add_widget(@item_label, 2, 1)
    l.add_widget(text_button, 3, 0)
    l.add_widget(@text_label, 3, 1)
    l.add_widget(color_button, 4, 0)
    l.add_widget(@color_label, 4, 1)
    l.add_widget(font_button, 5, 0)
    l.add_widget(@font_label, 5, 1)
    l.add_widget(directory_button, 6, 0)
    l.add_widget(@directory_label, 6, 1)
    l.add_widget(open_file_name_button, 7, 0)
    l.add_widget(@open_file_name_label, 7, 1)
    l.add_widget(open_file_names_button, 8, 0)
    l.add_widget(@open_file_names_label, 8, 1)
    l.add_widget(save_file_name_button, 9, 0)
    l.add_widget(@save_file_name_label, 9, 1)
    l.add_widget(critical_button, 10, 0)
    l.add_widget(@critical_label, 10, 1)
    l.add_widget(informationButton, 11, 0)
    l.add_widget(@information_label, 11, 1)
    l.add_widget(question_button, 12, 0)
    l.add_widget(@question_label, 12, 1)
    l.add_widget(warning_button, 13, 0)
    l.add_widget(@warning_label, 13, 1)
    l.add_widget(error_button, 14, 0)
    l.add_widget(@error_label, 14, 1)
    set_layout(l)

    set_window_title tr('Standard Dialogs')
  end

  def set_int
    ok = QBool.new
    i = QInputDialog.get_int(self, tr('QInputDialog.getInt()'), tr('Percentage:'), 25, 0, 100, 1, ok)
    return unless ok

    @integer_label.set_text tr('%d%%' % i)
  end

  def set_double
    ok = QBool.new
    d = QInputDialog.get_double(self, tr('QInputDialog.getDouble()'), tr('Amount:'), 37.56, -10_000, 10_000, 2, ok)
    return unless ok

    @double_label.set_text '$%f' % d
  end

  def set_item
    items = QStringList.new
    items << tr('Spring') << tr('Summer') << tr('Fall') << tr('Winter')

    ok = QBool.new
    item = QInputDialog.get_item(self, tr('QInputDialog.getItem()'), tr('Season:'), items, 0, false, ok)
    return unless ok && !item.nil?

    @item_label.set_text item
  end

  def set_text
    ok = QBool.new
    text = QInputDialog.get_text(self, tr('QInputDialog.getText()'), tr('User name:'), QLineEdit::Normal,
                                 QDir.home.dir_name, ok)
    return unless ok && !text.nil?

    @text_label.set_text text
  end

  def set_color
    color = QColorDialog.get_color(QColor.new(Qt::Green), self)
    return unless color.valid?

    @color_label.set_text color.name
    @color_label.set_palette QPalette.new(color)
  end

  def set_font
    ok = QBool.new
    font = QFontDialog.get_font(ok, QFont.new(@font_label.text), self)
    return unless ok

    @font_label.set_text font.key
  end

  def set_existing_directory
    directory = QFileDialog.get_existing_directory(self, tr('QFileDialog.getExistingDirectory()'),
                                                   @directory_label.text, QFileDialog::DontResolveSymlinks | QFileDialog::ShowDirsOnly)
    return if directory.nil?

    @directory_label.set_text directory
  end

  def set_open_file_name
    file_name = QFileDialog.get_open_file_name(self, tr('QFileDialog.getOpenFileName()'), @open_file_name_label.text,
                                               tr('All Files (*);;Text Files (*.txt)'))
    return if file_name.nil?

    @open_file_name_label.set_text file_name
  end

  def set_open_file_names
    files = QFileDialog.get_open_file_names(self, tr('QFileDialog.getOpenFileNames()'), @open_files_path || '',
                                            tr('All Files (*);;Text Files (*.txt)'))
    return if files.empty?

    @open_files_path = files[0]
    @open_file_names_label.set_text '[%s]' % files.join(', ')
  end

  def set_save_file_name
    file_name = QFileDialog.get_save_file_name(self, tr('QFileDialog.getSaveFileName()'), @save_file_name_label.text,
                                               tr('All Files (*);;Text Files (*.txt)'))
    return if file_name.nil?

    @save_file_name_label.set_text file_name
  end

  def critical_message
    reply = QMessageBox.critical(self, tr('QMessageBox.showCritical()'), @message,
                                 QMessageBox::Abort | QMessageBox::Retry | QMessageBox::Ignore, QMessageBox::Ignore)
    if reply == QMessageBox::Abort
      @critical_label.set_text tr('Abort')
    elsif reply == QMessageBox::Retry
      @critical_label.set_text tr('Retry')
    else
      @critical_label.set_text tr('Ignore')
    end
  end

  def information_message
    QMessageBox.information(self, tr('QMessageBox.showInformation()'), @message)
    @information_label.set_text tr('Closed with OK or Esc')
  end

  def question_message
    reply = QMessageBox.question(self, tr('QMessageBox.showQuestion()'), @message,
                                 QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, QMessageBox::Cancel)
    if reply == QMessageBox::Yes
      @question_label.set_text tr('Yes')
    elsif reply == QMessageBox::No
      @question_label.set_text tr('No')
    else
      @question_label.set_text tr('Cancel')
    end
  end

  def warning_message
    reply = QMessageBox.warning(self, tr('QMessageBox.showWarning()'), @message,
                                QMessageBox::Save | QMessageBox::Discard, QMessageBox::Discard)
    if reply == QMessageBox::Save
      @warning_label.set_text tr('Save')
    else
      @warning_label.set_text tr('Discard')
    end
  end

  def error_message
    @error_message_dialog.show_message(
      tr('This dialog shows and remembers error messages. ' \
           'If the checkbox is checked (as it is by default), ' \
           'the shown message will be shown again, ' \
           'but if the user unchecks the box the message ' \
           'will not appear again if QErrorMessage.showMessage() ' \
           'is called with the same message.')
    )
    @error_label.set_text tr("If the box is unchecked, the message won't appear again.")
  end
end
