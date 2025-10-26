# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qmetamethod.html
    class QMetaMethod
      # @!parse class Access    ; end
      # @!parse class Attributes; end
      # @!parse class MethodType; end
      rubyqt6_declare_enum_under QMetaMethod, QMetaMethod::Access
      rubyqt6_declare_enum_under QMetaMethod, QMetaMethod::Attributes
      rubyqt6_declare_enum_under QMetaMethod, QMetaMethod::MethodType

      # @!visibility private
      def inspect
        T.inspect_struct(self, type: method_type.to_s, signature: method_signature.to_s)
      end
    end
  end
end
