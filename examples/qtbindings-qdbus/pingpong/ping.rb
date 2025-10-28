# frozen_string_literal: true

require 'qt6/all'
require_relative 'common'

QCoreApplication.new(ARGV)

unless QDBusConnection.session_bus.connected?
  warn("#{__FILE__}: Cannot connect to the D-BUS session bus. To start it, run:\n\teval `dbus-launch --auto-syntax`\n")
  exit(1)
end

iface = QDBusInterface.new(SERVICE_NAME, '/', '', QDBusConnection.session_bus)
if iface.valid?
  message = iface.call(RUBYQT6_SLOT_NAME(:ping), ARGV.length.positive? ? ARGV[0] : '')
  reply = QDBusReply.new(message)
  if reply.value
    puts("#{__FILE__}: Reply was: %s\n" % reply.value)
    exit(0)
  end

  warn("#{__FILE__}: Call failed: %s\n" % reply.error.message)
  exit(1)
end

warn("#{__FILE__}: %s\n" % QDBusConnection.session_bus.last_error.message)
exit(1)
