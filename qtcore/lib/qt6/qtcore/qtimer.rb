# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qtimer.html
    class QTimer < RubyQt6::QtCore::QObject
      # @!visibility private
      def self.single_shot(nsec, receiver, member)
        metamethod = QtCore::Private::MetaObject.find_receiver_metamethod!(receiver, member)
        _single_shot(nsec, receiver, metamethod.qsignature)
      end

      # @!parse
      q_object do
        signal "timeout()"
        slot "start(int)"
        slot "start()"
        slot "stop()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QTimer]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
