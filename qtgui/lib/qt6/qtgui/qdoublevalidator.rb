# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qdoublevalidator.html
    class QDoubleValidator < RubyQt6::QtGui::QValidator
      # @!parse class Notation; end
      rubyqt6_declare_enum_under QDoubleValidator, QDoubleValidator::Notation

      # @!parse
      q_object do
        signal "bottomChanged(double)"
        signal "decimalsChanged(int)"
        signal "notationChanged(QDoubleValidator::Notation)"
        signal "topChanged(double)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QDoubleValidator]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
