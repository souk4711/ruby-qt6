# frozen_string_literal: true

module RubyQt6
  module QtDBus
    # @see https://doc.qt.io/qt-6/qdbuserror.html
    class QDBusError
      # @!parse class ErrorType; end
      rubyqt6_declare_enum_under QDBusError, QDBusError::ErrorType
    end
  end
end
