# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qanystringview.html
    class QAnyStringView
      # @!method initialize(str = "")
      #   @param str [QString]
      #   @return [QAnyStringView]
      #
      #   Constructs a string view on str.
      #
      # @!visibility private
      def self.new(str = "")
        return str if str.is_a?(QAnyStringView)
        allocate.tap { |o| o.__send__(:initialize, QString.new(str)) }
      end
    end
  end
end
