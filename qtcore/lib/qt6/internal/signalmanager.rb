# frozen_string_literal: true

module RubyQt6
  module Internal
    class SignalManager
      def self.connect(sender, signal, receiver, method)
        metamethod = Internal::MetaObject.find_receiver_metamethod(receiver, method)
        QtCore::QObject._connect(sender, signal.qsignature, receiver, metamethod.qsignature)
      end

      def self.disconnect(conn)
        QtCore::QObject._disconnect(conn)
      end

      def self.emit(sender, signal, *args)
      end
    end
  end
end
