#include "qitemselection-rb.hpp"
#include <qitemselectionmodel.h>

using namespace Rice;

Rice::Class rb_cQItemSelectionRange;
Rice::Class rb_cQItemSelection;

void Init_qitemselection(Rice::Module rb_mQt6QtCore)
{
    rb_cQItemSelectionRange =
        // RubyQt6::QtCore::QItemSelectionRange
        define_class_under<QItemSelectionRange>(rb_mQt6QtCore, "QItemSelectionRange")
            // Constructor
            .define_constructor(Constructor<QItemSelectionRange>())
            .define_constructor(Constructor<QItemSelectionRange, const QModelIndex &>(), Arg("index"))
            .define_constructor(Constructor<QItemSelectionRange, const QModelIndex &, const QModelIndex &>(), Arg("top_left"), Arg("bottom_right"))
            // Public Functions
            .define_method("bottom", &QItemSelectionRange::bottom)
            .define_method("bottom_right", &QItemSelectionRange::bottomRight)
            .define_method<bool (QItemSelectionRange::*)(const QModelIndex &) const>("contains", &QItemSelectionRange::contains, Arg("index"))
            .define_method<bool (QItemSelectionRange::*)(int, int, const QModelIndex &) const>("contains", &QItemSelectionRange::contains, Arg("row"), Arg("column"), Arg("parent_index"))
            .define_method("height", &QItemSelectionRange::height)
            .define_method("indexes", &QItemSelectionRange::indexes)
            .define_method("intersected", &QItemSelectionRange::intersected, Arg("other"))
            .define_method("intersects", &QItemSelectionRange::intersects, Arg("other"))
            .define_method("empty?", &QItemSelectionRange::isEmpty)
            .define_method("valid?", &QItemSelectionRange::isValid)
            .define_method("left", &QItemSelectionRange::left)
            .define_method("model", &QItemSelectionRange::model)
            .define_method("parent", &QItemSelectionRange::parent)
            .define_method("right", &QItemSelectionRange::right)
            .define_method("swap", &QItemSelectionRange::swap, Arg("other"))
            .define_method("top", &QItemSelectionRange::top)
            .define_method("top_left", &QItemSelectionRange::topLeft)
            .define_method("width", &QItemSelectionRange::width);

    rb_cQItemSelection =
        // RubyQt6::QtCore::QItemSelection
        define_class_under<QItemSelection, QList<QItemSelectionRange>>(rb_mQt6QtCore, "QItemSelection")
            // Public Functions
            .define_method("contains", &QItemSelection::contains, Arg("index"))
            .define_method("indexes", &QItemSelection::indexes)
            .define_method("merge", &QItemSelection::merge, Arg("other"), Arg("command"))
            .define_method("select", &QItemSelection::select, Arg("top_left"), Arg("bottom_right"))
            // Static Public Members
            .define_singleton_function("split", &QItemSelection::split, Arg("range"), Arg("other"), Arg("result"));
 }
