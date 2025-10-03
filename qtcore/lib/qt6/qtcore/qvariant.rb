# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qvariant.html
    class QVariant
      # @!visibility private
      QtCore::QMetaType::Type.constants.each do |name|
        value = QtCore::QMetaType::Type.const_get(name).to_i
        QtCore::QVariant.const_set("T_#{name}", value)
      end

      # @!visibility private
      def self.from_rb_value(value, qmetatype)
        QVariant.new(value).tap(&->(variant) {
          return if variant.type_id == qmetatype.id
          raise "Type mismatch, expected '#{qmetatype.name}', but got '#{variant.type_name}'"
        })
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param obj [Object]
      # @return [QVariant]
      def initialize(obj)
        _initialize(obj)
      end

      # @!visibility private
      def to_rb_value
        case type_id
        when QtCore::QVariant::T_Bool then to_bool
        when QtCore::QVariant::T_Int then to_int
        when QtCore::QVariant::T_Double then to_double
        when QtCore::QVariant::T_QString then to_string
        else raise "Unsupported type '#{type_name}'"
        end
      end
    end
  end
end
