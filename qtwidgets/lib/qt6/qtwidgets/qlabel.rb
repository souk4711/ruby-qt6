# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qlabel.html
    class QLabel < RubyQt6::QtWidgets::QFrame
      # @!visibility private
      q_object do
        signal "linkActivated(QString)"
        signal "linkHovered(QString)"
        slot "clear()"
        slot "setMovie(QMovie*)"
        slot "setNum(int)"
        slot "setNum(double)"
        slot "setPicture(QPicture)"
        slot "setPixmap(QPixmap)"
        slot "setText(QString)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param text [QString]
      # @param parent [QWidget]
      # @return [QLabel]
      def initialize(text, parent = nil)
        _initialize(QtCore::QString.new(text), parent)
        _take_ownership_from_ruby(self) if parent
      end

      # @!visibility private
      def set_text(text)
        _set_text(QtCore::QString.new(text))
      end
    end
  end
end
