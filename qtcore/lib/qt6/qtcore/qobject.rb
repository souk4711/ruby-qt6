# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qobject.html
    class QObject
      # @!visibility private
      def self.q_object(&blk)
        if !name.start_with?("RubyQt6::")
          if !superclass.name.start_with?("RubyQt6::Bando::")
            raise "Invalid superclass: macro `q_object` " \
              "only available for subclass of RubyQt6::Bando::<...>"
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
            define_method("_rubyqt6_slot_" + meth.qsignature_name) do |*args|
              r = __send__(meth.name, *args.map(&:value))
              next if meth.return_type.nil?

              qmetatype = QMetaType.from_name(meth.return_type)
              QVariant.new(r, qmetatype)
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
        _take_ownership_from_ruby(self)
      end

      # @!visibility private
      def children
        _children.map { |child| T.bando_qobject_cast(child) }
      end

      # @!visibility private
      def delete_now
        self.class._delete_now(self)
      end

      # @!visibility private
      def find_child(name, options = nil)
        options ||= Qt::FindChildrenRecursively
        child = _find_child(T.to_qanystringview(name), T.to_qflags(options))
        T.bando_qobject_cast(child)
      end

      # @!visibility private
      def find_children(name, options = nil)
        options ||= Qt::FindChildrenRecursively
        children = _find_children(T.to_qanystringview(name), T.to_qflags(options))
        children.map { |child| T.bando_qobject_cast(child) }
      end

      # @!visibility private
      def parent
        T.bando_qobject_cast(_parent)
      end

      # @!visibility private
      def set_object_name(name)
        _set_object_name(T.to_qstr(name))
      end

      # @!visibility private
      def tr(source_text, disambiguation = "", n = -1)
        context = self.class.name
        QCoreApplication.translate(context, source_text, disambiguation, n)
      end

      private

      def _take_ownership_from_ruby(object)
        self.class._take_ownership_from_ruby(object)
      end
    end
  end
end
