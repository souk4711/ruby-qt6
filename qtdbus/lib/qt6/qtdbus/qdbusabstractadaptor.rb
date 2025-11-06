# frozen_string_literal: true

module RubyQt6
  module QtDBus
    # @see https://doc.qt.io/qt-6/qdbusabstractadaptor.html
    class QDBusAbstractAdaptor < RubyQt6::QtCore::QObject
      # @!parse
      q_object do
      end

      # @param parent [QObject]
      # @return [QDBusAbstractAdaptor]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
