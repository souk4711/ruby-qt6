# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qdir.html
    class QDir
      # @!parse class Filter  ; end
      # @!parse class SortFlag; end
      rubyqt6_declare_enum_under QDir, QDir::Filter
      rubyqt6_declare_enum_under QDir, QDir::SortFlag

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QDir]
      #
      # @overload initialize(path)
      #   @param path [String, QString]
      #
      # @overload initialize(path, name_filter)
      #   @param path [String, QString]
      #   @param name_filter [String, QString]
      def initialize(*args)
        args[0] = T.to_qstr(args[0]) if args[0].is_a?(String)
        args[1] = T.to_qstr(args[1]) if args[1].is_a?(String)
        _initialize(*args)
      end
    end
  end
end
