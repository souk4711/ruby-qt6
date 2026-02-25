#include "qwebenginenotification-rb.hpp"
#include <qwebenginenotification.h>

#include <QImage>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQWebEngineNotification;

void Init_qwebenginenotification(Module rb_mQt6QtWebEngineCore)
{
    rb_cQWebEngineNotification =
        // RubyQt6::QtWebEngineCore::QWebEngineNotification
        define_qlass_under<QWebEngineNotification, QObject>(rb_mQt6QtWebEngineCore, "QWebEngineNotification")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QWebEngineNotification * { return qobject_cast<QWebEngineNotification *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QWebEngineNotification::staticMetaObject; })
            // Public Functions
            .define_method("direction", &QWebEngineNotification::direction)
            .define_method("icon", &QWebEngineNotification::icon)
            .define_method("language", &QWebEngineNotification::language)
            .define_method("matches", &QWebEngineNotification::matches, Arg("other"))
            .define_method("message", &QWebEngineNotification::message)
            .define_method("origin", &QWebEngineNotification::origin)
            .define_method("tag", &QWebEngineNotification::tag)
            .define_method("title", &QWebEngineNotification::title)
            // Public Slots
            .define_method("click", &QWebEngineNotification::click)
            .define_method("close", &QWebEngineNotification::close)
            .define_method("show", &QWebEngineNotification::show);
            // Signals
            // .define_method("closed", &QWebEngineNotification::closed);
}
