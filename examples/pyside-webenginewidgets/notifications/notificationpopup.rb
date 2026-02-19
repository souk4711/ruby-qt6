# frozen_string_literal: true

class NotificationPopup < RubyQt6::Bando::QWidget
  q_object do
    slot 'on_closed()'
  end

  def initialize(parent)
    super

    @notification = nil
    @m_icon = QLabel.new
    @m_title = QLabel.new
    @m_message = QLabel.new
    set_window_flags(Qt::ToolTip)

    root_layout = QHBoxLayout.new(self)
    root_layout.add_widget(@m_icon)

    body_layout = QVBoxLayout.new
    root_layout.add_layout(body_layout)

    title_layout = QHBoxLayout.new
    body_layout.add_layout(title_layout)

    title_layout.add_widget(@m_title)
    title_layout.add_item(QSpacerItem.new(0, 0, QSizePolicy::Policy::Expanding))

    close = QPushButton.new('Close')
    title_layout.add_widget(close)
    close.clicked.connect(self, :on_closed)

    body_layout.add_widget(@m_message)
    adjust_size
  end

  def present(new_notification)
    if @notification
      @notification.close
      @notification = nil
    end

    @notification = new_notification
    @m_title.set_text("<b>#{@notification.title}</b>")
    @m_message.set_text(@notification.message)
    @m_icon.set_pixmap(QPixmap.from_image(@notification.icon).scaled_to_height(@m_icon.height))

    show
    @notification.show

    @notification.closed.connect(self, :on_closed)
    QTimer.single_shot(10_000, self, :on_closed)

    move(parent_widget.map_to_global(parent_widget.rect.bottom_right - QPoint.new(width + 10, height + 10)))
  end

  def on_closed
    hide
    @notification&.close
    @notification = nil
  end

  def mouse_release_event(event)
    _mouse_release_event(event)
    return unless event.button == Qt::MouseButton::LeftButton && @notification

    @notification.click
    on_closed
  end
end
