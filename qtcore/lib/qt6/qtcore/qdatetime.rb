# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qdatetime.html
    class QDateTime
      # @!parse class TransitionResolution; end
      rubyqt6_include_constants QDateTime, QDateTime::TransitionResolution

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QDateTime]
      #
      # @overload initialize(date, time, time_zone, resolve = QDateTime::LegacyBehavior)
      #   @param date [QDate]
      #   @param time [QTime]
      #   @param time_zone [QTimeZone]
      #   @param resolve [QDateTime::TransitionResolution]
      #
      # @overload initialize(date, time, resolve = QDateTime::LegacyBehavior)
      #   @param date [QDate]
      #   @param time [QTime]
      #   @param resolve [QDateTime::TransitionResolution]
      def initialize(*args)
        _initialize(*args)
      end

      # @!visibility private
      def to_s
        to_string(Qt::RFC2822Date).to_s
      end

      # @!visibility private
      def inspect
        T.q_inspect(self, str: to_s)
      end
    end
  end
end
