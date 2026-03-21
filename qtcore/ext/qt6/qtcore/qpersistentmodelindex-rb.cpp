#include "qpersistentmodelindex-rb.hpp"
#include <qabstractitemmodel.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQPersistentModelIndex;

void Init_qpersistentmodelindex(Module rb_mQt6QtCore)
{
    rb_cQPersistentModelIndex =
        // RubyQt6::QtCore::QPersistentModelIndex
        define_qlass_under<QPersistentModelIndex>(rb_mQt6QtCore, "QPersistentModelIndex")
            // Constructor
            .define_constructor(Constructor<QPersistentModelIndex, const QModelIndex &>(), Arg("index"))
            // Public Functions
            .define_method("column", &QPersistentModelIndex::column)
            .define_method("data", &QPersistentModelIndex::data, Arg("role") = static_cast<int>(Qt::DisplayRole))
            .define_method("flags", &QPersistentModelIndex::flags)
            .define_method("valid?", &QPersistentModelIndex::isValid)
            .define_method("model", &QPersistentModelIndex::model)
            .define_method("multi_data", &QPersistentModelIndex::multiData, Arg("role_data_span"))
            .define_method("parent", &QPersistentModelIndex::parent)
            .define_method("row", &QPersistentModelIndex::row)
            .define_method("sibling", &QPersistentModelIndex::sibling, Arg("row"), Arg("column"))
            .define_method("to_qmodelindex", [](QPersistentModelIndex *self) -> QModelIndex { return *self; });
}
