# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qtextcharformat.html
    class QTextCharFormat < RubyQt6::QtGui::QTextFormat
      # @!parse class VerticalAlignment                ; end
      # @!parse class UnderlineStyle                   ; end
      # @!parse class FontPropertiesInheritanceBehavior; end
      rubyqt6_declare_enum_under QTextCharFormat, QTextCharFormat::VerticalAlignment
      rubyqt6_declare_enum_under QTextCharFormat, QTextCharFormat::UnderlineStyle
      rubyqt6_declare_enum_under QTextCharFormat, QTextCharFormat::FontPropertiesInheritanceBehavior

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QTextCharFormat]
      def initialize
        _initialize
      end
    end
  end
end
