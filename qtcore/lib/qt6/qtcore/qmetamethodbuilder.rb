# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @!visibility private
    class QMetaMethodBuilder
      def set_return_type(value)
        _set_return_type(T.to_qbytearray(value))
      end
    end
  end
end
