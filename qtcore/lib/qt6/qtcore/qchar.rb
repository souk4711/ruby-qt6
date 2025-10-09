# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qchar.html
    class QChar
      # @!parse class Category        ; end
      # @!parse class CombiningClass  ; end
      # @!parse class Decomposition   ; end
      # @!parse class Direction       ; end
      # @!parse class JoiningType     ; end
      # @!parse class Script          ; end
      # @!parse class SpecialCharacter; end
      # @!parse class UnicodeVersion  ; end
      rubyqt6_declare_enum_under QChar, QChar::Category
      rubyqt6_declare_enum_under QChar, QChar::CombiningClass
      rubyqt6_declare_enum_under QChar, QChar::Decomposition
      rubyqt6_declare_enum_under QChar, QChar::Direction
      rubyqt6_declare_enum_under QChar, QChar::JoiningType
      rubyqt6_declare_enum_under QChar, QChar::Script
      rubyqt6_declare_enum_under QChar, QChar::SpecialCharacter
      rubyqt6_declare_enum_under QChar, QChar::UnicodeVersion

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QChar]
      #
      # @overload initialize(code)
      #   @param code [Integer]
      def initialize(*args)
        _initialize(*args)
      end

      # @!visibility private
      def to_s
        to_std_string
      end

      # @!visibility private
      def inspect
        T.q_inspect(self, str: to_s)
      end
    end
  end
end
