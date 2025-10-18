# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qtexttableformat.html
    class QTextTableFormat < RubyQt6::QtGui::QTextFrameFormat
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QTextTableFormat]
      def initialize
        _initialize
      end
    end
  end
end
