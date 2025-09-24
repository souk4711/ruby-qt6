# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qpushbutton.html
    class QPushButton < RubyQt6::QtWidgets::QAbstractButton
      # @!visibility private
      q_object do
        slot "showMenu()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param text [String, QString]
      # @param parent [QWidget]
      # @return [QLabel]
      def initialize(text, parent = nil)
        _initialize(T.to_qstr(text), parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
