# frozen_string_literal: true

module RubyQt6
  module QtCore
    class QObject
      # @!visibility private
      def self.q_object(&blk)
        mo = Internal::MetaObject.new(self)
        mo.instance_exec(&blk)

        metamethods = mo.metamethods.sort_by { |meth| [meth.name, meth.parameters.size] }
        metamethods.each do |meth|
          next unless meth.signal?
          define_method(meth.name) do
            Internal::Signal.new(self, meth)
          end
        end

        @_rubyqt6_metaobject = mo
      end

      # @!visibility private
      def self._rubyqt6_metaobject
        @_rubyqt6_metaobject
      end
    end
  end
end
