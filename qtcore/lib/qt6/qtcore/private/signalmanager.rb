# frozen_string_literal: true

module RubyQt6
  module QtCore
    module Private
      class SignalManager
        def self.connections
          @connections ||= {}
        end

        def self.connect(sender, signal, receiver, metamethod)
          metamethod = QtCore::Private::MetaObject.find_receiver_metamethod!(receiver, metamethod, signal)
          QtCore::QObject._connect(sender, signal.qsignature, receiver, metamethod.qsignature).tap do |conn|
            connections[conn] = [sender, receiver]
          end
        end

        def self.disconnect(conn)
          connections.delete(conn)
          QtCore::QObject._disconnect(conn)
        end

        def self.emit(sender, signal, *args)
          qmo = sender.class._qmetaobject
          qmetamethod = qmo.method(qmo.index_of_signal(signal.qsignature[1..]))

          raise "Too many arguments" if qmetamethod.parameter_count < args.count
          raise "Not enough arguments" if qmetamethod.parameter_count > args.count
          args = args.map.with_index { |v, i| QtCore::QVariant.from_rb_value(v, qmetamethod.parameter_meta_type(i)) }

          QtCore::QObject._emit(sender, qmetamethod, args)
        end
      end
    end
  end
end
