# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qactiongroup.html
    class QActionGroup < RubyQt6::QtCore::QObject
      # @!parse class ExclusionPolicy; end
      rubyqt6_include_constants QActionGroup, QActionGroup::ExclusionPolicy

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QActionGroup]
      def initialize(parent)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
