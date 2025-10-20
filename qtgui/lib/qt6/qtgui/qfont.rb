# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qfont.html
    class QFont
      # @!parse class Capitalization   ; end
      # @!parse class HintingPreference; end
      # @!parse class SpacingType      ; end
      # @!parse class Stretch          ; end
      # @!parse class Style            ; end
      # @!parse class StyleHint        ; end
      # @!parse class StyleStrategy    ; end
      # @!parse class Weight           ; end
      rubyqt6_declare_enum_under QFont, QFont::Capitalization
      rubyqt6_declare_enum_under QFont, QFont::HintingPreference
      rubyqt6_declare_enum_under QFont, QFont::SpacingType
      rubyqt6_declare_enum_under QFont, QFont::Stretch
      rubyqt6_declare_enum_under QFont, QFont::Style
      rubyqt6_declare_enum_under QFont, QFont::StyleHint
      rubyqt6_declare_enum_under QFont, QFont::StyleStrategy
      rubyqt6_declare_enum_under QFont, QFont::Weight

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QFont]
      #
      # @overload initialize
      #
      # @overload initialize(family)
      #   @param family [String, QString]
      #
      # @overload initialize(family, point_size)
      #   @param family [String, QString]
      #   @param point_size [Integer]
      #
      # @overload initialize(family, point_size, weight)
      #   @param family [String, QString]
      #   @param point_size [Integer]
      #   @param weight [QFont::Weight]
      #
      # @overload initialize(families)
      #   @param families [QStringList]
      #
      # @overload initialize(families, point_size)
      #   @param families [QStringList]
      #   @param point_size [Integer]
      #
      # @overload initialize(families, point_size, weight)
      #   @param families [QStringList]
      #   @param point_size [Integer]
      #   @param weight [QFont::Weight]
      def initialize(*args)
        T.args_nth_to_qstr(args, 0)
        _initialize(*args)
      end

      # @!visibility private
      def to_s
        to_string.to_s
      end

      # @!visibility private
      def inspect
        T.inspect_struct(self, str: to_s)
      end
    end
  end
end
