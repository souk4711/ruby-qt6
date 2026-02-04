# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qfileinfo.html
    class QFileInfo
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QFileInfo]
      #
      # @overload initialize
      #
      # @overload initialize(file)
      #   @param file [String, QString]
      #
      # @overload initialize(file)
      #   @param file [QFileDevice]
      #
      # @overload initialize(dir, file)
      #   @param dir [QDir]
      #   @param file [String, QString]
      def initialize(*args)
        T.args_nth_to_qstr(args, 0)
        T.args_nth_to_qstr(args, 1)
        _initialize(*args)
      end

      # @!visibility private
      def inspect
        T.inspect_struct(self, absolute_file_path: absolute_file_path.to_s)
      end
    end
  end
end
