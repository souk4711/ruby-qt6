# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qlayoutitem.html
    class QLayoutItem
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
