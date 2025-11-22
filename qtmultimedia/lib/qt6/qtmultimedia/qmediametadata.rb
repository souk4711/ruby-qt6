# frozen_string_literal: true

module RubyQt6
  module QtMultimedia
    # @see https://doc.qt.io/qt-6/qmediametadata.html
    class QMediaMetaData
      # @!parse class Key; end
      rubyqt6_declare_enum_under QMediaMetaData, QMediaMetaData::Key

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QMediaMetaData]
      def initialize
        _initialize
      end
    end
  end
end
