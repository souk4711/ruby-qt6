# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qtextformat.html
    class QTextFormat
      # @!parse class FormatType    ; end
      # @!parse class Property      ; end
      # @!parse class ObjectTypes   ; end
      # @!parse class PageBreakFlag ; end
      # @!parse class PageBreakFlags; end
      rubyqt6_declare_enum_under QTextFormat, QTextFormat::FormatType
      rubyqt6_declare_enum_under QTextFormat, QTextFormat::Property
      rubyqt6_declare_enum_under QTextFormat, QTextFormat::ObjectTypes
      rubyqt6_declare_enum_under QTextFormat, QTextFormat::PageBreakFlag
      rubyqt6_declare_qflags QTextFormat::PageBreakFlags, QTextFormat::PageBreakFlag

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QTextFormat]
      #
      # @overload initialize
      #
      # @overload initialize(type)
      #   @param type [Integer]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
