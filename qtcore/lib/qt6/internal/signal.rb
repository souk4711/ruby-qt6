# frozen_string_literal: true

module RubyQt6
  module Internal
    class Signal
      def initialize(sender, metamethod)
        @sender = sender
        @metamethod = metamethod
      end

      def connect(receiver, method)
        Internal::SignalManager.connect(@sender, @metamethod, receiver, method)
      end

      def emit(*args)
        Internal::SignalManager.emit(@sender, @metamethod, *args)
      end
    end
  end
end
