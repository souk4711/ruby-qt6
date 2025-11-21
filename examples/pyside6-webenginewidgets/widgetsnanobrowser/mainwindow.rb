class MainWindow < RubyQt6::Bando::QMainWindow
  INITIAL_URL = 'http://qt.io'

  q_object do
    slot "load()"
    slot "back()"
    slot "forward()"
    slot "url_changed(QUrl)"
  end

  def initialize
    super

    set_window_title('PySide6 WebEngineWidgets Example')

    tool_bar = QToolBar.new
    add_tool_bar(tool_bar)

    back_button = QPushButton.new
    back_button.set_icon(QIcon.new('images/left-32.png'))
    back_button.clicked.connect(self, :back)
    tool_bar.add_widget(back_button)

    forward_button = QPushButton.new
    forward_button.set_icon(QIcon.new('images/right-32.png'))
    forward_button.clicked.connect(self, :forward)
    tool_bar.add_widget(forward_button)

    @address_line_edit = QLineEdit.new(INITIAL_URL)
    @address_line_edit.return_pressed.connect(self, :load)
    tool_bar.add_widget(@address_line_edit)

    @web_engine_view = QWebEngineView.new
    @web_engine_view.load(QUrl.new(INITIAL_URL))
    @web_engine_view.page.title_changed.connect(self, :set_window_title)
    @web_engine_view.page.url_changed.connect(self, :url_changed)
    set_central_widget(@web_engine_view)
  end

  def load
    url = QUrl.from_user_input(@address_line_edit.text)
    @web_engine_view.load(url) if url.valid?
  end

  def back
    @web_engine_view.page.trigger_action(QWebEnginePage::Back)
  end

  def forward
    @web_engine_view.page.trigger_action(QWebEnginePage::Forward)
  end

  def url_changed(url)
    @address_line_edit.set_text(url.to_string)
  end
end
