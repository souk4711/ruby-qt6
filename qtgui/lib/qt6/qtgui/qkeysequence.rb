# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qkeysequence.html
    class QKeySequence
      # @!parse class SequenceFormat; end
      # @!parse class SequenceMatch ; end
      # @!parse class StandardKey   ; end
      rubyqt6_declare_enum_under QKeySequence, QKeySequence::SequenceFormat
      rubyqt6_declare_enum_under QKeySequence, QKeySequence::SequenceMatch
      rubyqt6_declare_enum_under QKeySequence, QKeySequence::StandardKey

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QKeySequence]
      #
      # @overload initialize
      #
      # @overload initialize(key)
      #   @param key [Integer]
      #
      # @overload initialize(key)
      #   @param key [QKeySequence::StandardKey]
      #
      # @overload initialize(key)
      #   @param key [String, QString]
      def initialize(*args)
        args[0] = T.to_qstr(args[0]) if args[0].is_a?(String)
        _initialize(*args)
      end

      # @!visibility private
      def to_s
        to_string.to_s
      end

      # @!visibility private
      def inspect
        T.q_inspect(self, str: to_s)
      end
    end
  end
end
