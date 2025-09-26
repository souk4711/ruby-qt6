# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qkeysequence.html
    class QKeySequence
      # @!parse class SequenceFormat; end
      # @!parse class SequenceMatch ; end
      # @!parse class StandardKey   ; end
      rubyqt6_include_constants QKeySequence, QKeySequence::SequenceFormat
      rubyqt6_include_constants QKeySequence, QKeySequence::SequenceMatch
      rubyqt6_include_constants QKeySequence, QKeySequence::StandardKey

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QKeySequence]
      #
      # @overload initialize
      #
      # @overload initialize(key)
      #   @param key [QKeySequence::StandardKey]
      #
      # @overload initialize(key, format = QKeySequence::SequenceFormat::NativeText)
      #   @param key [String, QString]
      #   @param format [QKeySequence::SequenceFormat]
      #
      # @overload initialize(k1, k2 = 0, k3 = 0, k4 = 0)
      #   @param k1 [Integer]
      #   @param k2 [Integer]
      #   @param k3 [Integer]
      #   @param k4 [Integer]
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
