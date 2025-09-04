# frozen_string_literal: true

module RubyQt6
  module QtQuick
    # @see https://doc.qt.io/qt-6/qquickitem.html
    class QQuickItem < RubyQt6::QtCore::QObject
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QQuickItem]
      # @return [QQuickItem]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_rubyrice(self) if parent
      end

      # @!visibility private
      def set_parent_item(parent)
        _set_parent_item(parent)
        _take_ownership_from_rubyrice(self) if parent
      end
    end
  end
end
