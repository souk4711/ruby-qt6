# frozen_string_literal: true

module RubyQt6
  module QtMultimediaWidgets
    # @see https://doc.qt.io/qt-6/qvideowidget.html
    class QVideoWidget < RubyQt6::QtWidgets::QWidget
      # @!parse
      q_object do
        signal "aspectRatioModeChanged(Qt::AspectRatioMode)"
        signal "fullScreenChanged(bool)"
        slot "setAspectRatioMode(Qt::AspectRatioMode)"
        slot "setFullScreen(bool)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QVideoWidget]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
