# frozen_string_literal: true

class MainWindow < RubyQt6::Bando::QMainWindow
  q_object do
    slot 'new_file()'
    slot 'open()'
    slot 'save()'
    slot 'save_as()'
    slot 'about()'
    slot 'document_was_modified()'
  end

  def initialize(parent = nil)
    super

    @text_edit = QTextEdit.new('')
    set_central_widget(@text_edit)

    create_actions
    create_menu
    create_tool_bars
    create_status_bar
    read_settings

    @text_edit.document.contents_changed.connect(self, :document_was_modified)
    set_current_file('')
  end

  def close_event(event)
    if maybe_save?
      write_settings
      event.accept
    else
      event.ignore
    end
  end

  def new_file
    return unless maybe_save?

    @text_edit.clear
    set_current_file('')
  end

  def open
    return unless maybe_save?

    file_name = QFileDialog.get_open_file_name(self)
    return if file_name.nil?

    load_file(file_name)
  end

  def save
    return save_as if @current_file.empty?

    save_file(@current_file)
  end

  def save_as
    file_name = QFileDialog.get_save_file_name(self)
    return false if file_name.nil?

    save_file(file_name)
  end

  def about
    QMessageBox.about(
      self,
      tr('About Application'),
      tr('The <b>Application</b> example demonstrates how to ' \
         'write modern GUI applications using Qt, with a menu bar, ' \
         'toolbars, and a status bar.')
    )
  end

  def document_was_modified
    set_window_modified(true)
  end

  def create_actions
    @new_action = QAction.new(QIcon.new('images/new.png'), tr('&New'), self)
    @new_action.set_shortcut QKeySequence.new(tr('Ctrl+N'))
    @new_action.set_status_tip tr('Create a file.new')
    @new_action.triggered.connect(self, :new_file)

    @open_action = QAction.new(QIcon.new('images/open.png'), tr('&Open...'), self)
    @open_action.set_shortcut QKeySequence.new(tr('Ctrl+O'))
    @open_action.set_status_tip tr('Open an existing file')
    @open_action.triggered.connect(self, :open)

    @save_action = QAction.new(QIcon.new('images/save.png'), tr('&Save'), self)
    @save_action.set_shortcut QKeySequence.new(tr('Ctrl+S'))
    @save_action.set_status_tip tr('Save the document to disk')
    @save_action.triggered.connect(self, :save)

    @save_as_action = QAction.new(QIcon.new, tr('Save &As...'), self)
    @save_as_action.set_status_tip tr('Save the document under a name.new')
    @save_as_action.triggered.connect(self, :save_as)

    @exit_action = QAction.new(QIcon.new, tr('E&xit'), self)
    @exit_action.set_shortcut QKeySequence.new(tr('Ctrl+Q'))
    @exit_action.set_status_tip tr('Exit the application')
    @exit_action.triggered.connect(self, :close)

    @cut_action = QAction.new(QIcon.new('images/cut.png'), tr('Cu&t'), self)
    @cut_action.set_shortcut QKeySequence.new(tr('Ctrl+X'))
    @cut_action.set_status_tip tr("Cut the current selection's contents to the clipboard")
    @cut_action.triggered.connect(@text_edit, :cut)

    @copy_action = QAction.new(QIcon.new('images/copy.png'), tr('&Copy'), self)
    @copy_action.set_shortcut QKeySequence.new(tr('Ctrl+C'))
    @copy_action.set_status_tip tr("Copy the current selection's contents to the clipboard")
    @copy_action.triggered.connect(@text_edit, :copy)

    @paste_action = QAction.new(QIcon.new('images/paste.png'), tr('&Paste'), self)
    @paste_action.set_shortcut QKeySequence.new(tr('Ctrl+V'))
    @paste_action.set_status_tip tr("Paste the clipboard's contents into the current selection")
    @paste_action.triggered.connect(@text_edit, :paste)

    @about_action = QAction.new(QIcon.new, tr('&About'), self)
    @about_action.set_status_tip tr("Show the application's About box")
    @about_action.triggered.connect(self, :about)

    @about_qt_action = QAction.new(QIcon.new, tr('About &Qt'), self)
    @about_qt_action.set_status_tip tr("Show the Qt library's About box")
    @about_qt_action.triggered.connect($qApp, :about_qt)

    @cut_action.set_enabled(false)
    @copy_action.set_enabled(false)
    @text_edit.copy_available.connect(@cut_action, :set_enabled)
    @text_edit.copy_available.connect(@copy_action, :set_enabled)
  end

  def create_menu
    @file_menu = menu_bar.add_menu(tr('&File'))
    @file_menu.add_action(@new_action)
    @file_menu.add_action(@open_action)
    @file_menu.add_action(@save_action)
    @file_menu.add_action(@save_as_action)
    @file_menu.add_separator
    @file_menu.add_action(@exit_action)

    @edit_menu = menu_bar.add_menu(tr('&Edit'))
    @edit_menu.add_action(@cut_action)
    @edit_menu.add_action(@copy_action)
    @edit_menu.add_action(@paste_action)

    menu_bar.add_separator

    @help_menu = menu_bar.add_menu(tr('&Help'))
    @help_menu.add_action(@about_action)
    @help_menu.add_action(@about_qt_action)
  end

  def create_tool_bars
    @file_tool_bar = add_tool_bar(tr('File'))
    @file_tool_bar.add_action(@new_action)
    @file_tool_bar.add_action(@open_action)
    @file_tool_bar.add_action(@save_action)

    @edit_tool_bar = add_tool_bar(tr('Edit'))
    @edit_tool_bar.add_action(@cut_action)
    @edit_tool_bar.add_action(@copy_action)
    @edit_tool_bar.add_action(@paste_action)
  end

  def create_status_bar
    status_bar.show_message(tr('Ready'))
  end

  def read_settings
    settings = QSettings.new('Trolltech', 'Application Example')
    pos = settings.value('pos', QPoint.new(200, 200))
    size = settings.value('size', QSize.new(400, 400))
    resize(size)
    move(pos)
  end

  def write_settings
    settings = QSettings.new('Trolltech', 'Application Example')
    settings.set_value('pos', pos)
    settings.set_value('size', size)
  end

  def maybe_save?
    if @text_edit.document.modified?
      ret = QMessageBox.warning(
        self,
        tr('Application'),
        tr("The document has been modified.\nDo you want to save your changes?"),
        QMessageBox::Yes | QMessageBox::Default,
        QMessageBox::No
      )
      return save if ret == QMessageBox::Yes
    end
    true
  end

  def load_file(file_name)
    file = QFile.new(file_name)
    unless file.open(QFile::ReadOnly | QFile::Text)
      QMessageBox.warning(self, tr('Application'),
                          tr(format("Cannot read file %s:\n%s.", file_name, file.error_string)))
      return
    end

    inf = QTextStream.new(file)
    QApplication.set_override_cursor(QCursor.new(Qt::WaitCursor))
    @text_edit.set_plain_text(inf.read_all)
    QApplication.restore_override_cursor

    set_current_file(file_name)
    status_bar.show_message(tr('File loaded'), 2000)
  end

  def save_file(file_name)
    file = QFile.new(file_name)
    unless file.open(QFile::WriteOnly | QFile::Text)
      QMessageBox.warning(self, tr('Application'),
                          tr(format("Cannot write file %s:\n%s.", file_name, file.error_string)))
      return false
    end

    outf = QTextStream.new(file)
    QApplication.set_override_cursor(QCursor.new(Qt::WaitCursor))
    outf << @text_edit.to_plain_text
    outf.flush
    QApplication.restore_override_cursor

    set_current_file(file_name)
    status_bar.show_message(tr('File saved'), 2000)
    true
  end

  def set_current_file(file_name)
    @current_file = file_name
    @text_edit.document.set_modified(false)
    set_window_modified(false)

    show_name =
      if @current_file.empty?
        'untitled.txt'
      else
        stripped_name(@current_file)
      end

    set_window_title(tr(format('%s[*] - %s', show_name, tr('Application'))))
  end

  def stripped_name(full_file_name)
    QFileInfo.new(full_file_name).file_name
  end
end
