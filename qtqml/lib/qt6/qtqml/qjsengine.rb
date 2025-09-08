# frozen_string_literal: true

module RubyQt6
  module QtQml
    # @see https://doc.qt.io/qt-6/qjsengine.html
    class QJSEngine < RubyQt6::QtCore::QObject
      # @!visibility private
      q_object do
        signal "uiLanguageChanged()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QJSEngine]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_rubyrice(self) if parent
      end
    end
  end
end
