# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qregularexpressionvalidator.html
    class QRegularExpressionValidator < RubyQt6::QtGui::QValidator
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
        parent = args.delete_at(-1) if args[-1].is_a?(QtCore::QObject)
        case args.size
        when 0
          _initialize(parent)
        when 1
          _initialize(parent)
          set_regular_expression(args[0])
        else
          message = "Could not resolve method call for #{self.class.name}#initialize\n" \
             "  2 overload(s) were evaluated based on the types of Ruby parameters provided:\n" \
             "     initialize(parent = nil)\n" \
             "     initialize(re, parent = nil)\n"
          raise ArgumentError, message
        end

        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
