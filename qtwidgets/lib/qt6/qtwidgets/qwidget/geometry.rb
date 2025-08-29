# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    class QWidget < RubyQt6::QtCore::QObject
      # @return [QPoint]
      #
      # This property holds the position of the widget within its parent
      # widget.
      #
      # If the widget is a window, the position is that of the widget on
      # the desktop, including its frame.
      #
      # When changing the position, the widget, if visible, receives a
      # move event (moveEvent()) immediately. If the widget is not currently
      # visible, it is guaranteed to receive an event before it is shown.
      #
      # By default, this property contains a position that refers to the
      # origin.
      def pos
        _pos
      end

      # @return [Integer]
      #
      # This property holds the x coordinate of the widget relative to its
      # parent including any window frame.
      #
      # By default, this property has a value of 0.
      def x
        _x
      end

      # @return [Integer]
      #
      # This property holds the y coordinate of the widget relative to its
      # parent and including any window frame.
      #
      # By default, this property has a value of 0.
      def y
        _y
      end

      # @return [QRect]
      #
      # This property holds the internal geometry of the widget excluding any
      # window frame.
      #
      # The rect property equals QRect(0, 0, width(), height()).
      #
      # By default, this property contains a value that depends on the user's
      # platform and screen geometry.
      def rect
        _rect
      end

      # @return [QSize]
      #
      # This property holds the size of the widget excluding any window frame.
      #
      # If the widget is visible when it is being resized, it receives a resize
      # event (resizeEvent()) immediately. If the widget is not currently
      # visible, it is guaranteed to receive an event before it is shown.
      #
      # The size is adjusted if it lies outside the range defined by
      # minimumSize() and maximumSize().
      #
      # By default, this property contains a value that depends on the user's
      # platform and screen geometry.
      def size
        _size
      end

      # @return [Integer]
      #
      # This property holds the width of the widget excluding any window frame.
      #
      # By default, this property contains a value that depends on the user's
      # platform and screen geometry.
      def width
        _width
      end

      # @return [Integer]
      #
      # This property holds the height of the widget excluding any window frame.
      #
      # By default, this property contains a value that depends on the user's
      # platform and screen geometry.
      def height
        _height
      end

      # @return [QRect]
      #
      # This property holds the geometry of the widget relative to its parent
      # and excluding the window frame.
      #
      # When changing the geometry, the widget, if visible, receives a move
      # event (moveEvent()) and/or a resize event (resizeEvent()) immediately.
      # If the widget is not currently visible, it is guaranteed to receive
      # appropriate events before it is shown.
      #
      # The size component is adjusted if it lies outside the range defined
      # by minimumSize() and maximumSize().
      #
      # See the Window Geometry documentation for an overview of geometry
      # issues with windows.
      #
      # By default, this property contains a value that depends on the user's
      # platform and screen geometry.
      def geometry
        _geometry
      end

      # @return [QSize]
      #
      # This property holds the widget's maximum size in pixels.
      #
      # The widget cannot be resized to a larger size than the maximum widget
      # size.
      #
      # By default, this property contains a size in which both width and
      # height have values of 16777215.
      def maximum_size
        _maximum_size
      end

      # @return [Integer]
      #
      # This property holds the widget's maximum width in pixels.
      #
      # This property corresponds to the width held by the maximumSize property.
      #
      # By default, this property contains a value of 16777215.
      def maximum_width
        _maximum_width
      end

      # @return [Integer]
      #
      # This property holds the widget's maximum height in pixels.
      #
      # This property corresponds to the height held by the maximumSize property.
      #
      # By default, this property contains a value of 16777215.
      def maximum_height
        _maximum_height
      end

      # @return [QSize]
      #
      # This property holds the widget's minimum size.
      #
      # The widget cannot be resized to a smaller size than the minimum widget
      # size. The widget's size is forced to the minimum size if the current
      # size is smaller.
      #
      # The minimum size set by this function will override the minimum size
      # defined by QLayout. To unset the minimum size, use a value of QSize(0, 0).
      #
      # By default, this property contains a size with zero width and height.
      def minimum_size
        _minimum_size
      end

      # @return [Integer]
      #
      # This property holds the widget's minimum width in pixels.
      #
      # This property corresponds to the width held by the minimumSize property.
      #
      # By default, this property has a value of 0.
      def minimum_width
        _minimum_width
      end

      # @return [Integer]
      #
      # This property holds the widget's minimum height in pixels.
      #
      # This property corresponds to the height held by the minimumSize property.
      #
      # By default, this property has a value of 0.
      def minimum_height
        _minimum_height
      end

      # @return [QLayout]
      #
      # Returns the layout manager that is installed on this widget, or nullptr
      # if no layout manager is installed.
      #
      # The layout manager sets the geometry of the widget's children that have
      # been added to the layout.
      def layout
        _layout
      end

      # @return [QSizePolicy]
      #
      # This property holds the default layout behavior of the widget.
      #
      # If there is a QLayout that manages this widget's children, the size
      # policy specified by that layout is used. If there is no such QLayout,
      # the result of this function is used.
      #
      # The default policy is Preferred/Preferred, which means that the widget
      # can be freely resized, but prefers to be the size sizeHint() returns.
      # Button-like widgets set the size policy to specify that they may
      # stretch horizontally, but are fixed vertically. The same applies to
      # lineedit controls (such as QLineEdit, QSpinBox or an editable QComboBox)
      # and other horizontally orientated widgets (such as QProgressBar).
      # QToolButton's are normally square, so they allow growth in both
      # directions. Widgets that support different directions (such as QSlider,
      # QScrollBar or QHeader) specify stretching in the respective direction
      # only. Widgets that can provide scroll bars (usually subclasses of
      # QScrollArea) tend to specify that they can use additional space, and
      # that they can make do with less than sizeHint().
      def size_policy
        _size_policy
      end

      # @return [QSize]
      #
      # This property holds the recommended size for the widget.
      #
      # If the value of this property is an invalid size, no size is
      # recommended.
      #
      # The default implementation of sizeHint() returns an invalid size if
      # there is no layout for this widget, and returns the layout's preferred
      # size otherwise.
      def size_hint
        _size_hint
      end

      # @return [QSize]
      #
      # This property holds the recommended minimum size for the widget.
      #
      # If the value of this property is an invalid size, no minimum size is
      # recommended.
      #
      # The default implementation of minimumSizeHint() returns an invalid size
      # if there is no layout for this widget, and returns the layout's minimum
      # size otherwise. Most built-in widgets reimplement minimumSizeHint().
      #
      # QLayout will never resize a widget to a size smaller than the minimum
      # size hint unless minimumSize() is set or the size policy is set to
      # QSizePolicy::Ignore. If minimumSize() is set, the minimum size hint
      # will be ignored.
      def minimum_size_hint
        _minimum_size_hint
      end

      # @return [QSize]
      #
      # This property holds the base size of the widget.
      #
      # The base size is used to calculate a proper widget size if the widget
      # defines sizeIncrement().
      #
      # By default, for a newly-created widget, this property contains a size
      # with zero width and height.
      def base_size
        _base_size
      end

      # @return [QSize]
      #
      # This property holds the size increment of the widget.
      #
      # When the user resizes the window, the size will move in steps of
      # sizeIncrement().width() pixels horizontally and sizeIncrement.height()
      # pixels vertically, with baseSize() as the basis. Preferred widget sizes
      # are for non-negative integers i and j:
      #
      #   width = baseSize().width() + i * sizeIncrement().width();
      #   height = baseSize().height() + j * sizeIncrement().height();
      #
      # Note that while you can set the size increment for all widgets, it
      # only affects windows.
      #
      # By default, this property contains a size with zero width and height.
      def size_increment
        _size_increment
      end

      # @return [QRect]
      #
      # This property holds the bounding rectangle of the widget's children.
      #
      # Hidden children are excluded.
      #
      # By default, for a widget with no children, this property contains a
      # rectangle with zero width and height located at the origin.
      def children_rect
        _children_rect
      end

      # @return [QRegion]
      #
      # This property holds the combined region occupied by the widget's
      # children.
      #
      # Hidden children are excluded.
      #
      # By default, for a widget with no children, this property contains an
      # empty region.
      def children_region
        _children_region
      end

      # @return [QRect]
      #
      # geometry of the widget relative to its parent including any window frame.
      #
      # See the Window Geometry documentation for an overview of geometry issues
      # with windows.
      #
      # By default, this property contains a value that depends on the user's
      # platform and screen geometry.
      def frame_geometry
        _frame_geometry
      end

      # @return [QSize]
      #
      # This property holds the size of the widget including any window frame
      #
      # By default, this property contains a value that depends on the user's
      # platform and screen geometry.
      def frame_size
        _frame_size
      end

      # @return [nil]
      # @overload move(pos)
      #   @param pos [QPoint]
      # @overload move(x, y)
      #   @param x [Integer]
      #   @param y [Integer]
      #
      # Sets the widget's pos property.
      def move(*args)
        _move(*args)
      end

      # @return [nil]
      # @overload resize(size)
      #   @param size [QSize]
      # @overload resize(w, h)
      #   @param w [Integer]
      #   @param h [Integer]
      #
      # Sets the widget's size property.
      def resize(*args)
        _resize(*args)
      end

      # @return [nil]
      # @overload set_geometry(rect)
      #   @param rect [QRect]
      # @overload set_geometry(x, y, w, h)
      #   @param x [Integer]
      #   @param y [Integer]
      #   @param w [Integer]
      #   @param h [Integer]
      #
      # Sets the widget's geometry property.
      def set_geometry(*args)
        _set_geometry(*args)
      end

      # @return [nil]
      # @overload set_maximum_size(size)
      #   @param size [QSize]
      # @overload set_maximum_size(w, h)
      #   @param w [Integer]
      #   @param h [Integer]
      #
      # Sets the widget's maximumSize property.
      def set_maximum_size(*args)
        _set_maximum_size(*args)
      end

      # @param w [Integer]
      # @return [nil]
      #
      # Sets the widget's maximumWidth property.
      def set_maximum_width(w)
        _set_maximum_width(w)
      end

      # @param h [Integer]
      # @return [nil]
      #
      # Sets the widget's maximumHeight property.
      def set_maximum_height(h)
        _set_maximum_height(h)
      end

      # @return [nil]
      # @overload set_minimum_size(size)
      #   @param size [QSize]
      # @overload set_minimum_size(w, h)
      #   @param w [Integer]
      #   @param h [Integer]
      #
      # Sets the widget's minimumSize property.
      def set_minimum_size(*args)
        _set_minimum_size(*args)
      end

      # @param w [Integer]
      # @return [nil]
      #
      # Sets the widget's minimumWidth property.
      def set_minimum_width(w)
        _set_minimum_width(w)
      end

      # @param h [Integer]
      # @return [nil]
      #
      # Sets the widget's minimumHeight property.
      def set_minimum_height(h)
        _set_minimum_height(h)
      end

      # @return [nil]
      # @overload set_fixed_size(size)
      #   @param size [QSize]
      # @overload set_fixed_size(w, h)
      #   @param w [Integer]
      #   @param h [Integer]
      #
      # Sets both the minimum and maximum sizes of the widget to s, thereby
      # preventing it from ever growing or shrinking.
      #
      # This will override the default size constraints set by QLayout.
      #
      # To remove constraints, set the size to QWIDGETSIZE_MAX.
      #
      # Alternatively, if you want the widget to have a fixed size based on
      # its contents, you can call QLayout::setSizeConstraint(QLayout::SetFixedSize);
      def set_fixed_size(*args)
        _set_fixed_size(*args)
      end

      # @param w [Integer]
      # @return [nil]
      #
      # Sets both the minimum and maximum width of the widget to w without
      # changing the heights. Provided for convenience.
      def set_fixed_width(w)
        _set_fixed_width(w)
      end

      # @param h [Integer]
      # @return [nil]
      #
      # Sets both the minimum and maximum heights of the widget to h without
      # changing the widths. Provided for convenience.
      def set_fixed_height(h)
        _set_fixed_height(h)
      end

      # @param layout [QLayout]
      # @return [nil]
      #
      # Sets the layout manager for this widget to layout.
      #
      # If there already is a layout manager installed on this widget, QWidget
      # won't let you install another. You must first delete the existing
      # layout manager (returned by layout()) before you can call setLayout()
      # with the new layout.
      #
      # If layout is the layout manager on a different widget, setLayout() will
      # reparent the layout and make it the layout manager for this widget.
      #
      # Example:
      #
      #     QVBoxLayout *layout = new QVBoxLayout;
      #     layout->addWidget(formWidget);
      #     setLayout(layout);
      #
      # An alternative to calling this function is to pass this widget to the
      # layout's constructor.
      #
      # The QWidget will take ownership of layout.
      def set_layout(layout)
        _set_layout(layout)
        _take_ownership_from_rice(layout)
      end

      # @return [nil]
      #
      # Adjusts the size of the widget to fit its contents.
      #
      # This function uses sizeHint() if it is valid, i.e., the size hint's
      # width and height are >= 0. Otherwise, it sets the size to the children
      # rectangle that covers all child widgets (the union of all child widget
      # rectangles).
      #
      # For windows, the screen size is also taken into account. If the
      # sizeHint() is less than (200, 100) and the size policy is expanding,
      # the window will be at least (200, 100). The maximum size of a window
      # is 2/3 of the screen's width and height.
      def adjust_size
        _adjust_size
      end

      # @return [nil]
      # @overload set_size_policy(policy)
      #   @param policy [QSizePolicy]
      # @overload set_size_policy(horizontal, vertical)
      #   @param horizontal [QSizePolicy::Policy]
      #   @param vertical [QSizePolicy::Policy]
      #
      # Sets the widget's sizePolicy property.
      def set_size_policy(*args)
        _set_size_policy(*args)
      end

      # @return [nil]
      # @overload set_base_size(size)
      #   @param size [QSize]
      # @overload set_base_size(w, h)
      #   @param w [Integer]
      #   @param h [Integer]
      #
      # Sets the widget's baseSize property.
      def set_base_size(*args)
        _set_base_size(*args)
      end

      # @return [nil]
      # @overload set_size_increment(size)
      #   @param size [QSize]
      # @overload set_size_increment(w, h)
      #   @param w [Integer]
      #   @param h [Integer]
      #
      # Sets the widget's baseIncrement property.
      def set_size_increment(*args)
        _set_size_increment(*args)
      end
    end
  end
end
