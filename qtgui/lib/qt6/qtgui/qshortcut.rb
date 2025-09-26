# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qshortcut.html
    class QShortcut < RubyQt6::QtCore::QObject
      # @!parse
      q_object do
        signal "activated()"
        signal "activatedAmbiguously()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param key [QKeySequence]
      # @param parent [QWindow, QWidget]
      # @return [QShortcut]
      def initialize(key, parent)
        _initialize(key, parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
