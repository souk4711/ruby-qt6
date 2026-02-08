# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qprocessenvironment.html
    class QProcessEnvironment
      # @!parse class Initialization; end
      rubyqt6_declare_enum_under QProcessEnvironment, QProcessEnvironment::Initialization

      # @!visibility private
      def contains(name)
        _contains(T.to_qstr(name))
      end

      # @!visibility private
      def insert(name, value)
        _insert(T.to_qstr(name), T.to_qstr(value))
      end

      # @!visibility private
      def remove(name)
        _remove(T.to_qstr(name))
      end

      # @!visibility private
      def value(name, default_value = "")
        _value(T.to_qstr(name), T.to_qstr(default_value))
      end
    end
  end
end
