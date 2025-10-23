# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstyleoptionframe.html
    class QStyleOptionFrame < RubyQt6::QtWidgets::QStyleOption
      # @!parse class StyleOptionType   ; end
      # @!parse class StyleOptionVersion; end
      # @!parse class FrameFeature      ; end
      rubyqt6_declare_enum_under QStyleOptionFrame, QStyleOptionFrame::StyleOptionType
      rubyqt6_declare_enum_under QStyleOptionFrame, QStyleOptionFrame::StyleOptionVersion
      rubyqt6_declare_enum_under QStyleOptionFrame, QStyleOptionFrame::FrameFeature
    end
  end
end
