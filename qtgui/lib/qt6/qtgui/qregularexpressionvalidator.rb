# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qregularexpressionvalidator.html
    class QRegularExpressionValidator < RubyQt6::QtGui::QValidator
      INITIALIZE_ARG_ERROR_MESSAGE =
        "Could not resolve method call for #{name}#initialize\n" \
        "  2 overload(s) were evaluated based on the types of Ruby parameters provided:\n" \
        "    initialize(QObject)\n" \
        "    initialize(QRegularExpression, QObject)\n"

      # @!parse
      q_object do
        signal "regularExpressionChanged(QRegularExpression)"
        slot "setRegularExpression(QRegularExpression)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QRegularExpressionValidator]
      #
      # @overload initialize(parent = nil)
      #   @param parent [QObject]
      #
      # @overload initialize(re, parent = nil)
      #   @param re [QRegularExpression]
      #   @param parent [QObject]
      def initialize(*args)
        parent = T.args_nth_delete_qobject(args, -1)
        case args.size
        when 0 then _initialize(parent)
        when 1 then _initialize_p(args[-1], parent)
        else raise ArgumentError, INITIALIZE_ARG_ERROR_MESSAGE
        end
        _take_ownership_from_ruby(self)
      end

      private

      def _initialize_p(re, parent)
        _initialize(parent)
        set_regular_expression(re)
      end
    end
  end
end
