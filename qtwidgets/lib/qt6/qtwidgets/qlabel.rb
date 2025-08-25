# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qlabel.html
    class QLabel < RubyQt6::QtWidgets::QFrame
      # @!method initialize(text = "", parent = nil)
      #   @param text [QString]
      #   @param parent [QWidget]
      #   @return [QLabel]
      #
      #   Constructs a label that displays the text.
      #
      # @!visibility private
      alias_method :_initialize, :initialize
      def initialize(text = "", parent = nil)
        _initialize(QtCore::QString.new(text), parent)
      end
    end
  end
end
