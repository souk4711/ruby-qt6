#include "qscrollbar-rb.hpp"
#include <qscrollbar.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQScrollBar;

void Init_qscrollbar(Module rb_mQt6QtWidgets)
{
    rb_cQScrollBar =
        // RubyQt6::QtWidgets::QScrollBar
        define_qlass_under<QScrollBar, QAbstractSlider>(rb_mQt6QtWidgets, "QScrollBar")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QScrollBar * { return qobject_cast<QScrollBar *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QScrollBar::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QScrollBar, Qt::Orientation, QWidget *>(), Arg("orientation"), Arg("parent"));
}
