# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qpushbutton.html
    class QPushButton < RubyQt6::QtWidgets::QAbstractButton
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param text [QString]
      # @param parent [QWidget]
      # @return [QLabel]
      #
      # Constructs a label that displays the text.
      def initialize(text = "", parent = nil)
        _initialize(QtCore::QString.new(text), parent)
      end
    end
  end
end
