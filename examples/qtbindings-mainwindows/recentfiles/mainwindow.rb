# frozen_string_literal: true

class MainWindow < RubyQt6::Bando::QMainWindow
  MAX_RECENT_FILES = 5

  q_object do
    slot 'new_file()'
    slot 'open()'
    slot 'save()'
    slot 'save_as()'
    slot 'open_recent_file(QString)'
    slot 'about()'
  end

  @@main_windows = {}
  def initialize(parent = nil)
    super

    @@main_windows[self] = self

    @text_edit = QTextEdit.new
    @recent_file_actions = []

    set_central_widget(@text_edit)
    create_actions
    create_menu

    # set_attribute(Qt::WA_DeleteOnClose)
    set_window_title(tr('Recent Files'))
    resize(400, 300)
  end

  def new_file
    other = MainWindow.new
    other.show
  end

  def open
    file_name = QFileDialog.get_open_file_name(self)
    return if file_name.nil?

    load_file(file_name)
  end

  def save
    if @current_file.nil?
      save_as
    else
      save_file(@current_file)
    end
  end

  def save_as
    file_name = QFileDialog.get_save_file_name(self)
    return if file_name.nil?

    if QFile.exists(file_name)
      ret = QMessageBox.warning(
        self,
        tr('Recent Files'),
        tr("File %s already exists.\nDo you want to overwrite it?" % QDir.to_native_separators(file_name)),
        QMessageBox::Yes | QMessageBox::Default,
        QMessageBox::No
      )
      return if ret == QMessageBox::No
    end

    save_file(file_name)
  end

  def open_recent_file(file_name)
    load_file(file_name)
  end

  def about
    QMessageBox.about(
      self,
      tr('About Recent Files'),
      tr('The <b>Recent Files</b> example demonstrates how to provide a recently used file menu in a Qt application.')
    )
  end

  def create_actions
    @new_action = QAction.new(QIcon.new, tr('&New'), self)
    @new_action.set_shortcut QKeySequence.new(tr('Ctrl+N'))
    @new_action.set_status_tip tr('Create a file.new')
    @new_action.triggered.connect(self, :new_file)

    @open_action = QAction.new(QIcon.new, tr('&Open...'), self)
    @open_action.set_shortcut QKeySequence.new(tr('Ctrl+O'))
    @open_action.set_status_tip tr('Open an existing file')
    @open_action.triggered.connect(self, :open)

    @save_action = QAction.new(QIcon.new, tr('&Save'), self)
    @save_action.set_shortcut QKeySequence.new(tr('Ctrl+S'))
    @save_action.set_status_tip tr('Save the document to disk')
    @save_action.triggered.connect(self, :save)

    @save_as_act = QAction.new(QIcon.new, tr('Save &As...'), self)
    @save_as_act.set_status_tip tr('Save the document under a name.new')
    @save_as_act.triggered.connect(self, :save_as)

    @recent_file_actions_mapper = QSignalMapper.new(self)
    (0...MAX_RECENT_FILES).each do |i|
      @recent_file_actions[i] = QAction.new(QIcon.new, '', self)
      @recent_file_actions[i].set_visible false
      @recent_file_actions[i].triggered.connect(@recent_file_actions_mapper, :map)
    end
    @recent_file_actions_mapper.mapped_string.connect(self, :open_recent_file)

    @exit_action = QAction.new(QIcon.new, tr('&Close'), self)
    @exit_action.set_shortcut QKeySequence.new(tr('Ctrl+W'))
    @exit_action.set_status_tip tr('Close self window')
    @exit_action.triggered.connect(self, :close)

    @exit_action = QAction.new(QIcon.new, tr('E&xit'), self)
    @exit_action.set_shortcut QKeySequence.new(tr('Ctrl+Q'))
    @exit_action.set_status_tip tr('Exit the application')
    @exit_action.triggered.connect($qApp, :close_all_windows)

    @about_action = QAction.new(QIcon.new, tr('&About'), self)
    @about_action.set_status_tip tr("Show the application's About box")
    @about_action.triggered.connect(self, :about)

    @about_qt_action = QAction.new(QIcon.new, tr('About &Qt'), self)
    @about_qt_action.set_status_tip tr("Show the Qt library's About box")
    @about_qt_action.triggered.connect($qApp, :about_qt)
  end

  def create_menu
    @file_menu = menu_bar.add_menu(tr('&File'))
    @file_menu.add_action(@new_action)
    @file_menu.add_action(@open_action)
    @file_menu.add_action(@save_action)
    @file_menu.add_action(@save_as_act)

    @separator_act = @file_menu.add_separator
    (0...MAX_RECENT_FILES).each { |i| @file_menu.add_action(@recent_file_actions[i]) }
    update_recent_file_actions

    @file_menu.add_separator
    @file_menu.add_action(@exit_action)

    menu_bar.add_separator

    @help_menu = menu_bar.add_menu(tr('&Help'))
    @help_menu.add_action(@about_action)
    @help_menu.add_action(@about_qt_action)
  end

  def load_file(file_name)
    file = QFile.new(file_name)
    unless file.open(QFile::ReadOnly | QFile::Text)
      QMessageBox.warning(self, tr('Recent Files'),
                          tr(format("Cannot read file %s:\n%s.", file_name, file.error_string)))
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
      QMessageBox.warning(self, tr('Recent Files'),
                          tr(format("Cannot write file %s:\n%s.", file_name, file.error_string)))
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
    @current_file = file_name
    if @current_file.nil?
      set_window_title(tr('Recent Files'))
    else
      set_window_title(tr(format('%s - %s', stripped_name(@current_file), tr('Recent Files'))))
    end

    settings = QSettings.new('Trolltech', 'Recent Files Example')
    files = settings.value('recentFileList', QStringList.new)
    files.delete(file_name)
    files.insert(0, file_name)
    files.pop while files.length > MAX_RECENT_FILES
    settings.set_value('recentFileList', files)

    @@main_windows.each_value(&:update_recent_file_actions)
  end

  def update_recent_file_actions
    settings = QSettings.new('Trolltech', 'Recent Files Example')
    files = settings.value('recentFileList', QStringList.new)

    num_recent_files = [files.length, MAX_RECENT_FILES].min
    (0...num_recent_files).each do |i|
      text = tr(format('&%s %s', i + 1, stripped_name(files[i])))
      @recent_file_actions[i].set_text text
      @recent_file_actions[i].set_visible true
      @recent_file_actions_mapper.set_mapping(@recent_file_actions[i], files[i])
    end
    (num_recent_files...MAX_RECENT_FILES).each do |j|
      @recent_file_actions[j].set_visible false
    end

    @separator_act.set_visible num_recent_files.positive?
  end

  def stripped_name(full_file_name)
    QFileInfo.new(full_file_name).file_name
  end

  def close_event(event)
    @@main_windows.delete(self)
    event.accept
  end
end
