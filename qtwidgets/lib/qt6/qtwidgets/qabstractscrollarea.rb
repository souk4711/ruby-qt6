# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qabstractscrollarea.html
    class QAbstractScrollArea < RubyQt6::QtWidgets::QFrame
      # @!parse class SizeAdjustPolicy; end
      rubyqt6_declare_enum_under QAbstractScrollArea, QAbstractScrollArea::SizeAdjustPolicy

      # @!parse
      q_object do
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QAbstractScrollArea]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
