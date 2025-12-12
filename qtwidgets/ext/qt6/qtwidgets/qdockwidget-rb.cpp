#include "qdockwidget-rb.hpp"
#include <qdockwidget.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQDockWidget;

void Init_qdockwidget(Module rb_mQt6QtWidgets)
{
    rb_cQDockWidget =
        // RubyQt6::QtWidgets::QDockWidget
        define_class_under<QDockWidget, QWidget>(rb_mQt6QtWidgets, "QDockWidget")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QDockWidget::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QDockWidget, const QString &, QWidget *>(), Arg("title"), Arg("parent"))
            // Public Functions
            .define_method("allowed_areas", &QDockWidget::allowedAreas)
            .define_method("dock_location", &QDockWidget::dockLocation)
            .define_method("features", &QDockWidget::features)
            .define_method("area_allowed?", &QDockWidget::isAreaAllowed, Arg("area"))
            .define_method("floating?", &QDockWidget::isFloating)
            .define_method("set_allowed_areas", &QDockWidget::setAllowedAreas, Arg("areas"))
            .define_method("set_dock_location", &QDockWidget::setDockLocation, Arg("area"))
            .define_method("set_features", &QDockWidget::setFeatures, Arg("features"))
            .define_method("set_floating", &QDockWidget::setFloating, Arg("floating"))
            .define_method("set_title_bar_widget", &QDockWidget::setTitleBarWidget, Arg("widget"))
            .define_method("set_widget", &QDockWidget::setWidget, Arg("widget"))
            .define_method("title_bar_widget", &QDockWidget::titleBarWidget)
            .define_method("toggle_view_action", &QDockWidget::toggleViewAction)
            .define_method("widget", &QDockWidget::widget);
            // Signals
            // .define_method("allowed_areas_changed", &QDockWidget::allowedAreasChanged, Arg("allowed_areas"))
            // .define_method("dock_location_changed", &QDockWidget::dockLocationChanged, Arg("area"))
            // .define_method("features_changed", &QDockWidget::featuresChanged, Arg("features"))
            // .define_method("top_level_changed", &QDockWidget::topLevelChanged, Arg("top_level"))
            // .define_method("visibility_changed", &QDockWidget::visibilityChanged, Arg("visible"));

    Data_Type<QDockWidget::DockWidgetFeature> rb_cQDockWidgetDockWidgetFeature =
        // RubyQt6::QtWidgets::QDockWidget::DockWidgetFeature
        define_qenum_under<QDockWidget::DockWidgetFeature>(rb_cQDockWidget, "DockWidgetFeature");
        define_qenum_value_under(rb_cQDockWidgetDockWidgetFeature, "DockWidgetClosable", QDockWidget::DockWidgetFeature::DockWidgetClosable);
        define_qenum_value_under(rb_cQDockWidgetDockWidgetFeature, "DockWidgetMovable", QDockWidget::DockWidgetFeature::DockWidgetMovable);
        define_qenum_value_under(rb_cQDockWidgetDockWidgetFeature, "DockWidgetFloatable", QDockWidget::DockWidgetFeature::DockWidgetFloatable);
        define_qenum_value_under(rb_cQDockWidgetDockWidgetFeature, "DockWidgetVerticalTitleBar", QDockWidget::DockWidgetFeature::DockWidgetVerticalTitleBar);
        define_qenum_value_under(rb_cQDockWidgetDockWidgetFeature, "DockWidgetFeatureMask", QDockWidget::DockWidgetFeature::DockWidgetFeatureMask);
        define_qenum_value_under(rb_cQDockWidgetDockWidgetFeature, "NoDockWidgetFeatures", QDockWidget::DockWidgetFeature::NoDockWidgetFeatures);
        define_qenum_value_under(rb_cQDockWidgetDockWidgetFeature, "Reserved", QDockWidget::DockWidgetFeature::Reserved);

    Data_Type<QFlags<QDockWidget::DockWidgetFeature>> rb_cQDockWidgetDockWidgetFeatures =
        // RubyQt6::QtWidgets::QDockWidget::DockWidgetFeatures
        define_qflags_under<QDockWidget::DockWidgetFeature>(rb_cQDockWidget, "DockWidgetFeatures");
}
