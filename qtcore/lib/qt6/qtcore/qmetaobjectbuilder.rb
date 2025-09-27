# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @!visibility private
    class QMetaObjectBuilder
      alias_method :_initialize, :initialize

      def initialize
        _initialize
      end

      def set_class_name(name)
        _set_class_name(T.to_qbytearray(name))
      end

      def add_signal(signature)
        _add_signal(T.to_qbytearray(signature))
      end

      def add_slot(signature)
        _add_slot(T.to_qbytearray(signature))
      end
    end
  end
end
