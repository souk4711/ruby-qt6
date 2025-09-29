#include "qfocusframe-rb.hpp"
#include <qfocusframe.h>

using namespace Rice;

Rice::Class rb_cQFocusFrame;

void Init_qfocusframe(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQFocusFrame =
        // RubyQt6::QtWidgets::QFocusFrame
        define_class_under<QFocusFrame, QWidget>(rb_mQt6QtWidgets, "QFocusFrame")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QFocusFrame::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QFocusFrame, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("set_widget", &QFocusFrame::setWidget, Arg("widget").takeOwnership())
            .define_method("widget", &QFocusFrame::widget);
}
