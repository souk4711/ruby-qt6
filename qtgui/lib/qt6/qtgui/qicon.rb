# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qicon.html
    class QIcon
      # @!parse class Mode     ; end
      # @!parse class State    ; end
      # @!parse class ThemeIcon; end
      rubyqt6_include_constants QIcon, QIcon::Mode
      rubyqt6_include_constants QIcon, QIcon::State
      rubyqt6_include_constants QIcon, QIcon::ThemeIcon

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QIcon]
      #
      # @overload initialize(filename)
      #   @param filename [String, QString]
      #
      # @overload initialize(pixmap)
      #   @param pixmap [QPixmap]
      def initialize(*args)
        args[0] = T.to_qstr(args[0]) if args[0].is_a?(String)
        _initialize(*args)
      end
    end
  end
end
