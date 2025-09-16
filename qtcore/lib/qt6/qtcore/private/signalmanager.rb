# frozen_string_literal: true

module RubyQt6
  module QtCore
    module Private
      class SignalManager
        def self.connect(sender, signal, receiver, metamethod)
          metamethod = QtCore::Private::MetaObject.find_receiver_metamethod!(receiver, metamethod, signal)
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
end
