#include "qitemselectionmodel-rb.hpp"
#include <qitemselectionmodel.h>
#include <rice/qflags.hpp>

#include <QBindable>

using namespace Rice;

Rice::Class rb_cQItemSelectionModel;

void Init_qitemselectionmodel(Rice::Module rb_mQt6QtCore)
{
    rb_cQItemSelectionModel =
        // RubyQt6::QtCore::QItemSelectionModel
        define_class_under<QItemSelectionModel, QObject>(rb_mQt6QtCore, "QItemSelectionModel")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QItemSelectionModel::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QItemSelectionModel, QAbstractItemModel *, QObject *>(), Arg("model"), Arg("parent"))
            // Public Functions
            .define_method("bindable_model", &QItemSelectionModel::bindableModel)
            .define_method("column_intersects_selection", &QItemSelectionModel::columnIntersectsSelection, Arg("column"), Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("current_index", &QItemSelectionModel::currentIndex)
            .define_method("has_selection", &QItemSelectionModel::hasSelection)
            .define_method("column_selected?", &QItemSelectionModel::isColumnSelected, Arg("column"), Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("row_selected?", &QItemSelectionModel::isRowSelected, Arg("row"), Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("selected?", &QItemSelectionModel::isSelected, Arg("index"))
            .define_method<QAbstractItemModel *(QItemSelectionModel::*)()>("model", &QItemSelectionModel::model)
            .define_method<const QAbstractItemModel *(QItemSelectionModel::*)() const>("model", &QItemSelectionModel::model)
            .define_method("row_intersects_selection", &QItemSelectionModel::rowIntersectsSelection, Arg("row"), Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("selected_columns", &QItemSelectionModel::selectedColumns, Arg("row") = static_cast<int>(0))
            .define_method("selected_indexes", &QItemSelectionModel::selectedIndexes)
            .define_method("selected_rows", &QItemSelectionModel::selectedRows, Arg("column") = static_cast<int>(0))
            .define_method("selection", &QItemSelectionModel::selection)
            .define_method("set_model", &QItemSelectionModel::setModel, Arg("model"))
            // Public Slots
            .define_method("clear", &QItemSelectionModel::clear)
            .define_method("clear_current_index", &QItemSelectionModel::clearCurrentIndex)
            .define_method("clear_selection", &QItemSelectionModel::clearSelection)
            .define_method("reset", &QItemSelectionModel::reset)
            .define_method<void (QItemSelectionModel::*)(const QItemSelection &, QItemSelectionModel::SelectionFlags)>("select", &QItemSelectionModel::select, Arg("selection"), Arg("command"))
            .define_method<void (QItemSelectionModel::*)(const QModelIndex &, QItemSelectionModel::SelectionFlags)>("select", &QItemSelectionModel::select, Arg("index"), Arg("command"))
            .define_method("set_current_index", &QItemSelectionModel::setCurrentIndex, Arg("index"), Arg("command"))
            // Signals
            .define_method("current_changed", &QItemSelectionModel::currentChanged, Arg("current"), Arg("previous"))
            .define_method("current_column_changed", &QItemSelectionModel::currentColumnChanged, Arg("current"), Arg("previous"))
            .define_method("current_row_changed", &QItemSelectionModel::currentRowChanged, Arg("current"), Arg("previous"))
            .define_method("model_changed", &QItemSelectionModel::modelChanged, Arg("model"))
            .define_method("selection_changed", &QItemSelectionModel::selectionChanged, Arg("selected"), Arg("deselected"));

    Enum<QItemSelectionModel::SelectionFlag> rb_cQItemSelectionModelSelectionFlag =
        // RubyQt6::QtCore::QItemSelectionModel::SelectionFlag
        define_enum_under<QItemSelectionModel::SelectionFlag>("SelectionFlag", rb_cQItemSelectionModel)
            .define_value("NoUpdate", QItemSelectionModel::SelectionFlag::NoUpdate)
            .define_value("Clear", QItemSelectionModel::SelectionFlag::Clear)
            .define_value("Select", QItemSelectionModel::SelectionFlag::Select)
            .define_value("Deselect", QItemSelectionModel::SelectionFlag::Deselect)
            .define_value("Toggle", QItemSelectionModel::SelectionFlag::Toggle)
            .define_value("Current", QItemSelectionModel::SelectionFlag::Current)
            .define_value("Rows", QItemSelectionModel::SelectionFlag::Rows)
            .define_value("Columns", QItemSelectionModel::SelectionFlag::Columns)
            .define_value("SelectCurrent", QItemSelectionModel::SelectionFlag::SelectCurrent)
            .define_value("ToggleCurrent", QItemSelectionModel::SelectionFlag::ToggleCurrent)
            .define_value("ClearAndSelect", QItemSelectionModel::SelectionFlag::ClearAndSelect);

    Data_Type<QFlags<QItemSelectionModel::SelectionFlag>> rb_cQItemSelectionModelSelectionFlags =
        // RubyQt6::QtCore::QItemSelectionModel::SelectionFlags
        define_qflags_under<QItemSelectionModel::SelectionFlag>(rb_cQItemSelectionModel, "SelectionFlags");
 }
