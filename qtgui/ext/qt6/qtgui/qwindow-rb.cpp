#include "qwindow-rb.hpp"
#include <qwindow.h>

using namespace Rice;

Rice::Class rb_cQWindow;

void Init_qwindow(Rice::Module rb_mQt6QtGui)
{
    rb_cQWindow =
        // RubyQt6::QtGui::QWindow
        define_class_under<QWindow, QObject>(rb_mQt6QtGui, "QWindow")
            // inherits QSurface
            .define_method("_format", &QWindow::format)
            .define_method("_size", &QWindow::size)
            .define_method("_supports_open_gl?", &QWindow::supportsOpenGL)
            .define_method("_surface_class", &QWindow::surfaceClass)
            .define_method("_surface_type", &QWindow::surfaceType)
            .define_method("_set_format", &QWindow::setFormat, Arg("format"))
            .define_method("_set_surface_type", &QWindow::setSurfaceType, Arg("type"))
            // Window functions
            .define_method("_title", &QWindow::title)
            .define_method("_icon", &QWindow::icon)
            .define_method("_active?", &QWindow::isActive)
            .define_method("_content_orientation", &QWindow::contentOrientation)
            .define_method("_flags", &QWindow::flags)
            .define_method("_type", &QWindow::type)
            .define_method("_modality", &QWindow::modality)
            .define_method("_visibility", &QWindow::visibility)
            .define_method("_visible?", &QWindow::isVisible)
            .define_method("_show", &QWindow::show)
            .define_method("_show_full_screen", &QWindow::showFullScreen)
            .define_method("_show_maximized", &QWindow::showMaximized)
            .define_method("_show_minimized", &QWindow::showMinimized)
            .define_method("_show_normal", &QWindow::showNormal)
            .define_method("_hide", &QWindow::hide)
            .define_method("_raise", &QWindow::raise)
            .define_method("_lower", &QWindow::lower)
            .define_method("_close", &QWindow::close)
            .define_method("_alert", &QWindow::alert, Arg("msec"))
            .define_method("_set_title", &QWindow::setTitle, Arg("title"))
            .define_method("_set_icon", &QWindow::setIcon, Arg("icon"))
            .define_method("_report_content_orientation_change", &QWindow::reportContentOrientationChange, Arg("orientation"))
            .define_method("_set_flags", &QWindow::setFlags, Arg("flags"))
            .define_method("_set_flag", &QWindow::setFlag, Arg("flag"), Arg("on") = static_cast<bool>(true))
            .define_method("_set_modality", &QWindow::setModality, Arg("modality"))
            .define_method("_set_visibility", &QWindow::setVisibility, Arg("visibility"))
            .define_method("_set_visible", &QWindow::setVisible, Arg("visible"))
            // Geometry
            .define_method("_position", &QWindow::position)
            .define_method("_x", &QWindow::x)
            .define_method("_y", &QWindow::y)
            .define_method("_size", &QWindow::size)
            .define_method("_width", &QWindow::width)
            .define_method("_height", &QWindow::height)
            .define_method("_geometry", &QWindow::geometry)
            .define_method("_maximum_size", &QWindow::maximumSize)
            .define_method("_maximum_width", &QWindow::maximumWidth)
            .define_method("_maximum_height", &QWindow::maximumHeight)
            .define_method("_minimum_size", &QWindow::minimumSize)
            .define_method("_minimum_width", &QWindow::minimumWidth)
            .define_method("_minimum_height", &QWindow::minimumHeight)
            .define_method("_base_size", &QWindow::baseSize)
            .define_method("_size_increment", &QWindow::sizeIncrement)
            .define_method("_frame_margins", &QWindow::frameMargins)
            .define_method("_frame_geometry", &QWindow::frameGeometry)
            .define_method("_frame_position", &QWindow::framePosition)
            .define_method<void (QWindow::*)(const QPoint &)>("_set_position", &QWindow::setPosition, Arg("pos"))
            .define_method<void (QWindow::*)(int, int)>("_set_position", &QWindow::setPosition, Arg("x"), Arg("y"))
            .define_method("_set_x", &QWindow::setX, Arg("x"))
            .define_method("_set_y", &QWindow::setY, Arg("y"))
            .define_method("_set_width", &QWindow::setWidth, Arg("w"))
            .define_method("_set_height", &QWindow::setHeight, Arg("h"))
            .define_method<void (QWindow::*)(const QSize &)>("_resize", &QWindow::resize, Arg("size"))
            .define_method<void (QWindow::*)(int, int)>("_resize", &QWindow::resize, Arg("w"), Arg("h"))
            .define_method<void (QWindow::*)(const QRect &)>("_set_geometry", &QWindow::setGeometry, Arg("rect"))
            .define_method<void (QWindow::*)(int, int, int, int)>("_set_geometry", &QWindow::setGeometry, Arg("x"), Arg("y"), Arg("w"), Arg("h"))
            .define_method("_set_maximum_width", &QWindow::setMaximumWidth, Arg("w"))
            .define_method("_set_maximum_height", &QWindow::setMaximumHeight, Arg("h"))
            .define_method("_set_minimum_width", &QWindow::setMinimumWidth, Arg("w"))
            .define_method("_set_minimum_height", &QWindow::setMinimumHeight, Arg("h"))
            .define_method("_set_base_size", &QWindow::setBaseSize, Arg("size"))
            .define_method("_set_size_increment", &QWindow::setSizeIncrement, Arg("size"))
            .define_method("_set_frame_position", &QWindow::setFramePosition, Arg("position"))
            // Look and feel
            .define_method("_cursor", &QWindow::cursor)
            .define_method("_opacity", &QWindow::opacity)
            .define_method("_set_cursor", &QWindow::setCursor, Arg("cursor"))
            .define_method("_unset_cursor", &QWindow::unsetCursor)
            .define_method("_set_opacity", &QWindow::setOpacity, Arg("level"));

    Enum<QWindow::Visibility> rb_cQWindowVisibility =
        // RubyQt6::QtGui::QWindow::Visibility
        define_enum_under<QWindow::Visibility>("Visibility", rb_cQWindow)
            .define_value("Hidden", QWindow::Visibility::Hidden)
            .define_value("AutomaticVisibility", QWindow::Visibility::AutomaticVisibility)
            .define_value("Windowed", QWindow::Visibility::Windowed)
            .define_value("Minimized", QWindow::Visibility::Minimized)
            .define_value("Maximized", QWindow::Visibility::Maximized)
            .define_value("FullScreen", QWindow::Visibility::FullScreen);
}
