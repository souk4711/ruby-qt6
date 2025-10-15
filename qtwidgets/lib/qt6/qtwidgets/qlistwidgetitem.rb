# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qlistwidgetitem.html
    class QListWidgetItem
      # @!parse class ItemType; end
      rubyqt6_declare_enum_under QListWidgetItem, QListWidgetItem::ItemType

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
        T.args_nth_to_qstr_checked(args, 0)
        T.args_nth_to_qstr_checked(args, 1)
        _initialize(*args)
      end
    end
  end
end
