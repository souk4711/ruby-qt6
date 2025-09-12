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
        @qlass_underlying = @qlass.name.start_with?("RubyQt6::") ? :libQt6 : :ruby
        @metamethods = []
      end

      def add_signal(signature)
        @metamethods << Internal::MetaMethod.new(signature, :signal, @qlass_underlying)
      end
      alias_method :signal, :add_signal

      def add_slot(signature)
        @metamethods << Internal::MetaMethod.new(signature, :slot, @qlass_underlying)
      end
      alias_method :slot, :add_slot

      def to_qmetaobject
        return @qlass._static_meta_object if @qlass_underlying == :libQt6

        builder = QtCore::QMetaObjectBuilder.new
        builder.set_class_name(@qlass.name)
        builder.set_super_class(@qlass.superclass._qmetaobject)
        @metamethods.each { |meth| _to_qmetaobject_method(builder, meth) }
        builder.to_meta_object
      end

      private

      def _to_qmetaobject_method(builder, meth)
        case meth.type
        when :signal then _to_qmetaobject_method_signal(builder, meth)
        when :slot then _to_qmetaobject_method_slot(builder, meth)
        else raise ArgumentError
        end
      end

      def _to_qmetaobject_method_signal(builder, meth)
        _methbuilder = builder.add_signal(meth.qsignature[1..])
      end

      def _to_qmetaobject_method_slot(builder, meth)
        _methbuilder = builder.add_slot(meth.qsignature[1..])
      end
    end
  end
end
