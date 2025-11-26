#include "qsplashscreen-rb.hpp"
#include <qsplashscreen.h>

#include <QScreen>

using namespace Rice;

Rice::Class rb_cQSplashScreen;

void Init_qsplashscreen(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQSplashScreen =
        // RubyQt6::QtWidgets::QSplashScreen
        define_class_under<QSplashScreen, QWidget>(rb_mQt6QtWidgets, "QSplashScreen")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QSplashScreen::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QSplashScreen, const QPixmap &>(), Arg("pixmap"))
            // Public Functions
            .define_method("finish", &QSplashScreen::finish, Arg("w"))
            .define_method("message", &QSplashScreen::message)
            .define_method("pixmap", &QSplashScreen::pixmap)
            .define_method("repaint", &QSplashScreen::repaint)
            .define_method("set_pixmap", &QSplashScreen::setPixmap, Arg("pixmap"))
            // Public Slots
            .define_method("clear_message", &QSplashScreen::clearMessage)
            .define_method("show_message", &QSplashScreen::showMessage, Arg("message"), Arg("alignment") = static_cast<int>(Qt::AlignLeft), Arg("color") = static_cast<const QColor &>(Qt::black));
            // Signals
            // .define_method("message_changed", &QSplashScreen::messageChanged, Arg("message"));
}
