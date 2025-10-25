# frozen_string_literal: true

module RubyQt6
  module QtDBus
    # @see https://doc.qt.io/qt-6/qdbusconnection.html
    class QDBusConnection
      # @!parse class BusType               ; end
      # @!parse class RegisterOption        ; end
      # @!parse class RegisterOptions       ; end
      # @!parse class UnregisterMode        ; end
      # @!parse class ConnectionCapability  ; end
      # @!parse class ConnectionCapabilities; end
      rubyqt6_declare_enum_under QDBusConnection, QDBusConnection::BusType
      rubyqt6_declare_enum_under QDBusConnection, QDBusConnection::RegisterOption
      rubyqt6_declare_enum_under QDBusConnection, QDBusConnection::UnregisterMode
      rubyqt6_declare_enum_under QDBusConnection, QDBusConnection::ConnectionCapability
      rubyqt6_declare_qflags QDBusConnection::ConnectionCapabilities, QDBusConnection::ConnectionCapability
      rubyqt6_declare_qflags QDBusConnection::RegisterOptions, QDBusConnection::RegisterOption

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param name [String, QString]
      # @return [QDBusMessage]
      def initialize(name)
        _initialize(T.to_qstr(name))
      end
    end
  end
end
