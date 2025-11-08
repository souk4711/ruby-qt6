# frozen_string_literal: true

module RubyQt6
  module QtCore
    module Private
      class Signal
        def initialize(sender, metamethod)
          @sender = sender
          @metamethod = metamethod
        end

        def connect(receiver, metamethod)
          QtCore::Private::SignalManager.connect(@sender, @metamethod, receiver, metamethod)
        end

        def disconnect(receiver, metamethod)
          QtCore::Private::SignalManager.disconnect(@sender, @metamethod, receiver, metamethod)
        end

        def emit(*args)
          QtCore::Private::SignalManager.emit(@sender, @metamethod, *args)
        end
      end
    end
  end
end
