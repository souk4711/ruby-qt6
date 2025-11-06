# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qwidget.html
    class QWidget < RubyQt6::QtCore::QObject
      # @!parse class RenderFlag ; end
      # @!parse class RenderFlags; end
      rubyqt6_declare_enum_under QWidget, QWidget::RenderFlag
      rubyqt6_declare_qflags QWidget::RenderFlags, QWidget::RenderFlag

      # @!parse
      QtCore::QVariant.register(
        _qvariant_register_metatype,
        method(:_qvariant_from_value),
        method(:_qvariant_to_value),
        from: self
      )

      # @!parse
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
        _take_ownership_from_ruby(self)
      end

      # @!visibility private
      def add_action(*args)
        _add_action(*args.map { |arg| T.to_qstr(arg) })
      end

      # @!visibility private
      def raise(*args)
        Kernel.raise(*args) if args.size.nonzero?
        _raise
      end

      # @!visibility private
      def set_window_title(title)
        _set_window_title(T.to_qstr(title))
      end
    end
  end
end
