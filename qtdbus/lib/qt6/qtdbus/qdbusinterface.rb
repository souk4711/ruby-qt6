# frozen_string_literal: true

module RubyQt6
  module QtDBus
    # @see https://doc.qt.io/qt-6/qdbusinterface.html
    class QDBusInterface < RubyQt6::QtDBus::QDBusAbstractInterface
      # @!parse
      q_object do
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param service [String, QString]
      # @param path [String, QString]
      # @param interface [String, QString]
      # @param connection [QDBusConnection]
      # @param parent [QObject]
      # @return [QDBusInterface]
      def initialize(service, path, interface = "", connection = nil, parent = nil)
        _initialize(T.to_qstr(service), T.to_qstr(path), T.to_qstr(interface), connection || QtDBus::QDBusConnection.session_bus, parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
