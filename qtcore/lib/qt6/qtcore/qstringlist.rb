# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qstringlist.html
    class QStringList
      # @!visibility private
      def to_a
        (0...size).map { |i| at(i) }
      end

      # @!visibility private
      def to_ary
        (0...size).map { |i| at(i) }
      end

      # @!visibility private
      def inspect
        T.q_inspect(self, ary: to_a.map(&:to_s))
      end
    end
  end
end
