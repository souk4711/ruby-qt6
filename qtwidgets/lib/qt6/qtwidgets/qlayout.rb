# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qlayout.html
    class QLayout < RubyQt6::QtCore::QObject
      # @!parse class SizeConstraint; end
      rubyqt6_include_constants QLayout, QLayout::SizeConstraint
    end
  end
end
