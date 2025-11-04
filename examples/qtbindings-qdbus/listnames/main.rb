# frozen_string_literal: true

require 'qt6/all'

def method1
  puts('Method 1:')

  reply = QDBusConnection.session_bus.interface.registered_service_names
  unless reply.valid?
    puts("Error:#{reply.error.message}")
    exit 1
  end
  puts(reply.value)
  puts
end

def method2
  puts('Method 2:')

  bus = QDBusConnection.session_bus
  dbus_iface = QDBusInterface.new('org.freedesktop.DBus', '/org/freedesktop/DBus', 'org.freedesktop.DBus', bus)
  puts(dbus_iface.call('ListNames').arguments[0].value)
  puts
end

def method3
  puts('Method 3:')
  puts(QDBusConnection.session_bus.interface.registered_service_names.value)
end

QCoreApplication.new(ARGV)

unless QDBusConnection.session_bus.connected?
  warn("Cannot connect to the D-BUS session bus. To start it, run:\n\teval `dbus-launch --auto-syntax`\n")
  exit 1
end

method1
method2
method3
exit 0
