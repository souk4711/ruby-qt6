# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qvariant.html
    class QVariant
      # @!visibility private
      def self.from_object_methods
        @from_object_methods ||= {}
      end

      # @!visibility private
      def self.from_object(o, qmetatype)
        meth = from_object_methods[qmetatype.id]
        meth ? meth.call(o) : raise("Unsupported qmetatype '#{qmetatype.name}'")
      end

      # @!visibility private
      def self.to_object_methods
        @to_object_methods ||= {}
      end

      # @!visibility private
      def self.to_object(v)
        meth = to_object_methods[v.type_id]
        meth ? meth.call(v) : raise("Unsupported qmetatype '#{v.type_name}'")
      end

      # @!visibility private
      def self.register(id, from_object_method, to_object_method)
        id = id.to_i
        raise "QVariant with id already registered: #{id}" if from_object_methods.key?(id)

        from_object_methods[id] = from_object_method
        to_object_methods[id] = to_object_method
      end

      # @!parse
      register(QtCore::QMetaType::Type::Bool, method(:from_bool), method(:to_bool))
      register(QtCore::QMetaType::Type::Int, method(:from_int), method(:to_int))
      register(QtCore::QMetaType::Type::Double, method(:from_double), method(:to_double))
      register(QtCore::QMetaType::Type::QString, method(:from_qstring), method(:to_qstring))
    end
  end
end
