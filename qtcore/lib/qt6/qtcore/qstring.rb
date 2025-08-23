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
        str.is_a?(QString) ? str : super
      end
    end
  end
end
