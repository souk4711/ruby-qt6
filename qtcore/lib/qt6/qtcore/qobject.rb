# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qobject.html
    class QObject
      class << self
        # @param sender [QObject]
        # @param signal [String]
        # @param receiver [QObject]
        # @param slot [String]
        # @return [QMetaObject::Connection]
        #
        # Creates a connection of the given type from the signal in the sender
        # object to the method in the receiver object. Returns a handle to
        # the connection that can be used to disconnect it later.
        #
        # You must use the SIGNAL() and SLOT() macros when specifying the signal
        # and the method.
        # ```
        def connect(sender, signal, receiver, slot)
          _connect(sender, signal, receiver, slot)
        end

        # @param connection [QMetaObject::Connection]
        # @return [Boolean]
        #
        # Disconnect a connection.
        #
        # If the connection is invalid or has already been disconnected, do
        # nothing and return false.
        def disconnect(connection)
          _disconnect(connection)
        end
      end
    end
  end
end
