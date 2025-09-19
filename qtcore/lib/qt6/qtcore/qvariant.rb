# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qvariant.html
    class QVariant
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param obj [Object]
      # @return [QVariant]
      def initialize(obj)
        _initialize(obj)
      end

      # @!visibility private
      def to_rb_value
        case QtCore::QMetaType::Type.from_int(type_id)
        when QtCore::QMetaType::Type::Bool then to_bool
        when QtCore::QMetaType::Type::Int then to_int
        when QtCore::QMetaType::Type::Double then to_double
        when QtCore::QMetaType::Type::QString then to_string
        else raise "Unsupported type: #{type_name}"
        end
      end
    end
  end
end
