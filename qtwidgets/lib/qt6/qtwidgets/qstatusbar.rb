# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstatusbar.html
    class QStatusBar < RubyQt6::QtWidgets::QWidget
      # @!parse
      q_object do
        signal "messageChanged(QString)"
        slot "clearMessage()"
        slot "showMessage(QString,int)"
        slot "showMessage(QString)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QStatusBar]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
