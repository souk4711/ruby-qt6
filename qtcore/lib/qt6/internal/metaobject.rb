# frozen_string_literal: true

module RubyQt6
  module Internal
    class MetaObject
      attr_reader :metamethods

      def self.find_receiver_metamethod!(receiver, method, signal)
        name = Internal.inflector.ruby_fn_name(method.to_s)
        compatible_methods = signal.parameters.count.downto(0).map do |n|
          name + "(" + signal.parameters[0...n].join(",") + ")"
        end

        cls = receiver.class
        mo = cls._rubyqt6_metaobject
        until mo.nil?
          meth = mo.metamethods.find { |meth| compatible_methods.include?(meth.signature) }
          return meth if meth
          cls = cls.superclass
          mo = cls._rubyqt6_metaobject
        end

        klass = receiver.class.name.split("::").last
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
