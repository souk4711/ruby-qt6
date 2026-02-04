# frozen_string_literal: true

module RubyQt6
  module QtCore
    class QVariantList
      # @!visibility private
      alias_method :_count, :count
      alias_method :_include?, :include?
      alias_method :_index, :index
      alias_method :_insert, :insert
      alias_method :_push, :push
      alias_method :_delete, :delete
      alias_method "_[]=", :[]=

      # @!visibility private
      def count(*args)
        case args.size
        when 1 then _count(QVariant.new(args[0]))
        else _count(*args)
        end
      end

      # @!visibility private
      def include?(element)
        _include?(QVariant.new(element))
      end

      # @!visibility private
      def index(element)
        _index(QVariant.new(element))
      end

      # @!visibility private
      def insert(index, element)
        _insert(index, QVariant.new(element))
      end

      # @!visibility private
      def push(element)
        _push(QVariant.new(element))
      end
      alias_method :<<, :push

      # @!visibility private
      def delete(element)
        _delete(QVariant.new(element))
      end

      # @!visibility private
      def []=(index, element)
        __send__("_[]=", index, QVariant.new(element))
      end

      # @!visibility private
      def inspect
        T.inspect_struct(self, ary: to_a.map(&:value))
      end
    end
  end
end
