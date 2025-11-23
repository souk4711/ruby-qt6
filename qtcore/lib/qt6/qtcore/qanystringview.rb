# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qanystringview.html
    class QAnyStringView
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param str [String, QString]
      # @return [QAnyStringView]
      def initialize(str)
        _initialize(T.to_qstr(str))
      end

      # @!visibility private
      def to_s
        to_string.to_s
      end

      # @!visibility private
      def inspect
        T.inspect_struct(self, str: to_s)
      end
    end
  end
end
