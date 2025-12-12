#include "qgroupbox-rb.hpp"
#include <qgroupbox.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQGroupBox;

void Init_qgroupbox(Module rb_mQt6QtWidgets)
{
    rb_cQGroupBox =
        // RubyQt6::QtWidgets::QGroupBox
        define_class_under<QGroupBox, QWidget>(rb_mQt6QtWidgets, "QGroupBox")
            // RubyQt6-Defined Functions
            .define_method("set_alignment", [](QGroupBox *self, Qt::AlignmentFlag alignment) -> void { return self->setAlignment(alignment); }, Arg("alignment"))
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QGroupBox::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QGroupBox, const QString &, QWidget *>(), Arg("title"), Arg("parent"))
            // Public Functions
            .define_method("alignment", &QGroupBox::alignment)
            .define_method("checkable?", &QGroupBox::isCheckable)
            .define_method("checked?", &QGroupBox::isChecked)
            .define_method("flat?", &QGroupBox::isFlat)
            .define_method("set_alignment", &QGroupBox::setAlignment, Arg("alignment"))
            .define_method("set_checkable", &QGroupBox::setCheckable, Arg("checkable"))
            .define_method("set_flat", &QGroupBox::setFlat, Arg("flat"))
            .define_method("set_title", &QGroupBox::setTitle, Arg("title"))
            .define_method("title", &QGroupBox::title)
            // Public Slots
            .define_method("set_checked", &QGroupBox::setChecked, Arg("checked"));
            // Signals
            // .define_method("clicked", &QGroupBox::clicked, Arg("checked") = static_cast<bool>(false))
            // .define_method("toggled", &QGroupBox::toggled, Arg("on"));
}
