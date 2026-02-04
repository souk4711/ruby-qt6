# frozen_string_literal: true

module RubyQt6
  module QtDBus
    # @see https://doc.qt.io/qt-6/qdbusabstractinterface.html
    class QDBusAbstractInterface < RubyQt6::QtCore::QObject
      # @!parse
      q_object do
      end

      # @param service [String, QString]
      # @param path [String, QString]
      # @param interface [String]
      # @param connection [QDBusConnection]
      # @param parent [QObject]
      # @return [QDBusAbstractInterface]
      def initialize(service, path, interface, connection, parent = nil)
        _initialize(T.to_qstr(service), T.to_qstr(path), interface, connection, parent)
        _take_ownership_from_ruby(self)
      end

      # @!visibility private
      def async_call(method, *args)
        async_call_with_argument_list(T.to_qstr(method), T.to_qvariantlist(args))
      end

      # @!visibility private
      def call(*args)
        mode = args_nth_delete_callmode(args, 0) || QDBus::AutoDetect
        method = args.delete_at(0)
        call_with_argument_list(mode, T.to_qstr(method), T.to_qvariantlist(args))
      end

      private

      def args_nth_delete_callmode(args, index)
        return unless args[index].is_a?(QDBus::CallMode)
        args.delete_at(index)
      end
    end
  end
end
