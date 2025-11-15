# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qtexttableformat.html
    class QTextTableFormat < RubyQt6::QtGui::QTextFrameFormat
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QTextTableFormat]
      def initialize
        _initialize
      end

      # @!visibility private
      def set_column_width_constraints(*args)
        _set_column_width_constraints(to_qtextlengthlist(args))
      end

      private

      def to_qtextlengthlist(array)
        array.each_with_object(T::QList≺QTextLength≻.new) { |o, memo| memo << o }
      end
    end
  end
end
