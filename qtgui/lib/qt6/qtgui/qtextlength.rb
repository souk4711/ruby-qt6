# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qtextlength.html
    class QTextLength
      # @!parse class Type; end
      rubyqt6_declare_enum_under QTextLength, QTextLength::Type

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QTextLength]
      #
      # @overload initialize
      #
      # @overload initialize(type, value)
      #   @param type [QTextLength::Type]
      #   @param value [Float]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
