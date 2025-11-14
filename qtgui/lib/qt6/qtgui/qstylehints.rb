# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qstylehints.html
    class QStyleHints < RubyQt6::QtCore::QObject
      # @!parse
      q_object do
        signal "colorSchemeChanged(Qt::ColorScheme)"
        signal "contextMenuTriggerChanged(Qt::ContextMenuTrigger)"
        signal "cursorFlashTimeChanged(int)"
        signal "keyboardInputIntervalChanged(int)"
        signal "mouseDoubleClickIntervalChanged(int)"
        signal "mousePressAndHoldIntervalChanged(int)"
        signal "mouseQuickSelectionThresholdChanged(int)"
        signal "showShortcutsInContextMenusChanged(bool)"
        signal "startDragDistanceChanged(int)"
        signal "startDragTimeChanged(int)"
        signal "tabFocusBehaviorChanged(Qt::TabFocusBehavior)"
        signal "useHoverEffectsChanged(bool)"
        signal "wheelScrollLinesChanged(int)"
      end
    end
  end
end
