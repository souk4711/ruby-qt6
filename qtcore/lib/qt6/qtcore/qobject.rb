# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qobject.html
    class QObject
      # @!visibility private
      def self.q_object(&blk)
        if !name.start_with?("RubyQt6::")
          if !superclass.name.start_with?("RubyQt6::Bando::")
            raise "Invalid superclass: macro `q_object` only available for subclass of ::RubyQt6::Bando::<...>"
          end
        end

        mo = QtCore::Private::MetaObject.new(self)
        mo.instance_exec(&blk)

        metamethods = mo.metamethods.sort_by { |meth| [meth.name, meth.parameters.size] }
        metamethods.each do |meth|
          if meth.signal?
            define_method(meth.name) do
              QtCore::Private::Signal.new(self, meth)
            end
          elsif meth.slot? && mo.ruby?
            define_method(meth.qsignature_name) do |*args|
              __send__(meth.name, *args.map(&:to_rb_value))
            rescue => e
              log = "#{e.class.name}: #{e.message.force_encoding(::Encoding::UTF_8)}\n#{(e.backtrace || []).join("\n")}"
              ::RubyQt6.logger.error(log)
            end
          end
        end

        @_rubyqt6_metaobject = mo
        define_singleton_method("_rubyqt6_metaobject") do
          @_rubyqt6_metaobject
        end

        @_qmetaobject = mo.to_qmetaobject
        define_singleton_method("_qmetaobject") do
          @_qmetaobject
        end

        nil
      end

      # @!parse
      q_object do
        signal "destroyed(QObject*)"
        signal "destroyed()"
        signal "objectNameChanged(QString)"
        slot "deleteLater()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QObject]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end

      # @!visibility private
      def set_parent(parent)
        _set_parent(parent)
        _take_ownership_from_ruby(self) if parent
      end

      private

      def _take_ownership_from_ruby(object)
        self.class._take_ownership_from_ruby(object)
      end
    end
  end
end
