# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qaction.html
    class QAction < RubyQt6::QtCore::QObject
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
        parent = args.delete_at(-1) if args[-1].is_a?(QtCore::QObject)
        case args.size
        when 0
          icon = QtGui::QIcon.new
          text = ""
        when 1
          icon = QtGui::QIcon.new
          text = args[0]
        when 2
          icon = args[0]
          text = args[1]
        else
          message = "Could not resolve method call for #{self.class.name}#initialize\n" \
             "  3 overload(s) were evaluated based on the types of Ruby parameters provided:\n" \
             "     initialize(parent = nil)\n" \
             "     initialize(text, parent = nil)\n" \
             "     initialize(icon, text, parent = nil)\n"
          raise ArgumentError, message
        end

        _initialize(icon, T.to_qstr(text), parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
