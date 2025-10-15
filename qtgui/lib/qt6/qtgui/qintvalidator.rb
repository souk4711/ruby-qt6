# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qintvalidator.html
    class QIntValidator < RubyQt6::QtGui::QValidator
      INITIALIZE_ARG_ERROR_MESSAGE =
        "Could not resolve method call for #{name}#initialize\n" \
        "  2 overload(s) were evaluated based on the types of Ruby parameters provided:\n" \
        "    initialize(QObject)\n" \
        "    initialize(Integer, Integer, QObject)\n"

      # @!parse
      q_object do
        signal "bottomChanged(int)"
        signal "topChanged(int)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QIntValidator]
      #
      # @overload initialize(parent = nil)
      #   @param parent [QObject]
      #
      # @overload initialize(minimum, maximum, parent = nil)
      #   @param minimum [Integer]
      #   @param maximum [Integer]
      #   @param parent [QObject]
      def initialize(*args)
        parent = T.args_nth_delete_qobject(args, -1)
        case args.size
        when 0 then _initialize(parent)
        when 2 then _initialize_p(args[-2], args[-1], parent)
        else raise ArgumentError, INITIALIZE_ARG_ERROR_MESSAGE
        end
        _take_ownership_from_ruby(self) if parent
      end

      private

      def _initialize_p(minimum, maximum, parent)
        _initialize(parent)
        set_bottom(minimum)
        set_top(maximum)
      end
    end
  end
end
