# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qwidget.html
    class QWidget < RubyQt6::QtCore::QObject
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QWidget]
      #
      # Constructs a widget which is a child of parent, with widget flags set
      # to f.
      #
      # If parent is nullptr, the new widget becomes a window. If parent is
      # another widget, this widget becomes a child window inside parent. The
      # new widget is deleted when its parent is deleted.
      #
      # The widget flags argument, f, is normally 0, but it can be set to
      # customize the frame of a window (i.e. parent must be nullptr). To
      # customize the frame, use a value composed from the bitwise OR of any
      # of the window flags.
      #
      # If you add a child widget to an already visible widget you must
      # explicitly show the child to make it visible.
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_rice(self) if parent
      end
    end
  end
end
