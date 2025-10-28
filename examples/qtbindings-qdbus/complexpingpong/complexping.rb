# frozen_string_literal: true

require 'qt6/all'
require_relative 'common'

class Ping < RubyQt6::Bando::QObject
  q_object do
    slot 'start(QString, QString, QString)'
  end

  def start(name, _old_value, new_value)
    return if name != SERVICE_NAME || new_value.empty?

    iface = QDBusInterface.new(name, '/', 'com.trolltech.QtDBus.ComplexPong.Pong', QDBusConnection.session_bus, self)
    unless iface.valid?
      warn("#{__FILE__}: Invalid interface: %s" % QDBusConnection.session_bus.last_error.message)
      QCoreApplication.quit
      return
    end

    loop do
      print("#{__FILE__}: Ask your question: ")

      line = gets.strip
      if line.empty? || line == 'quit'
        iface.call(RUBYQT6_SLOT_NAME(:quit))
        QCoreApplication.quit
        return
      elsif line == 'value'
        reply = QDBusReply.new(iface.call(RUBYQT6_SLOT_NAME(:value)))
        puts("#{__FILE__}: value = %s" % reply.value) if reply.valid?
      elsif line =~ /^value=/
        iface.call(RUBYQT6_SLOT_NAME(:set_value), QVariant.new(line[6, line.length]))
      else
        reply = QDBusReply.new(iface.call(RUBYQT6_SLOT_NAME(:query), QVariant.new(line)))
        puts("#{__FILE__}: Reply was: %s" % reply.value.variant.value) if reply.valid?
      end

      warn("#{__FILE__}: Call failed: %s" % iface.last_error.message) if iface.last_error.valid?
    end
  end
end

app = QCoreApplication.new(ARGV)

unless QDBusConnection.session_bus.connected?
  warn("#{__FILE__}: Cannot connect to the D-BUS session bus. To start it, run:\n\teval `dbus-launch --auto-syntax`\n")
  exit(1)
end

ping = Ping.new
watcher = QDBusServiceWatcher.new
watcher.set_connection(QDBusConnection.session_bus)
watcher.add_watched_service(SERVICE_NAME)
watcher.service_owner_changed.connect(ping, :start)

app.exec
