# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qtextstream.html
    class QTextStream < RubyQt6::QtCore::QIODeviceBase
      # @!parse class FieldAlignment    ; end
      # @!parse class NumberFlag        ; end
      # @!parse class RealNumberNotation; end
      # @!parse class Status            ; end
      rubyqt6_declare_enum_under QTextStream, QTextStream::FieldAlignment
      rubyqt6_declare_enum_under QTextStream, QTextStream::NumberFlag
      rubyqt6_declare_enum_under QTextStream, QTextStream::RealNumberNotation
      rubyqt6_declare_enum_under QTextStream, QTextStream::Status

      # @!parse class NumberFlags; end
      rubyqt6_declare_qflags QTextStream::NumberFlags, QTextStream::NumberFlag

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QTextStream]
      #
      # @overload initialize
      #
      # @overload initialize(device)
      #   @param device [QIODevice]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
