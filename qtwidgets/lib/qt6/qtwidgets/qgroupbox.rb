# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qgroupbox.html
    class QGroupBox < RubyQt6::QtWidgets::QWidget
      # @!parse
      q_object do
        signal "clicked(bool)"
        signal "clicked()"
        signal "toggled(bool)"
        slot "setChecked(bool)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param title [String, QString]
      # @param parent [QWidget]
      # @return [QGroupBox]
      def initialize(title, parent = nil)
        _initialize(T.to_qstr(title), parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
