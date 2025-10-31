#include "qdbusservicewatcher-rb.hpp"
#include <qdbusservicewatcher.h>
#include <rice/qenum.hpp>
#include <rice/qflags.hpp>

#include <QBindable>
#include <QDBusConnection>

using namespace Rice;

Rice::Class rb_cQDBusServiceWatcher;

void Init_qdbusservicewatcher(Rice::Module rb_mQt6QtDBus)
{
    rb_cQDBusServiceWatcher =
        // RubyQt6::QtDBus::QDBusServiceWatcher
        define_class_under<QDBusServiceWatcher, QObject>(rb_mQt6QtDBus, "QDBusServiceWatcher")
            // RubyQt6-Defined Functions
            .define_method("add_watched_service", [](QDBusServiceWatcher *self, const char *new_service) -> void { return self->addWatchedService(new_service); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QDBusServiceWatcher::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QDBusServiceWatcher, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("add_watched_service", &QDBusServiceWatcher::addWatchedService, Arg("new_service"))
            .define_method("bindable_watch_mode", &QDBusServiceWatcher::bindableWatchMode)
            .define_method("bindable_watched_services", &QDBusServiceWatcher::bindableWatchedServices)
            .define_method("connection", &QDBusServiceWatcher::connection)
            .define_method("remove_watched_service", &QDBusServiceWatcher::removeWatchedService, Arg("service"))
            .define_method("set_connection", &QDBusServiceWatcher::setConnection, Arg("connection"))
            .define_method("set_watch_mode", &QDBusServiceWatcher::setWatchMode, Arg("mode"))
            .define_method("set_watched_services", &QDBusServiceWatcher::setWatchedServices, Arg("services"))
            .define_method("watch_mode", &QDBusServiceWatcher::watchMode)
            .define_method("watched_services", &QDBusServiceWatcher::watchedServices)
            // Signals
            .define_method("service_owner_changed", &QDBusServiceWatcher::serviceOwnerChanged, Arg("service"), Arg("old_owner"), Arg("new_owner"))
            .define_method("service_registered", &QDBusServiceWatcher::serviceRegistered, Arg("service"))
            .define_method("service_unregistered", &QDBusServiceWatcher::serviceUnregistered, Arg("service"));

    Data_Type<QDBusServiceWatcher::WatchModeFlag> rb_cQDBusServiceWatcherWatchModeFlag =
        // RubyQt6::QtDBus::QDBusServiceWatcher::WatchModeFlag
        define_qenum_under<QDBusServiceWatcher::WatchModeFlag>(rb_cQDBusServiceWatcher, "WatchModeFlag");
        define_qenum_value_under(rb_cQDBusServiceWatcherWatchModeFlag, "WatchForRegistration", QDBusServiceWatcher::WatchModeFlag::WatchForRegistration);
        define_qenum_value_under(rb_cQDBusServiceWatcherWatchModeFlag, "WatchForUnregistration", QDBusServiceWatcher::WatchModeFlag::WatchForUnregistration);
        define_qenum_value_under(rb_cQDBusServiceWatcherWatchModeFlag, "WatchForOwnerChange", QDBusServiceWatcher::WatchModeFlag::WatchForOwnerChange);

    Data_Type<QFlags<QDBusServiceWatcher::WatchModeFlag>> rb_cQDBusServiceWatcherWatchMode =
        // RubyQt6::QtDBus::QDBusServiceWatcher::WatchMode
        define_qflags_under<QDBusServiceWatcher::WatchModeFlag>(rb_cQDBusServiceWatcher, "WatchMode");
}
