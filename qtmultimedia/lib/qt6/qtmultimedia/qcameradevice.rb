# frozen_string_literal: true

module RubyQt6
  module QtMultimedia
    # @see https://doc.qt.io/qt-6/qcameradevice.html
    class QCameraDevice
      # @!parse class Position; end
      rubyqt6_declare_enum_under QCameraDevice, QCameraDevice::Position

      # @!parse
      QVariant.register(
        _qvariant_register_metatype,
        method(:_qvariant_from_value),
        method(:_qvariant_to_value),
        from: self
      )

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QCameraDevice]
      def initialize
        _initialize
      end

      # @!visibility private
      def ==(other)
        return false unless other.is_a?(self.class)
        self.class._operator_equal(self, other)
      end

      # @!visibility private
      def inspect
        T.inspect_struct(self, id: id.to_s, description: description.to_s)
      end
    end
  end
end
