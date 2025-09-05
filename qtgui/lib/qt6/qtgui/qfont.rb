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

      # @param family [QString]
      # @param point_size [Integer]
      # @param weight [Integer]
      # @param italic [Boolean]
      # @return [QFont]
      def initialize(family, point_size = -1, weight = -1, italic = false)
        _initialize(QtCore::QString.new(family), point_size, weight, italic)
      end
    end
  end
end
