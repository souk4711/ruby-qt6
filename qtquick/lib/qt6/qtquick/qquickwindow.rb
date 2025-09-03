# frozen_string_literal: true

module RubyQt6
  module QtQuick
    # @see https://doc.qt.io/qt-6/qquickwindow.html
    class QQuickWindow < RubyQt6::QtGui::QWindow
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWindow]
      # @return [QQuickWindow]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_rubyrice(self) if parent
      end
    end
  end
end
