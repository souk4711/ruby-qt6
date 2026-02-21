#include "qmodelindex-rb.hpp"
#include <qabstractitemmodel.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQModelIndex;

void Init_qmodelindex(Module rb_mQt6QtCore)
{
    rb_cQModelIndex =
        // RubyQt6::QtCore::QModelIndex
        define_qlass_under<QModelIndex>(rb_mQt6QtCore, "QModelIndex")
            // Constructor
            .define_constructor(Constructor<QModelIndex>())
            // Public Functions
            .define_method("column", &QModelIndex::column)
            .define_method("const_internal_pointer", &QModelIndex::constInternalPointer)
            .define_method("data", &QModelIndex::data, Arg("role") = static_cast<int>(Qt::DisplayRole))
            .define_method("flags", &QModelIndex::flags)
            .define_method("internal_id", &QModelIndex::internalId)
            .define_method("internal_pointer", &QModelIndex::internalPointer)
            .define_method("valid?", &QModelIndex::isValid)
            .define_method("model", &QModelIndex::model)
            .define_method("multi_data", &QModelIndex::multiData, Arg("role_data_span"))
            .define_method("parent", &QModelIndex::parent)
            .define_method("row", &QModelIndex::row)
            .define_method("sibling", &QModelIndex::sibling, Arg("row"), Arg("column"))
            .define_method("sibling_at_column", &QModelIndex::siblingAtColumn, Arg("column"))
            .define_method("sibling_at_row", &QModelIndex::siblingAtRow, Arg("row"));
}
