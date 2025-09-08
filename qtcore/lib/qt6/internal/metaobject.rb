# frozen_string_literal: true

module RubyQt6
  module Internal
    class MetaObject
      def initialize
        @methods = []
      end

      def add_signal(signature)
        @methods << Internal::MetaMethod.new(signature)
      end
      alias_method :signal, :add_signal

      def add_slot(signature)
        @methods << Internal::MetaMethod.new(signature)
      end
      alias_method :slot, :add_slot
    end
  end
end
