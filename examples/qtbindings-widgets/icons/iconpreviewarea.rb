# frozen_string_literal: true

class IconPreviewArea < RubyQt6::Bando::QWidget
  NUM_MODES = 3
  NUM_STATES = 2

  def initialize(parent = nil)
    super(parent)

    main_layout = QGridLayout.new
    set_layout(main_layout)

    state_labels = []
    state_labels[0] = create_header_label(tr('Off'))
    state_labels[1] = create_header_label(tr('On'))

    mode_labels = []
    mode_labels[0] = create_header_label(tr('Normal'))
    mode_labels[1] = create_header_label(tr('Active'))
    mode_labels[2] = create_header_label(tr('Disabled'))

    (0...NUM_STATES).each do |j|
      main_layout.add_widget(state_labels[j], j + 1, 0)
    end

    @pixmap_labels = []
    (0...NUM_MODES).each do |i|
      main_layout.add_widget(mode_labels[i], 0, i + 1)

      @pixmap_labels[i] = []
      (0...NUM_STATES).each do |j|
        @pixmap_labels[i][j] = create_pixmap_label
        main_layout.add_widget(@pixmap_labels[i][j], j + 1, i + 1)
      end
    end

    @size = QSize.new
    @icon = QIcon.new
  end

  def set_icon(icon)
    @icon = icon
    update_pixmap_labels
  end

  def set_size(size)
    return unless size != @size

    @size = size
    update_pixmap_labels
  end

  def create_header_label(text)
    label = QLabel.new(tr('<b>%s</b>' % text))
    label.set_alignment Qt::AlignCenter
    label
  end

  def create_pixmap_label
    label = QLabel.new
    label.set_enabled false
    label.set_alignment Qt::AlignCenter
    label.set_frame_shape QFrame::Box
    label.set_size_policy QSizePolicy::Expanding, QSizePolicy::Expanding
    label.set_background_role QPalette::Base
    label.set_minimum_size(132, 132)
    label
  end

  def update_pixmap_labels
    (0...NUM_MODES).each do |i|
      mode =
        if i.zero?
          QIcon::Normal
        elsif i == 1
          QIcon::Active
        else
          QIcon::Disabled
        end

      (0...NUM_STATES).each do |j|
        state = j.zero? ? QIcon::Off : QIcon::On
        pixmap = @icon.pixmap(@size, mode, state)
        @pixmap_labels[i][j].set_pixmap pixmap
        @pixmap_labels[i][j].set_enabled !pixmap.nil?
      end
    end
  end
end
