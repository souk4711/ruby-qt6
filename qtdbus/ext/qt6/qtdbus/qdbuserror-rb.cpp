#include "qdbuserror-rb.hpp"
#include <qdbuserror.h>
#include <rice/qenum.hpp>

#include <QDBusMessage>

using namespace Rice;

Rice::Class rb_cQDBusError;

void Init_qdbuserror(Rice::Module rb_mQt6QtDBus)
{
    rb_cQDBusError =
        // RubyQt6::QtDBus::QDBusError
        define_class_under<QDBusError>(rb_mQt6QtDBus, "QDBusError")
            // Constructor
            .define_constructor(Constructor<QDBusError, const QDBusMessage&>(), Arg("message"))
            .define_constructor(Constructor<QDBusError, QDBusError::ErrorType, const QString &>(), Arg("type"), Arg("message"))
            // Public Functions
            .define_method("valid?", &QDBusError::isValid)
            .define_method("message", &QDBusError::message)
            .define_method("name", &QDBusError::name)
            .define_method("type", &QDBusError::type)
            // Static Public Members
            .define_singleton_function("error_string", &QDBusError::errorString, Arg("error"));

    Data_Type<QDBusError::ErrorType> rb_cQDBusErrorErrorType =
        // RubyQt6::QtDBus::QDBusError::ErrorType
        define_qenum_under<QDBusError::ErrorType>(rb_cQDBusError, "ErrorType");
        define_qenum_value_under(rb_cQDBusErrorErrorType, "NoError", QDBusError::ErrorType::NoError);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "Other", QDBusError::ErrorType::Other);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "Failed", QDBusError::ErrorType::Failed);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "NoMemory", QDBusError::ErrorType::NoMemory);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "ServiceUnknown", QDBusError::ErrorType::ServiceUnknown);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "NoReply", QDBusError::ErrorType::NoReply);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "BadAddress", QDBusError::ErrorType::BadAddress);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "NotSupported", QDBusError::ErrorType::NotSupported);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "LimitsExceeded", QDBusError::ErrorType::LimitsExceeded);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "AccessDenied", QDBusError::ErrorType::AccessDenied);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "NoServer", QDBusError::ErrorType::NoServer);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "Timeout", QDBusError::ErrorType::Timeout);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "NoNetwork", QDBusError::ErrorType::NoNetwork);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "AddressInUse", QDBusError::ErrorType::AddressInUse);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "Disconnected", QDBusError::ErrorType::Disconnected);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "InvalidArgs", QDBusError::ErrorType::InvalidArgs);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "UnknownMethod", QDBusError::ErrorType::UnknownMethod);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "TimedOut", QDBusError::ErrorType::TimedOut);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "InvalidSignature", QDBusError::ErrorType::InvalidSignature);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "UnknownInterface", QDBusError::ErrorType::UnknownInterface);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "UnknownObject", QDBusError::ErrorType::UnknownObject);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "UnknownProperty", QDBusError::ErrorType::UnknownProperty);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "PropertyReadOnly", QDBusError::ErrorType::PropertyReadOnly);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "InternalError", QDBusError::ErrorType::InternalError);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "InvalidService", QDBusError::ErrorType::InvalidService);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "InvalidObjectPath", QDBusError::ErrorType::InvalidObjectPath);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "InvalidInterface", QDBusError::ErrorType::InvalidInterface);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "InvalidMember", QDBusError::ErrorType::InvalidMember);
        define_qenum_value_under(rb_cQDBusErrorErrorType, "LastErrorType", QDBusError::ErrorType::LastErrorType);
}
