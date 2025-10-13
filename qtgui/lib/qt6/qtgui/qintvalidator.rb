# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qintvalidator.html
    class QIntValidator < RubyQt6::QtGui::QValidator
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
        parent = args.delete_at(-1) if args[-1].is_a?(QtCore::QObject)
        case args.size
        when 0
          _initialize(parent)
        when 2
          _initialize(parent)
          set_bottom(args[0])
          set_top(args[1])
        else
          message = "Could not resolve method call for #{self.class.name}#initialize\n" \
             "  2 overload(s) were evaluated based on the types of Ruby parameters provided:\n" \
             "     initialize(parent = nil)\n" \
             "     initialize(minimum, maximum, parent = nil)\n"
          raise ArgumentError, message
        end

        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
