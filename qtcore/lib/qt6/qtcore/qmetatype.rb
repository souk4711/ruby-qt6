# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qmetatype.html
    class QMetaType
      # @!parse class Type; end
      rubyqt6_declare_enum_under QMetaType, QMetaType::Type

      # @!visibility private
      alias_method :_initialize, :initialize

      # @!visibility private
      def self.infer(o)
        k = o.class
        k.respond_to?(:default_qmetatype) ? k.default_qmetatype : raise("Could not infer qmetatype")
      end

      # @param type_id [Integer]
      # @return [QMetaType]
      def initialize(type_id)
        _initialize(type_id)
      end
    end
  end
end
