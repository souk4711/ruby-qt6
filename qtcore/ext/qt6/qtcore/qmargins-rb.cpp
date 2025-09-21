#include "qmargins-rb.hpp"
#include <qmargins.h>

using namespace Rice;

Rice::Class rb_cQMargins;
Rice::Class rb_cQMarginsF;

void Init_qmargins(Rice::Module rb_mQt6QtCore)
{
    rb_cQMargins =
        // RubyQt6::QtCore::QMargins
        define_class_under<QMargins>(rb_mQt6QtCore, "QMargins")
            // Constructor
            .define_constructor(Constructor<QMargins, int, int, int, int>(), Arg("left"), Arg("top"), Arg("right"), Arg("bottom"))
            // Public Functions
            .define_method("bottom", &QMargins::bottom)
            .define_method("null?", &QMargins::isNull)
            .define_method("left", &QMargins::left)
            .define_method("right", &QMargins::right)
            .define_method("set_bottom", &QMargins::setBottom, Arg("bottom"))
            .define_method("set_left", &QMargins::setLeft, Arg("left"))
            .define_method("set_right", &QMargins::setRight, Arg("right"))
            .define_method("set_top", &QMargins::setTop, Arg("top"))
            .define_method("to_margins_f", &QMargins::toMarginsF)
            .define_method("top", &QMargins::top);

    rb_cQMarginsF =
        // RubyQt6::QtCore::QMarginsF
        define_class_under<QMarginsF>(rb_mQt6QtCore, "QMarginsF")
            // Constructor
            .define_constructor(Constructor<QMarginsF, int, int, int, int>(), Arg("left"), Arg("top"), Arg("right"), Arg("bottom"))
            .define_constructor(Constructor<QMarginsF, const QMargins &>(), Arg("margin"))
            // Public Functions
            .define_method("bottom", &QMarginsF::bottom)
            .define_method("null?", &QMarginsF::isNull)
            .define_method("left", &QMarginsF::left)
            .define_method("right", &QMarginsF::right)
            .define_method("set_bottom", &QMarginsF::setBottom, Arg("bottom"))
            .define_method("set_left", &QMarginsF::setLeft, Arg("left"))
            .define_method("set_right", &QMarginsF::setRight, Arg("right"))
            .define_method("set_top", &QMarginsF::setTop, Arg("top"))
            .define_method("to_margins", &QMarginsF::toMargins)
            .define_method("top", &QMarginsF::top);
}
