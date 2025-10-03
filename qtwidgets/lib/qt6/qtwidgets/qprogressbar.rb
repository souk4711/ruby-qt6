# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qprogressbar.html
    class QProgressBar < RubyQt6::QtWidgets::QWidget
      # @!parse class Direction; end
      rubyqt6_declare_enum_under QProgressBar, QProgressBar::Direction

      # @!parse
      q_object do
        signal "valueChanged(int)"
        slot "reset()"
        slot "setMaximum(int)"
        slot "setMinimum(int)"
        slot "setOrientation(Qt::Orientation)"
        slot "setRange(int,int)"
        slot "setValue(int)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QProgressBar]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
