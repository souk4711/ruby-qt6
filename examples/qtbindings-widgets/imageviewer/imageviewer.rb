# frozen_string_literal: true

class ImageViewer < RubyQt6::Bando::QMainWindow
  q_object do
    slot 'open()'
    slot 'print()'
    slot 'zoom_in()'
    slot 'zoom_out()'
    slot 'normal_size()'
    slot 'fit_to_window()'
    slot 'about()'
  end

  def initialize(parent = nil)
    super(parent)

    @image_label = QLabel.new
    @image_label.set_background_role QPalette::Base
    @image_label.set_size_policy(QSizePolicy::Ignored, QSizePolicy::Ignored)
    @image_label.set_scaled_contents true

    @scroll_area = QScrollArea.new
    @scroll_area.set_background_role QPalette::Dark
    @scroll_area.set_widget @image_label
    set_central_widget(@scroll_area)

    create_actions
    create_menus

    set_window_title(tr('Image Viewer'))
    resize(500, 400)

    @printer = QPrinter.new
  end

  def open
    file_name = QFileDialog.get_open_file_name(self, tr('Open File'), QDir.current_path)
    return if file_name.nil?

    image = QImage.new(file_name)
    if image.nil?
      QMessageBox.information(self, tr('Image Viewer'), tr('Cannot load %s.' % file_name))
      return
    end
    @image_label.set_pixmap QPixmap.from_image(image)
    @scale_factor = 1.0

    @print_act.set_enabled true
    @fit_to_window_act.set_enabled true
    update_actions

    return if @fit_to_window_act.checked?

    @image_label.adjust_size
  end

  def print
    dialog = QPrintDialog.new(@printer, self)
    return unless dialog.exec

    painter = QPainter.new(@printer)
    rect = painter.viewport
    size = @image_label.pixmap.size
    size.scale(rect.size, Qt::KeepAspectRatio)
    painter.set_viewport QRect.new(rect.x, rect.y, size.width, size.height)
    painter.set_window @image_label.pixmap.rect
    painter.draw_pixmap(0, 0, @image_label.pixmap)
  end

  def zoom_in
    scale_image(1.25)
  end

  def zoom_out
    scale_image(0.8)
  end

  def normal_size
    @image_label.adjust_size
    @scale_factor = 1.0
  end

  def fit_to_window
    fit_to_window = @fit_to_window_act.checked?
    @scroll_area.set_widget_resizable fit_to_window
    @image_label.adjust_size unless fit_to_window

    update_actions
  end

  def about
    QMessageBox.about(self, tr('About Image Viewer'),
                      tr('<p>The <b>Image Viewer</b> example shows how to combine QLabel ' \
                        'and QScrollArea to display an image. QLabel is typically used ' \
                        'for displaying a text, but it can also display an image. ' \
                        'QScrollArea provides a scrolling view around another widget. ' \
                        'If the child widget exceeds the size of the frame, QScrollArea ' \
                        'automatically provides scroll bars. </p><p>The example ' \
                        "demonstrates how QLabel's ability to scale its contents " \
                        "(QLabel::scaledContents), and QScrollArea's ability to " \
                        'automatically resize its contents ' \
                        '(QScrollArea.widgetResizable), can be used to implement ' \
                        'zoom_ing and scaling features. </p><p>In addition the example ' \
                        'shows how to use QPainter to print an image.</p>'))
  end

  def create_actions
    @open_act = QAction.new(tr('&Open...'), self)
    @open_act.set_shortcut QKeySequence.new(tr('Ctrl+O'))
    @open_act.triggered.connect(self, :open)

    @print_act = QAction.new(tr('&Print...'), self)
    @print_act.set_shortcut QKeySequence.new(tr('Ctrl+P'))
    @print_act.set_enabled false
    @print_act.triggered.connect(self, :print)

    @exit_act = QAction.new(tr('E&xit'), self)
    @exit_act.set_shortcut QKeySequence.new(tr('Ctrl+Q'))
    @exit_act.triggered.connect(self, :close)

    @zoom_in_act = QAction.new(tr('Zoom &In (25%)'), self)
    @zoom_in_act.set_shortcut QKeySequence.new(tr('Ctrl++'))
    @zoom_in_act.set_enabled false
    @zoom_in_act.triggered.connect(self, :zoom_in)

    @zoom_out_act = QAction.new(tr('Zoom &Out (25%)'), self)
    @zoom_out_act.set_shortcut QKeySequence.new(tr('Ctrl+-'))
    @zoom_out_act.set_enabled false
    @zoom_out_act.triggered.connect(self, :zoom_out)

    @normal_size_act = QAction.new(tr('&Normal Size'), self)
    @normal_size_act.set_shortcut QKeySequence.new(tr('Ctrl+S'))
    @normal_size_act.set_enabled false
    @normal_size_act.triggered.connect(self, :normal_size)

    @fit_to_window_act = QAction.new(tr('&Fit to Window'), self)
    @fit_to_window_act.set_enabled false
    @fit_to_window_act.set_checkable true
    @fit_to_window_act.set_shortcut QKeySequence.new(tr('Ctrl+F'))
    @fit_to_window_act.triggered.connect(self, :fit_to_window)

    @about_act = QAction.new(tr('&About'), self)
    @about_act.triggered.connect(self, :about)

    @about_qt_act = QAction.new(tr('About &Qt'), self)
    @about_qt_act.triggered.connect($qApp, :about_qt)
  end

  def create_menus
    @file_menu = QMenu.new(tr('&File'), self)
    @file_menu.add_action(@open_act)
    @file_menu.add_action(@print_act)
    @file_menu.add_separator
    @file_menu.add_action(@exit_act)

    @view_menu = QMenu.new(tr('&View'), self)
    @view_menu.add_action(@zoom_in_act)
    @view_menu.add_action(@zoom_out_act)
    @view_menu.add_action(@normal_size_act)
    @view_menu.add_separator
    @view_menu.add_action(@fit_to_window_act)

    @help_menu = QMenu.new(tr('&Help'), self)
    @help_menu.add_action(@about_act)
    @help_menu.add_action(@about_qt_act)

    menu_bar.add_menu(@file_menu)
    menu_bar.add_menu(@view_menu)
    menu_bar.add_menu(@help_menu)
  end

  def update_actions
    @zoom_in_act.set_enabled !@fit_to_window_act.checked?
    @zoom_out_act.set_enabled !@fit_to_window_act.checked?
    @normal_size_act.set_enabled !@fit_to_window_act.checked?
  end

  def scale_image(factor)
    @scale_factor *= factor
    @image_label.resize(@image_label.pixmap.size * @scale_factor)

    adjust_scroll_bar(@scroll_area.horizontal_scroll_bar, factor)
    adjust_scroll_bar(@scroll_area.vertical_scroll_bar, factor)

    @zoom_in_act.set_enabled @scale_factor < 3.0
    @zoom_out_act.set_enabled @scale_factor > 0.333
  end

  def adjust_scroll_bar(scroll_bar, factor)
    scroll_bar.set_value factor * scroll_bar.value + ((factor - 1) * scroll_bar.page_step / 2)
  end
end
