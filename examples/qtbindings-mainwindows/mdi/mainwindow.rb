# frozen_string_literal: true

require_relative 'mdichild'

class MainWindow < RubyQt6::Bando::QMainWindow
  q_object do
    slot 'new_file()'
    slot 'open()'
    slot 'save()'
    slot 'save_as()'
    slot 'cut()'
    slot 'copy()'
    slot 'paste()'
    slot 'about()'
    slot 'update_menus()'
    slot 'update_window_menu()'
    slot 'create_mdi_child()'
    slot 'swicth_layout_direction()'
    slot 'set_active_sub_window(QObject*)'
  end

  def initialize
    super

    @mdi_area = QMdiArea.new
    @mdi_area.sub_window_activated.connect(self, :update_menus)
    set_central_widget(@mdi_area)

    @window_mapper = QSignalMapper.new(self)
    @window_mapper.mapped_object.connect(self, :set_active_sub_window)

    create_actions
    create_menu
    create_tool_bars
    create_status_bar
    update_menus
    read_settings

    set_window_title(tr('MDI'))
  end

  def close_event(event)
    @mdi_area.close_all_sub_windows
    if active_mdi_child
      event.ignore
    else
      write_settings
      event.accept
    end
  end

  def new_file
    child = create_mdi_child
    child.new_file
    child.show
  end

  def open
    file_name = QFileDialog.get_open_file_name(self)
    return if file_name.nil?

    existing = find_mdi_child(file_name)
    unless existing.nil?
      @mdi_area.set_active_sub_window(existing)
      return
    end

    child = create_mdi_child
    if child.load_file(file_name)
      status_bar.show_message(tr('File loaded'), 2000)
      child.show
    else
      child.close
    end
  end

  def save
    return unless active_mdi_child&.save
    status_bar.show_message(tr('File saved'), 2000)
  end

  def save_as
    return unless active_mdi_child&.save_as
    status_bar.show_message(tr('File saved'), 2000)
  end

  def cut
    return unless active_mdi_child
    active_mdi_child.cut
  end

  def copy
    return unless active_mdi_child
    active_mdi_child.copy
  end

  def paste
    return unless active_mdi_child
    active_mdi_child.paste
  end

  def about
    QMessageBox.about(self, tr('About MDI'), tr('The <b>MDI</b> example demonstrates how to write multiple document interface applications using Qt.'))
  end

  def update_menus
    has_mdi_child = !active_mdi_child.nil?
    @save_act.set_enabled has_mdi_child
    @save_as_act.set_enabled has_mdi_child
    @paste_act.set_enabled has_mdi_child
    @close_act.set_enabled has_mdi_child
    @close_all_act.set_enabled has_mdi_child
    @tile_act.set_enabled has_mdi_child
    @cascade_act.set_enabled has_mdi_child
    @next_act.set_enabled has_mdi_child
    @previous_act.set_enabled has_mdi_child
    @separator_act.set_visible has_mdi_child

    has_selection = active_mdi_child&.text_cursor&.has_selection
    @cut_act.set_enabled has_selection
    @copy_act.set_enabled has_selection
  end

  def update_window_menu
    @window_menu.clear
    @window_menu.add_action(@close_act)
    @window_menu.add_action(@close_all_act)
    @window_menu.add_separator
    @window_menu.add_action(@tile_act)
    @window_menu.add_action(@cascade_act)
    @window_menu.add_separator
    @window_menu.add_action(@next_act)
    @window_menu.add_action(@previous_act)
    @window_menu.add_action(@separator_act)

    windows = @mdi_area.sub_window_list
    @separator_act.set_visible !windows.empty?
    (0...windows.size).each do |i|
      child = windows[i].widget
      text = if i < 9
               tr(format('&%s %s', i + 1, child.user_friendly_current_file))
             else
               tr(format('%s %s', i + 1, child.user_friendly_current_file))
             end
      action = @window_menu.add_action(text)
      action.set_checkable true
      action.set_checked child == active_mdi_child
      action.triggered.connect(@window_mapper, :map)
      @window_mapper.set_mapping(action, child)
    end
  end

  def create_mdi_child
    child = MdiChild.new
    @mdi_area.add_sub_window(child)
    child.copy_available.connect(@cut_act, :set_enabled)
    child.copy_available.connect(@copy_act, :set_enabled)
    child
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

    @exit_act = QAction.new(tr('E&xit'), self)
    @exit_act.set_shortcut QKeySequence.new(tr('Ctrl+Q'))
    @exit_act.set_status_tip tr('Exit the application')
    @exit_act.triggered.connect($qApp, :close_all_windows)

    @cut_act = QAction.new(QIcon.new('images/cut.png'), tr('Cu&t'), self)
    @cut_act.set_shortcut QKeySequence.new(tr('Ctrl+X'))
    @cut_act.set_status_tip(tr("Cut the current selection's contents to the clipboard"))
    @cut_act.triggered.connect(self, :cut)

    @copy_act = QAction.new(QIcon.new('images/copy.png'), tr('&Copy'), self)
    @copy_act.set_shortcut QKeySequence.new(tr('Ctrl+C'))
    @copy_act.set_status_tip(tr("Copy the current selection's contents to the clipboard"))
    @copy_act.triggered.connect(self, :copy)

    @paste_act = QAction.new(QIcon.new('images/paste.png'), tr('&Paste'), self)
    @paste_act.set_shortcut QKeySequence.new(tr('Ctrl+V'))
    @paste_act.set_status_tip(tr("Paste the clipboard's contents into the current selection"))
    @paste_act.triggered.connect(self, :paste)

    @close_act = QAction.new(tr('Cl&ose'), self)
    @close_act.set_shortcut QKeySequence.new(tr('Ctrl+F4'))
    @close_act.set_status_tip tr('Close the active window')
    @close_act.triggered.connect(@mdi_area, :close_active_sub_window)

    @close_all_act = QAction.new(tr('Close &All'), self)
    @close_all_act.set_status_tip tr('Close all the windows')
    @close_all_act.triggered.connect(@mdi_area, :close_all_sub_windows)

    @tile_act = QAction.new(tr('&Tile'), self)
    @tile_act.set_status_tip tr('Tile the windows')
    @tile_act.triggered.connect(@mdi_area, :tile_sub_windows)

    @cascade_act = QAction.new(tr('&Cascade'), self)
    @cascade_act.set_status_tip tr('Cascade the windows')
    @cascade_act.triggered.connect(@mdi_area, :cascade_sub_windows)

    @next_act = QAction.new(tr('Ne&xt'), self)
    @next_act.set_shortcut QKeySequence.new(tr('Ctrl+F6'))
    @next_act.set_status_tip tr('Move the focus to the next window')
    @next_act.triggered.connect(@mdi_area, :activate_next_sub_window)

    @previous_act = QAction.new(tr('Pre&vious'), self)
    @previous_act.set_shortcut QKeySequence.new(tr('Ctrl+Shift+F6'))
    @previous_act.set_status_tip(tr('Move the focus to the previous window'))
    @previous_act.triggered.connect(@mdi_area, :activate_previous_sub_window)

    @separator_act = QAction.new(self)
    @separator_act.set_separator true

    @about_act = QAction.new(tr('&About'), self)
    @about_act.set_status_tip tr("Show the application's About box")
    @about_act.triggered.connect(self, :about)

    @about_qt_act = QAction.new(tr('About &Qt'), self)
    @about_qt_act.set_status_tip tr("Show the Qt library's About box")
    @about_qt_act.triggered.connect($qApp, :about_qt)
  end

  def create_menu
    @file_menu = menu_bar.add_menu(tr('&File'))
    @file_menu.add_action(@new_act)
    @file_menu.add_action(@open_act)
    @file_menu.add_action(@save_act)
    @file_menu.add_action(@save_as_act)
    @file_menu.add_separator
    action = @file_menu.add_action(tr('Switch layout direction'))
    action.triggered.connect(self, :swicth_layout_direction)
    @file_menu.add_action(@exit_act)

    @edit_menu = menu_bar.add_menu(tr('&Edit'))
    @edit_menu.add_action(@cut_act)
    @edit_menu.add_action(@copy_act)
    @edit_menu.add_action(@paste_act)

    @window_menu = menu_bar.add_menu(tr('&Window'))
    update_window_menu
    @window_menu.about_to_show.connect(self, :update_window_menu)

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
    settings = QSettings.new('Trolltech', 'MDI Example')
    pos = settings.value('pos', QPoint.new(200, 200))
    size = settings.value('size', QSize.new(400, 400))
    move(pos)
    resize(size)
  end

  def write_settings
    settings = QSettings.new('Trolltech', 'MDI Example')
    settings.set_value('pos', pos)
    settings.set_value('size', size)
  end

  def active_mdi_child
    return @mdi_area.active_sub_window.widget if @mdi_area.active_sub_window
    nil
  end

  def find_mdi_child(file_name)
    canonical_file_path = QFileInfo.new(file_name).canonical_file_path

    @mdi_area.sub_window_list.each do |window|
      mdi_child = window.widget
      return window if mdi_child.current_file == canonical_file_path
    end
    nil
  end
end
