# frozen_string_literal: true

class Ui_ChatMainWindow
  attr_reader :widget

  def initialize
    loader = QUiLoader.new
    @widget = loader.load(QFile.new('./chatmainwindow.ui'))
  end

  def chat_history
    @widget.find_child('chatHistory')
  end

  def message_line_edit
    @widget.find_child('messageLineEdit')
  end

  def send_button
    @widget.find_child('sendButton')
  end

  def action_change_nickname
    @widget.find_child('actionChangeNickname')
  end

  def action_about_qt
    @widget.find_child('actionAboutQt')
  end

  def show
    @widget.show
  end
end
