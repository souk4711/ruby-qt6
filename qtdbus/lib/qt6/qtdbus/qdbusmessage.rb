# frozen_string_literal: true

module RubyQt6
  module QtDBus
    # @see https://doc.qt.io/qt-6/qdbusmessage.html
    class QDBusMessage
      # @!parse class MessageType; end
      rubyqt6_declare_enum_under QDBusMessage, QDBusMessage::MessageType

      # @!visibility private
      alias_method :_initialize, :initialize

      # @!visibility private
      def self.create_method_call(destination, path, interface, method)
        _create_method_call(T.to_qstr(destination), T.to_qstr(path), T.to_qstr(interface), T.to_qstr(method))
      end

      # @!visibility private
      def self.create_signal(path, interface, name)
        _create_signal(T.to_qstr(path), T.to_qstr(interface), T.to_qstr(name))
      end

      # @!visibility private
      def self.create_targeted_signal(service, path, interface, name)
        _create_targeted_signal(T.to_qstr(service), T.to_qstr(path), T.to_qstr(interface), T.to_qstr(name))
      end

      # @return [QDBusMessage]
      def initialize
        _initialize
      end

      # @!visibility private
      def set_arguments(*args)
        _set_arguments(T.to_qvariantlist(args))
      end
    end
  end
end
