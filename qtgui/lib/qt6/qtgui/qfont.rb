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
    end
  end
end
