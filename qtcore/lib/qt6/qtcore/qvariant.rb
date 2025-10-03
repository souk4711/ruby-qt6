# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qvariant.html
    class QVariant
      # @!visibility private
      def self.from_rb_value_blks
        @from_rb_value_blks ||= {}
      end

      # @!visibility private
      def self.to_rb_value_blks
        @to_rb_value_blks ||= {}
      end

      # @!visibility private
      def self.register(id, from_rb_value_blk, to_rb_value_blk)
        id = id.to_i
        raise "QVariant with id alread registered: #{id}" if from_rb_value_blks.key?(id)

        from_rb_value_blks[id] = from_rb_value_blk
        to_rb_value_blks[id] = to_rb_value_blk
      end

      # @!visibility private
      def self.from_rb_value(value, qmetatype)
        blk = from_rb_value_blks[qmetatype.id]
        raise "Unsupported type '#{qmetatype.name}'" if blk.nil?

        blk.call(value)
      end

      # @!visibility private
      def self.to_rb_value(qvariant)
        blk = to_rb_value_blks[qvariant.type_id]
        raise "Unsupported type '#{qvariant.type_name}'" if blk.nil?

        blk.call(qvariant)
      end

      # @!visibility private
      register(QtCore::QMetaType::Type::Bool, method(:from_bool), method(:to_bool))
      register(QtCore::QMetaType::Type::Int, method(:from_int), method(:to_int))
      register(QtCore::QMetaType::Type::Double, method(:from_double), method(:to_double))
      register(QtCore::QMetaType::Type::QString, method(:from_qstring), method(:to_qstring))
    end
  end
end
