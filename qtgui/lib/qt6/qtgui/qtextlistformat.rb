# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qtextlistformat.html
    class QTextListFormat < RubyQt6::QtGui::QTextFormat
      # @!parse class Style; end
      rubyqt6_declare_enum_under QTextListFormat, QTextListFormat::Style

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QTextListFormat]
      def initialize
        _initialize
      end
    end
  end
end
