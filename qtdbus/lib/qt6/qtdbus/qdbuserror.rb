# frozen_string_literal: true

module RubyQt6
  module QtDBus
    # @see https://doc.qt.io/qt-6/qdbuserror.html
    class QDBusError
      # @!parse class ErrorType; end
      rubyqt6_declare_enum_under QDBusError, QDBusError::ErrorType

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QDBusError]
      #
      # @overload initialize(message)
      #   @param message [QDBusMessage]
      #
      # @overload initialize(type, message)
      #   @param type [QDBusError::ErrorType]
      #   @param message [String, QString]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
