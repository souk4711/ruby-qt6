# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qdatetime.html
    class QDateTime
      include Comparable

      # @!parse class TransitionResolution; end
      rubyqt6_declare_enum_under QDateTime, QDateTime::TransitionResolution

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QDateTime]
      #
      # @overload initialize
      #
      # @overload initialize(date, time)
      #   @param date [QDate]
      #   @param time [QTime]
      #
      # @overload initialize(date, time, time_zone)
      #   @param date [QDate]
      #   @param time [QTime]
      #   @param time_zone [QTimeZone]
      def initialize(*args)
        _initialize(*args)
      end

      # @!visibility private
      def to_string(*args)
        T.args_nth_to_qstr(args, 0)
        _to_string(*args)
      end

      # @!visibility private
      def to_s
        _to_string(QtCore::Qt::RFC2822Date).to_s
      end

      # @!visibility private
      def <=>(other)
        return nil unless other.is_a?(QtCore::QDateTime)
        self.class._operator_compare(self, other)
      end

      # @!visibility private
      def inspect
        T.inspect_struct(self, str: to_s)
      end
    end
  end
end
