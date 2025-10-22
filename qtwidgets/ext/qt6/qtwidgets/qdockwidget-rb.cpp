#include "qdockwidget-rb.hpp"
#include <qdockwidget.h>
#include <rice/qenum.hpp>
#include <rice/qflags.hpp>

using namespace Rice;

Rice::Class rb_cQDockWidget;

void Init_qdockwidget(Rice::Module rb_mQt6QtWidgets)
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
            .define_method("set_title_bar_widget", &QDockWidget::setTitleBarWidget, Arg("widget").takeOwnership())
            .define_method("set_widget", &QDockWidget::setWidget, Arg("widget").takeOwnership())
            .define_method("title_bar_widget", &QDockWidget::titleBarWidget)
            .define_method("toggle_view_action", &QDockWidget::toggleViewAction)
            .define_method("widget", &QDockWidget::widget)
            // Signals
            .define_method("allowed_areas_changed", &QDockWidget::allowedAreasChanged, Arg("allowed_areas"))
            .define_method("dock_location_changed", &QDockWidget::dockLocationChanged, Arg("area"))
            .define_method("features_changed", &QDockWidget::featuresChanged, Arg("features"))
            .define_method("top_level_changed", &QDockWidget::topLevelChanged, Arg("top_level"))
            .define_method("visibility_changed", &QDockWidget::visibilityChanged, Arg("visible"));

    Enum<QDockWidget::DockWidgetFeature> rb_cQDockWidgetDockWidgetFeature =
        // RubyQt6::QtWidgets::QDockWidget::DockWidgetFeature
        define_qenum_under<QDockWidget::DockWidgetFeature>("DockWidgetFeature", rb_cQDockWidget)
            .define_value("DockWidgetClosable", QDockWidget::DockWidgetFeature::DockWidgetClosable)
            .define_value("DockWidgetMovable", QDockWidget::DockWidgetFeature::DockWidgetMovable)
            .define_value("DockWidgetFloatable", QDockWidget::DockWidgetFeature::DockWidgetFloatable)
            .define_value("DockWidgetVerticalTitleBar", QDockWidget::DockWidgetFeature::DockWidgetVerticalTitleBar)
            .define_value("DockWidgetFeatureMask", QDockWidget::DockWidgetFeature::DockWidgetFeatureMask)
            .define_value("NoDockWidgetFeatures", QDockWidget::DockWidgetFeature::NoDockWidgetFeatures)
            .define_value("Reserved", QDockWidget::DockWidgetFeature::Reserved);

    Data_Type<QFlags<QDockWidget::DockWidgetFeature>> rb_cQDockWidgetDockWidgetFeatures =
        // RubyQt6::QtWidgets::QDockWidget::DockWidgetFeatures
        define_qflags_under<QDockWidget::DockWidgetFeature>(rb_cQDockWidget, "DockWidgetFeatures");
}
