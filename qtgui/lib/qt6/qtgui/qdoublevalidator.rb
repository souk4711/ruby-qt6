# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qdoublevalidator.html
    class QDoubleValidator < RubyQt6::QtGui::QValidator
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
      def initialize(parent = nil)
        parent = args.delete_at(-1) if args[-1].is_a?(QtCore::QObject)
        case args.size
        when 0
          _initialize(parent)
        when 3
          _initialize(parent)
          set_bottom(args[0])
          set_top(args[1])
          set_decimals(args[2])
        else
          message = "Could not resolve method call for #{self.class.name}#initialize\n" \
             "  2 overload(s) were evaluated based on the types of Ruby parameters provided:\n" \
             "     initialize(parent = nil)\n" \
             "     initialize(bottom, top, decimals, parent = nil)\n"
          raise ArgumentError, message
        end

        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
