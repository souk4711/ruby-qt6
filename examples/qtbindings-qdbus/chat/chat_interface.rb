# frozen_string_literal: true

class ChatInterface < RubyQt6::Bando::QDBusAbstractInterface
  q_object do
    signal 'action(QString, QString)'
    signal 'message(QString, QString)'
  end

  def initialize(service, path, connection, parent)
    super(service, path, 'com.trolltech.chat', connection, parent)
  end
end
