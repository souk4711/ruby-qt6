# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qstring.html
    class QString
      # @!visibility private
      alias_method :_initialize, :initialize

      class << self
        # @!visibility private
        def new(str = "")
          return str if str.is_a?(QString)
          allocate.tap { |o| o.__send__(:initialize, str) }
        end
      end

      # @param str [String]
      # @return [QString]
      #
      # Constructs a string on str.
      def initialize(str = "")
        _initialize(str)
      end

      # @return [String]
      #
      # Returns a String object with the data contained in this QString.
      def to_s
        _to_std_string
      end

      # @return [String]
      #
      # Returns a printable version of self, enclosed in double-quotes, and
      # with special characters escaped.
      def inspect
        to_s.inspect
      end
    end
  end
end
