# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @!visibility private
    class QMetaObjectBuilder
      alias_method :_initialize, :initialize

      def initialize
        _initialize
      end

      def add_class_info(name, value)
        _add_class_info(T.to_qbytearray(name), T.to_qbytearray(value))
      end

      def add_signal(signature)
        _add_signal(T.to_qbytearray(signature))
      end

      def add_slot(signature)
        _add_slot(T.to_qbytearray(signature))
      end

      def set_class_name(name)
        _set_class_name(T.to_qbytearray(name))
      end
    end
  end
end
