# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qsplitterhandle.html
    class QSplitterHandle < RubyQt6::QtWidgets::QWidget
      # @!parse
      q_object do
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param orientation [Qt::Orientation]
      # @param parent [QSplitter]
      # @return [QSplitterHandle]
      def initialize(orientation, parent = nil)
        _initialize(orientation, parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
