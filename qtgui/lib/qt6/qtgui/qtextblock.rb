# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qtextblock.html
    class QTextBlock
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QTextBlock]
      def initialize
        _initialize
      end

      # @!visibility private
      def ==(other)
        return false unless other.is_a?(self.class)
        self.class._operator_equal(self, other)
      end
    end
  end
end
