# frozen_string_literal: true

module RubyQt6
  module QtQml
    # @see https://doc.qt.io/qt-6/qqmlengine.html
    class QQmlEngine < RubyQt6::QtQml::QJSEngine
      # @!visibility private
      q_object do
        signal "exit(int)"
        signal "offlineStoragePathChanged()"
        signal "quit()"
        signal "warnings(QList<QQmlError>)"
        slot "retranslate()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QQmlEngine]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_rubyrice(self) if parent
      end

      # @!visibility private
      def add_import_path(dir)
        _add_import_path(QtCore::QString.new(dir))
      end
    end
  end
end
