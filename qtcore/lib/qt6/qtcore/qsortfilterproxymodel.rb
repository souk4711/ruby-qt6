# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qsortfilterproxymodel.html
    class QSortFilterProxyModel < RubyQt6::QtCore::QAbstractProxyModel
      # @!parse class Direction; end
      rubyqt6_declare_enum_under QSortFilterProxyModel, QSortFilterProxyModel::Direction

      # @!parse
      q_object do
        signal "autoAcceptChildRowsChanged(bool)"
        signal "dynamicSortFilterChanged(bool)"
        signal "filterCaseSensitivityChanged(Qt::CaseSensitivity)"
        signal "filterRoleChanged(int)"
        signal "recursiveFilteringEnabledChanged(bool)"
        signal "sortCaseSensitivityChanged(Qt::CaseSensitivity)"
        signal "sortLocaleAwareChanged(bool)"
        signal "sortRoleChanged(int)"
        slot "invalidate()"
        slot "setFilterFixedString(QString)"
        slot "setFilterRegularExpression(QRegularExpression)"
        slot "setFilterRegularExpression(QString)"
        slot "setFilterWildcard(QString)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QSortFilterProxyModel]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
