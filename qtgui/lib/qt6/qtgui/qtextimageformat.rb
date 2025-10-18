# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qtextimageformat.html
    class QTextImageFormat < RubyQt6::QtGui::QTextCharFormat
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QTextImageFormat]
      def initialize
        _initialize
      end
    end
  end
end
