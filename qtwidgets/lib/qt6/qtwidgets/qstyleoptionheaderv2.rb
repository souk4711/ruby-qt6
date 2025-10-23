# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstyleoptionheaderv2.html
    class QStyleOptionHeaderV2 < RubyQt6::QtWidgets::QStyleOptionHeader
      # @!parse class StyleOptionType   ; end
      # @!parse class StyleOptionVersion; end
      rubyqt6_declare_enum_under QStyleOptionHeaderV2, QStyleOptionHeaderV2::StyleOptionType
      rubyqt6_declare_enum_under QStyleOptionHeaderV2, QStyleOptionHeaderV2::StyleOptionVersion
    end
  end
end
