# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qwizard.html
    class QWizard < RubyQt6::QtWidgets::QDialog
      # @!parse class WizardButton; end
      # @!parse class WizardOption; end
      # @!parse class WizardPixmap; end
      # @!parse class WizardStyle ; end
      rubyqt6_declare_enum_under QWizard, QWizard::WizardButton
      rubyqt6_declare_enum_under QWizard, QWizard::WizardOption
      rubyqt6_declare_enum_under QWizard, QWizard::WizardPixmap
      rubyqt6_declare_enum_under QWizard, QWizard::WizardStyle

      # @!parse
      q_object do
        signal "currentIdChanged(int)"
        signal "customButtonClicked(int)"
        signal "helpRequested()"
        signal "pageAdded(int)"
        signal "pageRemoved(int)"
        slot "back()"
        slot "next()"
        slot "restart()"
        slot "setCurrentId(int)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QWizard]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
