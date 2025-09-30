# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qtreewidgetitem.html
    class QTreeWidgetItem
      # @!parse class ChildIndicatorPolicy; end
      # @!parse class ItemType            ; end
      rubyqt6_include_constants QTreeWidgetItem, QTreeWidgetItem::ChildIndicatorPolicy
      rubyqt6_include_constants QTreeWidgetItem, QTreeWidgetItem::ItemType

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QTreeWidgetItem]
      #
      # @overload initialize(type = QTreeWidgetItem::ItemType::Type)
      #   @param type [QTreeWidgetItem::ItemType]
      #
      # @overload initialize(parent, type = QTreeWidgetItem::ItemType::Type)
      #   @param parent [QTreeWidget]
      #   @param type [QTreeWidgetItem::ItemType]
      #
      # @overload initialize(parent, type = QTreeWidgetItem::ItemType::Type)
      #   @param parent [QTreeWidgetItem]
      #   @param type [QTreeWidgetItem::ItemType]
      #
      # @overload initialize(parent, after, type = QTreeWidgetItem::ItemType::Type)
      #   @param parent [QTreeWidget]
      #   @param after [QTreeWidgetItem]
      #   @param type [QTreeWidgetItem::ItemType]
      #
      # @overload initialize(parent, after, type = QTreeWidgetItem::ItemType::Type)
      #   @param parent [QTreeWidgetItem]
      #   @param after [QTreeWidgetItem]
      #   @param type [QTreeWidgetItem::ItemType]
      #
      # @overload initialize(strings, type = QTreeWidgetItem::ItemType::Type)
      #   @param strings [QStringList]
      #   @param type [QTreeWidgetItem::ItemType]
      #
      # @overload initialize(parent, strings, type = QTreeWidgetItem::ItemType::Type)
      #   @param parent [QTreeWidget]
      #   @param strings [QStringList]
      #   @param type [QTreeWidgetItem::ItemType]
      #
      # @overload initialize(parent, strings, type = QTreeWidgetItem::ItemType::Type)
      #   @param parent [QTreeWidgetItem]
      #   @param strings [QStringList]
      #   @param type [QTreeWidgetItem::ItemType]
      def initialize(*args)
        _initialize(*args)

        parent = args.find { |arg| arg.is_a?(QtWidgets::QTreeWidget) || arg.is_a?(QtWidgets::QTreeWidgetItem) }
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
