# frozen_string_literal: true

module RubyQt6
  module QtCore
    module Private
      class MetaObject
        attr_reader :metamethods

        def self.find_receiver_metamethod!(receiver, method, signal)
          if signal.nil?
            signature = "anonymous()"
            signal = QtCore::Private::MetaMethod.new(signature, :signal, :ruby)
          end

          name = QtCore::Private::MetaMethod.normalized_name(method.to_s)
          compatible_methods = signal.parameters.count.downto(0).map do |n|
            QtCore::Private::MetaMethod.normalized_signature(name, signal.parameters[0...n])
          end

          receiver_class = receiver.is_a?(Class) ? receiver : receiver.class
          mo = receiver_class._rubyqt6_metaobject
          until mo.nil?
            mo.metamethods.each { |meth| return meth if compatible_methods.include?(meth.signature) }
            mo.metamethods.each { |meth| return meth if name == meth.name } if mo.ruby?
            mo = mo.super_class
          end

          qlass = receiver_class.name.split("::").last
          raise "No compatible metamethod: #{qlass}##{name}"
        end

        def initialize(qlass)
          @qlass = qlass
          @qlass_underlying = @qlass.name.start_with?("RubyQt6::") ? :libQt6 : :ruby
          @classinfo = {}
          @metamethods = []
        end

        def add_classinfo(name, value)
          @classinfo[name] = value
        end
        alias_method :classinfo, :add_classinfo

        def add_signal(signature)
          @metamethods << QtCore::Private::MetaMethod.new(signature, :signal, @qlass_underlying)
        end
        alias_method :signal, :add_signal

        def add_slot(signature)
          @metamethods << QtCore::Private::MetaMethod.new(signature, :slot, @qlass_underlying)
        end
        alias_method :slot, :add_slot

        def class_name
          @qlass.name
        end

        def super_class
          return nil if @qlass == QtCore::QObject
          @qlass.superclass._rubyqt6_metaobject
        end

        def ruby?
          @qlass_underlying == :ruby
        end

        def to_qmetaobject
          return @qlass._static_meta_object unless ruby?

          builder = QtCore::QMetaObjectBuilder.new
          builder.set_class_name(@qlass.name)
          builder.set_super_class(@qlass.superclass._qmetaobject)
          @classinfo.each { |name, value| builder.add_class_info(name, value) }
          @metamethods.each { |meth| _to_qmetaobject_method(builder, meth) }
          builder.to_meta_object
        end

        private

        def _to_qmetaobject_method(builder, meth)
          case meth.type
          when :signal then _to_qmetaobject_method_signal(builder, meth)
          when :slot then _to_qmetaobject_method_slot(builder, meth)
          else raise "Unknown metamethod type: #{meth.type}"
          end
        end

        def _to_qmetaobject_method_signal(builder, meth)
          _methbuilder = builder.add_signal(meth.qsignature[1..])
        end

        def _to_qmetaobject_method_slot(builder, meth)
          methbuilder = builder.add_slot(meth.qsignature[1..])
          methbuilder.set_return_type(meth.return_type) unless meth.return_type.nil?
        end
      end
    end
  end
end
