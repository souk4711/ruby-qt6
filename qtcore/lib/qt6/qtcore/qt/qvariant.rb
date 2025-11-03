# frozen_string_literal: true

module RubyQt6
  module QtCore
    class QVariant
      # @!visibility private
      def self.register(id, from_object_method, to_object_method, from:)
        id = id.to_i
        raise "QVariant with id `#{id}` already registered" if from_object_methods.key?(id)

        from_object_methods[id] = from_object_method
        to_object_methods[id] = to_object_method

        qmetatype = QtCore::QMetaType.new(id)
        Array(from).each do |klass|
          klass.define_singleton_method(:default_qmetatype) do
            qmetatype
          end
        end
      end

      def self.from_object_methods
        @from_object_methods ||= {}
      end
      private_class_method :from_object_methods

      def self.from_object(object, qmetatype)
        qmetatype = QtCore::QMetaType.infer(object) if qmetatype.nil?
        meth = from_object_methods[qmetatype.id]
        meth ? meth.call(object) : raise("Unsupported qmetatype `#{qmetatype.name}`")
      end
      private_class_method :from_object

      def self.to_object_methods
        @to_object_methods ||= {}
      end
      private_class_method :to_object_methods

      def self.to_object(qvariant)
        meth = to_object_methods[qvariant.type_id]
        meth ? meth.call(qvariant) : raise("Unsupported qmetatype `#{qvariant.type_name}`")
      end
      private_class_method :to_object
    end
  end
end
