# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qtextbrowser.html
    class QTextBrowser < RubyQt6::QtWidgets::QTextEdit
      # @!parse
      q_object do
        signal "anchorClicked(QUrl)"
        signal "backwardAvailable(bool)"
        signal "forwardAvailable(bool)"
        signal "highlighted(QUrl)"
        signal "historyChanged()"
        signal "sourceChanged(QUrl)"
        slot "backward()"
        slot "forward()"
        slot "home()"
        slot "reload()"
        slot "setSource(QUrl,QTextDocument::ResourceType)"
        slot "setSource(QUrl)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QTextBrowser]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
