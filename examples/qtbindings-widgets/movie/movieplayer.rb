# frozen_string_literal: true

class MoviePlayer < RubyQt6::Bando::QWidget
  q_object do
    slot 'open()'
    slot 'go_to_frame(int)'
    slot 'fit_to_window()'
    slot 'update_buttons()'
    slot 'update_frame_slider()'
  end

  def initialize(parent = nil)
    super(parent)

    @movie = QMovie.new(self)
    @movie.set_cache_mode QMovie::CacheAll

    @movie_label = QLabel.new(tr('No movie loaded')).tap do |m|
      m.set_alignment Qt::AlignCenter
      m.set_size_policy(QSizePolicy::Ignored, QSizePolicy::Ignored)
      m.set_background_role QPalette::Dark
      m.set_auto_fill_background true
    end

    @current_movie_directory = '@movies'.to_qstr
    create_controls
    create_buttons

    @movie.frame_changed.connect(self, :update_frame_slider)
    @movie.state_changed.connect(self, :update_buttons)
    @fit_checkbox.clicked.connect(self, :fit_to_window)
    @frame_slider.value_changed.connect(self, :go_to_frame)
    @speed_spinbox.value_changed.connect(@movie, :setSpeed)

    layout = QVBoxLayout.new.tap do |m|
      m.add_widget(@movie_label)
      m.add_layout(@controls_layout)
      m.add_layout(@buttons_layout)
    end
    set_layout(layout)

    update_frame_slider
    update_buttons

    set_window_title(tr('Movie Player'))
    resize(400, 400)
  end

  def open
    file_name = QFileDialog.get_open_file_name(self, tr('Open a Movie'), @current_movie_directory)
    return if file_name.empty?

    @current_movie_directory = QFileInfo.new(file_name).path
    @movie.stop
    @movie_label.set_movie @movie
    @movie.set_file_name file_name
    @movie.start

    update_frame_slider
    update_buttons
  end

  def go_to_frame(frame)
    @movie.jump_to_frame(frame)
  end

  def fit_to_window
    @movie_label.set_scaled_contents @fit_checkbox.checked?
  end

  def update_frame_slider
    has_frames = (@movie.current_frame_number >= 0)
    if has_frames
      if @movie.frame_count.positive?
        @frame_slider.set_maximum @movie.frame_count - 1
      elsif @movie.current_frame_number > @frame_slider.maximum
        @frame_slider.set_maximum @movie.current_frame_number
      end
      @frame_slider.set_value @movie.current_frame_number
    else
      @frame_slider.set_maximum 0
    end
    @frame_label.set_enabled has_frames
    @frame_slider.set_enabled has_frames
  end

  def update_buttons
    @play_button.set_enabled @movie.valid? && @movie.frame_count != 1 && @movie.state == QMovie::NotRunning
    @pause_button.set_enabled @movie.state != QMovie::NotRunning
    @pause_button.set_checked @movie.state == QMovie::Paused
    @stop_button.set_enabled @movie.state != QMovie::NotRunning
  end

  def create_controls
    @fit_checkbox = QCheckBox.new(tr('Fit to Window'))

    @frame_label = QLabel.new(tr('Current frame:'))
    @frame_slider = QSlider.new(Qt::Horizontal).tap do |f|
      f.set_tick_position QSlider::TicksBelow
      f.set_tick_interval 10
    end

    @speed_label = QLabel.new(tr('Speed:'))
    @speed_spinbox = QSpinBox.new do |s|
      s.set_range 1, 9999
      s.set_value 100
      s.set_suffix tr('%')
    end

    @controls_layout = QGridLayout.new.tap do |c|
      c.add_widget(@fit_checkbox, 0, 0, 1, 2)
      c.add_widget(@frame_label, 1, 0)
      c.add_widget(@frame_slider, 1, 1, 1, 2)
      c.add_widget(@speed_label, 2, 0)
      c.add_widget(@speed_spinbox, 2, 1)
    end
  end

  def create_buttons
    icon_size = QSize.new(36, 36)

    @open_button = QToolButton.new.tap do |o|
      o.set_icon QIcon.new('images/open.png')
      o.set_icon_size icon_size
      o.set_tool_tip tr('Open File')
    end
    @open_button.clicked.connect(self, :open)

    @play_button = QToolButton.new.tap do |p|
      p.set_icon QIcon.new('images/play.png')
      p.set_icon_size icon_size
      p.set_tool_tip tr('Play')
    end
    @play_button.clicked.connect(@movie, :start)

    @pause_button = QToolButton.new.tap do |p|
      p.set_checkable true
      p.set_icon QIcon.new('images/pause.png')
      p.set_icon_size icon_size
      p.set_tool_tip tr('Pause')
    end
    @pause_button.clicked.connect(@movie, :setPaused)

    @stop_button = QToolButton.new.tap do |s|
      s.set_icon QIcon.new('images/stop.png')
      s.set_icon_size icon_size
      s.set_tool_tip tr('Stop')
    end
    @stop_button.clicked.connect(@movie, :stop)

    @quit_button = QToolButton.new.tap do |q|
      q.set_icon QIcon.new('images/quit.png')
      q.set_icon_size icon_size
      q.set_tool_tip tr('Quit')
    end
    @quit_button.clicked.connect(self, :close)

    @buttons_layout = QHBoxLayout.new.tap do |b|
      b.add_stretch
      b.add_widget(@open_button)
      b.add_widget(@play_button)
      b.add_widget(@pause_button)
      b.add_widget(@stop_button)
      b.add_widget(@quit_button)
      b.add_stretch
    end
  end
end
