# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qboxlayout.html
    class QBoxLayout < RubyQt6::QtWidgets::QLayout
      # @!parse class Direction; end
      rubyqt6_include_constants QBoxLayout, QBoxLayout::Direction

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param direction [QBoxLayout::Direction]
      # @param parent [QWidget]
      # @return [QBoxLayout]
      #
      # Constructs a new QBoxLayout with direction dir and parent widget
      # parent.
      #
      # The layout is set directly as the top-level layout for parent. There
      # can be only one top-level layout for a widget. It is returned by
      # QWidget::layout().
      def initialize(direction, parent = nil)
        _initialize(direction, parent)
        _take_ownership_from_rubyrice(self) if parent
      end

      # @return [QBoxLayout::Direction]
      #
      # Returns the direction of the box. addWidget() and addSpacing() work in
      # this direction; the stretch stretches in this direction.
      def direction
        _direction
      end

      # @param direction [QBoxLayout::Direction]
      # @return [nil]
      #
      # Sets the direction of this layout to direction.
      def set_direction(direction)
        _set_direction(direction)
      end

      # @param layout [QLayout]
      # @param stretch [Integer]
      # @return [nil]
      #
      # Adds layout to the end of the box, with serial stretch factor stretch.
      def add_layout(layout, stretch = 0)
        _add_layout(layout, stretch)
      end

      # @param item [QSpacerItem]
      # @return [nil]
      #
      # Adds spacerItem to the end of this box layout.
      def add_spacer_item(item)
        _add_spacer_item(item)
      end

      # @param size [Integer]
      # @return [nil]
      #
      # Adds a non-stretchable space (a QSpacerItem) with size size to the
      # end of this box layout. QBoxLayout provides default margin and
      # spacing. This function adds additional space.
      def add_spacing(size)
        _add_spacing(size)
      end

      # @param stretch [Integer]
      # @return [nil]
      #
      # Adds a stretchable space (a QSpacerItem) with zero minimum size and
      # stretch factor stretch to the end of this box layout.
      def add_stretch(stretch = 0)
        _add_stretch(stretch)
      end

      # @param size [Integer]
      # @return [nil]
      #
      # Limits the perpendicular dimension of the box (e.g. height if the
      # box is LeftToRight) to a minimum of size. Other constraints may
      # increase the limit.
      def add_strut(size)
        _add_strut(size)
      end

      # @param widget [QWidget]
      # @param stretch [Integer]
      # @return [nil]
      #
      # Adds widget to the end of this box layout, with a stretch factor of
      # stretch and alignment alignment.
      #
      # The stretch factor applies only in the direction of the QBoxLayout,
      # and is relative to the other boxes and widgets in this QBoxLayout.
      # Widgets and boxes with higher stretch factors grow more.
      #
      # If the stretch factor is 0 and nothing else in the QBoxLayout has a
      # stretch factor greater than zero, the space is distributed according
      # to the QWidget:sizePolicy() of each widget that's involved.
      #
      # The alignment is specified by alignment. The default alignment is 0,
      # which means that the widget fills the entire cell.
      def add_widget(widget, stretch = 0)
        _add_widget(widget, stretch)
      end

      # @param index [Integer]
      # @param item [QLayoutItem]
      # @return [nil]
      #
      # Inserts item into this box layout at position index. Index must be
      # either negative or within the range 0 to count(), inclusive. If
      # index is negative or count(), the item is added at the end.
      def insert_item(index, item)
        _insert_item(index, item)
      end

      # @param index [Integer]
      # @param layout [QLayout]
      # @param stretch [Integer]
      #
      # Inserts layout at position index, with stretch factor stretch. If
      # index is negative, the layout is added at the end.
      #
      # layout becomes a child of the box layout.
      def insert_layout(index, layout, stretch = 0)
        _insert_layout(index, layout, stretch)
      end

      # @param index {Integer]
      # @param item [QSpacerItem]
      # @return [nil]
      #
      # Inserts spacerItem at position index, with zero minimum size and
      # stretch factor. If index is negative the space is added at the end.
      def insert_spacer_item(index, item)
        _insert_spacer_item(index, item)
      end

      # @param index {Integer]
      # @param size [Integer]
      # @return [nil]
      #
      # Inserts a non-stretchable space (a QSpacerItem) at position index,
      # with size size. If index is negative the space is added at the end.
      #
      # The box layout has default margin and spacing. This function adds
      # additional space.
      def insert_spacing(index, size)
        _insert_spacing(index, size)
      end

      # @param index {Integer]
      # @param stretch [Integer]
      # @return [nil]
      #
      # Inserts a stretchable space (a QSpacerItem) at position index, with
      # zero minimum size and stretch factor stretch. If index is negative
      # the space is added at the end.
      def insert_stretch(index, stretch = 0)
        _insert_stretch(index, stretch)
      end

      # @param index {Integer]
      # @param widget [QWidget]
      # @param stretch [Integer]
      #
      # Inserts widget at position index, with stretch factor stretch and
      # alignment alignment. If index is negative, the widget is added at
      # the end.
      #
      # The stretch factor applies only in the direction of the QBoxLayout,
      # and is relative to the other boxes and widgets in this QBoxLayout.
      # Widgets and boxes with higher stretch factors grow more.
      #
      # If the stretch factor is 0 and nothing else in the QBoxLayout has a
      # stretch factor greater than zero, the space is distributed according
      # to the QWidget:sizePolicy() of each widget that's involved.
      #
      # The alignment is specified by alignment. The default alignment is 0,
      # which means that the widget fills the entire cell.
      def insert_widget(index, widget, stretch = 0)
        _insert_widget(index, widget, stretch)
      end

      # @return [Integer]
      #
      # Returns the stretch factor at position index.
      def stretch(index)
        _stretch(index)
      end

      # @param index {Integer]
      # @param stretch [Integer]
      # @return [nil]
      #
      # Sets the stretch factor at position index. to stretch.
      def set_stretch(index, stretch)
        _set_stretch(index, stretch)
      end

      # @param item [QLayout, QWidget]
      # @param stretch [Integer]
      # @return [Boolean]
      #
      # Sets the stretch factor for the layout layout to stretch and returns
      # true if layout is found in this layout (not including child layouts);
      # otherwise returns false.
      def set_stretch_factor(item, stretch)
        _set_stretch_factor(item, stretch)
      end
    end
  end
end
