# frozen_string_literal: true

module RubyQt6
  module QtDBus
    # @see https://doc.qt.io/qt-6/qdbusservicewatcher.html
    class QDBusServiceWatcher < RubyQt6::QtCore::QObject
      # @!parse class WatchModeFlag; end
      # @!parse class WatchMode    ; end
      rubyqt6_declare_enum_under QDBusServiceWatcher, QDBusServiceWatcher::WatchModeFlag
      rubyqt6_declare_qflags QDBusServiceWatcher::WatchMode, QDBusServiceWatcher::WatchModeFlag

      # @!parse
      q_object do
        signal "serviceOwnerChanged(QString,QString,QString)"
        signal "serviceRegistered(QString)"
        signal "serviceUnregistered(QString)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QDBusServiceWatcher]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end

      # @!visibility private
      def add_watched_service(new_service)
        _add_watched_service(T.to_qstr(new_service))
      end
    end
  end
end
