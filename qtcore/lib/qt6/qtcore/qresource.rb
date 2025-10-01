# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qresource.html
    class QResource
      # @!parse class Compression; end
      rubyqt6_include_constants QResource, QResource::Compression

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QResource]
      #
      # @overload initialize
      #
      # @overload initialize(file)
      #   @param file [String, QString]
      #
      # @overload initialize(file, locale)
      #   @param file [String, QString]
      #   @param locale [QLocale]
      def initialize(*args)
        args[0] = T.to_qstr(args[0]) if args[0].is_a?(::String)
        _initialize(*args)
      end
    end
  end
end
