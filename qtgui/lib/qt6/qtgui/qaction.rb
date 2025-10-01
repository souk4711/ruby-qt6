# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qaction.html
    class QAction < RubyQt6::QtCore::QObject
      # @!parse class MenuRole   ; end
      # @!parse class Priority   ; end
      # @!parse class ActionEvent; end
      rubyqt6_include_constants QAction, QAction::MenuRole
      rubyqt6_include_constants QAction, QAction::Priority
      rubyqt6_include_constants QAction, QAction::ActionEvent

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param icon [QIcon]
      # @param text [String, QString]
      # @param parent [QObject]
      # @return [QAction]
      def initialize(icon, text, parent = nil)
        _initialize(icon, T.to_qstr(text), parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
