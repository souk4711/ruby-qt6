# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qtextlayout.html
    class QTextLayout
      # @!parse class CursorMode           ; end
      # @!parse class GlyphRunRetrievalFlag; end
      rubyqt6_declare_enum_under QTextLayout, QTextLayout::CursorMode
      rubyqt6_declare_enum_under QTextLayout, QTextLayout::GlyphRunRetrievalFlag

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QTextLayout]
      #
      # @overload initialize
      #
      # @overload initialize(text)
      #   @param text [String, QString]
      #
      # @overload initialize(text, font, paintdevice)
      #   @param text [String, QString]
      #   @param font [QFont]
      #   @param paintdevice [QPaintDevice]
      #
      # @overload initialize(block)
      #   @param block [QTextBlock]
      def initialize(*args)
        T.args_nth_to_qstr(args, 0)
        _initialize(*args)
      end
    end
  end
end
