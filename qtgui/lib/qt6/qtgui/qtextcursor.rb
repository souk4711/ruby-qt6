# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qtextcursor.html
    class QTextCursor
      # @!parse class SelectionType; end
      # @!parse class MoveOperation; end
      # @!parse class MoveMode     ; end
      rubyqt6_declare_enum_under QTextCursor, QTextCursor::SelectionType
      rubyqt6_declare_enum_under QTextCursor, QTextCursor::MoveOperation
      rubyqt6_declare_enum_under QTextCursor, QTextCursor::MoveMode

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QTextCursor]
      #
      # @overload initialize
      #
      # @overload initialize(document)
      #   @param document [QTextDocument]
      #
      # @overload initialize(frame)
      #   @param frame [QTextFrame]
      #
      # @overload initialize(block)
      #   @param block [QTextBlock]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
