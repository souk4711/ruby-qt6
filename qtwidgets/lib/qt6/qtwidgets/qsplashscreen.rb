# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qsplashscreen.html
    class QSplashScreen < RubyQt6::QtWidgets::QWidget
      # @!parse
      q_object do
        signal "messageChanged(QString)"
        slot "clearMessage()"
        slot "showMessage(QString,int,QColor)"
        slot "showMessage(QString,int)"
        slot "showMessage(QString)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param pixmap [QPixmap]
      # @return [QSplashScreen]
      def initialize(pixmap)
        _initialize(pixmap)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
