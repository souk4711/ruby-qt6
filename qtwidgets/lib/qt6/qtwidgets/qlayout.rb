# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qlayout.html
    class QLayout < RubyQt6::QtCore::QObject
      # @!parse class SizeConstraint; end
      rubyqt6_include_constants QLayout, QLayout::SizeConstraint

      # @!parse
      q_object do
      end

      # @!visibility private
      def remove_item(item)
        _remove_item(item)
        # TODO: transfer ownership to the caller
      end

      # @!visibility private
      def remove_widget(widget)
        _remove_widget(widget)
        # TODO: transfer ownership to the caller
      end
    end
  end
end
