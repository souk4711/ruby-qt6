# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qcheckbox.html
    class QCheckBox < RubyQt6::QtWidgets::QAbstractButton
      # @!parse
      q_object do
        signal "checkStateChanged(Qt::CheckState)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param text [String, QString]
      # @param parent [QWidget]
      # @return [QCheckBox]
      def initialize(text, parent = nil)
        _initialize(T.to_qstr(text), parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
