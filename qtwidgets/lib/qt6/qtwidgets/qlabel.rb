# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qlabel.html
    class QLabel < RubyQt6::QtWidgets::QFrame
      # @!method initialize(str = "", parent = nil)
      #   @param str [QString]
      #   @param parent [QWidget]
      #   @return [QLabel]
      #
      #   Constructs a label that displays the text.
      #
      # @!visibility private
      alias_method :_initialize, :initialize
      def initialize(str = "", parent = nil)
        _initialize(QtCore::QString.new(str), parent)
      end
    end
  end
end
