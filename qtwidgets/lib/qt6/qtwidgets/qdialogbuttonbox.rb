# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qdialogbuttonbox.html
    class QDialogButtonBox < RubyQt6::QtWidgets::QWidget
      # @!parse class ButtonLayout  ; end
      # @!parse class ButtonRole    ; end
      # @!parse class StandardButton; end
      rubyqt6_include_constants QDialogButtonBox, QDialogButtonBox::ButtonLayout
      rubyqt6_include_constants QDialogButtonBox, QDialogButtonBox::ButtonRole
      rubyqt6_include_constants QDialogButtonBox, QDialogButtonBox::StandardButton

      # @!parse
      q_object do
        signal "accepted()"
        signal "clicked(QAbstractButton*)"
        signal "helpRequested()"
        signal "rejected()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param buttons [QDialogButtonBox::StandardButtons]
      # @param orientation [Qt::Orientation]
      # @param parent [QWidget]
      # @return [QDialogButtonBox]
      def initialize(buttons, orientation, parent = nil)
        _initialize(buttons, orientation, parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
