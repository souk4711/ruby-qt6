# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qanystringview.html
    class QAnyStringView
      # @!visibility private
      alias_method :_initialize, :initialize

      class << self
        # @!visibility private
        def new(str = "")
          return str if str.is_a?(QAnyStringView)
          allocate.tap { |o| o.__send__(:initialize, str) }
        end
      end

      # @param str [QString]
      # @return [QAnyStringView]
      #
      # Constructs a string view on str.
      def initialize(str)
        _initialize(QString.new(str))
      end
    end
  end
end
