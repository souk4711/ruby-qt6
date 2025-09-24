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
      rubyqt6_include_constants QFont, QFont::Capitalization
      rubyqt6_include_constants QFont, QFont::HintingPreference
      rubyqt6_include_constants QFont, QFont::SpacingType
      rubyqt6_include_constants QFont, QFont::Stretch
      rubyqt6_include_constants QFont, QFont::Style
      rubyqt6_include_constants QFont, QFont::StyleHint
      rubyqt6_include_constants QFont, QFont::StyleStrategy
      rubyqt6_include_constants QFont, QFont::Weight

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QFont]
      #
      # @overload initialize(family, point_size = -1, Weight = -1, italic = false)
      #   @param family [QString]
      #   @param point_size [Integer]
      #   @param weight [Integer]
      #   @param italic [Boolean]
      #
      # @overload initialize(families, point_size = -1, Weight = -1, italic = false)
      #   @param families [QStringList]
      #   @param point_size [Integer]
      #   @param weight [Integer]
      #   @param italic [Boolean]
      def initialize(*args)
        args[0] = T.to_qstr(args[0]) if args[0].is_a?(String)
        _initialize(*args)
      end
    end
  end
end
