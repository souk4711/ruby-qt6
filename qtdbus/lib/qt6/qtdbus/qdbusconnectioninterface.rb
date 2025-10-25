# frozen_string_literal: true

module RubyQt6
  module QtDBus
    # @see https://doc.qt.io/qt-6/qdbusconnectioninterface.html
    class QDBusConnectionInterface < RubyQt6::QtDBus::QDBusAbstractInterface
      # @!parse class ServiceQueueOptions      ; end
      # @!parse class ServiceReplacementOptions; end
      # @!parse class RegisterServiceReply     ; end
      rubyqt6_declare_enum_under QDBusConnectionInterface, QDBusConnectionInterface::ServiceQueueOptions
      rubyqt6_declare_enum_under QDBusConnectionInterface, QDBusConnectionInterface::ServiceReplacementOptions
      rubyqt6_declare_enum_under QDBusConnectionInterface, QDBusConnectionInterface::RegisterServiceReply

      # @!parse
      q_object do
        signal "callWithCallbackFailed(QDBusError,QDBusMessage)"
        signal "serviceRegistered(QString)"
        signal "serviceUnregistered(QString)"
      end
    end
  end
end
