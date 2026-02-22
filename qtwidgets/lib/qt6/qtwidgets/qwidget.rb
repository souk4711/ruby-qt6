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
      QVariant.register(
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
        args.each_with_index { |_, index| T.args_nth_to_qstr(args, index) }
        _add_action(*args)
      end

      # @!visibility private
      def raise(*args)
        Kernel.raise(*args) if args.size.nonzero?
        _raise
      end

      # @!visibility private
      def set_style_sheet(sheet)
        _set_style_sheet(T.to_qstr(sheet))
      end

      # @!visibility private
      def set_tool_tip(tool_tip)
        _set_tool_tip(T.to_qstr(tool_tip))
      end

      # @!visibility private
      def set_whats_this(whats_this)
        _set_whats_this(T.to_qstr(whats_this))
      end

      # @!visibility private
      def set_window_file_path(file_path)
        _set_window_file_path(T.to_qstr(file_path))
      end

      # @!visibility private
      def set_window_title(title)
        _set_window_title(T.to_qstr(title))
      end

      # @!visibility private
      def set_window_flags(type)
        _set_window_flags(T.to_qflags(type))
      end
    end
  end
end
