# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qaction.html
    class QAction < RubyQt6::QtCore::QObject
      INITIALIZE_ARG_ERROR_MESSAGE =
        "Could not resolve method call for #{name}#initialize\n" \
        "  3 overload(s) were evaluated based on the types of Ruby parameters provided:\n" \
        "    initialize(QObject)\n" \
        "    initialize(QString, QObject)\n" \
        "    initialize(QIcon, QString, QObject)\n"

      # @!parse class MenuRole   ; end
      # @!parse class Priority   ; end
      # @!parse class ActionEvent; end
      rubyqt6_declare_enum_under QAction, QAction::MenuRole
      rubyqt6_declare_enum_under QAction, QAction::Priority
      rubyqt6_declare_enum_under QAction, QAction::ActionEvent

      # @!parse
      q_object do
        signal "changed()"
        signal "checkableChanged(bool)"
        signal "enabledChanged(bool)"
        signal "hovered()"
        signal "toggled(bool)"
        signal "triggered(bool)"
        signal "triggered()"
        signal "visibleChanged()"
        slot "hover()"
        slot "resetEnabled()"
        slot "setChecked(bool)"
        slot "setDisabled(bool)"
        slot "setEnabled(bool)"
        slot "setVisible(bool)"
        slot "toggle()"
        slot "trigger()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QAction]
      #
      # @overload initialize(parent = nil)
      #   @param parent [QObject]
      #
      # @overload initialize(text, parent = nil)
      #   @param text [String, QString]
      #   @param parent [QObject]
      #
      # @overload initialize(icon, text, parent = nil)
      #   @param icon [QIcon]
      #   @param text [String, QString]
      #   @param parent [QObject]
      def initialize(*args)
        parent = T.args_nth_delete_qobject(args, -1)
        case args.size
        when 0 then _initialize(QtGui::QIcon.new, T.to_qstr(""), parent)
        when 1 then _initialize(QtGui::QIcon.new, T.to_qstr(args[-1]), parent)
        when 2 then _initialize(args[-2], T.to_qstr(args[-1]), parent)
        else raise ArgumentError, INITIALIZE_ARG_ERROR_MESSAGE
        end
        _take_ownership_from_ruby(self)
      end

      # @!visibility private
      def menu
        QtWidgets::QMenu._ioc_qaction_menu(self)
      end

      # @!visibility private
      def set_menu(menu)
        QtWidgets::QMenu._ioc_qaction_set_menu(self, menu)
      end

      # @!visibility private
      def set_text(text)
        _set_text(T.to_qstr(text))
      end

      # @!visibility private
      def set_shortcut(shortcut)
        _set_shortcut(T.to_qkeysequence(shortcut))
      end
    end
  end
end
