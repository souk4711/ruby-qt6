# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qlayout.html
    class QLayout < RubyQt6::QtWidgets::QWidget
      # @!parse class SizeConstraint; end
      rubyqt6_include_constants QLayout, QLayout::SizeConstraint

      # @return [QLayout::SizeConstraint]
      #
      # This property holds the resize mode of the layout.
      #
      # The default mode is SetDefaultConstraint.
      def size_constraint
        _size_constraint
      end

      # @return [Integer]
      #
      # This property holds the spacing between widgets inside the layout
      #
      # If no value is explicitly set, the layout's spacing is inherited from
      # the parent layout, or from the style settings for the parent widget.
      #
      # For QGridLayout and QFormLayout, it is possible to set different
      # horizontal and vertical spacings using setHorizontalSpacing() and
      # setVerticalSpacing(). In that case, spacing() returns -1.
      def spacing
        _spacing
      end

      # @return [Boolean]
      #
      # Returns true if the layout is enabled; otherwise returns false.
      def enabled?
        _enabled?
      end

      # @param constraint [QLayout::SizeConstraint]
      # @return [nil]
      #
      # Sets the layout's sizeConstraint property.
      def set_size_constraint(constraint)
        _set_size_constraint(constraint)
      end

      # @param spacing [Integer]
      # @return [nil]
      #
      # Sets the layout's spacing property.
      def set_spacing(spacing)
        _set_spacing(spacing)
      end

      # @param enabled [Boolean]
      # @return [nil]
      #
      # Enables this layout if enable is true, otherwise disables it.
      #
      # An enabled layout adjusts dynamically to changes; a disabled layout
      # acts as if it did not exist.
      #
      # By default all layouts are enabled.
      def set_enabled(enabled)
        _set_enabled(enabled)
      end

      # @param item [QLayoutItem]
      # @return [nil]
      #
      # Implemented in subclasses to add an item. How it is added is specific
      # to each subclass.
      #
      # This function is not usually called in application code. To add a
      # widget to a layout, use the addWidget() function; to add a child
      # layout, use the addLayout() function provided by the relevant QLayout
      # subclass.
      #
      # Note: The ownership of item is transferred to the layout, and it's the
      # layout's responsibility to delete it.
      def add_item(item)
        _add_item(item)
        _take_ownership_from_rice(item)
      end

      # @param widget [QWidget]
      # @return [nil]
      #
      # Adds widget w to this layout in a manner specific to the layout.
      # This function uses addItem().
      def add_widget(widget)
        _add_widget(widget)
        _take_ownership_from_rice(widget)
      end

      # @param item [QLayoutItem]
      # @return [nil]
      #
      # Removes the layout item item from the layout. It is the caller's
      # responsibility to delete the item.
      #
      # Notice that item can be a layout (since QLayout inherits QLayoutItem).
      def remove_item(item)
        _remove_item(item)
        # TODO: transfer ownership of item to the caller
      end

      # @param widget [QWidget]
      # @return [nil]
      #
      # Removes the widget widget from the layout. After this call, it is the
      # caller's responsibility to give the widget a reasonable geometry or
      # to put the widget back into a layout or to explicitly hide it if
      # necessary.
      #
      # Note: The ownership of widget remains the same as when it was added.
      def remove_widget(widget)
        _remove_widget(widget)
        # TODO: transfer ownership of item to the caller
      end

      # @param item [QLayoutItem]
      # @return [Integer]
      #
      # Searches for layoutitem in this layout (not including child layouts).
      #
      # Returns the index of layoutItem, or -1 if layoutItem is not found.
      def index_of(item)
        _index_of(item)
      end

      # @param index [Integer]
      # @return [QLayoutItem]
      #
      # Must be implemented in subclasses to return the layout item at index.
      # If there is no such item, the function must return nullptr. Items are
      # numbered consecutively from 0. If an item is deleted, other items
      # will be renumbered.
      #
      # This function can be used to iterate over a layout.
      def item_at(index)
        _item_at(index)
      end

      # @param index [Integer]
      # @return [QLayoutItem]
      #
      # Must be implemented in subclasses to remove the layout item at index
      # from the layout, and return the item. If there is no such item, the
      # function must do nothing and return 0. Items are numbered
      # consecutively from 0. If an item is removed, other items will be
      # renumbered.
      def take_at(index)
        _take_at(index)
      end

      # @return [Integer]
      #
      # Must be implemented in subclasses to return the number of items in
      # the layout.
      def count
        _count
      end
    end
  end
end
