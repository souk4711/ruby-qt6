#include "qscrollbar-rb.hpp"
#include <qscrollbar.h>

#include <QEvent>

using namespace Rice;

Rice::Class rb_cQScrollBar;

void Init_qscrollbar(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQScrollBar =
        // RubyQt6::QtWidgets::QScrollBar
        define_class_under<QScrollBar, QAbstractSlider>(rb_mQt6QtWidgets, "QScrollBar")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QScrollBar::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QScrollBar, Qt::Orientation, QWidget *>(), Arg("orientation"), Arg("parent"))
            // Public Functions
            .define_method("event", &QScrollBar::event, Arg("event"))
            .define_method("size_hint", &QScrollBar::sizeHint);
}
