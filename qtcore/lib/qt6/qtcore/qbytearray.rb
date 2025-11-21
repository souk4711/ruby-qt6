# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qbytearray.html
    class QByteArray
      include Comparable

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param str [String]
      # @return [QByteArray]
      def initialize(str)
        _initialize(str)
      end

      # @!visibility private
      def <=>(other)
        return nil unless other.is_a?(QtCore::QByteArray)
        self.class._operator_compare(self, other)
      end

      # @!visibility private
      def to_s
        to_std_string
      end

      # @!visibility private
      def inspect
        T.inspect_struct(self, str: to_s)
      end
    end
  end
end
