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

      # @return [QUiLoader]
      def initialize
        _initialize
      end
    end
  end
end
