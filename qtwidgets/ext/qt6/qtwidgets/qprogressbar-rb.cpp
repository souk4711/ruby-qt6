#include "qprogressbar-rb.hpp"
#include <qprogressbar.h>
#include <rice/qenum.hpp>

using namespace Rice;

Rice::Class rb_cQProgressBar;

void Init_qprogressbar(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQProgressBar =
        // RubyQt6::QtWidgets::QProgressBar
        define_class_under<QProgressBar, QWidget>(rb_mQt6QtWidgets, "QProgressBar")
            // RubyQt6-Defined Functions
            .define_method("set_alignment", [](QProgressBar *self, Qt::AlignmentFlag alignment) -> void { return self->setAlignment(alignment); }, Arg("alignment"))
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QProgressBar::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QProgressBar, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("alignment", &QProgressBar::alignment)
            .define_method("format", &QProgressBar::format)
            .define_method("inverted_appearance", &QProgressBar::invertedAppearance)
            .define_method("text_visible?", &QProgressBar::isTextVisible)
            .define_method("maximum", &QProgressBar::maximum)
            .define_method("minimum", &QProgressBar::minimum)
            .define_method("orientation", &QProgressBar::orientation)
            .define_method("reset_format", &QProgressBar::resetFormat)
            .define_method("set_alignment", &QProgressBar::setAlignment, Arg("alignment"))
            .define_method("set_format", &QProgressBar::setFormat, Arg("format"))
            .define_method("set_inverted_appearance", &QProgressBar::setInvertedAppearance, Arg("invert"))
            .define_method("set_text_direction", &QProgressBar::setTextDirection, Arg("text_direction"))
            .define_method("set_text_visible", &QProgressBar::setTextVisible, Arg("visible"))
            .define_method("text", &QProgressBar::text)
            .define_method("text_direction", &QProgressBar::textDirection)
            .define_method("value", &QProgressBar::value)
            // Public Slots
            .define_method("reset", &QProgressBar::reset)
            .define_method("set_maximum", &QProgressBar::setMaximum, Arg("maximum"))
            .define_method("set_minimum", &QProgressBar::setMinimum, Arg("minimum"))
            .define_method("set_orientation", &QProgressBar::setOrientation, Arg("orientation"))
            .define_method("set_range", &QProgressBar::setRange, Arg("minimum"), Arg("maximum"))
            .define_method("set_value", &QProgressBar::setValue, Arg("value"))
            // Signals
            .define_method("value_changed", &QProgressBar::valueChanged, Arg("value"));

    Data_Type<QProgressBar::Direction> rb_cQProgressBarDirection =
        // RubyQt6::QtWidgets::QProgressBar::Direction
        define_qenum_under<QProgressBar::Direction>(rb_cQProgressBar, "Direction");
        define_qenum_value_under(rb_cQProgressBarDirection, "TopToBottom", QProgressBar::Direction::TopToBottom);
        define_qenum_value_under(rb_cQProgressBarDirection, "BottomToTop", QProgressBar::Direction::BottomToTop);
}
