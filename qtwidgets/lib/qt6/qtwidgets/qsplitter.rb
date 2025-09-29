# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qsplitter.html
    class QSplitter < RubyQt6::QtWidgets::QFrame
      # @!parse
      q_object do
        signal "splitterMoved(int,int)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param orientation [Qt::Orientation]
      # @param parent [QWidget]
      # @return [QSplitter]
      def initialize(orientation, parent = nil)
        _initialize(orientation, parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
