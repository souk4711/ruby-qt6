# frozen_string_literal: true

module RubyQt6
  module QtQuick
    # @see https://doc.qt.io/qt-6/qquickview.html
    class QQuickView < RubyQt6::QtQuick::QQuickWindow
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWindow]
      # @return [QQuickWindow]
      #
      # Constructs a QQuickView with the given parent.
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_rice(self) if parent
      end

      # @return [QQmlEngine]
      #
      # Returns the QQmlEngine used for instantiating QML Components.
      def engine
        _engine
      end

      # @param uri [QString]
      # @param type_name [QString]
      # @return [nil]
      #
      # Loads the QML component identified by uri and typeName. If the component
      # is backed by a QML file, source will be set accordingly. For types
      # defined in C++, source will be empty.
      #
      # If any source was set before this method was called, it will be cleared.
      #
      # Calling this method multiple times with the same uri and typeName will
      # result in the QML component being reinstantiated.
      def load_from_module(uri, type_name)
        _load_from_module(
          QtCore::QAnyStringView.new(uri),
          QtCore::QAnyStringView.new(type_name)
        )
      end
    end
  end
end
