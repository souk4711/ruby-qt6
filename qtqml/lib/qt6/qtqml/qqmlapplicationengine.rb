# frozen_string_literal: true

module RubyQt6
  module QtQml
    # @see https://doc.qt.io/qt-6/qqmlapplicationengine.html
    class QQmlApplicationEngine < RubyQt6::QtQml::QQmlEngine
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QQmlApplicationEngine]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_rubyrice(self) if parent
      end
    end
  end
end
