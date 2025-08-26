# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qfont.html
    class QFont
      # @!visibility private
      alias_method :_initialize, :initialize

      # @!visibility private
      rubyqt6_include_constants QFont, QFont::Capitalization
      rubyqt6_include_constants QFont, QFont::HintingPreference
      rubyqt6_include_constants QFont, QFont::SpacingType
      rubyqt6_include_constants QFont, QFont::Stretch
      rubyqt6_include_constants QFont, QFont::Style
      rubyqt6_include_constants QFont, QFont::StyleHint
      rubyqt6_include_constants QFont, QFont::StyleStrategy
      rubyqt6_include_constants QFont, QFont::Weight

      # @param family [QString]
      # @param point_size [Integer]
      # @param weight [Integer]
      # @param italic [Boolean]
      # @return [QFont]
      #
      # If pointSize is zero or negative, the point size of the font is set
      # to a system-dependent default value. Generally, this is 12 points.
      #
      # The family name may optionally also include a foundry name, e.g.
      # "Helvetica [Cronyx]". If the family is available from more than one
      # foundry and the foundry isn't specified, an arbitrary foundry is
      # chosen. If the family isn't available a family will be set using
      # the font matching algorithm.
      #
      # This will split the family string on a comma and call setFamilies()
      # with the resulting list. To preserve a font that uses a comma in
      # its name, use the constructor that takes a QStringList.
      def initialize(family, point_size = -1, weight = -1, italic = false)
        _initialize(QtCore::QString.new(family), point_size, weight, italic)
      end
    end
  end
end
