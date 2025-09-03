# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qstring.html
    class QString
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
    end
  end
end
