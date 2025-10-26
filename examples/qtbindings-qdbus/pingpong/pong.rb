# frozen_string_literal: true

require 'qt6/all'
require_relative 'common'

class Pong < RubyQt6::Bando::QObject
  q_object do
    slot 'QString ping(QString)'
  end

  def ping(arg)
    "ping('#{arg}') got called".tap { |msg| puts(msg) }
  end
end

app = QCoreApplication.new(ARGV)

unless QDBusConnection.session_bus.connected?
  warn("Cannot connect to the D-BUS session bus. To start it, run:\n\teval `dbus-launch --auto-syntax`\n")
  exit(1)
end

unless QDBusConnection.session_bus.register_service(SERVICE_NAME)
  warn("Cannot register service: %s\n" % QDBusConnection.session_bus.last_error.message)
  exit(1)
end

pong = Pong.new
QDBusConnection.session_bus.register_object('/', pong, QDBusConnection::ExportAllSlots)

app.exec
