# frozen_string_literal: true

module RubyQt6
  module Internal
    class MetaObject
      attr_reader :metamethods

      def self.find_receiver_metamethod!(receiver, method, signal)
        name = Internal::MetaMethod.normalized_name(method.to_s)
        compatible_methods = signal.parameters.count.downto(0).map do |n|
          Internal::MetaMethod.normalized_signature(name, signal.parameters[0...n])
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

      def initialize(qlass)
        @qlass = qlass
        @metamethods = []
      end

      def add_signal(signature)
        @metamethods << Internal::MetaMethod.new(signature, :signal, _underlying)
      end
      alias_method :signal, :add_signal

      def add_slot(signature)
        @metamethods << Internal::MetaMethod.new(signature, :slot, _underlying)
      end
      alias_method :slot, :add_slot

      private

      def _underlying
        @qlass.name.start_with?("RubyQt6::") ? :libQt6 : :ruby
      end
    end
  end
end
