# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qheaderview.html
    class QHeaderView < RubyQt6::QtWidgets::QAbstractItemView
      # @!parse class ResizeMode; end
      rubyqt6_declare_enum_under QHeaderView, QHeaderView::ResizeMode

      # @!parse
      q_object do
        signal "geometriesChanged()"
        signal "sectionClicked(int)"
        signal "sectionCountChanged(int,int)"
        signal "sectionDoubleClicked(int)"
        signal "sectionEntered(int)"
        signal "sectionHandleDoubleClicked(int)"
        signal "sectionMoved(int,int,int)"
        signal "sectionPressed(int)"
        signal "sectionResized(int,int,int)"
        signal "sortIndicatorChanged(int,Qt::SortOrder)"
        signal "sortIndicatorClearableChanged(bool)"
        slot "headerDataChanged(Qt::Orientation,int,int)"
        slot "setOffset(int)"
        slot "setOffsetToLastSection()"
        slot "setOffsetToSectionPosition(int)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param orientation [Qt::Orientation]
      # @param parent [QWidget]
      # @return [QHeaderView]
      def initialize(orientation, parent = nil)
        _initialize(orientation, parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
