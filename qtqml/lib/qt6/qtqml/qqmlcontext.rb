# frozen_string_literal: true

module RubyQt6
  module QtQml
    # @see https://doc.qt.io/qt-6/qqmlcontext.html
    class QQmlContext < RubyQt6::QtCore::QObject
      # @!parse
      q_object do
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param engine [QQmlEngine]
      # @param parent [QObject]
      # @return [QQmlContext]
      def initialize(engine, parent = nil)
        _initialize(engine, parent)
        _take_ownership_from_ruby(self)
      end

      # @!visibility private
      def set_context_property(name, value)
        _set_context_property(T.to_qstr(name), value)
      end
    end
  end
end
