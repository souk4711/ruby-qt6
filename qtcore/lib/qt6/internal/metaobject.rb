# frozen_string_literal: true

module RubyQt6
  module Internal
    class MetaObject
      attr_reader :metamethods

      def self.find_receiver_metamethod!(receiver, method, signal)
        name = method.to_s
        compatible_methods = signal.parameters.count.downto(0).map do |n|
          Internal::MetaMethod.normalized_signature(name, signal.parameters[0...n])
        end

        cls = receiver.class
        mo = cls.__qmetaobject__
        until mo.nil?
          meth = mo.metamethods.find { |meth| compatible_methods.include?(meth.signature) }
          return meth if meth
          cls = cls.superclass
          mo = cls.__qmetaobject__
        end

        klass = Internal.inflector.demodulize(receiver.class.name)
        name = Internal.inflector.underscore(name)
        raise "No such metamethod #{klass}##{name}"
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
