# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qmovie.html
    class QMovie < RubyQt6::QtCore::QObject
      # @!parse class CacheMode ; end
      # @!parse class MovieState; end
      rubyqt6_declare_enum_under QMovie, QMovie::CacheMode
      rubyqt6_declare_enum_under QMovie, QMovie::MovieState

      # @!parse
      q_object do
        signal "error(QImageReader::ImageReaderError)"
        signal "finished()"
        signal "frameChanged(int)"
        signal "resized(QSize)"
        signal "started()"
        signal "stateChanged(QMovie::MovieState)"
        signal "updated(QRect)"
        slot "jumpToNextFrame()"
        slot "setPaused(bool)"
        slot "setSpeed(int)"
        slot "start()"
        slot "stop()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QMovie]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
