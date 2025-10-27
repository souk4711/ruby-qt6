# frozen_string_literal: true

module RubyQt6
  module QtQuick
    # @see https://doc.qt.io/qt-6/qquickview.html
    class QQuickView < RubyQt6::QtQuick::QQuickWindow
      # @!parse
      q_object do
        signal "statusChanged(QQuickView::Status)"
        slot "loadFromModule(QAnyStringView,QAnyStringView)"
        slot "setInitialProperties(QVariantMap)"
        slot "setSource(QUrl)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWindow]
      # @return [QQuickView]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end

      # @!visibility private
      def load_from_module(uri, type_name)
        _load_from_module(T.to_qanystringview(uri), T.to_qanystringview(type_name))
      end
    end
  end
end
