# frozen_string_literal: true

module RubyQt6
  module QtCore
    class QObject
      def self.q_object(&blk)
        m = Internal::MetaObject.new
        m.instance_exec(&blk)

        @__qmetaobject__ = m
      end

      def self.__qmetaobject__
        @__qmetaobject__
      end
    end
  end
end
