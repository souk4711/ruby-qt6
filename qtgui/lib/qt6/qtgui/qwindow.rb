# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qwindow.html
    class QWindow < RubyQt6::QtCore::QObject
      # @!parse class AncestorMode; end
      # @!parse class Visibility  ; end
      rubyqt6_include_constants QWindow, QWindow::AncestorMode
      rubyqt6_include_constants QWindow, QWindow::Visibility

      # @!parse
      q_object do
        signal "activeChanged()"
        signal "contentOrientationChanged(Qt::ScreenOrientation)"
        signal "focusObjectChanged(QObject*)"
        signal "heightChanged(int)"
        signal "maximumHeightChanged(int)"
        signal "maximumWidthChanged(int)"
        signal "minimumHeightChanged(int)"
        signal "minimumWidthChanged(int)"
        signal "modalityChanged(Qt::WindowModality)"
        signal "opacityChanged(double)"
        signal "safeAreaMarginsChanged(QMargins)"
        signal "screenChanged(QScreen*)"
        signal "transientParentChanged(QWindow*)"
        signal "visibilityChanged(QWindow::Visibility)"
        signal "visibleChanged(bool)"
        signal "widthChanged(int)"
        signal "windowStateChanged(Qt::WindowState)"
        signal "windowTitleChanged(QString)"
        signal "xChanged(int)"
        signal "yChanged(int)"
        slot "alert(int)"
        slot "close()"
        slot "hide()"
        slot "lower()"
        slot "raise()"
        slot "requestActivate()"
        slot "requestUpdate()"
        slot "setGeometry(QRect)"
        slot "setGeometry(int,int,int,int)"
        slot "setHeight(int)"
        slot "setMaximumHeight(int)"
        slot "setMaximumWidth(int)"
        slot "setMinimumHeight(int)"
        slot "setMinimumWidth(int)"
        slot "setTitle(QString)"
        slot "setVisible(bool)"
        slot "setWidth(int)"
        slot "setX(int)"
        slot "setY(int)"
        slot "show()"
        slot "showFullScreen()"
        slot "showMaximized()"
        slot "showMinimized()"
        slot "showNormal()"
        slot "startSystemMove()"
        slot "startSystemResize(Qt::Edges)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWindow]
      # @return [QWindow]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end

      # @!visibility private
      def raise(*args)
        ::Kernel.raise(*args) if args.size.nonzero?
        _raise
      end

      # @!visibility private
      def set_parent(parent)
        _set_parent(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
