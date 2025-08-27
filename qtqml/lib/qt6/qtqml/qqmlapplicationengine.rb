# frozen_string_literal: true

module RubyQt6
  module QtQml
    # @see https://doc.qt.io/qt-6/qqmlapplicationengine.html
    class QQmlApplicationEngine < RubyQt6::QtQml::QQmlEngine
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QQmlApplicationEngine]
      #
      # Create a new QQmlApplicationEngine with the given parent. You will
      # have to call load() later in order to load a QML file.
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_rice(self) if parent
      end

      # @param uri [QString]
      # @param type_name [QString]
      # @return [nil]
      #
      # Loads the QML type typeName from the module specified by uri. If the
      # type originates from a QML file located at a remote url, the type will
      # be loaded asynchronously. Listen to the objectCreated signal to
      # determine when the object tree is ready.
      def load_from_module(uri, type_name)
        _load_from_module(
          QtCore::QAnyStringView.new(uri),
          QtCore::QAnyStringView.new(type_name)
        )
      end
    end
  end
end
