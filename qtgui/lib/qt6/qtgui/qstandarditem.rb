# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qstandarditem.html
    class QStandardItem
      # @!parse class ItemType; end
      rubyqt6_declare_enum_under QStandardItem, QStandardItem::ItemType

      # @!parse
      QVariant.register(
        _qvariant_register_metatype,
        method(:_qvariant_from_value),
        method(:_qvariant_to_value),
        from: self
      )

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QStandardItem]
      #
      # @overload initialize
      #
      # @overload initialize(text)
      #   @param text [String, QString]
      #
      # @overload initialize(icon, text)
      #   @param icon [QIcon]
      #   @param text [String, QString]
      #
      # @overload initialize(rows, columns)
      #   @param rows [Integer]
      #   @param columns [Integer]
      def initialize(*args)
        T.args_nth_to_qstr(args, 0)
        T.args_nth_to_qstr(args, 1)
        _initialize(*args)
        _take_ownership_from_ruby(self)
      end

      # @!visibility private
      def delete_now
        self.class._delete_now(self)
      end

      private

      def _take_ownership_from_ruby(item)
        self.class._take_ownership_from_ruby(item)
      end
    end
  end
end
