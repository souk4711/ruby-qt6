#include "qsortfilterproxymodel-rb.hpp"
#include <qsortfilterproxymodel.h>
#include <rice/qt6/qenum.hpp>

#include <QBindable>
#include <QItemSelection>
#include <QSize>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQSortFilterProxyModel;

void Init_qsortfilterproxymodel(Module rb_mQt6QtCore)
{
    rb_cQSortFilterProxyModel =
        // RubyQt6::QtCore::QSortFilterProxyModel
        define_qlass_under<QSortFilterProxyModel, QAbstractProxyModel>(rb_mQt6QtCore, "QSortFilterProxyModel")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QSortFilterProxyModel * { return qobject_cast<QSortFilterProxyModel *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QSortFilterProxyModel::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QSortFilterProxyModel, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("auto_accept_child_rows", &QSortFilterProxyModel::autoAcceptChildRows)
            .define_method("bindable_auto_accept_child_rows", &QSortFilterProxyModel::bindableAutoAcceptChildRows)
            .define_method("bindable_dynamic_sort_filter", &QSortFilterProxyModel::bindableDynamicSortFilter)
            .define_method("bindable_filter_case_sensitivity", &QSortFilterProxyModel::bindableFilterCaseSensitivity)
            .define_method("bindable_filter_key_column", &QSortFilterProxyModel::bindableFilterKeyColumn)
            .define_method("bindable_filter_regular_expression", &QSortFilterProxyModel::bindableFilterRegularExpression)
            .define_method("bindable_filter_role", &QSortFilterProxyModel::bindableFilterRole)
            .define_method("bindable_is_sort_locale_aware", &QSortFilterProxyModel::bindableIsSortLocaleAware)
            .define_method("bindable_recursive_filtering_enabled", &QSortFilterProxyModel::bindableRecursiveFilteringEnabled)
            .define_method("bindable_sort_case_sensitivity", &QSortFilterProxyModel::bindableSortCaseSensitivity)
            .define_method("bindable_sort_role", &QSortFilterProxyModel::bindableSortRole)
            .define_method("buddy", &QSortFilterProxyModel::buddy, Arg("index"))
            .define_method("can_fetch_more", &QSortFilterProxyModel::canFetchMore, Arg("parent"))
            .define_method("column_count", &QSortFilterProxyModel::columnCount, Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("data", &QSortFilterProxyModel::data, Arg("index"), Arg("role") = static_cast<int>(Qt::DisplayRole))
            .define_method("drop_mime_data", &QSortFilterProxyModel::dropMimeData, Arg("data"), Arg("action"), Arg("row"), Arg("column"), Arg("parent"))
            .define_method("dynamic_sort_filter", &QSortFilterProxyModel::dynamicSortFilter)
            .define_method("fetch_more", &QSortFilterProxyModel::fetchMore, Arg("parent"))
            .define_method("filter_case_sensitivity", &QSortFilterProxyModel::filterCaseSensitivity)
            .define_method("filter_key_column", &QSortFilterProxyModel::filterKeyColumn)
            .define_method("filter_regular_expression", &QSortFilterProxyModel::filterRegularExpression)
            .define_method("filter_role", &QSortFilterProxyModel::filterRole)
            .define_method("flags", &QSortFilterProxyModel::flags, Arg("index"))
            .define_method("has_children", &QSortFilterProxyModel::hasChildren, Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("header_data", &QSortFilterProxyModel::headerData, Arg("section"), Arg("orientation"), Arg("role") = static_cast<int>(Qt::DisplayRole))
            .define_method("index", &QSortFilterProxyModel::index, Arg("row"), Arg("column"), Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("insert_columns", &QSortFilterProxyModel::insertColumns, Arg("column"), Arg("count"), Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("insert_rows", &QSortFilterProxyModel::insertRows, Arg("row"), Arg("count"), Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("recursive_filtering_enabled?", &QSortFilterProxyModel::isRecursiveFilteringEnabled)
            .define_method("sort_locale_aware?", &QSortFilterProxyModel::isSortLocaleAware)
            .define_method("map_from_source", &QSortFilterProxyModel::mapFromSource, Arg("source_index"))
            .define_method("map_selection_from_source", &QSortFilterProxyModel::mapSelectionFromSource, Arg("source_selection"))
            .define_method("map_selection_to_source", &QSortFilterProxyModel::mapSelectionToSource, Arg("proxy_selection"))
            .define_method("map_to_source", &QSortFilterProxyModel::mapToSource, Arg("proxy_index"))
            .define_method("match", &QSortFilterProxyModel::match, Arg("start"), Arg("role"), Arg("value"), Arg("hits") = static_cast<int>(1), Arg("flags") = static_cast<Qt::MatchFlags>(Qt::MatchFlags(Qt::MatchStartsWith | Qt::MatchWrap)))
            .define_method("mime_data", &QSortFilterProxyModel::mimeData, Arg("indexes"))
            .define_method("mime_types", &QSortFilterProxyModel::mimeTypes)
            // .define_method("parent", &QSortFilterProxyModel::parent, Arg("child"))
            .define_method("remove_columns", &QSortFilterProxyModel::removeColumns, Arg("column"), Arg("count"), Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("remove_rows", &QSortFilterProxyModel::removeRows, Arg("row"), Arg("count"), Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("row_count", &QSortFilterProxyModel::rowCount, Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("set_auto_accept_child_rows", &QSortFilterProxyModel::setAutoAcceptChildRows, Arg("accept"))
            .define_method("set_data", &QSortFilterProxyModel::setData, Arg("index"), Arg("value"), Arg("role") = static_cast<int>(Qt::EditRole))
            .define_method("set_dynamic_sort_filter", &QSortFilterProxyModel::setDynamicSortFilter, Arg("enable"))
            .define_method("set_filter_case_sensitivity", &QSortFilterProxyModel::setFilterCaseSensitivity, Arg("cs"))
            .define_method("set_filter_key_column", &QSortFilterProxyModel::setFilterKeyColumn, Arg("column"))
            .define_method("set_filter_role", &QSortFilterProxyModel::setFilterRole, Arg("role"))
            .define_method("set_header_data", &QSortFilterProxyModel::setHeaderData, Arg("section"), Arg("orientation"), Arg("value"), Arg("role") = static_cast<int>(Qt::EditRole))
            .define_method("set_recursive_filtering_enabled", &QSortFilterProxyModel::setRecursiveFilteringEnabled, Arg("recursive"))
            .define_method("set_sort_case_sensitivity", &QSortFilterProxyModel::setSortCaseSensitivity, Arg("cs"))
            .define_method("set_sort_locale_aware", &QSortFilterProxyModel::setSortLocaleAware, Arg("on"))
            .define_method("set_sort_role", &QSortFilterProxyModel::setSortRole, Arg("role"))
            .define_method("set_source_model", &QSortFilterProxyModel::setSourceModel, Arg("source_model"))
            .define_method("sibling", &QSortFilterProxyModel::sibling, Arg("row"), Arg("column"), Arg("idx"))
            .define_method("sort", &QSortFilterProxyModel::sort, Arg("column"), Arg("order") = static_cast<Qt::SortOrder>(Qt::AscendingOrder))
            .define_method("sort_case_sensitivity", &QSortFilterProxyModel::sortCaseSensitivity)
            .define_method("sort_column", &QSortFilterProxyModel::sortColumn)
            .define_method("sort_order", &QSortFilterProxyModel::sortOrder)
            .define_method("sort_role", &QSortFilterProxyModel::sortRole)
            .define_method("span", &QSortFilterProxyModel::span, Arg("index"))
            .define_method("supported_drop_actions", &QSortFilterProxyModel::supportedDropActions)
            // Public Slots
            .define_method("invalidate", &QSortFilterProxyModel::invalidate)
            .define_method("set_filter_fixed_string", &QSortFilterProxyModel::setFilterFixedString, Arg("pattern"))
            .define_method<void (QSortFilterProxyModel::*)(const QRegularExpression &)>("set_filter_regular_expression", &QSortFilterProxyModel::setFilterRegularExpression, Arg("regular_expression"))
            .define_method<void (QSortFilterProxyModel::*)(const QString &)>("set_filter_regular_expression", &QSortFilterProxyModel::setFilterRegularExpression, Arg("pattern"))
            .define_method("set_filter_wildcard", &QSortFilterProxyModel::setFilterWildcard, Arg("pattern"));
            // Signals
            // .define_method("auto_accept_child_rows_changed", &QSortFilterProxyModel::autoAcceptChildRowsChanged, Arg("auto_accept_child_rows"))
            // .define_method("dynamic_sort_filter_changed", &QSortFilterProxyModel::dynamicSortFilterChanged, Arg("dynamic_sort_filter"))
            // .define_method("filter_case_sensitivity_changed", &QSortFilterProxyModel::filterCaseSensitivityChanged, Arg("filter_case_sensitivity"))
            // .define_method("filter_role_changed", &QSortFilterProxyModel::filterRoleChanged, Arg("filter_role"))
            // .define_method("recursive_filtering_enabled_changed", &QSortFilterProxyModel::recursiveFilteringEnabledChanged, Arg("recursive_filtering_enabled"))
            // .define_method("sort_case_sensitivity_changed", &QSortFilterProxyModel::sortCaseSensitivityChanged, Arg("sort_case_sensitivity"))
            // .define_method("sort_locale_aware_changed", &QSortFilterProxyModel::sortLocaleAwareChanged, Arg("sort_locale_aware"))
            // .define_method("sort_role_changed", &QSortFilterProxyModel::sortRoleChanged, Arg("sort_role"));


    Data_Type<QSortFilterProxyModel::Direction> rb_cQSortFilterProxyModelDirection =
        // RubyQt6::QtCore::QSortFilterProxyModel::Direction
        define_qenum_under<QSortFilterProxyModel::Direction>(rb_cQSortFilterProxyModel, "Direction");
        define_qenum_value_under(rb_cQSortFilterProxyModelDirection, "Rows", QSortFilterProxyModel::Direction::Rows);
        define_qenum_value_under(rb_cQSortFilterProxyModelDirection, "Columns", QSortFilterProxyModel::Direction::Columns);
        define_qenum_value_under(rb_cQSortFilterProxyModelDirection, "Both", QSortFilterProxyModel::Direction::Both);
}
