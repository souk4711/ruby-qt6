# frozen_string_literal: true

class Screenshot < RubyQt6::Bando::QWidget
  q_object do
    slot 'new_screenshot()'
    slot 'save_screenshot()'
    slot 'shoot_screen()'
    slot 'update_checkbox()'
  end

  def initialize(parent = nil)
    super(parent)

    @screenshot_label = QLabel.new
    @screenshot_label.set_size_policy(QSizePolicy::Expanding, QSizePolicy::Expanding)
    @screenshot_label.set_alignment Qt::AlignCenter.to_i
    @screenshot_label.set_minimum_size(240, 160)

    create_options_groupbox
    create_buttons_layout

    @main_layout = QVBoxLayout.new
    @main_layout.add_widget(@screenshot_label)
    @main_layout.add_widget(@options_groupbox)
    @main_layout.add_layout(@buttons_layout)
    set_layout(@main_layout)

    shoot_screen
    @delay_spinbox.set_value(5)

    set_window_title(tr('Screenshot'))
    resize(300, 200)
  end

  def resize_event(_event)
    sccaled_size = @original_pixmap.size
    sccaled_size.scale(@screenshot_label.size, Qt::KeepAspectRatio)
    return unless @screenshot_label.pixmap.nil? || sccaled_size != @screenshot_label.pixmap.size

    updatescreenshot_label
  end

  def new_screenshot
    hide if @hide_this_window_checkbox.checked?
    @new_screenshot_button.set_disabled true

    QTimer.single_shot(@delay_spinbox.value * 1000, self, :shoot_screen)
  end

  def save_screenshot
    format = 'png'
    initial_path = "#{QDir.current_path}/untitled.#{format}"

    file_name = QFileDialog.get_save_file_name(
      self,
      tr('Save As'),
      initial_path,
      tr(format('%s Files (*.%s);;All Files (*)', format.upcase, format))
    )
    return if file_name.nil?

    @original_pixmap.save(file_name, format.to_s)
  end

  def shoot_screen
    QApplication.beep if @delay_spinbox.value != 0
    @original_pixmap = QApplication.primary_screen.grab_window
    updatescreenshot_label

    @new_screenshot_button.set_disabled false
    return unless @hide_this_window_checkbox.checked?

    show
  end

  def update_checkbox
    @hide_this_window_checkbox.set_disabled(@delay_spinbox.value.zero? || false)
  end

  def create_options_groupbox
    @options_groupbox = QGroupBox.new(tr('Options'))

    @delay_spinbox = QSpinBox.new
    @delay_spinbox.set_suffix tr(' s')
    @delay_spinbox.set_maximum 60
    @delay_spinbox.value_changed.connect(self, :update_checkbox)

    @delay_spinbox_label = QLabel.new(tr('Screenshot Delay:'))
    @hide_this_window_checkbox = QCheckBox.new(tr('Hide This Window'))

    @options_groupbox_layout = QGridLayout.new
    @options_groupbox_layout.add_widget(@delay_spinbox_label, 0, 0)
    @options_groupbox_layout.add_widget(@delay_spinbox, 0, 1)
    @options_groupbox_layout.add_widget(@hide_this_window_checkbox, 1, 0, 1, 2)
    @options_groupbox.set_layout @options_groupbox_layout
  end

  def create_buttons_layout
    @new_screenshot_button = create_button(tr('New Screenshot'), self, :new_screenshot)
    @save_screenshot_button = create_button(tr('Save Screenshot'), self, :save_screenshot)
    @quit_screenshot_button = create_button(tr('Quit'), self, :close)

    @buttons_layout = QHBoxLayout.new
    @buttons_layout.add_stretch
    @buttons_layout.add_widget(@new_screenshot_button)
    @buttons_layout.add_widget(@save_screenshot_button)
    @buttons_layout.add_widget(@quit_screenshot_button)
  end

  def create_button(text, receiver, member)
    button = QPushButton.new(text)
    button.clicked.connect(receiver, member)
    button
  end

  def updatescreenshot_label
    @screenshot_label.set_pixmap @original_pixmap.scaled(@screenshot_label.size, Qt::KeepAspectRatio, Qt::SmoothTransformation)
  end
end
