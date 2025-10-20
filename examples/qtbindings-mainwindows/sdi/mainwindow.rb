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

  attr_reader :current_file, :is_untitled

  @@sequence_number = 0
  @@windows = {}

  def initialize(file_name = '')
    super()
    @@windows[self] = self

    init

    if file_name.empty?
      set_current_file('')
    else
      load_file(file_name)
    end
  end

  def close_event(event)
    if maybe_save
      write_settings
      event.accept
      @@windows.delete(self)
    else
      event.ignore
    end
  end

  def new_file
    other = MainWindow.new
    other.move(x + 40, y + 40)
    other.show
  end

  def open
    file_name = QFileDialog.get_open_file_name(self)
    return if file_name.nil?

    existing = find_main_window(file_name)
    if existing
      existing.show
      existing.raise
      existing.activate_window
      return
    end

    if @is_untitled && @text_edit.document.empty? && !window_modified?
      load_file(file_name)
    else
      other = MainWindow.new(file_name)
      if other.is_untitled
        other.dispose
        return
      end
      other.move(x + 40, y + 40)
      other.show
    end
  end

  def save
    return save_as if @is_untitled

    save_file(@current_file)
  end

  def save_as
    file_name = QFileDialog.get_save_file_name(self, tr('Save As'), @current_file)
    return false if file_name.nil?

    save_file(file_name)
  end

  def about
    QMessageBox.about(self, tr('About SDI'),
                      tr('The <b>SDI</b> example demonstrates how to write single document interface applications using Qt.'))
  end

  def document_was_modified
    set_window_modified(true)
  end

  def init
    @is_untitled = true
    @text_edit = QTextEdit.new
    set_central_widget(@text_edit)

    create_actions
    create_menu
    create_tool_bars
    create_status_bar

    read_settings

    @text_edit.document.contents_changed.connect(self, :document_was_modified)
  end

  def create_actions
    @new_act = QAction.new(QIcon.new('images/new.png'), tr('&New'), self)
    @new_act.set_shortcut QKeySequence.new(tr('Ctrl+N'))
    @new_act.set_status_tip tr('Create a file.new')
    @new_act.triggered.connect(self, :new_file)

    @open_act = QAction.new(QIcon.new('images/open.png'), tr('&Open...'), self)
    @open_act.set_shortcut QKeySequence.new(tr('Ctrl+O'))
    @open_act.set_status_tip tr('Open an existing file')
    @open_act.triggered.connect(self, :open)

    @save_act = QAction.new(QIcon.new('images/save.png'), tr('&Save'), self)
    @save_act.set_shortcut QKeySequence.new(tr('Ctrl+S'))
    @save_act.set_status_tip tr('Save the document to disk')
    @save_act.triggered.connect(self, :save)

    @save_as_act = QAction.new(tr('Save &As...'), self)
    @save_as_act.set_status_tip tr('Save the document under a name.new')
    @save_as_act.triggered.connect(self, :save_as)

    @close_act = QAction.new(tr('&Close'), self)
    @close_act.set_shortcut QKeySequence.new(tr('Ctrl+W'))
    @close_act.set_status_tip tr('Close self window')
    @close_act.triggered.connect(self, :close)

    @exit_act = QAction.new(tr('E&xit'), self)
    @exit_act.set_shortcut QKeySequence.new(tr('Ctrl+Q'))
    @exit_act.set_status_tip tr('Exit the application')
    @exit_act.triggered.connect($qApp, :close_all_windows)

    @cut_act = QAction.new(QIcon.new('images/cut.png'), tr('Cu&t'), self)
    @cut_act.set_shortcut QKeySequence.new(tr('Ctrl+X'))
    @cut_act.set_status_tip(tr("Cut the current selection's contents to the clipboard"))
    @cut_act.triggered.connect(@text_edit, :cut)

    @copy_act = QAction.new(QIcon.new('images/copy.png'), tr('&Copy'), self)
    @copy_act.set_shortcut QKeySequence.new(tr('Ctrl+C'))
    @copy_act.set_status_tip(tr("Copy the current selection's contents to the clipboard"))
    @copy_act.triggered.connect(@text_edit, :copy)

    @paste_act = QAction.new(QIcon.new('images/paste.png'), tr('&Paste'), self)
    @paste_act.set_shortcut QKeySequence.new(tr('Ctrl+V'))
    @paste_act.set_status_tip(tr("Paste the clipboard's contents into the current selection"))
    @paste_act.triggered.connect(@text_edit, :paste)

    @about_act = QAction.new(tr('&About'), self)
    @about_act.set_status_tip tr("Show the application's About box")
    @about_act.triggered.connect(self, :about)

    @about_qt_act = QAction.new(tr('About &Qt'), self)
    @about_qt_act.set_status_tip tr("Show the Qt library's About box")
    @about_qt_act.triggered.connect($qApp, :about_qt)

    @cut_act.set_enabled false
    @copy_act.set_enabled false
    @text_edit.copy_available.connect(@cut_act, :set_enabled)
    @text_edit.copy_available.connect(@copy_act, :set_enabled)
  end

  def create_menu
    @file_menu = menu_bar.add_menu(tr('&File'))
    @file_menu.add_action(@new_act)
    @file_menu.add_action(@open_act)
    @file_menu.add_action(@save_act)
    @file_menu.add_action(@save_as_act)
    @file_menu.add_separator
    @file_menu.add_action(@close_act)
    @file_menu.add_action(@exit_act)

    @edit_menu = menu_bar.add_menu(tr('&Edit'))
    @edit_menu.add_action(@cut_act)
    @edit_menu.add_action(@copy_act)
    @edit_menu.add_action(@paste_act)

    menu_bar.add_separator

    @help_menu = menu_bar.add_menu(tr('&Help'))
    @help_menu.add_action(@about_act)
    @help_menu.add_action(@about_qt_act)
  end

  def create_tool_bars
    @file_tool_bar = add_tool_bar(tr('File'))
    @file_tool_bar.add_action(@new_act)
    @file_tool_bar.add_action(@open_act)
    @file_tool_bar.add_action(@save_act)

    @edit_tool_bar = add_tool_bar(tr('Edit'))
    @edit_tool_bar.add_action(@cut_act)
    @edit_tool_bar.add_action(@copy_act)
    @edit_tool_bar.add_action(@paste_act)
  end

  def create_status_bar
    status_bar.show_message(tr('Ready'))
  end

  def read_settings
    settings = QSettings.new('Trolltech', 'SDI Example')
    pos = settings.value('pos', QPoint.new(200, 200))
    size = settings.value('size', QSize.new(400, 400))
    move(pos)
    resize(size)
  end

  def write_settings
    settings = QSettings.new('Trolltech', 'SDI Example')
    settings.set_value('pos', pos)
    settings.set_value('size', size)
  end

  def maybe_save
    if @text_edit.document.modified?
      ret = QMessageBox.warning(
        self,
        tr('SDI'),
        tr("The document has been modified.\n Do you want to save your changes?"),
        QMessageBox::Yes | QMessageBox::Default,
        QMessageBox::No
      )
      return if ret == QMessageBox::Yes
    end
    true
  end

  def load_file(file_name)
    file = QFile.new(file_name)
    unless file.open(QFile::ReadOnly | QFile::Text)
      QMessageBox.warning(self, tr('SDI'), tr(format("Cannot read file %s:\n%s.", file_name, file.error_string)))
      return
    end

    inf = QTextStream.new(file)
    QApplication.set_override_cursor QCursor.new(Qt::WaitCursor)
    @text_edit.set_plain_text inf.read_all
    QApplication.restore_override_cursor

    set_current_file(file_name)
    status_bar.show_message(tr('File loaded'), 2000)
  end

  def save_file(file_name)
    file = QFile.new(file_name)
    unless file.open(QFile::WriteOnly | QFile::Text)
      QMessageBox.warning(self, tr('SDI'), tr(format("Cannot write file %s:\n%s.", file_name, file.error_string)))
      return
    end

    outf = QTextStream.new(file)
    QApplication.set_override_cursor QCursor.new(Qt::WaitCursor)
    outf << @text_edit.to_plain_text
    outf.flush
    QApplication.restore_override_cursor

    set_current_file(file_name)
    status_bar.show_message(tr('File saved'), 2000)
  end

  def set_current_file(file_name)
    @is_untitled = file_name.empty?
    @current_file = if @is_untitled
                      tr(format('document%d.txt', @@sequence_number += 1))
                    else
                      QFileInfo.new(file_name).canonical_file_path
                    end

    @text_edit.document.set_modified false
    set_window_modified(false)
    set_window_title(tr(format('%s[*] - %s', stripped_name(@current_file), tr('SDI'))))
  end

  def stripped_name(full_file_name)
    QFileInfo.new(full_file_name).file_name
  end

  def find_main_window(file_name)
    canonical_file_path = QFileInfo.new(file_name).canonical_file_path
    @@windows.each_value do |window|
      return window if window.current_file == canonical_file_path
    end
    nil
  end
end
