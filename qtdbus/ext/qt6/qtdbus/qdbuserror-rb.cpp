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
            .define_method("swap", &QDBusError::swap, Arg("other"))
            .define_method("type", &QDBusError::type)
            // Static Public Members
            .define_singleton_function("error_string", &QDBusError::errorString, Arg("error"));

    Enum<QDBusError::ErrorType> rb_cQDBusErrorErrorType =
        // RubyQt6::QtDBus::QDBusError::ErrorType
        define_qenum_under<QDBusError::ErrorType>("ErrorType", rb_cQDBusError)
            .define_value("NoError", QDBusError::ErrorType::NoError)
            .define_value("Other", QDBusError::ErrorType::Other)
            .define_value("Failed", QDBusError::ErrorType::Failed)
            .define_value("NoMemory", QDBusError::ErrorType::NoMemory)
            .define_value("ServiceUnknown", QDBusError::ErrorType::ServiceUnknown)
            .define_value("NoReply", QDBusError::ErrorType::NoReply)
            .define_value("BadAddress", QDBusError::ErrorType::BadAddress)
            .define_value("NotSupported", QDBusError::ErrorType::NotSupported)
            .define_value("LimitsExceeded", QDBusError::ErrorType::LimitsExceeded)
            .define_value("AccessDenied", QDBusError::ErrorType::AccessDenied)
            .define_value("NoServer", QDBusError::ErrorType::NoServer)
            .define_value("Timeout", QDBusError::ErrorType::Timeout)
            .define_value("NoNetwork", QDBusError::ErrorType::NoNetwork)
            .define_value("AddressInUse", QDBusError::ErrorType::AddressInUse)
            .define_value("Disconnected", QDBusError::ErrorType::Disconnected)
            .define_value("InvalidArgs", QDBusError::ErrorType::InvalidArgs)
            .define_value("UnknownMethod", QDBusError::ErrorType::UnknownMethod)
            .define_value("TimedOut", QDBusError::ErrorType::TimedOut)
            .define_value("InvalidSignature", QDBusError::ErrorType::InvalidSignature)
            .define_value("UnknownInterface", QDBusError::ErrorType::UnknownInterface)
            .define_value("UnknownObject", QDBusError::ErrorType::UnknownObject)
            .define_value("UnknownProperty", QDBusError::ErrorType::UnknownProperty)
            .define_value("PropertyReadOnly", QDBusError::ErrorType::PropertyReadOnly)
            .define_value("InternalError", QDBusError::ErrorType::InternalError)
            .define_value("InvalidService", QDBusError::ErrorType::InvalidService)
            .define_value("InvalidObjectPath", QDBusError::ErrorType::InvalidObjectPath)
            .define_value("InvalidInterface", QDBusError::ErrorType::InvalidInterface)
            .define_value("InvalidMember", QDBusError::ErrorType::InvalidMember)
            .define_value("LastErrorType", QDBusError::ErrorType::LastErrorType);
}
