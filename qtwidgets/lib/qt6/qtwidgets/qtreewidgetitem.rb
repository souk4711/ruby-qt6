# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qtreewidgetitem.html
    class QTreeWidgetItem
      # @!parse class ChildIndicatorPolicy; end
      # @!parse class ItemType            ; end
      rubyqt6_declare_enum_under QTreeWidgetItem, QTreeWidgetItem::ChildIndicatorPolicy
      rubyqt6_declare_enum_under QTreeWidgetItem, QTreeWidgetItem::ItemType

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QTreeWidgetItem]
      #
      # @overload initialize
      #
      # @overload initialize(parent)
      #   @param parent [QTreeWidget]
      #
      # @overload initialize(parent)
      #   @param parent [QTreeWidgetItem]
      #
      # @overload initialize(parent, after)
      #   @param parent [QTreeWidget]
      #   @param after [QTreeWidgetItem]
      #
      # @overload initialize(parent, after)
      #   @param parent [QTreeWidgetItem]
      #   @param after [QTreeWidgetItem]
      #
      # @overload initialize(strings)
      #   @param strings [QStringList]
      #
      # @overload initialize(parent, strings)
      #   @param parent [QTreeWidget]
      #   @param strings [QStringList]
      #
      # @overload initialize(parent, strings)
      #   @param parent [QTreeWidgetItem]
      #   @param strings [QStringList]
      def initialize(*args)
        _initialize(*args)
        _take_ownership_from_ruby(self)
      end

      private

      def _take_ownership_from_ruby(item)
        self.class._take_ownership_from_ruby(item)
      end
    end
  end
end
