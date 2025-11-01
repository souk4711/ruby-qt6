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

      # @!visibility private
      def insert_html(html)
        _insert_html(T.to_qstr(html))
      end

      # @!visibility private
      def insert_image(*args)
        T.args_nth_to_qstr(args, 0)
        T.args_nth_to_qstr(args, 1)
        _insert_image(*args)
      end

      # @!visibility private
      def insert_markdown(markdown, features = nil)
        _insert_markdown(T.to_qstr(markdown), T.to_qflags(features || QtGui::QTextDocument::MarkdownDialectGitHub))
      end

      # @!visibility private
      def insert_text(*args)
        T.args_nth_to_qstr(args, 0)
        _insert_text(*args)
      end
    end
  end
end
