# frozen_string_literal: true

require_relative 'audioinfo'
require_relative 'renderarea'

class InputTest < RubyQt6::Bando::QWidget
  q_object do
    slot 'device_changed(int)'
    slot 'slider_changed(int)'
    slot 'toggle_mode()'
    slot 'toggle_suspend()'
    slot 'push_mode_slot()'
  end

  def initialize
    super

    @m_pull_mode = false
    initialize_window
    initialize_audio(QMediaDevices.default_audio_input)
  end

  def initialize_window
    @layout = QVBoxLayout.new(self)

    @m_canvas = RenderArea.new(self)
    @layout.add_widget(@m_canvas)

    default_device_info = QMediaDevices.default_audio_input
    @m_device_box = QComboBox.new(self)
    @m_device_box.add_item(default_device_info.description, QVariant.new(default_device_info))

    QMediaDevices.audio_inputs.each do |device_info|
      if device_info != default_device_info
        @m_device_box.add_item(device_info.description, QVariant.new(device_info))
      end
    end

    @m_device_box.activated.connect(self, :device_changed)
    @layout.add_widget(@m_device_box)

    @m_volume_slider = QSlider.new(Qt::Horizontal, self)
    @m_volume_slider.set_range(0, 100)
    @m_volume_slider.set_value(100)
    @m_volume_slider.value_changed.connect(self, :slider_changed)
    @layout.add_widget(@m_volume_slider)

    @m_mode_button = QPushButton.new(self)
    @m_mode_button.clicked.connect(self, :toggle_mode)
    @layout.add_widget(@m_mode_button)

    @m_suspend_resume_button = QPushButton.new(self)
    @m_suspend_resume_button.clicked.connect(self, :toggle_suspend)
    @layout.add_widget(@m_suspend_resume_button)
  end

  def initialize_audio(device_info)
    format = QAudioFormat.new
    format.set_sample_rate(8000)
    format.set_channel_count(1)
    format.set_sample_format(QAudioFormat::Int16)
    @m_audio_info = AudioInfo.new(format)

    @m_audio_input = QAudioSource.new(device_info, format)
    initial_volume = QtAudio.convert_volume(@m_audio_input.volume, QtAudio::LinearVolumeScale, QtAudio::LogarithmicVolumeScale)
    @m_volume_slider.set_value((initial_volume * 100).round)

    toggle_mode
  end

  def toggle_mode
    @m_audio_input.stop
    toggle_suspend

    @m_mode_button.set_text('Enable pull mode')
    @io = @m_audio_input.start
    @io.ready_read.connect(self, :push_mode_slot)
  end

  def push_mode_slot
    len = @m_audio_input.bytes_available
    buffer_size = 4096
    len = buffer_size if len > buffer_size
    buffer = @io.read(len)
    return unless len.positive?

    level = @m_audio_info.calculate_level(buffer, len)
    @m_canvas.set_level(level)
  end

  def toggle_suspend
    state = @m_audio_input.state
    if [QtAudio::State::SuspendedState, QtAudio::State::StoppedState].include?(state)
      @m_audio_input.resume
      @m_suspend_resume_button.set_text('Suspend recording')
    elsif state == QtAudio::State::ActiveState
      @m_audio_input.suspend
      @m_suspend_resume_button.set_text('Resume recording')
    end
  end

  def device_changed(index)
    @m_audio_input.stop

    device = @m_device_box.item_data(index).value
    initialize_audio(device)
  end

  def slider_changed(value)
    linear_volume = QtAudio.convert_volume(value.to_f / 100, QtAudio::VolumeScale::LogarithmicVolumeScale, QtAudio::VolumeScale::LinearVolumeScale)
    @m_audio_input.set_volume(linear_volume)
  end
end
