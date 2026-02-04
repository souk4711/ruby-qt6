# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qfile.html
    class QFile < RubyQt6::QtCore::QFileDevice
      # @!parse
      q_object do
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param name [String, QString]
      # @return [QFile]
      def initialize(name)
        _initialize(T.to_qstr(name))
      end

      # @!visibility private
      def inspect
        T.inspect_struct(self, file_name: file_name.to_s)
      end
    end
  end
end
