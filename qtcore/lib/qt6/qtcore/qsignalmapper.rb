# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qsignalmapper.html
    class QSignalMapper < RubyQt6::QtCore::QObject
      # @!parse
      q_object do
        signal "mappedInt(int)"
        signal "mappedObject(QObject*)"
        signal "mappedString(QString)"
        slot "map()"
        slot "map(QObject*)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QSignalMapper]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end

      # @!visibility private
      def set_mapping(*args)
        T.args_nth_to_qstr(args, 1)
        _set_mapping(*args)
      end
    end
  end
end
