# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qfontinfo.html
    class QFontInfo
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param font [QFont]
      # @return [QFontInfo]
      def initialize(font)
        _initialize(font)
      end
    end
  end
end
