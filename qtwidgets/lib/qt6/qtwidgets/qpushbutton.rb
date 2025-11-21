# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qpushbutton.html
    class QPushButton < RubyQt6::QtWidgets::QAbstractButton
      INITIALIZE_ARG_ERROR_MESSAGE =
        "Could not resolve method call for #{name}#initialize\n" \
        "  2 overload(s) were evaluated based on the types of Ruby parameters provided:\n" \
        "    initialize(QWidget)\n" \
        "    initialize(QString, QWidget)\n"

      # @!parse
      q_object do
        slot "showMenu()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QPushButton]
      #
      # @overload initialize(parent = nil)
      #   @param parent [QWidget]
      #
      # @overload initialize(text, parent = nil)
      #   @param text [String, QString]
      #   @param parent [QWidget]
      def initialize(*args)
        parent = T.args_nth_delete_qwidget(args, -1)
        case args.size
        when 0 then _initialize(T.to_qstr(""), parent)
        when 1 then _initialize(T.to_qstr(args[-1]), parent)
        else raise ArgumentError, INITIALIZE_ARG_ERROR_MESSAGE
        end
        _take_ownership_from_ruby(self)
      end
    end
  end
end
