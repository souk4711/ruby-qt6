# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qtextblock.html
    class QTextBlock
      include Comparable

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QTextBlock]
      def initialize
        _initialize
      end

      # @!visibility private
      def <=>(other)
        return nil unless other.is_a?(QtGui::QTextBlock)
        self.class._operator_compare(self, other)
      end
    end
  end
end
