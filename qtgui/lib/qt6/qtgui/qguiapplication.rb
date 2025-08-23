# frozen_string_literal: true

module RubyQt6
  module QtGui
    class QGuiApplication < RubyQt6::QtCore::QCoreApplication
      %w[exec].each do |name|
        define_method(name) do
          self.class.__send__(name)
        end
      end
    end
  end
end
