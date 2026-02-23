#include "qwebenginecertificateerror-rb.hpp"
#include <qwebenginecertificateerror.h>
#include <rice/qt6/qenum.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQWebEngineCertificateError;

void Init_qwebenginecertificateerror(Module rb_mQt6QtWebEngineCore)
{
    rb_cQWebEngineCertificateError =
        // RubyQt6::QtWebEngineCore::QWebEngineCertificateError
        define_qlass_under<QWebEngineCertificateError>(rb_mQt6QtWebEngineCore, "QWebEngineCertificateError")
            // Public Functions
            .define_method("accept_certificate", &QWebEngineCertificateError::acceptCertificate)
            .define_method("certificate_chain", &QWebEngineCertificateError::certificateChain)
            .define_method("defer", &QWebEngineCertificateError::defer)
            .define_method("description", &QWebEngineCertificateError::description)
            .define_method("main_frame?", &QWebEngineCertificateError::isMainFrame)
            .define_method("overridable?", &QWebEngineCertificateError::isOverridable)
            .define_method("reject_certificate", &QWebEngineCertificateError::rejectCertificate)
            .define_method("type", &QWebEngineCertificateError::type)
            .define_method("url", &QWebEngineCertificateError::url);

    Data_Type<QWebEngineCertificateError::Type> rb_cQWebEngineCertificateErrorType =
        // RubyQt6::QtWebEngineCore::QWebEngineCertificateError::Type
        define_qenum_under<QWebEngineCertificateError::Type>(rb_cQWebEngineCertificateError, "Type");
        define_qenum_value_under(rb_cQWebEngineCertificateErrorType, "Ok", QWebEngineCertificateError::Type::Ok);
        define_qenum_value_under(rb_cQWebEngineCertificateErrorType, "SslPinnedKeyNotInCertificateChain", QWebEngineCertificateError::Type::SslPinnedKeyNotInCertificateChain);
        define_qenum_value_under(rb_cQWebEngineCertificateErrorType, "CertificateCommonNameInvalid", QWebEngineCertificateError::Type::CertificateCommonNameInvalid);
        define_qenum_value_under(rb_cQWebEngineCertificateErrorType, "CertificateDateInvalid", QWebEngineCertificateError::Type::CertificateDateInvalid);
        define_qenum_value_under(rb_cQWebEngineCertificateErrorType, "CertificateAuthorityInvalid", QWebEngineCertificateError::Type::CertificateAuthorityInvalid);
        define_qenum_value_under(rb_cQWebEngineCertificateErrorType, "CertificateContainsErrors", QWebEngineCertificateError::Type::CertificateContainsErrors);
        define_qenum_value_under(rb_cQWebEngineCertificateErrorType, "CertificateNoRevocationMechanism", QWebEngineCertificateError::Type::CertificateNoRevocationMechanism);
        define_qenum_value_under(rb_cQWebEngineCertificateErrorType, "CertificateUnableToCheckRevocation", QWebEngineCertificateError::Type::CertificateUnableToCheckRevocation);
        define_qenum_value_under(rb_cQWebEngineCertificateErrorType, "CertificateRevoked", QWebEngineCertificateError::Type::CertificateRevoked);
        define_qenum_value_under(rb_cQWebEngineCertificateErrorType, "CertificateInvalid", QWebEngineCertificateError::Type::CertificateInvalid);
        define_qenum_value_under(rb_cQWebEngineCertificateErrorType, "CertificateWeakSignatureAlgorithm", QWebEngineCertificateError::Type::CertificateWeakSignatureAlgorithm);
        define_qenum_value_under(rb_cQWebEngineCertificateErrorType, "CertificateNonUniqueName", QWebEngineCertificateError::Type::CertificateNonUniqueName);
        define_qenum_value_under(rb_cQWebEngineCertificateErrorType, "CertificateWeakKey", QWebEngineCertificateError::Type::CertificateWeakKey);
        define_qenum_value_under(rb_cQWebEngineCertificateErrorType, "CertificateNameConstraintViolation", QWebEngineCertificateError::Type::CertificateNameConstraintViolation);
        define_qenum_value_under(rb_cQWebEngineCertificateErrorType, "CertificateValidityTooLong", QWebEngineCertificateError::Type::CertificateValidityTooLong);
        define_qenum_value_under(rb_cQWebEngineCertificateErrorType, "CertificateTransparencyRequired", QWebEngineCertificateError::Type::CertificateTransparencyRequired);
        define_qenum_value_under(rb_cQWebEngineCertificateErrorType, "CertificateSymantecLegacy", QWebEngineCertificateError::Type::CertificateSymantecLegacy);
        define_qenum_value_under(rb_cQWebEngineCertificateErrorType, "CertificateKnownInterceptionBlocked", QWebEngineCertificateError::Type::CertificateKnownInterceptionBlocked);
        define_qenum_value_under(rb_cQWebEngineCertificateErrorType, "SslObsoleteVersion", QWebEngineCertificateError::Type::SslObsoleteVersion);
}
