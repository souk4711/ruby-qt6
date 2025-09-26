# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qstring.html
    class QString
      include ::Comparable

      # @!visibility private
      alias_method :_initialize, :initialize

      # @!visibility private
      def self.new(str)
        return str if str.is_a?(self)
        allocate.tap { |o| o.__send__(:initialize, str) }
      end

      # @param str [String]
      # @return [QString]
      def initialize(str)
        _initialize(str)
      end

      # @!visibility private
      def to_s
        to_std_string
      end

      # @!visibility private
      def to_str
        to_std_string
      end

      # @!visibility private
      def <=>(other)
        return nil unless other.respond_to?(:to_str)
        to_str <=> other.to_str
      end

      # @!visibility private
      def inspect
        T.q_inspect(self, str: to_s)
      end
    end
  end
end
