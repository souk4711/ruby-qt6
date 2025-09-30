#include "qscrollarea-rb.hpp"
#include <qscrollarea.h>

using namespace Rice;

Rice::Class rb_cQScrollArea;

void Init_qscrollarea(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQScrollArea =
        // RubyQt6::QtWidgets::QScrollArea
        define_class_under<QScrollArea, QAbstractScrollArea>(rb_mQt6QtWidgets, "QScrollArea")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QScrollArea::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QScrollArea, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("alignment", &QScrollArea::alignment)
            .define_method("ensure_visible", &QScrollArea::ensureVisible, Arg("x"), Arg("y"), Arg("xmargin") = static_cast<int>(50), Arg("ymargin") = static_cast<int>(50))
            .define_method("ensure_widget_visible", &QScrollArea::ensureWidgetVisible, Arg("child_widget"), Arg("xmargin") = static_cast<int>(50), Arg("ymargin") = static_cast<int>(50))
            .define_method("focus_next_prev_child", &QScrollArea::focusNextPrevChild, Arg("next"))
            .define_method("set_alignment", &QScrollArea::setAlignment, Arg("alignment"))
            .define_method("set_widget", &QScrollArea::setWidget, Arg("widget").takeOwnership())
            .define_method("set_widget_resizable", &QScrollArea::setWidgetResizable, Arg("resizable"))
            .define_method("size_hint", &QScrollArea::sizeHint)
            .define_method("take_widget", &QScrollArea::takeWidget, Return().takeOwnership())
            .define_method("widget", &QScrollArea::widget)
            .define_method("widget_resizable", &QScrollArea::widgetResizable);
}
