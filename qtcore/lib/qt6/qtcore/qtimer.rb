# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qtimer.html
    class QTimer < RubyQt6::QtCore::QObject
      # @!parse
      q_object do
        signal "timeout()"
        slot "start(int)"
        slot "start()"
        slot "stop()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @!visibility private
      def self.single_shot(nsec, receiver, member)
        metamethod = QtCore::Private::MetaObject.find_receiver_metamethod!(receiver, member, nil)
        _single_shot(nsec, receiver, metamethod.qsignature)
      end

      # @param parent [QObject]
      # @return [QTimer]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
