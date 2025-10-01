# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qlistwidgetitem.html
    class QListWidgetItem
      # @!parse class ItemType; end
      rubyqt6_include_constants QListWidgetItem, QListWidgetItem::ItemType

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QListWidgetItem]
      #
      # @overload initialize
      #
      # @overload initialize(text)
      #   @param text [String, QString]
      #
      # @overload initialize(icon, text)
      #   @param icon [QIcon]
      #   @param text [String, QString]
      def initialize(*args)
        args[0] = T.to_qstr(args[0]) if args[0].is_a?(::String)
        args[1] = T.to_qstr(args[1]) if args[1].is_a?(::String)
        _initialize(*args)
      end
    end
  end
end
