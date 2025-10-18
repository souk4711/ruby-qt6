# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qtextframeformat.html
    class QTextFrameFormat < RubyQt6::QtGui::QTextFormat
      # @!parse class Position   ; end
      # @!parse class BorderStyle; end
      rubyqt6_declare_enum_under QTextFrameFormat, QTextFrameFormat::Position
      rubyqt6_declare_enum_under QTextFrameFormat, QTextFrameFormat::BorderStyle

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QTextFrameFormat]
      def initialize
        _initialize
      end
    end
  end
end
