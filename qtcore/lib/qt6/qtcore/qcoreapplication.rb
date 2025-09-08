# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qcoreapplication.html
    class QCoreApplication < RubyQt6::QtCore::QObject
      # @!visibility private
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
      alias_method :_initialize, :initialize

      # @param argv [Array<String>]
      # @return [QCoreApplication]
      def initialize(argv)
        argv = Rice::Buffer≺char∗≻.new(argv.map(&:bytes))
        _initialize(argv.size, argv)
        _initialize_qApp
      end

      # @!visibility private
      %w[exec].each do |meth|
        define_method(meth) do |*args|
          self.class.exec(*args)
        end
      end

      private

      def _initialize_qApp
        $qApp = self
      end
    end
  end
end
