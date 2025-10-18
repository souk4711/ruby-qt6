# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qtextblockformat.html
    class QTextBlockFormat < RubyQt6::QtGui::QTextFormat
      # @!parse class LineHeightTypes; end
      # @!parse class MarkerType     ; end
      rubyqt6_declare_enum_under QTextBlockFormat, QTextBlockFormat::LineHeightTypes
      rubyqt6_declare_enum_under QTextBlockFormat, QTextBlockFormat::MarkerType

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QTextBlockFormat]
      def initialize
        _initialize
      end
    end
  end
end
