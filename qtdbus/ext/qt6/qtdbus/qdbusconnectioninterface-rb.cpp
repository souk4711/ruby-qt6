#include "qdbusconnectioninterface-rb.hpp"
#include <qdbusconnectioninterface.h>
#include <rice/qt6/qenum.hpp>

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

    Data_Type<QDBusConnectionInterface::ServiceQueueOptions> rb_cQDBusConnectionInterfaceServiceQueueOptions =
        // RubyQt6::QtDBus::QDBusConnectionInterface::ServiceQueueOptions
        define_qenum_under<QDBusConnectionInterface::ServiceQueueOptions>(rb_cQDBusConnectionInterface, "ServiceQueueOptions");
        define_qenum_value_under(rb_cQDBusConnectionInterfaceServiceQueueOptions, "DontQueueService", QDBusConnectionInterface::ServiceQueueOptions::DontQueueService);
        define_qenum_value_under(rb_cQDBusConnectionInterfaceServiceQueueOptions, "QueueService", QDBusConnectionInterface::ServiceQueueOptions::QueueService);
        define_qenum_value_under(rb_cQDBusConnectionInterfaceServiceQueueOptions, "ReplaceExistingService", QDBusConnectionInterface::ServiceQueueOptions::ReplaceExistingService);

    Data_Type<QDBusConnectionInterface::ServiceReplacementOptions> rb_cQDBusConnectionInterfaceServiceReplacementOptions =
        // RubyQt6::QtDBus::QDBusConnectionInterface::ServiceReplacementOptions
        define_qenum_under<QDBusConnectionInterface::ServiceReplacementOptions>(rb_cQDBusConnectionInterface, "ServiceReplacementOptions");
        define_qenum_value_under(rb_cQDBusConnectionInterfaceServiceReplacementOptions, "DontAllowReplacement", QDBusConnectionInterface::ServiceReplacementOptions::DontAllowReplacement);
        define_qenum_value_under(rb_cQDBusConnectionInterfaceServiceReplacementOptions, "AllowReplacement", QDBusConnectionInterface::ServiceReplacementOptions::AllowReplacement);

    Data_Type<QDBusConnectionInterface::RegisterServiceReply> rb_cQDBusConnectionInterfaceRegisterServiceReply =
        // RubyQt6::QtDBus::QDBusConnectionInterface::RegisterServiceReply
        define_qenum_under<QDBusConnectionInterface::RegisterServiceReply>(rb_cQDBusConnectionInterface, "RegisterServiceReply");
        define_qenum_value_under(rb_cQDBusConnectionInterfaceRegisterServiceReply, "ServiceNotRegistered", QDBusConnectionInterface::RegisterServiceReply::ServiceNotRegistered);
        define_qenum_value_under(rb_cQDBusConnectionInterfaceRegisterServiceReply, "ServiceRegistered", QDBusConnectionInterface::RegisterServiceReply::ServiceRegistered);
        define_qenum_value_under(rb_cQDBusConnectionInterfaceRegisterServiceReply, "ServiceQueued", QDBusConnectionInterface::RegisterServiceReply::ServiceQueued);
}
