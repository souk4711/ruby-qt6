# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qlayout.html
    class QLayout < RubyQt6::QtCore::QObject
      # @!parse class SizeConstraint; end
      rubyqt6_declare_enum_under QLayout, QLayout::SizeConstraint

      # @!parse
      q_object do
      end

      # @param parent [QWidget]
      # @return [QLayout]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
