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

      # @!visibility private
      def register_object(*args)
        options = args_nth_delete_registeroptions(args, -1) || QtDBus::QDBusConnection::ExportAdaptors
        case args.size
        when 2 then _register_object(T.to_qstr(args[-2]), args[-1], T.to_qflags(options))
        when 3 then _register_object(T.to_qstr(args[-3]), T.to_qstr(args[-2]), args[-1], T.to_qflags(options))
        else _register_object(*args)
        end
      end

      # @!visibility private
      def register_service(service_name)
        _register_service(T.to_qstr(service_name))
      end

      private

      def args_nth_delete_registeroptions(args, index)
        return unless args[index].is_a?(QtDBus::QDBusConnection::RegisterOption) || args[index].is_a?(QtDBus::QDBusConnection::RegisterOptions)
        args.delete_at(index)
      end
    end
  end
end
