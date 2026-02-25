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
      def self.new
        argv = _initialize_qApp_argv
        _new(argv)._initialize_qApp
      end

      # @!visibility private
      def self.set_application_name(name)
        _set_application_name(T.to_qstr(name))
      end

      # @!visibility private
      def self.set_application_version(version)
        _set_application_version(T.to_qstr(version))
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
      def self._initialize_qApp_argv
        T::QList≺QByteArray≻.new.tap do |argv|
          argv << T.to_qbytearray($PROGRAM_NAME)
          ARGV.each { |arg| argv << T.to_qbytearray(arg) }
        end
      end

      # @!visibility private
      %w[exec].each do |meth|
        define_method(meth) do |*args|
          self.class.__send__(meth, *args)
        end
      end

      # @!visibility private
      def _initialize_qApp
        $qApp = self
      end
    end
  end
end
