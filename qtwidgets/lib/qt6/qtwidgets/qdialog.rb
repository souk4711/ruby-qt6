# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qdialog.html
    class QDialog < RubyQt6::QtWidgets::QWidget
      # @!parse class DialogCode; end
      rubyqt6_include_constants QDialog, QDialog::DialogCode

      # @!parse
      q_object do
        signal "finished(int)"
        signal "accepted()"
        signal "rejected()"
        slot "open()"
        slot "exec()"
        slot "done(int)"
        slot "accept()"
        slot "reject()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QDialog]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
