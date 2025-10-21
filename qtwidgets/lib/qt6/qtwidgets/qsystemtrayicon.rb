# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qsystemtrayicon.html
    class QSystemTrayIcon < RubyQt6::QtCore::QObject
      INITIALIZE_ARG_ERROR_MESSAGE =
        "Could not resolve method call for #{name}#initialize\n" \
        "  2 overload(s) were evaluated based on the types of Ruby parameters provided:\n" \
        "    initialize(QObject)\n" \
        "    initialize(QIcon, QObject)\n"

      # @!parse class ActivationReason; end
      # @!parse class MessageIcon     ; end
      rubyqt6_declare_enum_under QSystemTrayIcon, QSystemTrayIcon::ActivationReason
      rubyqt6_declare_enum_under QSystemTrayIcon, QSystemTrayIcon::MessageIcon

      # @!parse
      q_object do
        signal "activated(QSystemTrayIcon::ActivationReason)"
        signal "messageClicked()"
        slot "hide()"
        slot "setVisible(bool)"
        slot "show()"
        slot "showMessage(QString,QString)"
        slot "showMessage(QString,QString,QIcon)"
        slot "showMessage(QString,QString,QIcon,int)"
        slot "showMessage(QString,QString,QSystemTrayIcon::MessageIcon)"
        slot "showMessage(QString,QString,QSystemTrayIcon::MessageIcon,int)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QSystemTrayIcon]
      #
      # @overload initialize(parent = nil)
      #   @param parent [QObject]
      #
      # @overload initialize(icon, parent = nil)
      #   @param icon [QIcon]
      #   @param parent [QObject]
      def initialize(*args)
        parent = T.args_nth_delete_qobject(args, -1)
        case args.size
        when 0 then _initialize(QtGui::QIcon.new, parent)
        when 1 then _initialize(args[-1], parent)
        else raise ArgumentError, INITIALIZE_ARG_ERROR_MESSAGE
        end
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
