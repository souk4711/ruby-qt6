# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qmenubar.html
    class QMenuBar < RubyQt6::QtWidgets::QWidget
      # @!parse
      q_object do
        signal "hovered(QAction*)"
        signal "triggered(QAction*)"
        slot "setVisible(bool)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QMenuBar]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end

      # @!visibility private
      def add_menu(*args)
        T.args_nth_to_qstr(args, -1)
        _add_menu(*args)
      end
    end
  end
end
