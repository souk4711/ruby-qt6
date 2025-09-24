# frozen_string_literal: true

module RubyQt6
  module Bando
    # @!visibility private
    def self.define_bando_qlass(qlass)
      qlass.class_eval do
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

        def _rubyqt6_handle_event(event, *args)
          __send__(event, *args)
        rescue => e
          ::RubyQt6.logger.error e
        end
      end
    end
  end
end
