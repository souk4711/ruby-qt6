# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qvalidator.html
    class QValidator < RubyQt6::QtCore::QObject
      # @!parse class State; end
      rubyqt6_declare_enum_under QValidator, QValidator::State

      # @!parse
      q_object do
        signal "changed()"
      end
    end
  end
end
