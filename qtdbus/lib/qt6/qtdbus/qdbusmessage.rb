# frozen_string_literal: true

module RubyQt6
  module QtDBus
    # @see https://doc.qt.io/qt-6/qdbusmessage.html
    class QDBusMessage
      # @!parse class MessageType; end
      rubyqt6_declare_enum_under QDBusMessage, QDBusMessage::MessageType

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QDBusMessage]
      def initialize
        _initialize
      end
    end
  end
end
