#include "qsplitter-rb.hpp"
#include <qsplitter.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQSplitter;
Class rb_cQSplitterHandle;

void Init_qsplitter(Module rb_mQt6QtWidgets)
{
    rb_cQSplitter =
        // RubyQt6::QtWidgets::QSplitter
        define_qlass_under<QSplitter, QFrame>(rb_mQt6QtWidgets, "QSplitter")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QSplitter * { return qobject_cast<QSplitter *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QSplitter::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QSplitter, Qt::Orientation, QWidget *>(), Arg("orientation"), Arg("parent"))
            // Public Functions
            .define_method("add_widget", &QSplitter::addWidget, Arg("widget"))
            .define_method("children_collapsible", &QSplitter::childrenCollapsible)
            .define_method("count", &QSplitter::count)
            .define_method("get_range", &QSplitter::getRange, Arg("index"), Arg("min"), Arg("max"))
            .define_method("handle", &QSplitter::handle, Arg("index"))
            .define_method("handle_width", &QSplitter::handleWidth)
            .define_method("index_of", &QSplitter::indexOf, Arg("w"))
            .define_method("insert_widget", &QSplitter::insertWidget, Arg("index"), Arg("widget"))
            .define_method("collapsible?", &QSplitter::isCollapsible, Arg("index"))
            .define_method("opaque_resize", &QSplitter::opaqueResize)
            .define_method("orientation", &QSplitter::orientation)
            .define_method("refresh", &QSplitter::refresh)
            .define_method("replace_widget", &QSplitter::replaceWidget, Arg("index"), Arg("widget"))
            .define_method("restore_state", &QSplitter::restoreState, Arg("state"))
            .define_method("save_state", &QSplitter::saveState)
            .define_method("set_children_collapsible", &QSplitter::setChildrenCollapsible, Arg("enable"))
            .define_method("set_collapsible", &QSplitter::setCollapsible, Arg("index"), Arg("enable"))
            .define_method("set_handle_width", &QSplitter::setHandleWidth, Arg("w"))
            .define_method("set_opaque_resize", &QSplitter::setOpaqueResize, Arg("opaque") = static_cast<bool>(true))
            .define_method("set_orientation", &QSplitter::setOrientation, Arg("orientation"))
            .define_method("set_sizes", &QSplitter::setSizes, Arg("list"))
            .define_method("set_stretch_factor", &QSplitter::setStretchFactor, Arg("index"), Arg("stretch"))
            .define_method("sizes", &QSplitter::sizes)
            .define_method("widget", &QSplitter::widget, Arg("index"));
            // Signals
            // .define_method("splitter_moved", &QSplitter::splitterMoved, Arg("pos"), Arg("index"));

    rb_cQSplitterHandle =
        // RubyQt6::QtWidgets::QSplitterHandle
        define_qlass_under<QSplitterHandle, QWidget>(rb_mQt6QtWidgets, "QSplitterHandle")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QSplitterHandle * { return qobject_cast<QSplitterHandle *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QSplitterHandle::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QSplitterHandle, Qt::Orientation, QSplitter *>(), Arg("orientation"), Arg("parent"))
            // Public Functions
            .define_method("opaque_resize", &QSplitterHandle::opaqueResize)
            .define_method("orientation", &QSplitterHandle::orientation)
            .define_method("set_orientation", &QSplitterHandle::setOrientation, Arg("o"))
            .define_method("splitter", &QSplitterHandle::splitter);
}
