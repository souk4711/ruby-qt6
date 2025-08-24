# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qstring.html
    class QString
      # @!method initialize(str = "")
      #   @param str [String]
      #   @return [QString]
      #
      #   Constructs a string on str.
      #
      # @!visibility private
      def self.new(str = "")
        return str if str.is_a?(QString)
        allocate.tap { |o| o.__send__(:initialize, str) }
      end
    end
  end
end
