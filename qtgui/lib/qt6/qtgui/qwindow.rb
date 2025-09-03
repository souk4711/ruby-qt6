# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qwindow.html
    class QWindow < RubyQt6::QtCore::QObject
      # @!parse class AncestorMode; end
      # @!parse class Visibility  ; end
      rubyqt6_include_constants QWindow, QWindow::AncestorMode
      rubyqt6_include_constants QWindow, QWindow::Visibility

      # @!visibility private
      alias_method :_initialize, :initialize

      # @!visibility private
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_rubyrice(self) if parent
      end

      # @!visibility private
      def set_parent(parent)
        _set_parent(parent)
        _take_ownership_from_rubyrice(self) if parent
      end
    end
  end
end
