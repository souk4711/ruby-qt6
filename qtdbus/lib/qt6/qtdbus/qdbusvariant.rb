# frozen_string_literal: true

module RubyQt6
  module QtDBus
    # @see https://doc.qt.io/qt-6/qdbusvariant.html
    class QDBusVariant
      # @!parse
      QtCore::QVariant.register(_qvariant_register_metatype, method(:_qvariant_from_value), method(:_qvariant_to_value), from: self)

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param variant [QVariant]
      # @return [QDBusVariant]
      def initialize(variant)
        variant = variant.is_a?(QtCore::QVariant) ? variant : QtCore::QVariant.new(variant)
        _initialize(variant)
      end
    end
  end
end
