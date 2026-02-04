# frozen_string_literal: true

require "qt6/qtcore"

require_relative "qtdbus/version"
require_relative "qtdbus/qtdbus"
require_relative "qtdbus/qtdbusversion"
require_relative "qtdbus/qdbus"

require_relative "qtdbus/qdbusconnection"
require_relative "qtdbus/qdbuserror"
require_relative "qtdbus/qdbusmessage"
require_relative "qtdbus/qdbusreply"
require_relative "qtdbus/qdbusvariant"

require_relative "qtdbus/qdbusabstractadaptor"
require_relative "qtdbus/qdbusabstractinterface"
require_relative "qtdbus/qdbusconnectioninterface"
require_relative "qtdbus/qdbusinterface"
require_relative "qtdbus/qdbusservicewatcher"

require_relative "bando/qdbusabstractadaptor"
require_relative "bando/qdbusabstractinterface"

RubyQt6.initialize!(RubyQt6::QtDBus)
