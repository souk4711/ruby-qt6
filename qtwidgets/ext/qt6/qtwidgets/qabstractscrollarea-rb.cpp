#include "qabstractscrollarea-rb.hpp"
#include <qabstractscrollarea.h>
#include <rice/qt6/qenum.hpp>

#include <QScrollBar>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQAbstractScrollArea;

void Init_qabstractscrollarea(Module rb_mQt6QtWidgets)
{
    rb_cQAbstractScrollArea =
        // RubyQt6::QtWidgets::QAbstractScrollArea
        define_qlass_under<QAbstractScrollArea, QFrame>(rb_mQt6QtWidgets, "QAbstractScrollArea")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QAbstractScrollArea::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QAbstractScrollArea, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("add_scroll_bar_widget", &QAbstractScrollArea::addScrollBarWidget, Arg("widget"), Arg("alignment"))
            .define_method("corner_widget", &QAbstractScrollArea::cornerWidget)
            .define_method("horizontal_scroll_bar", &QAbstractScrollArea::horizontalScrollBar)
            .define_method("horizontal_scroll_bar_policy", &QAbstractScrollArea::horizontalScrollBarPolicy)
            .define_method("maximum_viewport_size", &QAbstractScrollArea::maximumViewportSize)
            .define_method("scroll_bar_widgets", &QAbstractScrollArea::scrollBarWidgets, Arg("alignment"))
            .define_method("set_corner_widget", &QAbstractScrollArea::setCornerWidget, Arg("widget"))
            .define_method("set_horizontal_scroll_bar", &QAbstractScrollArea::setHorizontalScrollBar, Arg("scrollbar"))
            .define_method("set_horizontal_scroll_bar_policy", &QAbstractScrollArea::setHorizontalScrollBarPolicy, Arg("policy"))
            .define_method("set_size_adjust_policy", &QAbstractScrollArea::setSizeAdjustPolicy, Arg("policy"))
            .define_method("set_vertical_scroll_bar", &QAbstractScrollArea::setVerticalScrollBar, Arg("scrollbar"))
            .define_method("set_vertical_scroll_bar_policy", &QAbstractScrollArea::setVerticalScrollBarPolicy, Arg("policy"))
            .define_method("set_viewport", &QAbstractScrollArea::setViewport, Arg("widget"))
            .define_method("setup_viewport", &QAbstractScrollArea::setupViewport, Arg("viewport"))
            .define_method("size_adjust_policy", &QAbstractScrollArea::sizeAdjustPolicy)
            .define_method("vertical_scroll_bar", &QAbstractScrollArea::verticalScrollBar)
            .define_method("vertical_scroll_bar_policy", &QAbstractScrollArea::verticalScrollBarPolicy)
            .define_method("viewport", &QAbstractScrollArea::viewport);

    Data_Type<QAbstractScrollArea::SizeAdjustPolicy> rb_cQAbstractScrollAreaSizeAdjustPolicy =
        // RubyQt6::QtWidgets::QAbstractScrollArea::SizeAdjustPolicy
        define_qenum_under<QAbstractScrollArea::SizeAdjustPolicy>(rb_cQAbstractScrollArea, "SizeAdjustPolicy");
        define_qenum_value_under(rb_cQAbstractScrollAreaSizeAdjustPolicy, "AdjustIgnored", QAbstractScrollArea::SizeAdjustPolicy::AdjustIgnored);
        define_qenum_value_under(rb_cQAbstractScrollAreaSizeAdjustPolicy, "AdjustToContentsOnFirstShow", QAbstractScrollArea::SizeAdjustPolicy::AdjustToContentsOnFirstShow);
        define_qenum_value_under(rb_cQAbstractScrollAreaSizeAdjustPolicy, "AdjustToContents", QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
}
