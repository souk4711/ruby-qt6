# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qdoublevalidator.html
    class QDoubleValidator < RubyQt6::QtGui::QValidator
      INITIALIZE_ARG_ERROR_MESSAGE =
        "Could not resolve method call for #{name}#initialize\n" \
        "  2 overload(s) were evaluated based on the types of Ruby parameters provided:\n" \
        "    initialize(QObject)\n" \
        "    initialize(Float, Float, Integer, QObject)\n"

      # @!parse class Notation; end
      rubyqt6_declare_enum_under QDoubleValidator, QDoubleValidator::Notation

      # @!parse
      q_object do
        signal "bottomChanged(double)"
        signal "decimalsChanged(int)"
        signal "notationChanged(QDoubleValidator::Notation)"
        signal "topChanged(double)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QDoubleValidator]
      #
      # @overload initialize(parent = nil)
      #   @param parent [QObject]
      #
      # @overload initialize(bottom, top, decimals, parent = nil)
      #   @param bottom [Float]
      #   @param top [Float]
      #   @param decimals [Integer]
      #   @param parent [QObject]
      def initialize(*args)
        parent = T.args_nth_delete_qobject(args, -1)
        case args.size
        when 0 then _initialize(parent)
        when 3 then _initialize_p(args[-3], args[-2], args[-1], parent)
        else raise ArgumentError, INITIALIZE_ARG_ERROR_MESSAGE
        end
        _take_ownership_from_ruby(self) if parent
      end

      private

      def _initialize_p(bottom, top, decimals, parent)
        _initialize(parent)
        set_bottom(bottom)
        set_top(top)
        set_decimals(decimals)
      end
    end
  end
end
