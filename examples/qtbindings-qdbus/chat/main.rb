# frozen_string_literal: true

require 'qt6/all'
require_relative 'chat'

app = QApplication.new

unless QDBusConnection.session_bus.connected?
  warn("Cannot connect to the D-BUS session bus.\nPlease check your system settings and try again.\n")
  exit(1)
end

chat = Chat.new
chat.show
app.exec
