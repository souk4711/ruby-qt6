# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qstring.html
    class QString
      include Comparable

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param str [String]
      # @return [QString]
      def initialize(str = "")
        _initialize(str)
      end

      # @!visibility private
      def contains(*args)
        T.args_nth_to_qstr(args, 0)
        _contains(*args)
      end

      # @!visibility private
      def ends_with(*args)
        T.args_nth_to_qstr(args, 0)
        _ends_with(*args)
      end

      # @!visibility private
      def index_of(*args)
        T.args_nth_to_qstr(args, 0)
        _index_of(*args).tap { |r| return nil if r == -1 }
      end
      alias_method :index, :index_of

      # @!visibility private
      def split(*args)
        T.args_nth_to_qstr(args, 0)
        _split(*args)
      end

      # @!visibility private
      def to_s
        to_std_string
      end

      # @!visibility private
      def to_str
        to_std_string
      end

      # @!visibility private
      def <=>(other)
        return nil unless other.respond_to?(:to_str)
        to_str <=> other.to_str
      end

      # @!visibility private
      alias_method :eql?, :==

      # @!visibility private
      def hash
        to_str.hash
      end

      # @!visibility private
      def inspect
        T.inspect_struct(self, str: to_s)
      end
    end
  end
end
