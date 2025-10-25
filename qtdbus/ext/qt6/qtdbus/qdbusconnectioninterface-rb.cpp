#include "qdbusconnectioninterface-rb.hpp"
#include <qdbusconnectioninterface.h>
#include <rice/qenum.hpp>

using namespace Rice;

Rice::Class rb_cQDBusConnectionInterface;

void Init_qdbusconnectioninterface(Rice::Module rb_mQt6QtDBus)
{
    rb_cQDBusConnectionInterface =
        // RubyQt6::QtDBus::QDBusConnectionInterface
        define_class_under<QDBusConnectionInterface, QDBusAbstractInterface>(rb_mQt6QtDBus, "QDBusConnectionInterface")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QDBusConnectionInterface::staticMetaObject; })
            // Public Functions
            .define_method("activatable_service_names", &QDBusConnectionInterface::activatableServiceNames)
            .define_method("service_registered?", &QDBusConnectionInterface::isServiceRegistered, Arg("service_name"))
            .define_method("register_service", &QDBusConnectionInterface::registerService, Arg("service_name"), Arg("qoption") = static_cast<QDBusConnectionInterface::ServiceQueueOptions>(QDBusConnectionInterface::ServiceQueueOptions::DontQueueService), Arg("roption") = static_cast<QDBusConnectionInterface::ServiceReplacementOptions>(QDBusConnectionInterface::ServiceReplacementOptions::DontAllowReplacement))
            .define_method("registered_service_names", &QDBusConnectionInterface::registeredServiceNames)
            .define_method("service_owner", &QDBusConnectionInterface::serviceOwner, Arg("name"))
            .define_method("service_pid", &QDBusConnectionInterface::servicePid, Arg("service_name"))
            .define_method("service_uid", &QDBusConnectionInterface::serviceUid, Arg("service_name"))
            .define_method("start_service", &QDBusConnectionInterface::startService, Arg("name"))
            .define_method("unregister_service", &QDBusConnectionInterface::unregisterService, Arg("service_name"))
            // Signals
            .define_method("call_with_callback_failed", &QDBusConnectionInterface::callWithCallbackFailed, Arg("error"), Arg("call"))
            .define_method("service_registered", &QDBusConnectionInterface::serviceRegistered, Arg("service"))
            .define_method("service_unregistered", &QDBusConnectionInterface::serviceUnregistered, Arg("service"));

    Enum<QDBusConnectionInterface::ServiceQueueOptions> rb_cQDBusConnectionInterfaceServiceQueueOptions =
        // RubyQt6::QtDBus::QDBusConnectionInterface::ServiceQueueOptions
        define_qenum_under<QDBusConnectionInterface::ServiceQueueOptions>("ServiceQueueOptions", rb_cQDBusConnectionInterface)
            .define_value("DontQueueService", QDBusConnectionInterface::ServiceQueueOptions::DontQueueService)
            .define_value("QueueService", QDBusConnectionInterface::ServiceQueueOptions::QueueService)
            .define_value("ReplaceExistingService", QDBusConnectionInterface::ServiceQueueOptions::ReplaceExistingService);

    Enum<QDBusConnectionInterface::ServiceReplacementOptions> rb_cQDBusConnectionInterfaceServiceReplacementOptions =
        // RubyQt6::QtDBus::QDBusConnectionInterface::ServiceReplacementOptions
        define_qenum_under<QDBusConnectionInterface::ServiceReplacementOptions>("ServiceReplacementOptions", rb_cQDBusConnectionInterface)
            .define_value("DontAllowReplacement", QDBusConnectionInterface::ServiceReplacementOptions::DontAllowReplacement)
            .define_value("AllowReplacement", QDBusConnectionInterface::ServiceReplacementOptions::AllowReplacement);

    Enum<QDBusConnectionInterface::RegisterServiceReply> rb_cQDBusConnectionInterfaceRegisterServiceReply =
        // RubyQt6::QtDBus::QDBusConnectionInterface::RegisterServiceReply
        define_qenum_under<QDBusConnectionInterface::RegisterServiceReply>("RegisterServiceReply", rb_cQDBusConnectionInterface)
            .define_value("ServiceNotRegistered", QDBusConnectionInterface::RegisterServiceReply::ServiceNotRegistered)
            .define_value("ServiceRegistered", QDBusConnectionInterface::RegisterServiceReply::ServiceRegistered)
            .define_value("ServiceQueued", QDBusConnectionInterface::RegisterServiceReply::ServiceQueued);
}
