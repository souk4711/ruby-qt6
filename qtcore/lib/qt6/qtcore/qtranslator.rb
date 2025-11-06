# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qtranslator.html
    class QTranslator < RubyQt6::QtCore::QObject
      # @!parse
      q_object do
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QTranslator]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end

      # @!visibility private
      def load(*args)
        _load(*args.map { |arg| T.to_qstr(arg) })
      end
    end
  end
end
