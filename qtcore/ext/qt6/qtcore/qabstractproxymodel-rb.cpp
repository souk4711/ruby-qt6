#include "qabstractproxymodel-rb.hpp"
#include <qabstractproxymodel.h>

#include <QBindable>
#include <QItemSelection>
#include <QSize>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQAbstractProxyModel;

void Init_qabstractproxymodel(Module rb_mQt6QtCore)
{
    rb_cQAbstractProxyModel =
        // RubyQt6::QtCore::QAbstractProxyModel
        define_qlass_under<QAbstractProxyModel, QAbstractItemModel>(rb_mQt6QtCore, "QAbstractProxyModel")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QAbstractProxyModel * { return qobject_cast<QAbstractProxyModel *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QAbstractProxyModel::staticMetaObject; })
            // Public Functions
            .define_method("bindable_source_model", &QAbstractProxyModel::bindableSourceModel)
            .define_method("buddy", &QAbstractProxyModel::buddy, Arg("index"))
            .define_method("can_drop_mime_data", &QAbstractProxyModel::canDropMimeData, Arg("data"), Arg("action"), Arg("row"), Arg("column"), Arg("parent"))
            .define_method("can_fetch_more", &QAbstractProxyModel::canFetchMore, Arg("parent"))
            .define_method("clear_item_data", &QAbstractProxyModel::clearItemData, Arg("index"))
            .define_method("data", &QAbstractProxyModel::data, Arg("proxy_index"), Arg("role") = static_cast<int>(Qt::DisplayRole))
            .define_method("drop_mime_data", &QAbstractProxyModel::dropMimeData, Arg("data"), Arg("action"), Arg("row"), Arg("column"), Arg("parent"))
            .define_method("fetch_more", &QAbstractProxyModel::fetchMore, Arg("parent"))
            .define_method("flags", &QAbstractProxyModel::flags, Arg("index"))
            .define_method("has_children", &QAbstractProxyModel::hasChildren, Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("header_data", &QAbstractProxyModel::headerData, Arg("section"), Arg("orientation"), Arg("role") = static_cast<int>(Qt::DisplayRole))
            .define_method("item_data", &QAbstractProxyModel::itemData, Arg("index"))
            .define_method("map_from_source", &QAbstractProxyModel::mapFromSource, Arg("source_index"))
            .define_method("map_selection_from_source", &QAbstractProxyModel::mapSelectionFromSource, Arg("selection"))
            .define_method("map_selection_to_source", &QAbstractProxyModel::mapSelectionToSource, Arg("selection"))
            .define_method("map_to_source", &QAbstractProxyModel::mapToSource, Arg("proxy_index"))
            .define_method("mime_data", &QAbstractProxyModel::mimeData, Arg("indexes"))
            .define_method("mime_types", &QAbstractProxyModel::mimeTypes)
            .define_method("revert", &QAbstractProxyModel::revert)
            .define_method("role_names", &QAbstractProxyModel::roleNames)
            .define_method("set_data", &QAbstractProxyModel::setData, Arg("index"), Arg("value"), Arg("role") = static_cast<int>(Qt::EditRole))
            .define_method("set_header_data", &QAbstractProxyModel::setHeaderData, Arg("section"), Arg("orientation"), Arg("value"), Arg("role") = static_cast<int>(Qt::EditRole))
            .define_method("set_item_data", &QAbstractProxyModel::setItemData, Arg("index"), Arg("roles"))
            .define_method("set_source_model", &QAbstractProxyModel::setSourceModel, Arg("source_model"))
            .define_method("sibling", &QAbstractProxyModel::sibling, Arg("row"), Arg("column"), Arg("idx"))
            .define_method("sort", &QAbstractProxyModel::sort, Arg("column"), Arg("order") = static_cast<Qt::SortOrder>(Qt::AscendingOrder))
            .define_method("source_model", &QAbstractProxyModel::sourceModel)
            .define_method("span", &QAbstractProxyModel::span, Arg("index"))
            .define_method("submit", &QAbstractProxyModel::submit)
            .define_method("supported_drag_actions", &QAbstractProxyModel::supportedDragActions)
            .define_method("supported_drop_actions", &QAbstractProxyModel::supportedDropActions);
            // Signals
            // .define_method("source_model_changed", &QAbstractProxyModel::sourceModelChanged, Arg("_"));
}
