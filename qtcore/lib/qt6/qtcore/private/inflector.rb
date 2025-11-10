# frozen_string_literal: true

module RubyQt6
  module QtCore
    module Private
      class Inflector
        def camelize(str)
          str = str.dup
          str.gsub!(/(?:_|(\/))([a-z\d]*)/i) { "#{$1}#{$2.capitalize}" }
          str
        end

        def underscore(str)
          str = str.dup
          str.gsub!(/([A-Z\d]+)([A-Z][a-z])/, '\1_\2')
          str.gsub!(/([a-z\d])([A-Z])/, '\1_\2')
          str.downcase!
          str
        end
      end

      def self.inflector
        @inflector ||= QtCore::Private::Inflector.new
      end
    end
  end
end
