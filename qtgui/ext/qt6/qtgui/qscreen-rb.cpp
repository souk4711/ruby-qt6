#include "qscreen-rb.hpp"
#include <qscreen.h>

#include <QPixmap>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQScreen;

void Init_qscreen(Module rb_mQt6QtGui)
{
    rb_cQScreen =
        // RubyQt6::QtGui::QScreen
        define_qlass_under<QScreen, QObject>(rb_mQt6QtGui, "QScreen")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QScreen * { return qobject_cast<QScreen *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QScreen::staticMetaObject; })
            // Public Functions
            .define_method("angle_between", &QScreen::angleBetween, Arg("a"), Arg("b"))
            .define_method("available_geometry", &QScreen::availableGeometry)
            .define_method("available_size", &QScreen::availableSize)
            .define_method("available_virtual_geometry", &QScreen::availableVirtualGeometry)
            .define_method("available_virtual_size", &QScreen::availableVirtualSize)
            .define_method("depth", &QScreen::depth)
            .define_method("device_pixel_ratio", &QScreen::devicePixelRatio)
            .define_method("geometry", &QScreen::geometry)
            .define_method("grab_window", &QScreen::grabWindow, Arg("window") = static_cast<WId>(0), Arg("x") = static_cast<int>(0), Arg("y") = static_cast<int>(0), Arg("w") = static_cast<int>(-1), Arg("h") = static_cast<int>(-1))
            .define_method("landscape?", &QScreen::isLandscape, Arg("orientation"))
            .define_method("portrait?", &QScreen::isPortrait, Arg("orientation"))
            .define_method("logical_dots_per_inch", &QScreen::logicalDotsPerInch)
            .define_method("logical_dots_per_inch_x", &QScreen::logicalDotsPerInchX)
            .define_method("logical_dots_per_inch_y", &QScreen::logicalDotsPerInchY)
            .define_method("manufacturer", &QScreen::manufacturer)
            .define_method("map_between", &QScreen::mapBetween, Arg("a"), Arg("b"), Arg("rect"))
            .define_method("model", &QScreen::model)
            .define_method("name", &QScreen::name)
            .define_method("native_orientation", &QScreen::nativeOrientation)
            .define_method("orientation", &QScreen::orientation)
            .define_method("physical_dots_per_inch", &QScreen::physicalDotsPerInch)
            .define_method("physical_dots_per_inch_x", &QScreen::physicalDotsPerInchX)
            .define_method("physical_dots_per_inch_y", &QScreen::physicalDotsPerInchY)
            .define_method("physical_size", &QScreen::physicalSize)
            .define_method("primary_orientation", &QScreen::primaryOrientation)
            .define_method("refresh_rate", &QScreen::refreshRate)
            .define_method("serial_number", &QScreen::serialNumber)
            .define_method("size", &QScreen::size)
            .define_method("transform_between", &QScreen::transformBetween, Arg("a"), Arg("b"), Arg("target"))
            .define_method("virtual_geometry", &QScreen::virtualGeometry)
            .define_method("virtual_sibling_at", &QScreen::virtualSiblingAt, Arg("point"))
            .define_method("virtual_siblings", &QScreen::virtualSiblings)
            .define_method("virtual_size", &QScreen::virtualSize);
            // Signals
            // .define_method("available_geometry_changed", &QScreen::availableGeometryChanged, Arg("geometry"))
            // .define_method("geometry_changed", &QScreen::geometryChanged, Arg("geometry"))
            // .define_method("logical_dots_per_inch_changed", &QScreen::logicalDotsPerInchChanged, Arg("dpi"))
            // .define_method("orientation_changed", &QScreen::orientationChanged, Arg("orientation"))
            // .define_method("physical_dots_per_inch_changed", &QScreen::physicalDotsPerInchChanged, Arg("dpi"))
            // .define_method("physical_size_changed", &QScreen::physicalSizeChanged, Arg("size"))
            // .define_method("primary_orientation_changed", &QScreen::primaryOrientationChanged, Arg("orientation"))
            // .define_method("refresh_rate_changed", &QScreen::refreshRateChanged, Arg("refresh_rate"))
            // .define_method("virtual_geometry_changed", &QScreen::virtualGeometryChanged, Arg("rect"));
}
