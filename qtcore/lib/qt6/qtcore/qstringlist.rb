# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qstringlist.html
    class QStringList
      # @!visibility private
      def join(separator = "")
        _join(T.to_qstr(separator))
      end

      # @!visibility private
      def inspect
        T.inspect_struct(self, ary: to_a.map(&:to_s))
      end
    end
  end
end
