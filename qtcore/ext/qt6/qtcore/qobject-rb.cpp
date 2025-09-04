#include "qobject-rb.hpp"
#include <qobject.h>

#include <QBindable>
#include <QEvent>
#include <QMetaMethod>
#include <QMetaObject>
#include <QThread>
#include <QVariant>

using namespace Rice;

Rice::Class rb_cQObject;

void Init_qobject(Rice::Module rb_mQt6QtCore)
{
    rb_cQObject =
        // RubyQt6::QtCore::QObject
        define_class_under<QObject>(rb_mQt6QtCore, "QObject")
            // Rice - Ruby Interface for C++ Extensions
            .define_singleton_function("_take_ownership_from_rubyrice", [](QObject *) -> void {}, Arg("object").takeOwnership())
            // Constructor
            .define_constructor(Constructor<QObject, QObject *>(), Arg("parent") = static_cast<QObject *>(nullptr))
            // Public Functions
            .define_method("bindable_object_name", &QObject::bindableObjectName)
            .define_method<QBindingStorage *(QObject::*)()>("binding_storage", &QObject::bindingStorage)
            .define_method<const QBindingStorage *(QObject::*)() const>("binding_storage", &QObject::bindingStorage)
            .define_method("block_signals", &QObject::blockSignals, Arg("b"))
            .define_method("children", &QObject::children)
            .define_method<QMetaObject::Connection (QObject::*)(const QObject *, const char *, const char *, Qt::ConnectionType) const>("connect", &QObject::connect, Arg("sender"), Arg("signal"), Arg("member"), Arg("type") = static_cast<Qt::ConnectionType>(Qt::AutoConnection))
            .define_method<bool (QObject::*)(const QObject *, const char *) const>("disconnect", &QObject::disconnect, Arg("receiver"), Arg("member") = static_cast<const char *>(nullptr))
            .define_method<bool (QObject::*)(const char *, const QObject *, const char *) const>("disconnect", &QObject::disconnect, Arg("signal") = static_cast<const char *>(nullptr), Arg("receiver") = static_cast<const QObject *>(nullptr), Arg("member") = static_cast<const char *>(nullptr))
            .define_method("dump_object_info", &QObject::dumpObjectInfo)
            .define_method("dump_object_tree", &QObject::dumpObjectTree)
            .define_method("dynamic_property_names", &QObject::dynamicPropertyNames)
            .define_method("event", &QObject::event, Arg("event"))
            .define_method("event_filter", &QObject::eventFilter, Arg("watched"), Arg("event"))
            .define_method("inherits", &QObject::inherits, Arg("classname"))
            .define_method("install_event_filter", &QObject::installEventFilter, Arg("filter_obj"))
            .define_method("quick_item_type?", &QObject::isQuickItemType)
            .define_method("widget_type?", &QObject::isWidgetType)
            .define_method("window_type?", &QObject::isWindowType)
            .define_method<void (QObject::*)(Qt::TimerId)>("kill_timer", &QObject::killTimer, Arg("id"))
            .define_method<void (QObject::*)(int)>("kill_timer", &QObject::killTimer, Arg("id"))
            .define_method("move_to_thread", &QObject::moveToThread, Arg("thread"), Arg(""))
            .define_method("object_name", &QObject::objectName)
            .define_method("parent", &QObject::parent)
            .define_method("property", &QObject::property, Arg("name"))
            .define_method("remove_event_filter", &QObject::removeEventFilter, Arg("obj"))
            .define_method<void (QObject::*)(const QString &)>("set_object_name", &QObject::setObjectName, Arg("name"))
            .define_method<void (QObject::*)(QAnyStringView)>("set_object_name", &QObject::setObjectName, Arg("name"))
            .define_method("_set_parent", &QObject::setParent, Arg("parent"))
            .define_method<bool (QObject::*)(const char *, QVariant &&)>("set_property", &QObject::setProperty, Arg("name"), Arg("value"))
            .define_method<bool (QObject::*)(const char *, const QVariant &)>("set_property", &QObject::setProperty, Arg("name"), Arg("value"))
            .define_method("signals_blocked", &QObject::signalsBlocked)
            .define_method<int (QObject::*)(int, Qt::TimerType)>("start_timer", &QObject::startTimer, Arg("interval"), Arg("timer_type") = static_cast<Qt::TimerType>(Qt::CoarseTimer))
            .define_method<int (QObject::*)(std::chrono::nanoseconds, Qt::TimerType)>("start_timer", &QObject::startTimer, Arg("time"), Arg("timer_type") = static_cast<Qt::TimerType>(Qt::CoarseTimer))
            .define_method("thread", &QObject::thread)
            // Public Slots
            .define_method("delete_later", &QObject::deleteLater)
            // Signals
            .define_method("destroyed", &QObject::destroyed, Arg("") = static_cast<QObject *>(nullptr))
            .define_method("object_name_changed", &QObject::objectNameChanged, Arg("object_name"), Arg(""))
            // Static Public Members
            .define_singleton_function<QMetaObject::Connection (*)(const QObject *, const QMetaMethod &, const QObject *, const QMetaMethod &, Qt::ConnectionType)>("connect", &QObject::connect, Arg("sender"), Arg("signal"), Arg("receiver"), Arg("method"), Arg("type") = static_cast<Qt::ConnectionType>(Qt::AutoConnection))
            .define_singleton_function<QMetaObject::Connection (*)(const QObject *, const char *, const QObject *, const char *, Qt::ConnectionType)>("connect", &QObject::connect, Arg("sender"), Arg("signal"), Arg("receiver"), Arg("member"), Arg("") = static_cast<Qt::ConnectionType>(Qt::AutoConnection))
            .define_singleton_function<bool (*)(const QMetaObject::Connection &)>("disconnect", &QObject::disconnect, Arg(""))
            .define_singleton_function<bool (*)(const QObject *, const QMetaMethod &, const QObject *, const QMetaMethod &)>("disconnect", &QObject::disconnect, Arg("sender"), Arg("signal"), Arg("receiver"), Arg("member"))
            .define_singleton_function<bool (*)(const QObject *, const char *, const QObject *, const char *)>("disconnect", &QObject::disconnect, Arg("sender"), Arg("signal"), Arg("receiver"), Arg("member"));
}
