# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qdir.html
    class QDir
      # @!parse class Filter   ; end
      # @!parse class Filters  ; end
      # @!parse class SortFlag ; end
      # @!parse class SortFlags; end
      rubyqt6_declare_enum_under QDir, QDir::Filter
      rubyqt6_declare_enum_under QDir, QDir::SortFlag
      rubyqt6_declare_qflags QDir::Filters, QDir::Filter
      rubyqt6_declare_qflags QDir::SortFlags, QDir::SortFlag

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
        T.args_nth_to_qstr(args, 0)
        T.args_nth_to_qstr(args, 1)
        _initialize(*args)
      end

      # @!visibility private
      def inspect
        T.inspect_struct(self, absolute_path: absolute_path.to_s)
      end
    end
  end
end
