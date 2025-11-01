#include "qdbusmessage-rb.hpp"
#include <qdbusmessage.h>
#include <rice/qenum.hpp>

using namespace Rice;

Rice::Class rb_cQDBusMessage;

void Init_qdbusmessage(Rice::Module rb_mQt6QtDBus)
{
    rb_cQDBusMessage =
        // RubyQt6::QtDBus::QDBusMessage
        define_class_under<QDBusMessage>(rb_mQt6QtDBus, "QDBusMessage")
            // Constructor
            .define_constructor(Constructor<QDBusMessage>())
            // Public Functions
            .define_method("arguments", &QDBusMessage::arguments)
            .define_method("auto_start_service", &QDBusMessage::autoStartService)
            .define_method<QDBusMessage (QDBusMessage::*)(QDBusError::ErrorType, const QString &) const>("create_error_reply", &QDBusMessage::createErrorReply, Arg("type"), Arg("msg"))
            .define_method<QDBusMessage (QDBusMessage::*)(const QDBusError &) const>("create_error_reply", &QDBusMessage::createErrorReply, Arg("err"))
            .define_method<QDBusMessage (QDBusMessage::*)(const QString &, const QString &) const>("create_error_reply", &QDBusMessage::createErrorReply, Arg("name"), Arg("msg"))
            .define_method<QDBusMessage (QDBusMessage::*)(const QList<QVariant> &) const>("create_reply", &QDBusMessage::createReply, Arg("arguments") = static_cast<const QList<QVariant> &>(QList<QVariant>()))
            .define_method<QDBusMessage (QDBusMessage::*)(const QVariant &) const>("create_reply", &QDBusMessage::createReply, Arg("argument"))
            .define_method("error_message", &QDBusMessage::errorMessage)
            .define_method("error_name", &QDBusMessage::errorName)
            .define_method("interface", &QDBusMessage::interface)
            .define_method("delayed_reply?", &QDBusMessage::isDelayedReply)
            .define_method("interactive_authorization_allowed?", &QDBusMessage::isInteractiveAuthorizationAllowed)
            .define_method("reply_required?", &QDBusMessage::isReplyRequired)
            .define_method("member", &QDBusMessage::member)
            .define_method("path", &QDBusMessage::path)
            .define_method("service", &QDBusMessage::service)
            .define_method("_set_arguments", &QDBusMessage::setArguments, Arg("arguments"))
            .define_method("set_auto_start_service", &QDBusMessage::setAutoStartService, Arg("enable"))
            .define_method("set_delayed_reply", &QDBusMessage::setDelayedReply, Arg("enable"))
            .define_method("set_interactive_authorization_allowed", &QDBusMessage::setInteractiveAuthorizationAllowed, Arg("enable"))
            .define_method("signature", &QDBusMessage::signature)
            .define_method("type", &QDBusMessage::type)
            // Static Public Members
            .define_singleton_function<QDBusMessage (*)(QDBusError::ErrorType, const QString &)>("create_error", &QDBusMessage::createError, Arg("type"), Arg("msg"))
            .define_singleton_function<QDBusMessage (*)(const QDBusError &)>("create_error", &QDBusMessage::createError, Arg("err"))
            .define_singleton_function<QDBusMessage (*)(const QString &, const QString &)>("create_error", &QDBusMessage::createError, Arg("name"), Arg("msg"))
            .define_singleton_function("_create_method_call", &QDBusMessage::createMethodCall, Arg("destination"), Arg("path"), Arg("interface"), Arg("method"))
            .define_singleton_function("_create_signal", &QDBusMessage::createSignal, Arg("path"), Arg("interface"), Arg("name"))
            .define_singleton_function("_create_targeted_signal", &QDBusMessage::createTargetedSignal, Arg("service"), Arg("path"), Arg("interface"), Arg("name"));

    Data_Type<QDBusMessage::MessageType> rb_cQDBusMessageMessageType =
        // RubyQt6::QtDBus::QDBusMessage::MessageType
        define_qenum_under<QDBusMessage::MessageType>(rb_cQDBusMessage, "MessageType");
        define_qenum_value_under(rb_cQDBusMessageMessageType, "InvalidMessage", QDBusMessage::MessageType::InvalidMessage);
        define_qenum_value_under(rb_cQDBusMessageMessageType, "MethodCallMessage", QDBusMessage::MessageType::MethodCallMessage);
        define_qenum_value_under(rb_cQDBusMessageMessageType, "ReplyMessage", QDBusMessage::MessageType::ReplyMessage);
        define_qenum_value_under(rb_cQDBusMessageMessageType, "ErrorMessage", QDBusMessage::MessageType::ErrorMessage);
        define_qenum_value_under(rb_cQDBusMessageMessageType, "SignalMessage", QDBusMessage::MessageType::SignalMessage);
}
