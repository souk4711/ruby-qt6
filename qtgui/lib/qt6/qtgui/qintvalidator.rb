# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qintvalidator.html
    class QIntValidator < RubyQt6::QtGui::QValidator
      # @!parse
      q_object do
        signal "bottomChanged(int)"
        signal "topChanged(int)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QIntValidator]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
