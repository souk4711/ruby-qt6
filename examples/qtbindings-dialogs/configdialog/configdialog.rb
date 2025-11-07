# frozen_string_literal: true

require_relative 'configurationpage'
require_relative 'querypage'
require_relative 'updatepage'

class ConfigDialog < RubyQt6::Bando::QDialog
  q_object do
    slot 'change_page(QListWidgetItem*, QListWidgetItem*)'
  end

  def initialize
    super

    c = QListWidget.new
    c.set_view_mode QListView::IconMode
    c.set_icon_size QSize.new(96, 84)
    c.set_movement QListView::Static
    c.set_maximum_width 128
    c.set_spacing 12
    @contents_widget = c

    p = QStackedWidget.new
    p.add_widget(ConfigurationPage.new)
    p.add_widget(UpdatePage.new)
    p.add_widget(QueryPage.new)
    @pages_widget = p

    close_button = QPushButton.new(tr('Close'))
    close_button.clicked.connect(self, :close)

    create_icons
    @contents_widget.set_current_row 0

    horizontal_layout = QHBoxLayout.new
    horizontal_layout.add_widget(@contents_widget)
    horizontal_layout.add_widget(@pages_widget, 1)

    button_layout = QHBoxLayout.new
    button_layout.add_stretch(1)
    button_layout.add_widget(close_button)

    m = QVBoxLayout.new
    m.add_layout(horizontal_layout)
    m.add_stretch(1)
    m.add_spacing(12)
    m.add_layout(button_layout)
    set_layout(m)

    set_window_title(tr('Config Dialog'))
  end

  def create_icons
    c = QListWidgetItem.new
    c.set_icon QIcon.new('images/config.png')
    c.set_text tr('Configuration')
    c.set_text_alignment Qt::AlignHCenter
    c.set_flags Qt::ItemIsSelectable | Qt::ItemIsEnabled
    @contents_widget.add_item(c)

    u = QListWidgetItem.new
    u.set_icon QIcon.new('images/update.png')
    u.set_text tr('Update')
    u.set_text_alignment Qt::AlignHCenter
    u.set_flags Qt::ItemIsSelectable | Qt::ItemIsEnabled
    @contents_widget.add_item(u)

    q = QListWidgetItem.new
    q.set_icon QIcon.new('images/query.png')
    q.set_text tr('Query')
    q.set_text_alignment Qt::AlignHCenter
    q.set_flags Qt::ItemIsSelectable | Qt::ItemIsEnabled
    @contents_widget.add_item(q)

    @contents_widget.current_item_changed.connect(self, :change_page)
  end

  def change_page(current, previous)
    current = previous if current.nil?
    @pages_widget.set_current_index @contents_widget.row(current)
  end
end
