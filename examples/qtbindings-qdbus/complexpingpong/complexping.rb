# frozen_string_literal: true

require 'qt6/all'

class Ping < RubyQt6::Bando::QObject
  q_object do
    slot 'start(QString, QString, QString)'
  end

  def start(name, _old_value, new_value)
    return if name != 'com.trolltech.QtDBus.PingExample' || new_value.empty?

    @iface = QDBusInterface.new(name, '/', 'com.trolltech.QtDBus.ComplexPong.Pong', QDBusConnection.session_bus, self)
    unless @iface.valid?
      warn("#{__FILE__}: Invalid interface: %s" % QDBusConnection.session_bus.last_error.message)
      QCoreApplication.quit
      return
    end

    loop do
      print("#{__FILE__}: Ask your question: ")

      line = gets.strip
      if line.empty? || line == 'quit'
        iface_call('quit')
        QCoreApplication.quit
        return
      elsif line == 'value'
        reply = iface_call('value')
        puts("#{__FILE__}: Value was: %s" % reply.value) if reply.valid?
      elsif line =~ /^value=/
        reply = iface_call('set_value', line[6, line.length])
        puts("#{__FILE__}: Value updated") if reply.valid?
      else
        reply = iface_call('query', line)
        puts("#{__FILE__}: Reply was: %s" % reply.value.variant.value) if reply.valid?
      end

      warn("#{__FILE__}: Call failed: %s" % @iface.last_error.message) if @iface.last_error.valid?
    end
  end

  private

  def iface_call(method, *args)
    QDBusReply.new(@iface.call(method, *args))
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
watcher.add_watched_service('com.trolltech.QtDBus.PingExample')
watcher.service_owner_changed.connect(ping, :start)

app.exec
