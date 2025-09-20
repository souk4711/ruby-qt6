# frozen_string_literal: true

module RubyQt6
  module QtQuick
    # @see https://doc.qt.io/qt-6/qquickwindow.html
    class QQuickWindow < RubyQt6::QtGui::QWindow
      # @!visibility private
      q_object do
        signal "activeFocusItemChanged()"
        signal "afterAnimating()"
        signal "afterFrameEnd()"
        signal "afterRenderPassRecording()"
        signal "afterRendering()"
        signal "afterSynchronizing()"
        signal "beforeFrameBegin()"
        signal "beforeRenderPassRecording()"
        signal "beforeRendering()"
        signal "beforeSynchronizing()"
        signal "colorChanged(QColor)"
        signal "frameSwapped()"
        signal "sceneGraphAboutToStop()"
        signal "sceneGraphError(QQuickWindow::SceneGraphError,QString)"
        signal "sceneGraphInitialized()"
        signal "sceneGraphInvalidated()"
        slot "releaseResources()"
        slot "update()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWindow]
      # @return [QQuickWindow]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
