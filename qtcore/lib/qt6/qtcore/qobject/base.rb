# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qobject.html
    class QObject
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QObject]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_rubyrice(self) if parent
      end

      # @!visibility private
      def set_parent(parent)
        _set_parent(parent)
        _take_ownership_from_rubyrice(self) if parent
      end

      private

      def _take_ownership_from_rubyrice(object)
        self.class._take_ownership_from_rubyrice(object)
      end
    end
  end
end
