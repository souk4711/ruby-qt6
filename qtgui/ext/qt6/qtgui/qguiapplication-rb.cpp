#include "qguiapplication-rb.hpp"
#include <qguiapplication.h>

#include <QIcon>
#include <QScreen>

using namespace Rice;

Rice::Class rb_cQGuiApplication;

void Init_qguiapplication(Rice::Module rb_mQt6QtGui)
{
    rb_cQGuiApplication =
        // RubyQt6::QtGui::QGuiApplication
        define_class_under<QGuiApplication, QCoreApplication>(rb_mQt6QtGui, "QGuiApplication")
            .define_constructor(Constructor<QGuiApplication, int &, char **>(), Arg("argc") = static_cast<int>(0), Arg("argv") = static_cast<char **>(nullptr))
            .define_singleton_function("_application_display_name", &QGuiApplication::applicationDisplayName)
            .define_singleton_function("_desktop_file_name", &QGuiApplication::desktopFileName)
            .define_singleton_function("_layout_direction", &QGuiApplication::layoutDirection)
            .define_singleton_function("_platform_name", &QGuiApplication::platformName)
            .define_singleton_function("_primary_screen", &QGuiApplication::primaryScreen)
            .define_singleton_function("_quit_on_last_window_closed?", &QGuiApplication::quitOnLastWindowClosed)
            .define_singleton_function("_window_icon", &QGuiApplication::windowIcon)
            .define_singleton_function("_set_application_display_name", &QGuiApplication::setApplicationDisplayName, Arg("name"))
            .define_singleton_function("_set_desktop_file_name", &QGuiApplication::setDesktopFileName, Arg("name"))
            .define_singleton_function("_set_layout_direction", &QGuiApplication::setLayoutDirection, Arg("direction"))
            .define_singleton_function("_set_quit_on_last_window_closed", &QGuiApplication::setQuitOnLastWindowClosed, Arg("quit"))
            .define_singleton_function("_set_window_icon", &QGuiApplication::setWindowIcon, Arg("icon"))
            .define_singleton_function("_exec", &QGuiApplication::exec)
            .define_method("_device_pixel_ratio", &QGuiApplication::devicePixelRatio)
            .define_method("_saving_session?", &QGuiApplication::isSavingSession)
            .define_method("_session_restored?", &QGuiApplication::isSessionRestored)
            .define_method("_session_id", &QGuiApplication::sessionId)
            .define_method("_session_key", &QGuiApplication::sessionKey);
}
