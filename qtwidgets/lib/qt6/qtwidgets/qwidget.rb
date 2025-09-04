# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qwidget.html
    class QWidget < RubyQt6::QtCore::QObject
      # @!parse class RenderFlag; end
      rubyqt6_include_constants QWidget, QWidget::RenderFlag

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QWidget]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_rubyrice(self) if parent
      end

      # @!visibility private
      def set_parent(parent, f = nil)
        f.nil? ? _set_parent(parent) : _set_parent(parent, f)
        _take_ownership_from_rubyrice(self) if parent
      end
    end
  end
end
