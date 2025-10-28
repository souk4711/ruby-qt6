# frozen_string_literal: true

class ChatAdaptor < RubyQt6::Bando::QDBusAbstractAdaptor
  q_object do
    classinfo 'D-Bus Interface', 'com.trolltech.chat'
    signal 'action(QString, QString)'
    signal 'message(QString, QString)'
  end

  def initialize(parent)
    super
    set_auto_relay_signals(true)
  end
end
