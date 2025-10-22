# frozen_string_literal: true

class Window < RubyQt6::Bando::QWidget
  q_object do
    slot 'set_icon(int)'
    slot 'icon_activated(QSystemTrayIcon::ActivationReason)'
    slot 'show_message()'
    slot 'message_clicked()'
  end

  def initialize(parent = nil)
    super(parent)

    create_icon_group_box
    create_message_group_box

    @icon_label.set_minimum_width @duration_label.size_hint.width

    create_actions
    create_tray_icon

    @show_message_button.clicked.connect(self, :show_message)
    @show_icon_check_box.toggled.connect(@tray_icon, :set_visible)
    @icon_combo_box.current_index_changed.connect(self, :set_icon)
    @tray_icon.message_clicked.connect(self, :message_clicked)
    @tray_icon.activated.connect(self, :icon_activated)

    set_layout(QVBoxLayout.new.tap do |m|
      m.add_widget(@icon_group_box)
      m.add_widget(@message_group_box)
    end)

    @icon_combo_box.set_current_index 1
    @tray_icon.show

    set_window_title(tr('Systray'))
    resize(400, 300)
  end

  def set_visible(visible)
    @minimize_action.set_enabled visible
    @maximize_action.set_enabled !visible
    @restore_action.set_enabled !visible
    super(visible)
  end

  def close_event(event)
    return unless @tray_icon.visible?

    QMessageBox.information(
      self,
      tr('Systray'),
      tr('The program will keep running in the ' \
         'system tray. To terminate the program, ' \
         'choose <b>Quit</b> in the context menu ' \
         "that pops up when clicking self program's " \
         'entry in the system tray.')
    )
    hide
    event.ignore
  end

  def set_icon(index)
    icon = @icon_combo_box.item_icon(index)
    @tray_icon.set_icon icon
    set_window_icon(icon)
    @tray_icon.set_tool_tip @icon_combo_box.item_text(index)
  end

  def icon_activated(reason)
    case reason
    when QSystemTrayIcon::Trigger
    when QSystemTrayIcon::DoubleClick
      @icon_combo_box.set_current_index (icon_combo_box.current_index + 1) % @icon_combo_box.length
    when QSystemTrayIcon::MiddleClick
      show_message
    end
  end

  def show_message
    icon = @type_combo_box.item_data(@type_combo_box.current_index).value
    @tray_icon.show_message(@title_edit.text, @body_edit.to_plain_text, icon, @duration_spin_box.value * 1000)
  end

  def message_clicked
    QMessageBox.information(
      nil,
      tr('Systray'),
      tr("Sorry, I already gave what help I could.\n Maybe you should try asking a human?")
    )
  end

  def create_icon_group_box
    @icon_group_box = QGroupBox.new(tr('Tray Icon'))
    @icon_label = QLabel.new('Icon:')

    @icon_combo_box = QComboBox.new
    @icon_combo_box.add_item(QIcon.new(':/images/bad.svg'), tr('Bad'))
    @icon_combo_box.add_item(QIcon.new(':/images/heart.svg'), tr('Heart'))
    @icon_combo_box.add_item(QIcon.new(':/images/trash.svg'), tr('Trash'))

    @show_icon_check_box = QCheckBox.new(tr('Show icon'))
    @show_icon_check_box.set_checked true

    @icon_group_box.set_layout(QHBoxLayout.new.tap do |l|
      l.add_widget(@icon_label)
      l.add_widget(@icon_combo_box)
      l.add_stretch
      l.add_widget(@show_icon_check_box)
    end)
  end

  def create_message_group_box
    @message_group_box = QGroupBox.new(tr('Balloon Message'))

    @type_label = QLabel.new(tr('Type:'))

    @type_combo_box = QComboBox.new
    @type_combo_box.add_item(tr('None'), QVariant.new(QSystemTrayIcon::NoIcon))
    @type_combo_box.add_item(style.standard_icon(QStyle::SP_MessageBoxInformation), tr('Information'), QVariant.new(QSystemTrayIcon::Information))
    @type_combo_box.add_item(style.standard_icon(QStyle::SP_MessageBoxWarning), tr('Warning'), QVariant.new(QSystemTrayIcon::Warning))
    @type_combo_box.add_item(style.standard_icon(QStyle::SP_MessageBoxCritical), tr('Critical'), QVariant.new(QSystemTrayIcon::Critical))
    @type_combo_box.set_current_index 1

    @duration_label = QLabel.new(tr('Duration:'))

    @duration_spin_box = QSpinBox.new.tap do |s|
      s.set_range(5, 60)
      s.set_suffix ' s'
      s.set_value 15
    end

    @duration_warning_label = QLabel.new(tr('(some systems might ignore self ' \
                                         'hint)'))
    @duration_warning_label.set_indent 10

    @title_label = QLabel.new(tr('Title:'))

    @title_edit = QLineEdit.new(tr('Cannot connect to network'))

    @body_label = QLabel.new(tr('Body:'))

    @body_edit = QTextEdit.new
    @body_edit.set_plain_text(tr("Don't believe me. Honestly, I don't have a clue.\nClick self balloon for details."))

    @show_message_button = QPushButton.new(tr('Show Message'))
    @show_message_button.set_default true

    @message_group_box.set_layout(QGridLayout.new.tap do |m|
      m.add_widget(@type_label, 0, 0)
      m.add_widget(@type_combo_box, 0, 1, 1, 2)
      m.add_widget(@duration_label, 1, 0)
      m.add_widget(@duration_spin_box, 1, 1)
      m.add_widget(@duration_warning_label, 1, 2, 1, 3)
      m.add_widget(@title_label, 2, 0)
      m.add_widget(@title_edit, 2, 1, 1, 4)
      m.add_widget(@body_label, 3, 0)
      m.add_widget(@body_edit, 3, 1, 2, 4)
      m.add_widget(@show_message_button, 5, 4)
      m.set_column_stretch(3, 1)
      m.set_row_stretch(4, 1)
    end)
  end

  def create_actions
    @minimize_action = QAction.new(tr('Mi&nimize'), self)
    @minimize_action.triggered.connect(self, :hide)

    @maximize_action = QAction.new(tr('Ma&ximize'), self)
    @maximize_action.triggered.connect(self, :show_maximized)

    @restore_action = QAction.new(tr('&Restore'), self)
    @restore_action.triggered.connect(self, :show)

    @quit_action = QAction.new(tr('&Quit'), self)
    @quit_action.triggered.connect($qApp, :quit)
  end

  def create_tray_icon
    @tray_icon_menu = QMenu.new('', self).tap do |t|
      t.add_action(@minimize_action)
      t.add_action(@maximize_action)
      t.add_action(@restore_action)
      t.add_separator
      t.add_action(@quit_action)
    end
    @tray_icon = QSystemTrayIcon.new(self)
    @tray_icon.set_context_menu @tray_icon_menu
  end
end
