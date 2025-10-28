# frozen_string_literal: true

require_relative 'ui_chatmainwindow'
require_relative 'ui_nicknamedialog'
require_relative 'chat_interface'
require_relative 'chat_adaptor'

class Chat < RubyQt6::Bando::QObject
  q_object do
    signal 'message(QString, QString)'
    signal 'action(QString, QString)'
    slot 'message_slot(QString, QString)'
    slot 'action_slot(QString, QString)'
    slot 'text_changed_slot(QString)'
    slot 'send_clicked_slot()'
    slot 'change_nickname()'
    slot 'about_qt()'
    slot 'exiting()'
  end

  def initialize(parent = nil)
    super

    @m_nickname = 'nickname'

    @ui = Ui_ChatMainWindow.new
    @ui.send_button.set_enabled false

    @ui.message_line_edit.text_changed.connect(self, :text_changed_slot)
    @ui.send_button.clicked.connect(self, :send_clicked_slot)
    @ui.action_change_nickname.triggered.connect(self, :change_nickname)
    @ui.action_about_qt.triggered.connect($qApp, :about_qt)
    $qApp.last_window_closed.connect(self, :exiting)

    ChatAdaptor.new(self)
    QDBusConnection.session_bus.register_object('/', self)

    @iface = ChatInterface.new('', '', QDBusConnection.session_bus, self)
    @iface.message.connect(self, :message_slot)
    @iface.action.connect(self, :action_slot)

    dialog = Ui_NicknameDialog.new(@ui.widget)
    dialog.cancel_button.set_visible false
    dialog.exec

    @m_messages = []
    @m_nickname = dialog.nickname.text.to_s.strip
    action.emit(@m_nickname, 'joins the chat')
  end

  def message_slot(nickname, text)
    msg = format('<%s> %s', nickname, text)
    @m_messages.push(msg)
    @m_messages.shift if @m_messages.length > 100
    rebuild_history
  end

  def action_slot(nickname, text)
    msg = format('* %s %s', nickname, text)
    @m_messages.push(msg)
    @m_messages.shift if @m_messages.length > 100
    rebuild_history
  end

  def text_changed_slot(new_text)
    @ui.send_button.set_enabled !new_text.empty?
  end

  def send_clicked_slot
    message.emit(@m_nickname, @ui.message_line_edit.text)
    @ui.message_line_edit.clear
  end

  def change_nickname
    dialog = Ui_NicknameDialog.new(@ui.widget)
    return unless dialog.exec == QDialog::Accepted.to_i

    old = @m_nickname
    @m_nickname = dialog.nickname.text.to_s.strip
    action.emit(old, format('is now known as %s', @m_nickname))
  end

  def exiting
    action.emit(@m_nickname, 'leaves the chat')
  end

  def show
    @ui.show
  end

  private

  def rebuild_history
    history = @m_messages.join("\n")
    @ui.chat_history.set_plain_text history
  end
end
