# frozen_string_literal: true

module RubyQt6
  module KCoreAddons
    # @see https://api.kde.org/kformat.html
    class KFormat
      # @!parse class BinarySizeUnits      ; end
      # @!parse class BinaryUnitDialect    ; end
      # @!parse class DistanceFormatOption ; end
      # @!parse class DurationFormatOption ; end
      # @!parse class TimeFormatOption     ; end
      # @!parse class Unit                 ; end
      # @!parse class UnitPrefix           ; end
      # @!parse class DistanceFormatOptions; end
      # @!parse class DurationFormatOptions; end
      # @!parse class TimeFormatOptions    ; end
      rubyqt6_declare_enum_under KFormat, KFormat::BinarySizeUnits
      rubyqt6_declare_enum_under KFormat, KFormat::BinaryUnitDialect
      rubyqt6_declare_enum_under KFormat, KFormat::DistanceFormatOption
      rubyqt6_declare_enum_under KFormat, KFormat::DurationFormatOption
      rubyqt6_declare_enum_under KFormat, KFormat::TimeFormatOption
      rubyqt6_declare_enum_under KFormat, KFormat::Unit
      rubyqt6_declare_enum_under KFormat, KFormat::UnitPrefix
      rubyqt6_declare_qflags KFormat::DistanceFormatOptions, KFormat::DistanceFormatOption
      rubyqt6_declare_qflags KFormat::DurationFormatOptions, KFormat::DurationFormatOption
      rubyqt6_declare_qflags KFormat::TimeFormatOptions, KFormat::TimeFormatOption

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [KFormat]
      def initialize
        _initialize
      end

      # @!visibility private
      def format_distance(distance, options = nil)
        options ||= KFormat::LocaleDistanceUnits
        _format_distance(distance, T.to_qflags(options))
      end

      # @!visibility private
      def format_duration(msecs, options = nil)
        options ||= KFormat::DefaultDuration
        _format_duration(msecs, T.to_qflags(options))
      end

      # @!visibility private
      def format_time(datetime, format, options = nil)
        options ||= KFormat::DoNotAddTimeZone
        _format_time(datetime, format, T.to_qflags(options))
      end
    end
  end
end
