# frozen_string_literal: true

module RubyQt6
  module Internal
    class MetaObject
      attr_reader :metamethods

      def self.find_receiver_metamethod(receiver, method)
      end

      def initialize(underlying)
        @underlying = underlying
        @metamethods = []
      end

      def add_signal(signature)
        @metamethods << Internal::MetaMethod.new(signature, :signal, @underlying)
      end
      alias_method :signal, :add_signal

      def add_slot(signature)
        @metamethods << Internal::MetaMethod.new(signature, :slot, @underlying)
      end
      alias_method :slot, :add_slot
    end
  end
end
