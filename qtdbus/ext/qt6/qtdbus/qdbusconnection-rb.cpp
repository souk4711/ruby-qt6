#include "qdbusconnection-rb.hpp"
#include <qdbusconnection.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

#include <QDBusConnectionInterface>
#include <QDBusError>
#include <QDBusMessage>
#include <QDBusVirtualObject>

using namespace Rice;

Rice::Class rb_cQDBusConnection;

void Init_qdbusconnection(Rice::Module rb_mQt6QtDBus)
{
    rb_cQDBusConnection =
        // RubyQt6::QtDBus::QDBusConnection
        define_class_under<QDBusConnection>(rb_mQt6QtDBus, "QDBusConnection")
            // Constructor
            .define_constructor(Constructor<QDBusConnection, const QString &>(), Arg("name"))
            // Public Functions
            .define_method("async_call", &QDBusConnection::asyncCall, Arg("message"), Arg("timeout") = static_cast<int>(-1))
            .define_method("base_service", &QDBusConnection::baseService)
            .define_method("call", &QDBusConnection::call, Arg("message"), Arg("mode") = static_cast<QDBus::CallMode>(QDBus::Block), Arg("timeout") = static_cast<int>(-1))
            // .define_method<bool (QDBusConnection::*)(const QDBusMessage &, QObject *, const char *, const char *, int) const>("call_with_callback", &QDBusConnection::callWithCallback, Arg("message"), Arg("receiver"), Arg("return_method"), Arg("error_method"), Arg("timeout") = static_cast<int>(-1))
            // .define_method<bool (QDBusConnection::*)(const QDBusMessage &, QObject *, const char *, int) const>("call_with_callback", &QDBusConnection::callWithCallback, Arg("message"), Arg("receiver"), Arg("slot"), Arg("timeout") = static_cast<int>(-1))
            // .define_method<bool (QDBusConnection::*)(const QString &, const QString &, const QString &, const QString &, QObject *, const char *)>("connect", &QDBusConnection::connect, Arg("service"), Arg("path"), Arg("interface"), Arg("name"), Arg("receiver"), Arg("slot"))
            // .define_method<bool (QDBusConnection::*)(const QString &, const QString &, const QString &, const QString &, const QString &, QObject *, const char *)>("connect", &QDBusConnection::connect, Arg("service"), Arg("path"), Arg("interface"), Arg("name"), Arg("signature"), Arg("receiver"), Arg("slot"))
            // .define_method<bool (QDBusConnection::*)(const QString &, const QString &, const QString &, const QString &, const QStringList &, const QString &, QObject *, const char *)>("connect", &QDBusConnection::connect, Arg("service"), Arg("path"), Arg("interface"), Arg("name"), Arg("argument_match"), Arg("signature"), Arg("receiver"), Arg("slot"))
            .define_method("connection_capabilities", &QDBusConnection::connectionCapabilities)
            // .define_method<bool (QDBusConnection::*)(const QString &, const QString &, const QString &, const QString &, QObject *, const char *)>("disconnect", &QDBusConnection::disconnect, Arg("service"), Arg("path"), Arg("interface"), Arg("name"), Arg("receiver"), Arg("slot"))
            // .define_method<bool (QDBusConnection::*)(const QString &, const QString &, const QString &, const QString &, const QString &, QObject *, const char *)>("disconnect", &QDBusConnection::disconnect, Arg("service"), Arg("path"), Arg("interface"), Arg("name"), Arg("signature"), Arg("receiver"), Arg("slot"))
            // .define_method<bool (QDBusConnection::*)(const QString &, const QString &, const QString &, const QString &, const QStringList &, const QString &, QObject *, const char *)>("disconnect", &QDBusConnection::disconnect, Arg("service"), Arg("path"), Arg("interface"), Arg("name"), Arg("argument_match"), Arg("signature"), Arg("receiver"), Arg("slot"))
            .define_method("interface", &QDBusConnection::interface)
            .define_method("internal_pointer", &QDBusConnection::internalPointer)
            .define_method("connected?", &QDBusConnection::isConnected)
            .define_method("last_error", &QDBusConnection::lastError)
            .define_method("name", &QDBusConnection::name)
            .define_method("object_registered_at", &QDBusConnection::objectRegisteredAt, Arg("path"))
            .define_method<bool (QDBusConnection::*)(const QString &, QObject *, QDBusConnection::RegisterOptions)>("_register_object", &QDBusConnection::registerObject, Arg("path"), Arg("object"), Arg("options") = static_cast<QDBusConnection::RegisterOptions>(QDBusConnection::RegisterOption::ExportAdaptors))
            .define_method<bool (QDBusConnection::*)(const QString &, const QString &, QObject *, QDBusConnection::RegisterOptions)>("_register_object", &QDBusConnection::registerObject, Arg("path"), Arg("interface"), Arg("object"), Arg("options") = static_cast<QDBusConnection::RegisterOptions>(QDBusConnection::RegisterOption::ExportAdaptors))
            .define_method("_register_service", &QDBusConnection::registerService, Arg("service_name"))
            .define_method("register_virtual_object", &QDBusConnection::registerVirtualObject, Arg("path"), Arg("object"), Arg("options") = static_cast<QDBusConnection::VirtualObjectRegisterOption>(QDBusConnection::VirtualObjectRegisterOption::SingleNode))
            .define_method("send", &QDBusConnection::send, Arg("message"))
            .define_method("unregister_object", &QDBusConnection::unregisterObject, Arg("path"), Arg("mode") = static_cast<QDBusConnection::UnregisterMode>(QDBusConnection::UnregisterMode::UnregisterNode))
            .define_method("unregister_service", &QDBusConnection::unregisterService, Arg("service_name"))
            // Static Public Members
            .define_singleton_function<QDBusConnection (*)(QDBusConnection::BusType, const QString &)>("connect_to_bus", &QDBusConnection::connectToBus, Arg("type"), Arg("name"))
            .define_singleton_function<QDBusConnection (*)(const QString &, const QString &)>("connect_to_bus", &QDBusConnection::connectToBus, Arg("address"), Arg("name"))
            .define_singleton_function("connect_to_peer", &QDBusConnection::connectToPeer, Arg("address"), Arg("name"))
            .define_singleton_function("disconnect_from_bus", &QDBusConnection::disconnectFromBus, Arg("name"))
            .define_singleton_function("disconnect_from_peer", &QDBusConnection::disconnectFromPeer, Arg("name"))
            .define_singleton_function("local_machine_id", &QDBusConnection::localMachineId)
            .define_singleton_function("session_bus", &QDBusConnection::sessionBus)
            .define_singleton_function("system_bus", &QDBusConnection::systemBus);

    Data_Type<QDBusConnection::BusType> rb_cQDBusConnectionBusType =
        // RubyQt6::QtDBus::QDBusConnection::BusType
        define_qenum_under<QDBusConnection::BusType>(rb_cQDBusConnection, "BusType");
        define_qenum_value_under(rb_cQDBusConnectionBusType, "SessionBus", QDBusConnection::BusType::SessionBus);
        define_qenum_value_under(rb_cQDBusConnectionBusType, "SystemBus", QDBusConnection::BusType::SystemBus);
        define_qenum_value_under(rb_cQDBusConnectionBusType, "ActivationBus", QDBusConnection::BusType::ActivationBus);

    Data_Type<QDBusConnection::RegisterOption> rb_cQDBusConnectionRegisterOption =
        // RubyQt6::QtDBus::QDBusConnection::RegisterOption
        define_qenum_under<QDBusConnection::RegisterOption>(rb_cQDBusConnection, "RegisterOption");
        define_qenum_value_under(rb_cQDBusConnectionRegisterOption, "ExportAdaptors", QDBusConnection::RegisterOption::ExportAdaptors);
        define_qenum_value_under(rb_cQDBusConnectionRegisterOption, "ExportScriptableSlots", QDBusConnection::RegisterOption::ExportScriptableSlots);
        define_qenum_value_under(rb_cQDBusConnectionRegisterOption, "ExportScriptableSignals", QDBusConnection::RegisterOption::ExportScriptableSignals);
        define_qenum_value_under(rb_cQDBusConnectionRegisterOption, "ExportScriptableProperties", QDBusConnection::RegisterOption::ExportScriptableProperties);
        define_qenum_value_under(rb_cQDBusConnectionRegisterOption, "ExportScriptableInvokables", QDBusConnection::RegisterOption::ExportScriptableInvokables);
        define_qenum_value_under(rb_cQDBusConnectionRegisterOption, "ExportScriptableContents", QDBusConnection::RegisterOption::ExportScriptableContents);
        define_qenum_value_under(rb_cQDBusConnectionRegisterOption, "ExportNonScriptableSlots", QDBusConnection::RegisterOption::ExportNonScriptableSlots);
        define_qenum_value_under(rb_cQDBusConnectionRegisterOption, "ExportNonScriptableSignals", QDBusConnection::RegisterOption::ExportNonScriptableSignals);
        define_qenum_value_under(rb_cQDBusConnectionRegisterOption, "ExportNonScriptableProperties", QDBusConnection::RegisterOption::ExportNonScriptableProperties);
        define_qenum_value_under(rb_cQDBusConnectionRegisterOption, "ExportNonScriptableInvokables", QDBusConnection::RegisterOption::ExportNonScriptableInvokables);
        define_qenum_value_under(rb_cQDBusConnectionRegisterOption, "ExportNonScriptableContents", QDBusConnection::RegisterOption::ExportNonScriptableContents);
        define_qenum_value_under(rb_cQDBusConnectionRegisterOption, "ExportAllSlots", QDBusConnection::RegisterOption::ExportAllSlots);
        define_qenum_value_under(rb_cQDBusConnectionRegisterOption, "ExportAllSignals", QDBusConnection::RegisterOption::ExportAllSignals);
        define_qenum_value_under(rb_cQDBusConnectionRegisterOption, "ExportAllProperties", QDBusConnection::RegisterOption::ExportAllProperties);
        define_qenum_value_under(rb_cQDBusConnectionRegisterOption, "ExportAllInvokables", QDBusConnection::RegisterOption::ExportAllInvokables);
        define_qenum_value_under(rb_cQDBusConnectionRegisterOption, "ExportAllContents", QDBusConnection::RegisterOption::ExportAllContents);
        define_qenum_value_under(rb_cQDBusConnectionRegisterOption, "ExportAllSignal", QDBusConnection::RegisterOption::ExportAllSignal);
        define_qenum_value_under(rb_cQDBusConnectionRegisterOption, "ExportChildObjects", QDBusConnection::RegisterOption::ExportChildObjects);

    Data_Type<QDBusConnection::UnregisterMode> rb_cQDBusConnectionUnregisterMode =
        // RubyQt6::QtDBus::QDBusConnection::UnregisterMode
        define_qenum_under<QDBusConnection::UnregisterMode>(rb_cQDBusConnection, "UnregisterMode");
        define_qenum_value_under(rb_cQDBusConnectionUnregisterMode, "UnregisterNode", QDBusConnection::UnregisterMode::UnregisterNode);
        define_qenum_value_under(rb_cQDBusConnectionUnregisterMode, "UnregisterTree", QDBusConnection::UnregisterMode::UnregisterTree);

    Data_Type<QDBusConnection::ConnectionCapability> rb_cQDBusConnectionConnectionCapability =
        // RubyQt6::QtDBus::QDBusConnection::ConnectionCapability
        define_qenum_under<QDBusConnection::ConnectionCapability>(rb_cQDBusConnection, "ConnectionCapability");
        define_qenum_value_under(rb_cQDBusConnectionConnectionCapability, "UnixFileDescriptorPassing", QDBusConnection::ConnectionCapability::UnixFileDescriptorPassing);

    Data_Type<QFlags<QDBusConnection::ConnectionCapability>> rb_cQDBusConnectionConnectionCapabilities =
        // RubyQt6::QtDBus::QDBusConnection::ConnectionCapabilities
        define_qflags_under<QDBusConnection::ConnectionCapability>(rb_cQDBusConnection, "ConnectionCapabilities");

    Data_Type<QFlags<QDBusConnection::RegisterOption>> rb_cQDBusConnectionRegisterOptions =
        // RubyQt6::QtDBus::QDBusConnection::RegisterOptions
        define_qflags_under<QDBusConnection::RegisterOption>(rb_cQDBusConnection, "RegisterOptions");
}
