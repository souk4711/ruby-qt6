# frozen_string_literal: true

module RubyQt6
  module QtUiTools
    # @see https://doc.qt.io/qt-6/quiloader.html
    class QUiLoader < RubyQt6::QtCore::QObject
      # @!parse
      q_object do
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QUiLoader]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
