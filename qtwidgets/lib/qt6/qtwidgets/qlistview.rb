# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qlistview.html
    class QListView < RubyQt6::QtWidgets::QAbstractItemView
      # @!parse class Flow      ; end
      # @!parse class LayoutMode; end
      # @!parse class Movement  ; end
      # @!parse class ResizeMode; end
      # @!parse class ViewMode  ; end
      rubyqt6_include_constants QListView, QListView::Flow
      rubyqt6_include_constants QListView, QListView::LayoutMode
      rubyqt6_include_constants QListView, QListView::Movement
      rubyqt6_include_constants QListView, QListView::ResizeMode
      rubyqt6_include_constants QListView, QListView::ViewMode

      # @!parse
      q_object do
        signal "indexesMoved(QModelIndexList)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QListView]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
