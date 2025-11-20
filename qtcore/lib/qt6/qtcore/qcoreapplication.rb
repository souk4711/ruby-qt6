# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qcoreapplication.html
    class QCoreApplication < RubyQt6::QtCore::QObject
      # @!parse
      q_object do
        signal "aboutToQuit()"
        signal "applicationNameChanged()"
        signal "applicationVersionChanged()"
        signal "organizationDomainChanged()"
        signal "organizationNameChanged()"
        slot "exit(int)"
        slot "exit()"
        slot "quit()"
      end

      # @!visibility private
      def self.set_organization_domain(org_domain)
        _set_organization_domain(T.to_qstr(org_domain))
      end

      # @!visibility private
      def self.set_organization_name(org_name)
        _set_organization_name(T.to_qstr(org_name))
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param argv [Array<String>]
      # @return [QCoreApplication]
      def initialize(argv)
        argv = _initialize_qApp_argv(argv)
        _initialize(argv.size, argv.data)
        _initialize_qApp
      end

      # @!visibility private
      %w[exec].each do |meth|
        define_method(meth) do |*args|
          self.class.__send__(meth, *args)
        end
      end

      private

      # The data referred to by argc and argv must stay valid for the
      # entire lifetime of the QCoreApplication object. In addition,
      # argc must be greater than zero and argv must contain at least
      # one valid character string.
      def _initialize_qApp_argv(argv)
        argv = [$PROGRAM_NAME] + ARGV if argv == ARGV
        $qApp_argv = ::Rice::Buffer≺char∗≻.new(argv.map(&:bytes))
      end

      def _initialize_qApp
        $qApp = self
      end
    end
  end
end
