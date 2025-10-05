# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qmetatype.html
    class QMetaType
      # @!parse class Type; end
      rubyqt6_declare_enum_under QMetaType, QMetaType::Type

      # @!visibility private
      def self.from_klass(k)
        name =
          case k
          when ::TrueClass, ::FalseClass then "bool"
          when ::Integer then "int"
          when ::Float then "double"
          when ::String, QtCore::QString then "QString"
          else raise "Unsupported klass '#{k}'"
          end
        from_name(name)
      end
    end
  end
end
