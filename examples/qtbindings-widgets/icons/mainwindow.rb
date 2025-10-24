# frozen_string_literal: true

require_relative 'iconpreviewarea'
require_relative 'iconsizespinbox'
require_relative 'imagedelegate'

class MainWindow < RubyQt6::Bando::QMainWindow
  q_object do
    slot 'about()'
    slot 'change_style(bool)'
    slot 'change_size()'
    slot 'change_icon()'
    slot 'add_image()'
    slot 'remove_all_images()'
  end

  def initialize
    super

    @central_widget = QWidget.new
    set_central_widget(@central_widget)

    create_preview_group_box
    create_images_group_box
    create_icon_size_group_box

    create_actions
    create_menus
    create_context_menu

    main_layout = QGridLayout.new
    main_layout.add_widget(@images_group_box, 0, 0)
    main_layout.add_widget(@icon_size_group_box, 1, 0)
    main_layout.add_widget(@preview_group_box, 0, 1, 2, 1)
    @central_widget.set_layout main_layout

    set_window_title(tr('Icons'))
    check_current_style
    @other_radio_button.click
    resize(860, 400)
  end

  def about
    QMessageBox.about(
      self,
      tr('About Icons'),
      tr('The <b>Icons</b> example illustrates how Qt renders an icon in ' \
         'different modes (active, normal, and disabled) and states (on ' \
         'and off) based on a set of images.')
    )
  end

  def change_style(checked)
    return unless checked

    action = sender
    style = QStyleFactory.create(action.data.value)
    QApplication.set_style style

    @small_radio_button.set_text tr(format('Small (%d x %d', style.pixel_metric(QStyle::PM_SmallIconSize),
                                           style.pixel_metric(QStyle::PM_SmallIconSize)))
    @large_radio_button.set_text tr(format('Large (%d x %d', style.pixel_metric(QStyle::PM_LargeIconSize),
                                           style.pixel_metric(QStyle::PM_LargeIconSize)))
    @tool_bar_radio_button.set_text tr(format('Toolbars (%d x %d', style.pixel_metric(QStyle::PM_ToolBarIconSize),
                                              style.pixel_metric(QStyle::PM_ToolBarIconSize)))
    @list_view_radion_button.set_text tr(format('List views (%d x %d', style.pixel_metric(QStyle::PM_ListViewIconSize),
                                                style.pixel_metric(QStyle::PM_ListViewIconSize)))
    @icon_view_radio_button.set_text tr(format('Icon views (%d x %d', style.pixel_metric(QStyle::PM_IconViewIconSize),
                                               style.pixel_metric(QStyle::PM_IconViewIconSize)))

    change_size
  end

  def change_size
    if @other_radio_button.checked?
      extent = @other_spin_box.value
    else
      metric = if @small_radio_button.checked?
                 QStyle::PM_SmallIconSize
               elsif @large_radio_button.checked?
                 QStyle::PM_LargeIconSize
               elsif @tool_bar_radio_button.checked?
                 QStyle::PM_ToolBarIconSize
               elsif @list_view_radion_button.checked?
                 QStyle::PM_ListViewIconSize
               else
                 QStyle::PM_IconViewIconSize
               end
      extent = QApplication.style.pixel_metric(metric)
    end

    @preview_area.set_size QSize.new(extent, extent)
    @other_spin_box.set_enabled @other_radio_button.checked?
  end

  def change_icon
    icon = QIcon.new
    (0...@images_table.row_count).each do |row|
      item0 = @images_table.item(row, 0)
      item1 = @images_table.item(row, 1)
      item2 = @images_table.item(row, 2)
      next unless item0.check_state == Qt::Checked

      mode =
        if item1.text == tr('Normal')
          QIcon::Normal
        elsif item1.text == tr('Active')
          QIcon::Active
        else
          QIcon::Disabled
        end

      state =
        if item2.text == tr('On')
          QIcon::On
        else
          QIcon::Off
        end

      file_name = item0.data(Qt::UserRole).value
      image = QImage.new(file_name)
      icon.add_pixmap(QPixmap.from_image(image), mode, state) unless image.nil?
    end
    @preview_area.set_icon icon
  end

  def add_image
    file_names = QFileDialog.get_open_file_names(self, tr('Open Images'), '',
                                                 tr('Images (*.png *.xpm *.jpg);; All Files (*)'))
    return if file_names.nil?

    file_names.each do |file_name|
      row = @images_table.row_count
      @images_table.set_row_count row + 1

      image_name = QFileInfo.new(file_name).base_name
      item0 = QTableWidgetItem.new(image_name)
      item0.set_data(Qt::UserRole, QVariant.new(file_name))
      item0.set_flags(item0.flags & ~Qt::ItemIsEditable)

      item1 = QTableWidgetItem.new(tr('Normal'))
      item2 = QTableWidgetItem.new(tr('Off'))

      if @guess_mode_state_act.checked?
        if file_name.contains('_act')
          item1.set_text tr('Active')
        elsif file_name.contains('_dis')
          item1.set_text tr('Disabled')
        end

        item2.set_text tr('On') if file_name.contains('_on')
      end

      @images_table.set_item(row, 0, item0)
      @images_table.set_item(row, 1, item1)
      @images_table.set_item(row, 2, item2)
      @images_table.open_persistent_editor(item1)
      @images_table.open_persistent_editor(item2)

      item0.set_check_state Qt::Checked
    end
  end

  def remove_all_images
    @images_table.set_row_count(0)
    change_icon
  end

  def create_preview_group_box
    @preview_group_box = QGroupBox.new(tr('Preview'))
    @preview_area = IconPreviewArea.new

    layout = QVBoxLayout.new
    layout.add_widget(@preview_area)
    @preview_group_box.set_layout layout
  end

  def create_images_group_box
    @images_group_box = QGroupBox.new(tr('Images'))
    @images_group_box.set_size_policy(QSizePolicy::Expanding, QSizePolicy::Expanding)

    labels = QStringList.new
    labels << tr('Image') << tr('Mode') << tr('State')

    @images_table = QTableWidget.new(0, 0)
    @images_table.set_size_policy(QSizePolicy::Expanding, QSizePolicy::Ignored)
    @images_table.set_selection_mode QAbstractItemView::NoSelection
    @images_table.set_column_count 3
    @images_table.set_horizontal_header_labels labels
    @images_table.set_item_delegate ImageDelegate.new(self)

    @images_table.horizontal_header.resize_section(0, 160)
    @images_table.horizontal_header.resize_section(1, 80)
    @images_table.horizontal_header.resize_section(2, 80)
    @images_table.vertical_header.hide
    @images_table.item_changed.connect(self, :change_icon)

    layout = QVBoxLayout.new
    layout.add_widget(@images_table)
    @images_group_box.set_layout layout
  end

  def create_icon_size_group_box
    @icon_size_group_box = QGroupBox.new(tr('Icon Size'))

    @small_radio_button = QRadioButton.new
    @large_radio_button = QRadioButton.new
    @tool_bar_radio_button = QRadioButton.new
    @list_view_radion_button = QRadioButton.new
    @icon_view_radio_button = QRadioButton.new
    @other_radio_button = QRadioButton.new(tr('Other:'))

    @other_spin_box = IconSizeSpinBox.new
    @other_spin_box.set_range 8, 128
    @other_spin_box.set_value 64

    @tool_bar_radio_button.toggled.connect(self, :change_size)
    @list_view_radion_button.toggled.connect(self, :change_size)
    @icon_view_radio_button.toggled.connect(self, :change_size)
    @small_radio_button.toggled.connect(self, :change_size)
    @large_radio_button.toggled.connect(self, :change_size)
    @other_radio_button.toggled.connect(self, :change_size)
    @other_spin_box.value_changed.connect(self, :change_size)

    other_size_layout = QHBoxLayout.new
    other_size_layout.add_widget(@other_radio_button)
    other_size_layout.add_widget(@other_spin_box)

    layout = QGridLayout.new
    layout.add_widget(@small_radio_button, 0, 0)
    layout.add_widget(@large_radio_button, 1, 0)
    layout.add_widget(@tool_bar_radio_button, 2, 0)
    layout.add_widget(@list_view_radion_button, 0, 1)
    layout.add_widget(@icon_view_radio_button, 1, 1)
    layout.add_layout(other_size_layout, 2, 1)
    @icon_size_group_box.set_layout layout
  end

  def create_actions
    @add_image_act = QAction.new(tr('&Add Image...'), self)
    @add_image_act.set_shortcut QKeySequence.new(tr('Ctrl+A'))
    @add_image_act.triggered.connect(self, :add_image)

    @remove_all_images_act = QAction.new(tr('&Remove All Images'), self)
    @remove_all_images_act.set_shortcut QKeySequence.new(tr('Ctrl+R'))
    @remove_all_images_act.triggered.connect(self, :remove_all_images)

    @exit_act = QAction.new(tr('&Quit'), self)
    @exit_act.set_shortcut QKeySequence.new(tr('Ctrl+Q'))
    @exit_act.triggered.connect(self, :close)

    @style_action_group = QActionGroup.new(self)

    style_names = QStyleFactory.keys
    style_names.each do |style_name|
      action = QAction.new(@style_action_group)
      action.set_text tr('%s Style' % style_name)
      action.set_data QVariant.new(style_name)
      action.set_checkable true
      action.triggered.connect(self, :change_style)
    end

    @guess_mode_state_act = QAction.new(tr('&Guess Image Mode/State'), self)
    @guess_mode_state_act.set_checkable true
    @guess_mode_state_act.set_checked true

    @about_act = QAction.new(tr('&About'), self)
    @about_act.triggered.connect(self, :about)

    @about_qt_act = QAction.new(tr('About &Qt'), self)
    @about_qt_act.triggered.connect($qApp, :about_qt)
  end

  def create_menus
    @file_menu = menu_bar.add_menu(tr('&File'))
    @file_menu.add_action(@add_image_act)
    @file_menu.add_action(@remove_all_images_act)
    @file_menu.add_separator
    @file_menu.add_action(@exit_act)

    @view_menu = menu_bar.add_menu(tr('&View'))

    @style_action_group.actions.each do |action|
      @view_menu.add_action(action)
    end
    @view_menu.add_separator
    @view_menu.add_action(@guess_mode_state_act)

    menu_bar.add_separator

    @help_menu = menu_bar.add_menu(tr('&Help'))
    @help_menu.add_action(@about_act)
    @help_menu.add_action(@about_qt_act)
  end

  def create_context_menu
    @images_table.set_context_menu_policy Qt::ActionsContextMenu
    @images_table.add_action(@add_image_act)
    @images_table.add_action(@remove_all_images_act)
  end

  def check_current_style
    @style_action_group.actions.each do |action|
      style_name = action.data.value
      candidate = QStyleFactory.create(style_name)
      next unless candidate.class._qmetaobject == QApplication.style.class._qmetaobject

      action.trigger
      return
    end
  end
end
