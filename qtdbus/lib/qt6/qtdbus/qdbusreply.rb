# frozen_string_literal: true

module RubyQt6
  module QtDBus
    # @see https://doc.qt.io/qt-6/qdbusreply.html
    class QDBusReply
      # @!visibility private
      attr_reader :error

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param message [QDBusMessage]
      # @return [QDBusReply]
      def initialize(message)
        @error = QtDBus::QDBusError.new(message)
        if @error.valid?
          @data = QtCore::QVariant.new("")
          return
        end

        if message.arguments.size < 1
          @error = QtDBus::QDBusError.new(QtDBus::QDBusError::ErrorType::InvalidSignature, "Unexpected reply signature")
          @data = QtCore::QVariant.new("")
          return
        end

        @data = message.arguments[0]
      end

      # @!visibility private
      def valid?
        !@error.valid?
      end

      # @!visibility private
      def value
        valid? ? @data.value : nil
      end
    end
  end
end
