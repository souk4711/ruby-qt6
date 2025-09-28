# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qcommandlinkbutton.html
    class QCommandLinkButton < RubyQt6::QtWidgets::QPushButton
      # @!parse
      q_object do
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param text [String, QString]
      # @param description [String, QString]
      # @param parent [QWidget]
      # @return [QCommandLinkButton]
      def initialize(text, description, parent = nil)
        _initialize(T.to_qstr(text), T.to_qstr(description), parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
