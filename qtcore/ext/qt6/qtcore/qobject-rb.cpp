#include "qobject-rb.hpp"
#include <qobject.h>

#include <QBindable>
#include <QEvent>
#include <QMetaMethod>
#include <QMetaObject>
#include <QThread>
#include <QVariant>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQObject;

int QObject_emit(QObject *sender, const QMetaMethod *signal, const std::vector<QVariant> &args)
{
    Q_ASSERT(signal->isValid());
    Q_ASSERT(signal->methodType() == QMetaMethod::Signal);

    std::vector<void *> arguments(args.size() + 1, nullptr);
    for (size_t i = 0; i < args.size(); ++i)
        arguments[i + 1] = const_cast<void *>(args[i].constData());
    QMetaObject::activate(sender, signal->methodIndex(), arguments.data());

    return -1;
}

void Init_qobject(Module rb_mQt6QtCore)
{
    rb_cQObject =
        // RubyQt6::QtCore::QObject
        define_qlass_under<QObject>(rb_mQt6QtCore, "QObject")
            // RubyQt6-Defined Functions
            .define_method("_qobject_ptr", [](QObject *self) -> uintptr_t { return (uintptr_t)self; })
            .define_singleton_function("_emit", QObject_emit, Arg("sender"), Arg("signal"), Arg("args"))
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QObject * { return qobject_cast<QObject *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QObject::staticMetaObject; })
            .define_singleton_function("_delete_now", [](QObject *object) -> void { delete object; }, Arg("object").takeOwnership())
            .define_singleton_function("_take_ownership_from_ruby", [](QObject *) -> void {}, Arg("object").takeOwnership())
            // Constructor
            .define_constructor(Constructor<QObject, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("bindable_object_name", &QObject::bindableObjectName)
            .define_method<QBindingStorage *(QObject::*)()>("binding_storage", &QObject::bindingStorage)
            .define_method<const QBindingStorage *(QObject::*)() const>("binding_storage", &QObject::bindingStorage)
            .define_method("block_signals", &QObject::blockSignals, Arg("b"))
            .define_method("_children", &QObject::children)
            .define_method("dump_object_info", &QObject::dumpObjectInfo)
            .define_method("dump_object_tree", &QObject::dumpObjectTree)
            .define_method("dynamic_property_names", &QObject::dynamicPropertyNames)
            .define_method<QObject *(QObject::*)(QAnyStringView, Qt::FindChildOptions) const>("_find_child", &QObject::findChild, Arg("name"), Arg("options"))
            .define_method<QList<QObject *> (QObject::*)(QAnyStringView, Qt::FindChildOptions) const>("_find_children", &QObject::findChildren, Arg("name"), Arg("options"))
            .define_method("inherits", &QObject::inherits, Arg("classname"))
            .define_method("install_event_filter", &QObject::installEventFilter, Arg("filter_obj"))
            .define_method("quick_item_type?", &QObject::isQuickItemType)
            .define_method("widget_type?", &QObject::isWidgetType)
            .define_method("window_type?", &QObject::isWindowType)
            .define_method<void (QObject::*)(Qt::TimerId)>("kill_timer", &QObject::killTimer, Arg("id"))
            .define_method<void (QObject::*)(int)>("kill_timer", &QObject::killTimer, Arg("id"))
            .define_method("move_to_thread", &QObject::moveToThread, Arg("thread"))
            .define_method("object_name", &QObject::objectName)
            .define_method("_parent", &QObject::parent)
            .define_method("property", &QObject::property, Arg("name"))
            .define_method("remove_event_filter", &QObject::removeEventFilter, Arg("obj"))
            .define_method<void (QObject::*)(const QString &)>("_set_object_name", &QObject::setObjectName, Arg("name"))
            .define_method("set_parent", &QObject::setParent, Arg("parent"))
            .define_method<bool (QObject::*)(const char *, QVariant &&)>("set_property", &QObject::setProperty, Arg("name"), Arg("value"))
            .define_method("signals_blocked", &QObject::signalsBlocked)
            .define_method<int (QObject::*)(int, Qt::TimerType)>("start_timer", &QObject::startTimer, Arg("interval"), Arg("timer_type") = static_cast<Qt::TimerType>(Qt::CoarseTimer))
            .define_method("thread", &QObject::thread)
            // Public Slots
            .define_method("delete_later", &QObject::deleteLater)
            // Signals
            // .define_method("destroyed", &QObject::destroyed, Arg("obj") = static_cast<QObject *>(nullptr))
            // .define_method("object_name_changed", &QObject::objectNameChanged, Arg("object_name"))
            // Static Public Members
            .define_singleton_function<QMetaObject::Connection (*)(const QObject *, const char *, const QObject *, const char *, Qt::ConnectionType)>("_connect", &QObject::connect, Arg("sender"), Arg("signal"), Arg("receiver"), Arg("member"), Arg("type") = static_cast<Qt::ConnectionType>(Qt::AutoConnection))
            .define_singleton_function<bool (*)(const QObject *, const char *, const QObject *, const char *)>("_disconnect", &QObject::disconnect, Arg("sender"), Arg("signal"), Arg("receiver"), Arg("member"))
            .define_singleton_function<bool (*)(const QMetaObject::Connection &)>("_disconnect", &QObject::disconnect, Arg("conn"))
            .define_singleton_function("tr", &QObject::tr, Arg("source_text"), Arg("disambiguation") = static_cast<const char *>(nullptr), Arg("n") = static_cast<int>(-1));
}
