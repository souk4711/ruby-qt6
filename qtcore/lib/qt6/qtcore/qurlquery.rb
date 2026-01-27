# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qurlquery.html
    class QUrlQuery
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QUrlQuery]
      def initialize
        _initialize
      end

      # @!visibility private
      def add_query_item(key, value)
        _add_query_item(T.to_qstr(key), T.to_qstr(value))
      end

      # @!visibility private
      def has_query_item(key)
        _has_query_item(T.to_qstr(key))
      end

      # @!visibility private
      def remove_all_query_items(key)
        _remove_all_query_items(T.to_qstr(key))
      end

      # @!visibility private
      def remove_query_item(key)
        _remove_query_item(T.to_qstr(key))
      end

      # @!visibility private
      def set_query(query)
        _set_query(T.to_qstr(query))
      end
    end
  end
end
