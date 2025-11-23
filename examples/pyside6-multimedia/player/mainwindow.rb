# frozen_string_literal: true

class MainWindow < RubyQt6::Bando::QMainWindow
  AVI = 'video/x-msvideo'
  MP4 = 'video/mp4'

  q_object do
    slot 'open()'
    slot 'ensure_stopped()'
    slot 'previous_clicked()'
    slot 'next_clicked()'
    slot 'update_buttons(QMediaPlayer::PlaybackState)'
    slot 'player_error(QMediaPlayer::Error)'
    slot 'set_volume()'
  end

  def initialize
    super

    @playlist = []
    @playlist_index = -1
    @audio_output = QAudioOutput.new
    @player = QMediaPlayer.new
    @player.set_audio_output(@audio_output)

    @player.error_occurred.connect(self, :player_error)

    tool_bar = QToolBar.new
    add_tool_bar(tool_bar)

    file_menu = menu_bar.add_menu('&File')
    play_menu = menu_bar.add_menu('&Play')

    icon = QIcon.from_theme(QIcon::ThemeIcon::DocumentOpen)
    open_action = QAction.new(icon, '&Open...', self)
    open_action.set_shortcut(QKeySequence::Open)
    open_action.triggered.connect(self, :open)
    file_menu.add_action(open_action)
    tool_bar.add_action(open_action)

    icon = QIcon.from_theme(QIcon::ThemeIcon::ApplicationExit)
    exit_action = QAction.new(icon, 'E&xit', self)
    exit_action.set_shortcut('Ctrl+Q')
    exit_action.triggered.connect(self, :close)
    file_menu.add_action(exit_action)

    style = self.style
    icon = QIcon.from_theme(QIcon::ThemeIcon::MediaPlaybackStart, style.standard_icon(QStyle::SP_MediaPlay))
    @play_action = tool_bar.add_action(icon, 'Play')
    @play_action.triggered.connect(@player, :play)
    play_menu.add_action(@play_action)

    icon = QIcon.from_theme(QIcon::ThemeIcon::MediaSkipBackward, style.standard_icon(QStyle::SP_MediaSkipBackward))
    @previous_action = tool_bar.add_action(icon, 'Previous')
    @previous_action.triggered.connect(self, :previous_clicked)
    play_menu.add_action(@previous_action)

    icon = QIcon.from_theme(QIcon::ThemeIcon::MediaPlaybackPause, style.standard_icon(QStyle::SP_MediaPause))
    @pause_action = tool_bar.add_action(icon, 'Pause')
    @pause_action.triggered.connect(@player, :pause)
    play_menu.add_action(@pause_action)

    icon = QIcon.from_theme(QIcon::ThemeIcon::MediaSkipForward, style.standard_icon(QStyle::SP_MediaSkipForward))
    @next_action = tool_bar.add_action(icon, 'Next')
    @next_action.triggered.connect(self, :next_clicked)
    play_menu.add_action(@next_action)

    icon = QIcon.from_theme(QIcon::ThemeIcon::MediaPlaybackStop, style.standard_icon(QStyle::SP_MediaStop))
    @stop_action = tool_bar.add_action(icon, 'Stop')
    @stop_action.triggered.connect(self, :ensure_stopped)
    play_menu.add_action(@stop_action)

    @volume_slider = QSlider.new(Qt::Orientation::Horizontal)
    @volume_slider.set_minimum(0)
    @volume_slider.set_maximum(100)

    available_width = screen.available_geometry.width
    @volume_slider.set_fixed_width(available_width / 10)
    @volume_slider.set_value(@audio_output.volume * 100)
    @volume_slider.set_tick_interval(10)
    @volume_slider.set_tick_position(QSlider::TicksBelow)
    @volume_slider.set_tool_tip('Volume')
    @volume_slider.value_changed.connect(self, :set_volume)
    tool_bar.add_widget(@volume_slider)

    icon = QIcon.from_theme(QIcon::ThemeIcon::HelpAbout)
    about_menu = menu_bar.add_menu('&About')
    about_qt_act = QAction.new(icon, 'About &Qt', self)
    about_qt_act.triggered.connect($qApp, :about_qt)
    about_menu.add_action(about_qt_act)

    @video_widget = QVideoWidget.new
    set_central_widget(@video_widget)
    @player.playback_state_changed.connect(self, :update_buttons)
    @player.set_video_output(@video_widget)

    update_buttons(@player.playback_state)
    @mime_types = QStringList.new
  end

  def close_event(event)
    ensure_stopped
    event.accept
  end

  def open
    ensure_stopped
    file_dialog = QFileDialog.new(self)
    is_windows = (RUBY_PLATFORM =~ /win32/)

    if @mime_types.nil? || @mime_types.empty?
      @mime_types = get_supported_mime_types
      if is_windows && !@mime_types.include?(AVI)
        @mime_types << AVI
      elsif !@mime_types.include?(MP4)
        @mime_types << MP4
      end
    end

    file_dialog.set_mime_type_filters(@mime_types)
    default_mimetype = is_windows ? AVI : MP4
    file_dialog.select_mime_type_filter(default_mimetype) if @mime_types.include?(default_mimetype)

    movies_location = QStandardPaths.writable_location(QStandardPaths::MoviesLocation)
    file_dialog.set_directory(movies_location)

    return unless file_dialog.exec == QDialog::Accepted

    url = file_dialog.selected_urls[0]
    @playlist << url
    @playlist_index = @playlist.length - 1
    @player.set_source(url)
    @player.play
  end

  def ensure_stopped
    return unless @player.playback_state != QMediaPlayer::StoppedState

    @player.stop
  end

  def previous_clicked
    if @player.position <= 5000 && @playlist_index.positive?
      @playlist_index -= 1
      @playlist.previous
      @player.set_source(@playlist[@playlist_index])
    else
      @player.set_position(0)
    end
  end

  def next_clicked
    return unless @playlist_index < @playlist.length - 1

    @playlist_index += 1
    @player.set_source(@playlist[@playlist_index])
  end

  def update_buttons(state)
    media_count = @playlist.length
    @play_action.set_enabled(media_count.positive? && state != QMediaPlayer::PlayingState)
    @pause_action.set_enabled(state == QMediaPlayer::PlayingState)
    @stop_action.set_enabled(state != QMediaPlayer::StoppedState)
    @previous_action.set_enabled(@player.position.positive?)
    @next_action.set_enabled(media_count > 1)
  end

  def show_status_message(message)
    status_bar.show_message(message, 5000)
  end

  def player_error(error)
    warn error
    show_status_message(error)
  end

  def set_volume
    @volumne_value = QtAudio.convert_volume(@volume_slider.value.to_f / 100.0,
                                            QtAudio::VolumeScale::LogarithmicVolumeScale, QtAudio::VolumeScale::LinearVolumeScale)
    @audio_output.set_volume(@volumne_value)
  end

  private

  def get_supported_mime_types
    result = QStringList.new
    QMediaFormat.new.supported_file_formats(QMediaFormat::Decode).each do |f|
      mime_type = QMediaFormat.new(f).mime_type
      result << mime_type.name
    end
    result
  end
end
