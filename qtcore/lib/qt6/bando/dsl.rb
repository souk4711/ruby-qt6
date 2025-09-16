# frozen_string_literal: true

module RubyQt6
  module Bando
    def self.define_bando_qlass(klass)
      klass.class_eval do
        alias_method :_initialize, :initialize

        def initialize(*args)
          super
          _initialize_value(self, self.class._qmetaobject)
        end

        def self._rubyqt6_metaobject
          superclass._rubyqt6_metaobject
        end

        def self._qmetaobject
          superclass._qmetaobject
        end
      end
    end
  end
end
