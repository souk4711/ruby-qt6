# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstyleoptionheader.html
    class QStyleOptionHeader < RubyQt6::QtWidgets::QStyleOption
      # @!parse class StyleOptionType   ; end
      # @!parse class StyleOptionVersion; end
      # @!parse class SectionPosition   ; end
      # @!parse class SelectedPosition  ; end
      # @!parse class SortIndicator     ; end
      rubyqt6_declare_enum_under QStyleOptionHeader, QStyleOptionHeader::StyleOptionType
      rubyqt6_declare_enum_under QStyleOptionHeader, QStyleOptionHeader::StyleOptionVersion
      rubyqt6_declare_enum_under QStyleOptionHeader, QStyleOptionHeader::SectionPosition
      rubyqt6_declare_enum_under QStyleOptionHeader, QStyleOptionHeader::SelectedPosition
      rubyqt6_declare_enum_under QStyleOptionHeader, QStyleOptionHeader::SortIndicator
    end
  end
end
