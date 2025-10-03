# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qframe.html
    class QFrame < RubyQt6::QtWidgets::QWidget
      # @!parse class Shadow; end
      # @!parse class Shape ; end
      rubyqt6_declare_enum_under QFrame, QFrame::Shadow
      rubyqt6_declare_enum_under QFrame, QFrame::Shape

      # @!parse
      q_object do
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QFrame]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
