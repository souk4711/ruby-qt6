# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qgridlayout.html
    class QGridLayout < RubyQt6::QtWidgets::QLayout
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QGridLayout]
      #
      # Constructs a new QGridLayout with parent widget, parent. The layout
      # has one row and one column initially, and will expand when new items
      # are inserted.
      #
      # The layout is set directly as the top-level layout for parent. There
      # can be only one top-level layout for a widget. It is returned by
      # QWidget::layout().
      #
      # If parent is nullptr, then you must insert this grid layout into
      # another layout, or set it as a widget's layout using
      # QWidget::setLayout().
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_rubyrice(self) if parent
      end

      # @return [Integer]
      #
      # This property holds the spacing between widgets that are laid out side
      # by side.
      #
      # If no value is explicitly set, the layout's horizontal spacing is
      # inherited from the parent layout, or from the style settings for the
      # parent widget.
      def horizontal_spacing
        _horizontal_spacing
      end

      # @return [Integer]
      #
      # This property holds the spacing between widgets that are laid out on
      # top of each other.
      #
      # If no value is explicitly set, the layout's vertical spacing is
      # inherited from the parent layout, or from the style settings for
      # the parent widget.
      def vertical_spacing
        _vertical_spacing
      end

      # @param spacing [Integer]
      # @return [nil]
      #
      # Sets the layout's horizontalSpacing property.
      def set_horizontal_spacing(spacing)
        _set_horizontal_spacing(spacing)
      end

      # @param spacing [Integer]
      # @return [nil]
      #
      # Sets the layout's verticalSpacing property.
      def set_vertical_spacing(spacing)
        _set_vertical_spacing(spacing)
      end

      # @param item [QLayoutItem]
      # @param row [Integer]
      # @param column [Integer]
      # @param row_span [Integer]
      # @param column_span [Integer]
      # @return [nil]
      #
      # Adds item at position row, column, spanning rowSpan rows and
      # columnSpan columns, and aligns it according to alignment. If
      # rowSpan and/or columnSpan is -1, then the item will extend to
      # the bottom and/or right edge, respectively. The layout takes
      # ownership of the item
      #
      # Warning: Do not use this function to add child layouts or child
      # widget items. Use addLayout() or addWidget() instead.
      def add_item(item, row, column, row_span = 1, column_span = 1)
        _add_item(item, row, column, row_span, column_span)
      end

      # @return [nil]
      # @overload add_layout(layout, row, column)
      #   @param layout [QLayout]
      #   @param row [Integer]
      #   @param column [Integer]
      # @overload add_layout(layout, row, column, row_span, column_span)
      #   @param layout [QLayout]
      #   @param row [Integer]
      #   @param column [Integer]
      #   @param row_span [Integer]
      #   @param column_span [Integer]
      #
      # Places the layout at position (row, column) in the grid. The
      # top-left position is (0, 0).
      #
      # The alignment is specified by alignment. The default alignment is
      # 0, which means that the widget fills the entire cell.
      #
      # A non-zero alignment indicates that the layout should not grow to
      # fill the available space but should be sized according to sizeHint().
      #
      # layout becomes a child of the grid layout.
      def add_layout(*args)
        _add_layout(*args)
      end

      # @return [nil]
      # @overload add_widget(widget, row, column)
      #   @param widget [QWidget]
      #   @param row [Integer]
      #   @param column [Integer]
      # @overload add_widget(widget, row, column, row_span, column_span)
      #   @param widget [QWidget]
      #   @param row [Integer]
      #   @param column [Integer]
      #   @param row_span [Integer]
      #   @param column_span [Integer]
      #
      # Adds the given widget to the cell grid at row, column. The top-left
      # position is (0, 0) by default.
      #
      # The alignment is specified by alignment. The default alignment is 0,
      # which means that the widget fills the entire cell.
      def add_widget(*args)
        _add_widget(*args)
      end

      # @return [Qt::Corner]
      #
      # Returns the corner that's used for the grid's origin, i.e. for
      # position (0, 0).
      def origin_corner
        _origin_corner
      end

      # @param row [Integer]
      # @return [Integer]
      #
      # Returns the stretch factor for row row.
      def row_stretch(row)
        _row_stretch(row)
      end

      # @param column [Integer]
      # @return [Integer]
      #
      # Returns the stretch factor for column column.
      def column_stretch(column)
        _column_stretch(column)
      end

      # @param row [Integer]
      # @return [Integer]
      #
      # Returns the minimum height set for row row.
      def row_minimum_height(row)
        _row_minimum_height(row)
      end

      # @param column [Integer]
      # @return [Integer]
      #
      # Returns the minimum width set for column column.
      def column_minimum_width(column)
        _column_minimum_width(column)
      end

      # @param corner [Qt::Corner]
      # @return [nil]
      #
      # Sets the grid's origin corner, i.e. position (0, 0), to corner.
      def set_origin_corner(corner)
        _set_origin_corner(corner)
      end

      # @param row [Integer]
      # @param stretch [Integer]
      # @return [nil]
      #
      # Sets the stretch factor of row row to stretch. The first row is
      # number 0.
      #
      # The stretch factor is relative to the other rows in this grid.
      # Rows with a higher stretch factor take more of the available space.
      #
      # The default stretch factor is 0. If the stretch factor is 0 and no
      # other row in this table can grow at all, the row may still grow.
      def set_row_stretch(row, stretch)
        _set_row_stretch(row, stretch)
      end

      # @param column [Integer]
      # @param stretch [Integer]
      # @return [nil]
      #
      # Sets the stretch factor of column column to stretch. The first column
      # is number 0.
      #
      # The stretch factor is relative to the other columns in this grid.
      # Columns with a higher stretch factor take more of the available space.
      #
      # The default stretch factor is 0. If the stretch factor is 0 and no
      # other column in this table can grow at all, the column may still grow.
      #
      # An alternative approach is to add spacing using addItem() with a
      # QSpacerItem.
      def set_column_stretch(column, stretch)
        _set_column_stretch(column, stretch)
      end

      # @param row [Integer]
      # @param height [Integer]
      # @return [nil]
      #
      # Sets the minimum height of row row to minSize pixels.
      def set_row_minimum_height(row, height)
        _set_row_minimum_height(row, height)
      end

      # @param column [Integer]
      # @param width [Integer]
      # @return [nil]
      #
      # Sets the minimum width of column column to minSize pixels.
      def set_column_minimum_width(column, width)
        _set_column_minimum_width(column, width)
      end

      # @param row [Integer]
      # @param column [Integer]
      # @return [QLayoutItem]
      #
      # Returns the layout item that occupies cell (row, column), or nullptr
      # if the cell is empty.
      def item_at_position(row, column)
        _item_at_position(row, column)
      end

      # @return [Integer]
      #
      # Returns the number of rows in this grid.
      def row_count
        _row_count
      end

      # @return [Integer]
      #
      # Returns the number of columns in this grid.
      def column_count
        _column_count
      end
    end
  end
end
