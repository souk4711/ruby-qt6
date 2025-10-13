# frozen_string_literal: true

require_relative 'scribblearea'

class MainWindow < RubyQt6::Bando::QMainWindow
  q_object do
    slot 'open()'
    slot 'save(QString)'
    slot 'pen_color()'
    slot 'pen_width()'
    slot 'about()'
  end

  def initialize(parent = nil)
    super(parent)

    @scribble_area = ScribbleArea.new
    set_central_widget(@scribble_area)

    @save_as_acts = []
    create_actions
    create_menus

    set_window_title(tr('Scribble'))
    resize(500, 500)
  end

  def close_event(event)
    if maybe_save?
      event.accept
    else
      event.ignore
    end
  end

  def open
    return unless maybe_save?

    file_name = QFileDialog.get_open_file_name(self, tr('Open File'), QDir.current_path)
    return if file_name.nil?

    @scribble_area.open_image(file_name)
  end

  def save(file_format)
    save_file(file_format)
  end

  def pen_color
    new_color = QColorDialog.get_color(@scribble_area.pen_color)
    return unless new_color.valid?

    @scribble_area.pen_color = new_color
  end

  def pen_width
    boolean = QBool.new
    new_width = QInputDialog.get_int(
      self,
      tr('Scribble'),
      tr('Select pen width:'),
      @scribble_area.pen_width,
      1,
      50,
      1,
      boolean
    )
    return unless boolean.ok?

    @scribble_area.pen_width = new_width
  end

  def about
    QMessageBox.about(self, tr('About Scribble'),
                      tr('<p>The <b>Scribble</b> example shows how to use QMainWindow as the ' \
                      'base widget for an application, and how to reimplement some of ' \
                      "QWidget's event handlers to receive the events generated for " \
                      "the application's widgets:</p><p> We reimplement the mouse event " \
                      'handlers to facilitate drawing, the paint event handler to ' \
                      'update the application and the resize event handler to optimize ' \
                      "the application's appearance. In addition we reimplement the " \
                      'close event handler to intercept the close events before ' \
                      'terminating the application.</p><p> The example also demonstrates ' \
                      'how to use QPainter to draw an image in real time, as well as ' \
                      'to repaint widgets.</p>'))
  end

  def create_actions
    @open_act = QAction.new(tr('&Open...'), self)
    @open_act.set_shortcut QKeySequence.new(tr('Ctrl+O'))
    @open_act.triggered.connect(self, :open)

    @mapper = QSignalMapper.new(self)
    @mapper.mapped_string.connect(self, :save)
    QImageWriter.supported_image_formats.each do |format|
      format = format.to_s
      text = tr('%s...' % format.upcase)
      action = QAction.new(text, self)
      action.triggered.connect(@mapper, :map)
      @mapper.set_mapping(action, format)
      @save_as_acts.push(action)
    end

    @exit_act = QAction.new(tr('E&xit'), self)
    @exit_act.set_shortcut QKeySequence.new(tr('Ctrl+Q'))
    @exit_act.triggered.connect(self, :close)

    @pen_color_act = QAction.new(tr('&Pen Color...'), self)
    @pen_color_act.triggered.connect(self, :pen_color)

    @pen_width_act = QAction.new(tr('Pen &Width...'), self)
    @pen_width_act.triggered.connect(self, :pen_width)

    @clear_screen_act = QAction.new(tr('&Clear Screen'), self)
    @clear_screen_act.set_shortcut QKeySequence.new(tr('Ctrl+L'))
    @clear_screen_act.triggered.connect(@scribble_area, :clear_image)

    @about_act = QAction.new(tr('&About'), self)
    @about_act.triggered.connect(self, :about)

    @about_qt_act = QAction.new(tr('About &Qt'), self)
    @about_qt_act.triggered.connect($qApp, :about_qt)
  end

  def create_menus
    @save_as_menu = QMenu.new(tr('&Save As'), self)
    @save_as_acts.each do |action|
      @save_as_menu.add_action(action)
    end

    @file_menu = QMenu.new(tr('&File'), self).tap do |f|
      f.add_action(@open_act)
      f.add_menu(@save_as_menu)
      f.add_separator
      f.add_action(@exit_act)
    end

    @option_menu = QMenu.new(tr('&Options'), self).tap do |o|
      o.add_action(@pen_color_act)
      o.add_action(@pen_width_act)
      o.add_separator
      o.add_action(@clear_screen_act)
    end

    @help_menu = QMenu.new(tr('&Help'), self).tap do |h|
      h.add_action(@about_act)
      h.add_action(@about_qt_act)
    end

    menu_bar.add_menu(@file_menu)
    menu_bar.add_menu(@option_menu)
    menu_bar.add_menu(@help_menu)
  end

  def maybe_save?
    if @scribble_area.modified?
      ret = QMessageBox.warning(
        self,
        tr('Scribble'),
        tr("The image has been modified.\n Do you want to save your changes?"),
        QMessageBox::Yes | QMessageBox::Default,
        QMessageBox::No
      )
      return true if ret == QMessageBox::No

      return save_file('png')
    end
    true
  end

  def save_file(file_format)
    initial_path = "#{QDir.current_path}/untitled.#{file_format}".to_qstr
    file_name = QFileDialog.get_save_file_name(
      self,
      tr('Save As'),
      initial_path,
      tr(format('%s Files (*.%s);;All Files (*)', file_format.to_s.upcase, file_format))
    )
    return false if file_name.nil?

    @scribble_area.save_image(file_name, file_format)
  end
end
