# frozen_string_literal: true

require_relative 'previewwindow'

class ControllerWindow < RubyQt6::Bando::QWidget
  q_object do
    slot 'update_preview()'
  end

  def initialize(parent = nil)
    super(parent)

    @preview_window = PreviewWindow.new(self)

    create_type_group_box
    create_hints_group_box

    @quit_button = QPushButton.new(tr('&Quit'))
    @quit_button.clicked.connect($qApp, :quit)

    bottom_layout = QHBoxLayout.new
    bottom_layout.add_stretch
    bottom_layout.add_widget(@quit_button)

    main_layout = QVBoxLayout.new
    main_layout.add_widget(@type_group_box)
    main_layout.add_widget(@hints_group_box)
    main_layout.add_layout(bottom_layout)

    set_layout(main_layout)
    set_window_title(tr('Window Flags'))
    update_preview
  end

  def update_preview
    flags = Qt::WindowType.new

    if @window_radio_button.checked?
      flags = Qt::Window
    elsif @dialog_radio_button.checked?
      flags = Qt::Dialog
    elsif @sheet_radion_button.checked?
      flags = Qt::Sheet
    elsif @drawer_radio_button.checked?
      flags = Qt::Drawer
    elsif @popup_radio_button.checked?
      flags = Qt::Popup
    elsif @tool_radio_button.checked?
      flags = Qt::Tool
    elsif @tool_tip_radio_button.checked?
      flags = Qt::ToolTip
    elsif @splash_screen_radio_button.checked?
      flags = Qt::SplashScreen
    end

    flags = flags.to_qflags
    flags |= Qt::MSWindowsFixedSizeDialogHint if @mswindows_fixed_size_dialog_checkbox.checked?
    flags |= Qt::X11BypassWindowManagerHint if @x11_bypass_window_manager_checkbox.checked?
    flags |= Qt::FramelessWindowHint if @frameleess_window_checkbox.checked?
    flags |= Qt::WindowTitleHint if @window_title_checkbox.checked?
    flags |= Qt::WindowSystemMenuHint if @window_systtem_menu_checkbox.checked?
    flags |= Qt::WindowMinimizeButtonHint if @window_minimize_button_checkbox.checked?
    flags |= Qt::WindowMaximizeButtonHint if @window_maximize_button_checkbox.checked?
    flags |= Qt::WindowContextHelpButtonHint if @window_context_help_button_checkbox.checked?
    flags |= Qt::WindowShadeButtonHint if @window_shade_button_checkbox.checked?
    flags |= Qt::WindowStaysOnTopHint if @window_stays_on_top_checkbox.checked?

    @preview_window.set_window_flags(flags)
    @preview_window.close
    @preview_window.show

    pos = @preview_window.pos
    pos.set_x 0 if pos.x.negative?
    pos.set_y 0 if pos.y.negative?
    @preview_window.move(pos)
  end

  def create_type_group_box
    @type_group_box = QGroupBox.new(tr('Type'))

    @window_radio_button = create_radio_button(tr('Window'))
    @dialog_radio_button = create_radio_button(tr('Dialog'))
    @sheet_radion_button = create_radio_button(tr('Sheet'))
    @drawer_radio_button = create_radio_button(tr('Drawer'))
    @popup_radio_button = create_radio_button(tr('Popup'))
    @tool_radio_button = create_radio_button(tr('Tool'))
    @tool_tip_radio_button = create_radio_button(tr('Tooltip'))
    @splash_screen_radio_button = create_radio_button(tr('Splash screen'))
    @window_radio_button.set_checked true

    layout = QGridLayout.new
    layout.add_widget(@window_radio_button, 0, 0)
    layout.add_widget(@dialog_radio_button, 1, 0)
    layout.add_widget(@sheet_radion_button, 2, 0)
    layout.add_widget(@drawer_radio_button, 3, 0)
    layout.add_widget(@popup_radio_button, 0, 1)
    layout.add_widget(@tool_radio_button, 1, 1)
    layout.add_widget(@tool_tip_radio_button, 2, 1)
    layout.add_widget(@splash_screen_radio_button, 3, 1)

    @type_group_box.set_layout layout
  end

  def create_hints_group_box
    @hints_group_box = QGroupBox.new(tr('Hints'))

    @mswindows_fixed_size_dialog_checkbox = create_checkbox(tr('MS Windows fixed size dialog'))
    @x11_bypass_window_manager_checkbox = create_checkbox(tr('X11 bypass window manager'))
    @frameleess_window_checkbox = create_checkbox(tr('Frameless window'))
    @window_title_checkbox = create_checkbox(tr('Window title'))
    @window_systtem_menu_checkbox = create_checkbox(tr('Window system menu'))
    @window_minimize_button_checkbox = create_checkbox(tr('Window minimize button'))
    @window_maximize_button_checkbox = create_checkbox(tr('Window maximize button'))
    @window_context_help_button_checkbox = create_checkbox(tr('Window context help button'))
    @window_shade_button_checkbox = create_checkbox(tr('Window shade button'))
    @window_stays_on_top_checkbox = create_checkbox(tr('Window stays on top'))

    layout = QGridLayout.new
    layout.add_widget(@mswindows_fixed_size_dialog_checkbox, 0, 0)
    layout.add_widget(@x11_bypass_window_manager_checkbox, 1, 0)
    layout.add_widget(@frameleess_window_checkbox, 2, 0)
    layout.add_widget(@window_title_checkbox, 3, 0)
    layout.add_widget(@window_systtem_menu_checkbox, 4, 0)
    layout.add_widget(@window_minimize_button_checkbox, 0, 1)
    layout.add_widget(@window_maximize_button_checkbox, 1, 1)
    layout.add_widget(@window_context_help_button_checkbox, 2, 1)
    layout.add_widget(@window_shade_button_checkbox, 3, 1)
    layout.add_widget(@window_stays_on_top_checkbox, 4, 1)

    @hints_group_box.set_layout layout
  end

  def create_checkbox(text)
    checkbox = QCheckBox.new(text)
    checkbox.clicked.connect(self, :update_preview)
    checkbox
  end

  def create_radio_button(text)
    button = QRadioButton.new(text)
    button.clicked.connect(self, :update_preview)
    button
  end
end
