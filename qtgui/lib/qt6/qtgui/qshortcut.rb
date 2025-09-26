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

      # @return [QShortcut]
      #
      # @overload initialize(parent)
      #   @param parent [QWindow, QWidget]
      #
      # @overload initialize(standard_key, parent, member = "", ambiguous_member = "", context = Qt::WindowShortcut)
      #   @param standard_key [QKeySequence::StandardKey]
      #   @param parent [QWindow, QWidget]
      #   @param member [String]
      #   @param ambiguous_member [String]
      #   @param context [Qt::ShortcutContext]
      #
      # @overload initialize(key, parent, member = "", ambiguous_member = "", context = Qt::WindowShortcut)
      #   @param key [QKeySequence]
      #   @param parent [QWindow, QWidget]
      #   @param member [String]
      #   @param ambiguous_member [String]
      #   @param context [Qt::ShortcutContext]
      def initialize(*args)
        _initialize(*args)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
