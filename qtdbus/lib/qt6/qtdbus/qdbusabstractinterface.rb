# frozen_string_literal: true

module RubyQt6
  module QtDBus
    # @see https://doc.qt.io/qt-6/qdbusabstractinterface.html
    class QDBusAbstractInterface < RubyQt6::QtCore::QObject
      # @!parse
      q_object do
      end

      # @!visibility private
      def async_call(method, *args)
        async_call_with_argument_list(T.to_qstr(method), to_qvariantlist(args))
      end

      # @!visibility private
      def call(*args)
        mode = args_nth_delete_callmode(args, 0) || QtDBus::QDBus::CallMode::AutoDetect
        method = args.delete_at(0)
        call_with_argument_list(mode, T.to_qstr(method), to_qvariantlist(args))
      end

      private

      def args_nth_delete_callmode(args, index)
        return unless args[index].is_a?(QtDBus::QDBus::CallMode)
        args.delete_at(index)
      end

      def to_qvariantlist(args)
        args.each_with_object(T::QList≺QVariant≻.new) do |arg, args|
          args << (arg.is_a?(QtCore::QVariant) ? arg : QtCore::QVariant.new(arg))
        end
      end
    end
  end
end
