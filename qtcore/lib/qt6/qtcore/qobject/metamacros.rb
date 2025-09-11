# frozen_string_literal: true

module RubyQt6
  module QtCore
    class QObject
      # @!visibility private
      def self.q_object(&blk)
        underlying = name.start_with?("RubyQt6::") ? :libQt6 : :ruby
        mo = Internal::MetaObject.new(underlying)
        mo.instance_exec(&blk)

        metamethods = mo.metamethods.sort_by { |meth| [meth.name, meth.parameters.size] }
        metamethods.each do |meth|
          next unless meth.signal?
          define_method(meth.name) do
            Internal::Signal.new(self, meth)
          end
        end

        @__qmetaobject__ = mo
      end

      # @!visibility private
      def self.__qmetaobject__
        @__qmetaobject__
      end
    end
  end
end
