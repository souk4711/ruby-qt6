#include "qabstractitemmodel-rb.hpp"
#include <qabstractitemmodel.h>
#include <rice/qt6/qenum.hpp>

#include <QMimeData>
#include <QSize>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQAbstractItemModel;
Class rb_cQAbstractTableModel;
Class rb_cQAbstractListModel;

void Init_qabstractitemmodel(Module rb_mQt6QtCore)
{
    rb_cQAbstractItemModel =
        // RubyQt6::QtCore::QAbstractItemModel
        define_qlass_under<QAbstractItemModel, QObject>(rb_mQt6QtCore, "QAbstractItemModel")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QAbstractItemModel * { return qobject_cast<QAbstractItemModel *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QAbstractItemModel::staticMetaObject; })
            // Public Functions
            .define_method("buddy", &QAbstractItemModel::buddy, Arg("index"))
            .define_method("can_drop_mime_data", &QAbstractItemModel::canDropMimeData, Arg("data"), Arg("action"), Arg("row"), Arg("column"), Arg("parent"))
            .define_method("can_fetch_more", &QAbstractItemModel::canFetchMore, Arg("parent"))
            .define_method("check_index", &QAbstractItemModel::checkIndex, Arg("index"), Arg("options") = static_cast<QAbstractItemModel::CheckIndexOptions>(QAbstractItemModel::CheckIndexOption::NoOption))
            .define_method("clear_item_data", &QAbstractItemModel::clearItemData, Arg("index"))
            .define_method("column_count", &QAbstractItemModel::columnCount, Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("data", &QAbstractItemModel::data, Arg("index"), Arg("role") = static_cast<int>(Qt::DisplayRole))
            .define_method("drop_mime_data", &QAbstractItemModel::dropMimeData, Arg("data"), Arg("action"), Arg("row"), Arg("column"), Arg("parent"))
            .define_method("fetch_more", &QAbstractItemModel::fetchMore, Arg("parent"))
            .define_method("flags", &QAbstractItemModel::flags, Arg("index"))
            .define_method("has_children", &QAbstractItemModel::hasChildren, Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("has_index", &QAbstractItemModel::hasIndex, Arg("row"), Arg("column"), Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("header_data", &QAbstractItemModel::headerData, Arg("section"), Arg("orientation"), Arg("role") = static_cast<int>(Qt::DisplayRole))
            .define_method("index", &QAbstractItemModel::index, Arg("row"), Arg("column"), Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("insert_column", &QAbstractItemModel::insertColumn, Arg("column"), Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("insert_columns", &QAbstractItemModel::insertColumns, Arg("column"), Arg("count"), Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("insert_row", &QAbstractItemModel::insertRow, Arg("row"), Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("insert_rows", &QAbstractItemModel::insertRows, Arg("row"), Arg("count"), Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("item_data", &QAbstractItemModel::itemData, Arg("index"))
            .define_method("match", &QAbstractItemModel::match, Arg("start"), Arg("role"), Arg("value"), Arg("hits") = static_cast<int>(1), Arg("flags") = static_cast<Qt::MatchFlags>(Qt::MatchFlags(Qt::MatchStartsWith | Qt::MatchWrap)))
            .define_method("mime_data", &QAbstractItemModel::mimeData, Arg("indexes"))
            .define_method("mime_types", &QAbstractItemModel::mimeTypes)
            .define_method("move_column", &QAbstractItemModel::moveColumn, Arg("source_parent"), Arg("source_column"), Arg("destination_parent"), Arg("destination_child"))
            .define_method("move_columns", &QAbstractItemModel::moveColumns, Arg("source_parent"), Arg("source_column"), Arg("count"), Arg("destination_parent"), Arg("destination_child"))
            .define_method("move_row", &QAbstractItemModel::moveRow, Arg("source_parent"), Arg("source_row"), Arg("destination_parent"), Arg("destination_child"))
            .define_method("move_rows", &QAbstractItemModel::moveRows, Arg("source_parent"), Arg("source_row"), Arg("count"), Arg("destination_parent"), Arg("destination_child"))
            .define_method("multi_data", &QAbstractItemModel::multiData, Arg("index"), Arg("role_data_span"))
            // .define_method("parent", &QAbstractItemModel::parent, Arg("child"))
            .define_method("remove_column", &QAbstractItemModel::removeColumn, Arg("column"), Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("remove_columns", &QAbstractItemModel::removeColumns, Arg("column"), Arg("count"), Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("remove_row", &QAbstractItemModel::removeRow, Arg("row"), Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("remove_rows", &QAbstractItemModel::removeRows, Arg("row"), Arg("count"), Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("role_names", &QAbstractItemModel::roleNames)
            .define_method("row_count", &QAbstractItemModel::rowCount, Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("set_data", &QAbstractItemModel::setData, Arg("index"), Arg("value"), Arg("role") = static_cast<int>(Qt::EditRole))
            .define_method("set_header_data", &QAbstractItemModel::setHeaderData, Arg("section"), Arg("orientation"), Arg("value"), Arg("role") = static_cast<int>(Qt::EditRole))
            .define_method("set_item_data", &QAbstractItemModel::setItemData, Arg("index"), Arg("roles"))
            .define_method("sibling", &QAbstractItemModel::sibling, Arg("row"), Arg("column"), Arg("idx"))
            .define_method("sort", &QAbstractItemModel::sort, Arg("column"), Arg("order") = static_cast<Qt::SortOrder>(Qt::AscendingOrder))
            .define_method("span", &QAbstractItemModel::span, Arg("index"))
            .define_method("supported_drag_actions", &QAbstractItemModel::supportedDragActions)
            .define_method("supported_drop_actions", &QAbstractItemModel::supportedDropActions)
            // Public Slots
            .define_method("revert", &QAbstractItemModel::revert)
            .define_method("submit", &QAbstractItemModel::submit);
            // Signals
            // .define_method("columns_about_to_be_inserted", &QAbstractItemModel::columnsAboutToBeInserted, Arg("parent"), Arg("first"), Arg("last"), Arg("_"))
            // .define_method("columns_about_to_be_moved", &QAbstractItemModel::columnsAboutToBeMoved, Arg("source_parent"), Arg("source_start"), Arg("source_end"), Arg("destination_parent"), Arg("destination_column"), Arg("_"))
            // .define_method("columns_about_to_be_removed", &QAbstractItemModel::columnsAboutToBeRemoved, Arg("parent"), Arg("first"), Arg("last"), Arg("_"))
            // .define_method("columns_inserted", &QAbstractItemModel::columnsInserted, Arg("parent"), Arg("first"), Arg("last"), Arg("_"))
            // .define_method("columns_moved", &QAbstractItemModel::columnsMoved, Arg("source_parent"), Arg("source_start"), Arg("source_end"), Arg("destination_parent"), Arg("destination_column"), Arg("_"))
            // .define_method("columns_removed", &QAbstractItemModel::columnsRemoved, Arg("parent"), Arg("first"), Arg("last"), Arg("_"))
            // .define_method("data_changed", &QAbstractItemModel::dataChanged, Arg("top_left"), Arg("bottom_right"), Arg("roles") = static_cast<const QList<int> &>(QList<int>()))
            // .define_method("header_data_changed", &QAbstractItemModel::headerDataChanged, Arg("orientation"), Arg("first"), Arg("last"))
            // .define_method("layout_about_to_be_changed", &QAbstractItemModel::layoutAboutToBeChanged, Arg("parents") = static_cast<const QList<QPersistentModelIndex> &>(QList<QPersistentModelIndex>()), Arg("hint") = static_cast<QAbstractItemModel::LayoutChangeHint>(QAbstractItemModel::NoLayoutChangeHint))
            // .define_method("layout_changed", &QAbstractItemModel::layoutChanged, Arg("parents") = static_cast<const QList<QPersistentModelIndex> &>(QList<QPersistentModelIndex>()), Arg("hint") = static_cast<QAbstractItemModel::LayoutChangeHint>(QAbstractItemModel::NoLayoutChangeHint))
            // .define_method("model_about_to_be_reset", &QAbstractItemModel::modelAboutToBeReset, Arg("_"))
            // .define_method("model_reset", &QAbstractItemModel::modelReset, Arg("_"))
            // .define_method("rows_about_to_be_inserted", &QAbstractItemModel::rowsAboutToBeInserted, Arg("parent"), Arg("first"), Arg("last"), Arg("_"))
            // .define_method("rows_about_to_be_moved", &QAbstractItemModel::rowsAboutToBeMoved, Arg("source_parent"), Arg("source_start"), Arg("source_end"), Arg("destination_parent"), Arg("destination_row"), Arg("_"))
            // .define_method("rows_about_to_be_removed", &QAbstractItemModel::rowsAboutToBeRemoved, Arg("parent"), Arg("first"), Arg("last"), Arg("_"))
            // .define_method("rows_inserted", &QAbstractItemModel::rowsInserted, Arg("parent"), Arg("first"), Arg("last"), Arg("_"))
            // .define_method("rows_moved", &QAbstractItemModel::rowsMoved, Arg("source_parent"), Arg("source_start"), Arg("source_end"), Arg("destination_parent"), Arg("destination_row"), Arg("_"))
            // .define_method("rows_removed", &QAbstractItemModel::rowsRemoved, Arg("parent"), Arg("first"), Arg("last"), Arg("_"));

    Data_Type<QAbstractItemModel::CheckIndexOption> rb_cQAbstractItemModelCheckIndexOption =
        // RubyQt6::QtCore::QAbstractItemModel::CheckIndexOption
        define_qenum_under<QAbstractItemModel::CheckIndexOption>(rb_cQAbstractItemModel, "CheckIndexOption");
        define_qenum_value_under(rb_cQAbstractItemModelCheckIndexOption, "NoOption", QAbstractItemModel::CheckIndexOption::NoOption);
        define_qenum_value_under(rb_cQAbstractItemModelCheckIndexOption, "IndexIsValid", QAbstractItemModel::CheckIndexOption::IndexIsValid);
        define_qenum_value_under(rb_cQAbstractItemModelCheckIndexOption, "DoNotUseParent", QAbstractItemModel::CheckIndexOption::DoNotUseParent);
        define_qenum_value_under(rb_cQAbstractItemModelCheckIndexOption, "ParentIsInvalid", QAbstractItemModel::CheckIndexOption::ParentIsInvalid);

    Data_Type<QAbstractItemModel::LayoutChangeHint> rb_cQAbstractItemModelLayoutChangeHint =
        // RubyQt6::QtCore::QAbstractItemModel::LayoutChangeHint
        define_qenum_under<QAbstractItemModel::LayoutChangeHint>(rb_cQAbstractItemModel, "LayoutChangeHint");
        define_qenum_value_under(rb_cQAbstractItemModelLayoutChangeHint, "NoLayoutChangeHint", QAbstractItemModel::LayoutChangeHint::NoLayoutChangeHint);
        define_qenum_value_under(rb_cQAbstractItemModelLayoutChangeHint, "VerticalSortHint", QAbstractItemModel::LayoutChangeHint::VerticalSortHint);
        define_qenum_value_under(rb_cQAbstractItemModelLayoutChangeHint, "HorizontalSortHint", QAbstractItemModel::LayoutChangeHint::HorizontalSortHint);

    rb_cQAbstractTableModel =
        // RubyQt6::QtCore::QAbstractTableModel
        define_qlass_under<QAbstractTableModel, QAbstractItemModel>(rb_mQt6QtCore, "QAbstractTableModel")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QAbstractTableModel * { return qobject_cast<QAbstractTableModel *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QAbstractTableModel::staticMetaObject; })
            // Public Functions
            .define_method("drop_mime_data", &QAbstractTableModel::dropMimeData, Arg("data"), Arg("action"), Arg("row"), Arg("column"), Arg("parent"))
            .define_method("flags", &QAbstractTableModel::flags, Arg("index"))
            .define_method("index", &QAbstractTableModel::index, Arg("row"), Arg("column"), Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("sibling", &QAbstractTableModel::sibling, Arg("row"), Arg("column"), Arg("idx"));

    rb_cQAbstractListModel =
        // RubyQt6::QtCore::QAbstractListModel
        define_qlass_under<QAbstractListModel, QAbstractItemModel>(rb_mQt6QtCore, "QAbstractListModel")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QAbstractListModel * { return qobject_cast<QAbstractListModel *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QAbstractListModel::staticMetaObject; })
            // Public Functions
            .define_method("drop_mime_data", &QAbstractListModel::dropMimeData, Arg("data"), Arg("action"), Arg("row"), Arg("column"), Arg("parent"))
            .define_method("flags", &QAbstractListModel::flags, Arg("index"))
            .define_method("index", &QAbstractListModel::index, Arg("row"), Arg("column") = static_cast<int>(0), Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("sibling", &QAbstractListModel::sibling, Arg("row"), Arg("column"), Arg("idx"));
}
