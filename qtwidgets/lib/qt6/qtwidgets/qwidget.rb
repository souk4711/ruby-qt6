# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qwidget.html
    class QWidget < RubyQt6::QtCore::QObject
      # @!parse class RenderFlag; end
      rubyqt6_include_constants QWidget, QWidget::RenderFlag

      # @!visibility private
      q_object do
        signal "customContextMenuRequested(QPoint)"
        signal "windowIconChanged(QIcon)"
        signal "windowTitleChanged(QString)"
        slot "close()"
        slot "hide()"
        slot "lower()"
        slot "raise()"
        slot "repaint()"
        slot "setDisabled(bool)"
        slot "setEnabled(bool)"
        slot "setFocus()"
        slot "setHidden(bool)"
        slot "setStyleSheet(QString)"
        slot "setVisible(bool)"
        slot "setWindowModified(bool)"
        slot "setWindowTitle(QString)"
        slot "show()"
        slot "showFullScreen()"
        slot "showMaximized()"
        slot "showMinimized()"
        slot "showNormal()"
        slot "update()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QWidget]
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
      def set_parent(parent, f = nil)
        f.nil? ? _set_parent(parent) : _set_parent(parent, f)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
