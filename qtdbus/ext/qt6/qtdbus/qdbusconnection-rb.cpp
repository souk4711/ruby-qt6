#include "qdbusconnection-rb.hpp"
#include <qdbusconnection.h>
#include <rice/qenum.hpp>
#include <rice/qflags.hpp>

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
            .define_method<bool (QDBusConnection::*)(const QDBusMessage &, QObject *, const char *, const char *, int) const>("call_with_callback", &QDBusConnection::callWithCallback, Arg("message"), Arg("receiver"), Arg("return_method"), Arg("error_method"), Arg("timeout") = static_cast<int>(-1))
            .define_method<bool (QDBusConnection::*)(const QDBusMessage &, QObject *, const char *, int) const>("call_with_callback", &QDBusConnection::callWithCallback, Arg("message"), Arg("receiver"), Arg("slot"), Arg("timeout") = static_cast<int>(-1))
            .define_method<bool (QDBusConnection::*)(const QString &, const QString &, const QString &, const QString &, QObject *, const char *)>("connect", &QDBusConnection::connect, Arg("service"), Arg("path"), Arg("interface"), Arg("name"), Arg("receiver"), Arg("slot"))
            .define_method<bool (QDBusConnection::*)(const QString &, const QString &, const QString &, const QString &, const QString &, QObject *, const char *)>("connect", &QDBusConnection::connect, Arg("service"), Arg("path"), Arg("interface"), Arg("name"), Arg("signature"), Arg("receiver"), Arg("slot"))
            .define_method<bool (QDBusConnection::*)(const QString &, const QString &, const QString &, const QString &, const QStringList &, const QString &, QObject *, const char *)>("connect", &QDBusConnection::connect, Arg("service"), Arg("path"), Arg("interface"), Arg("name"), Arg("argument_match"), Arg("signature"), Arg("receiver"), Arg("slot"))
            .define_method("connection_capabilities", &QDBusConnection::connectionCapabilities)
            .define_method<bool (QDBusConnection::*)(const QString &, const QString &, const QString &, const QString &, QObject *, const char *)>("disconnect", &QDBusConnection::disconnect, Arg("service"), Arg("path"), Arg("interface"), Arg("name"), Arg("receiver"), Arg("slot"))
            .define_method<bool (QDBusConnection::*)(const QString &, const QString &, const QString &, const QString &, const QString &, QObject *, const char *)>("disconnect", &QDBusConnection::disconnect, Arg("service"), Arg("path"), Arg("interface"), Arg("name"), Arg("signature"), Arg("receiver"), Arg("slot"))
            .define_method<bool (QDBusConnection::*)(const QString &, const QString &, const QString &, const QString &, const QStringList &, const QString &, QObject *, const char *)>("disconnect", &QDBusConnection::disconnect, Arg("service"), Arg("path"), Arg("interface"), Arg("name"), Arg("argument_match"), Arg("signature"), Arg("receiver"), Arg("slot"))
            .define_method("interface", &QDBusConnection::interface)
            .define_method("internal_pointer", &QDBusConnection::internalPointer)
            .define_method("connected?", &QDBusConnection::isConnected)
            .define_method("last_error", &QDBusConnection::lastError)
            .define_method("name", &QDBusConnection::name)
            .define_method("object_registered_at", &QDBusConnection::objectRegisteredAt, Arg("path"))
            .define_method<bool (QDBusConnection::*)(const QString &, QObject *, QDBusConnection::RegisterOptions)>("register_object", &QDBusConnection::registerObject, Arg("path"), Arg("object"), Arg("options") = static_cast<QDBusConnection::RegisterOptions>(QDBusConnection::RegisterOption::ExportAdaptors))
            .define_method<bool (QDBusConnection::*)(const QString &, const QString &, QObject *, QDBusConnection::RegisterOptions)>("register_object", &QDBusConnection::registerObject, Arg("path"), Arg("interface"), Arg("object"), Arg("options") = static_cast<QDBusConnection::RegisterOptions>(QDBusConnection::RegisterOption::ExportAdaptors))
            .define_method("register_service", &QDBusConnection::registerService, Arg("service_name"))
            .define_method("register_virtual_object", &QDBusConnection::registerVirtualObject, Arg("path"), Arg("object"), Arg("options") = static_cast<QDBusConnection::VirtualObjectRegisterOption>(QDBusConnection::VirtualObjectRegisterOption::SingleNode))
            .define_method("send", &QDBusConnection::send, Arg("message"))
            .define_method("swap", &QDBusConnection::swap, Arg("other"))
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

    Enum<QDBusConnection::BusType> rb_cQDBusConnectionBusType =
        // RubyQt6::QtDBus::QDBusConnection::BusType
        define_qenum_under<QDBusConnection::BusType>("BusType", rb_cQDBusConnection)
            .define_value("SessionBus", QDBusConnection::BusType::SessionBus)
            .define_value("SystemBus", QDBusConnection::BusType::SystemBus)
            .define_value("ActivationBus", QDBusConnection::BusType::ActivationBus);

    Enum<QDBusConnection::RegisterOption> rb_cQDBusConnectionRegisterOption =
        // RubyQt6::QtDBus::QDBusConnection::RegisterOption
        define_qenum_under<QDBusConnection::RegisterOption>("RegisterOption", rb_cQDBusConnection)
            .define_value("ExportAdaptors", QDBusConnection::RegisterOption::ExportAdaptors)
            .define_value("ExportScriptableSlots", QDBusConnection::RegisterOption::ExportScriptableSlots)
            .define_value("ExportScriptableSignals", QDBusConnection::RegisterOption::ExportScriptableSignals)
            .define_value("ExportScriptableProperties", QDBusConnection::RegisterOption::ExportScriptableProperties)
            .define_value("ExportScriptableInvokables", QDBusConnection::RegisterOption::ExportScriptableInvokables)
            .define_value("ExportScriptableContents", QDBusConnection::RegisterOption::ExportScriptableContents)
            .define_value("ExportNonScriptableSlots", QDBusConnection::RegisterOption::ExportNonScriptableSlots)
            .define_value("ExportNonScriptableSignals", QDBusConnection::RegisterOption::ExportNonScriptableSignals)
            .define_value("ExportNonScriptableProperties", QDBusConnection::RegisterOption::ExportNonScriptableProperties)
            .define_value("ExportNonScriptableInvokables", QDBusConnection::RegisterOption::ExportNonScriptableInvokables)
            .define_value("ExportNonScriptableContents", QDBusConnection::RegisterOption::ExportNonScriptableContents)
            .define_value("ExportAllSlots", QDBusConnection::RegisterOption::ExportAllSlots)
            .define_value("ExportAllSignals", QDBusConnection::RegisterOption::ExportAllSignals)
            .define_value("ExportAllProperties", QDBusConnection::RegisterOption::ExportAllProperties)
            .define_value("ExportAllInvokables", QDBusConnection::RegisterOption::ExportAllInvokables)
            .define_value("ExportAllContents", QDBusConnection::RegisterOption::ExportAllContents)
            .define_value("ExportAllSignal", QDBusConnection::RegisterOption::ExportAllSignal)
            .define_value("ExportChildObjects", QDBusConnection::RegisterOption::ExportChildObjects);

    Enum<QDBusConnection::UnregisterMode> rb_cQDBusConnectionUnregisterMode =
        // RubyQt6::QtDBus::QDBusConnection::UnregisterMode
        define_qenum_under<QDBusConnection::UnregisterMode>("UnregisterMode", rb_cQDBusConnection)
            .define_value("UnregisterNode", QDBusConnection::UnregisterMode::UnregisterNode)
            .define_value("UnregisterTree", QDBusConnection::UnregisterMode::UnregisterTree);

    Enum<QDBusConnection::ConnectionCapability> rb_cQDBusConnectionConnectionCapability =
        // RubyQt6::QtDBus::QDBusConnection::ConnectionCapability
        define_qenum_under<QDBusConnection::ConnectionCapability>("ConnectionCapability", rb_cQDBusConnection)
            .define_value("UnixFileDescriptorPassing", QDBusConnection::ConnectionCapability::UnixFileDescriptorPassing);

    Data_Type<QFlags<QDBusConnection::ConnectionCapability>> rb_cQDBusConnectionConnectionCapabilities =
        // RubyQt6::QtDBus::QDBusConnection::ConnectionCapabilities
        define_qflags_under<QDBusConnection::ConnectionCapability>(rb_cQDBusConnection, "ConnectionCapabilities");

    Data_Type<QFlags<QDBusConnection::RegisterOption>> rb_cQDBusConnectionRegisterOptions =
        // RubyQt6::QtDBus::QDBusConnection::RegisterOptions
        define_qflags_under<QDBusConnection::RegisterOption>(rb_cQDBusConnection, "RegisterOptions");
}
