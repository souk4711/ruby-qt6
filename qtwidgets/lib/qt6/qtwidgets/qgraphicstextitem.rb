# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qgraphicstextitem.html
    class QGraphicsTextItem < RubyQt6::QtWidgets::QGraphicsObject
      INITIALIZE_ARG_ERROR_MESSAGE =
        "Could not resolve method call for #{name}#initialize\n" \
        "  2 overload(s) were evaluated based on the types of Ruby parameters provided:\n" \
        "    initialize(QGraphicsItem)\n" \
        "    initialize(QString, QGraphicsItem)\n"

      # @!parse
      q_object do
        signal "linkActivated(QString)"
        signal "linkHovered(QString)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QGraphicsTextItem]
      #
      # @overload initialize(parent = nil)
      #   @param parent [QGraphicsItem]
      #
      # @overload initialize(text, parent = nil)
      #   @param text [String, QString]
      #   @param parent [QGraphicsItem]
      def initialize(*args)
        parent = T.args_nth_delete_qgraphicsitem(args, -1)
        case args.size
        when 0 then _initialize(T.to_qstr(""), parent)
        when 1 then _initialize(T.to_qstr(args[-1]), parent)
        else raise ArgumentError, INITIALIZE_ARG_ERROR_MESSAGE
        end
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
