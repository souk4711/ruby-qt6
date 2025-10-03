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
        raise "Unsupported type '#{qvarian.type_name}'" if blk.nil?

        blk.call(qvariant)
      end

      # @!visibility private
      register(QtCore::QMetaType::Type::Bool, ->(value) { from_bool(value) }, ->(qvariant) { to_bool(qvariant) })
      register(QtCore::QMetaType::Type::Int, ->(value) { from_int(value) }, ->(qvariant) { to_int(qvariant) })
      register(QtCore::QMetaType::Type::Double, ->(value) { from_double(value) }, ->(qvariant) { to_double(qvariant) })
      register(QtCore::QMetaType::Type::QString, ->(value) { from_qstring(value) }, ->(qvariant) { to_qstring(qvariant) })
    end
  end
end
