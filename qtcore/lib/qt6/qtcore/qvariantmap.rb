# frozen_string_literal: true

module RubyQt6
  module QtCore
    class QVariantMap
      # @!visibility private
      alias_method :_has_key?, :has_key?
      alias_method :_has_value?, :has_value?
      alias_method :_insert, :insert
      alias_method :_delete, :delete
      alias_method "_[]", :[]

      # @!visibility private
      def has_key?(key)
        _has_key?(T.to_qstr(key))
      end
      alias_method :key?, :has_key?

      # @!visibility private
      def has_value?(value)
        _has_value?(QVariant.new(value))
      end
      alias_method :value?, :has_value?

      # @!visibility private
      def insert(key, value)
        _insert(T.to_qstr(key), QVariant.new(value))
      end
      alias_method :[]=, :insert

      # @!visibility private
      def delete(key)
        _delete(T.to_qstr(key))
      end

      # @!visibility private
      def [](key)
        __send__("_[]", T.to_qstr(key))
      end

      # @!visibility private
      def inspect
        T.inspect_struct(self, hash: to_h.transform_keys(&:to_s).transform_values(&:value))
      end
    end
  end
end
