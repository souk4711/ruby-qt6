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
        args[0] = T.to_qstr(args[0]) if args[0].is_a?(String)
        args[1] = T.to_qstr(args[1]) if args[1].is_a?(String)
        _initialize(*args)
      end
    end
  end
end
