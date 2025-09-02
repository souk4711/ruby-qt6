#include "qcoreapplication-rb.hpp"
#include <qcoreapplication.h>

#include <QAbstractNativeEventFilter>

using namespace Rice;

Rice::Class rb_cQCoreApplication;

void Init_qcoreapplication(Rice::Module rb_mQt6QtCore)
{
    rb_cQCoreApplication =
        // RubyQt6::QtCore::QCoreApplication
        define_class_under<QCoreApplication, QObject>(rb_mQt6QtCore, "QCoreApplication")
            .define_singleton_function("_application_name", &QCoreApplication::applicationName)
            .define_singleton_function("_application_version", &QCoreApplication::applicationVersion)
            .define_singleton_function("_application_dir_path", &QCoreApplication::applicationDirPath)
            .define_singleton_function("_application_file_path", &QCoreApplication::applicationFilePath)
            .define_singleton_function("_application_pid", &QCoreApplication::applicationPid)
            .define_singleton_function("_organization_domain", &QCoreApplication::organizationDomain)
            .define_singleton_function("_organization_name", &QCoreApplication::organizationName)
            .define_singleton_function("_quit_lock_enabled?", &QCoreApplication::isQuitLockEnabled)
            .define_singleton_function("_set_application_name", &QCoreApplication::setApplicationName, Arg("name"))
            .define_singleton_function("_set_application_version", &QCoreApplication::setApplicationVersion, Arg("version"))
            .define_singleton_function("_set_organization_domain", &QCoreApplication::setOrganizationDomain, Arg("domain"))
            .define_singleton_function("_set_organization_name", &QCoreApplication::setOrganizationName, Arg("name"))
            .define_singleton_function("_set_quit_lock_enabled", &QCoreApplication::setQuitLockEnabled, Arg("enabled"))
            .define_singleton_function("_exit", &QCoreApplication::exit, Arg("retcode") = static_cast<int>(0))
            .define_singleton_function("_quit", &QCoreApplication::quit)
            .define_singleton_function("_exec", &QCoreApplication::exec)
            .define_method("_install_native_event_filter", &QCoreApplication::installNativeEventFilter, Arg("filter"))
            .define_method("_remove_native_event_filter", &QCoreApplication::removeNativeEventFilter, Arg("filter"))
            .define_method("_notify", &QCoreApplication::notify, Arg("receiver"), Arg("event"));
}
