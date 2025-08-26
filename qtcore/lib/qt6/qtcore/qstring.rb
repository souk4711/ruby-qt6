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
    end
  end
end
