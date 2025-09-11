# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qbytearray.html
    class QByteArray
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param str [String]
      # @return [QByteArray]
      def initialize(str)
        _initialize(str)
      end
    end
  end
end
