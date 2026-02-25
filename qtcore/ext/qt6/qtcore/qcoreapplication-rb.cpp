#include "qcoreapplication-rb.hpp"
#include <qcoreapplication.h>

#include <QAbstractNativeEventFilter>
#include <QPermission>
#include <QTranslator>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQCoreApplication;

QCoreApplication* QCoreApplication_new(const QList<QByteArray>& strlist)
{
    // The data referred to by argc and argv must stay valid for the
    // entire lifetime of the QCoreApplication object. In addition,
    // argc must be greater than zero and argv must contain at least
    // one valid character string.
    static int argc = strlist.size();
    static char** argv = new char*[argc];
    for (int i = 0; i < argc; ++i) {
        const QByteArray &bytes = strlist[i];
        argv[i] = strdup(bytes.constData());
    }
    return new QCoreApplication(argc, argv);
}

void Init_qcoreapplication(Module rb_mQt6QtCore)
{
    rb_cQCoreApplication =
        // RubyQt6::QtCore::QCoreApplication
        define_qlass_under<QCoreApplication, QObject>(rb_mQt6QtCore, "QCoreApplication")
            // RubyQt6-Defined Functions
            .define_singleton_function("application_pid", []() -> qint64 { return QCoreApplication::applicationPid(); })
            .define_singleton_function("_new", QCoreApplication_new, Arg("argv"), Return().takeOwnership())
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QCoreApplication::staticMetaObject; })
            // Public Functions
            .define_method("check_permission", &QCoreApplication::checkPermission, Arg("permission"))
            .define_method("install_native_event_filter", &QCoreApplication::installNativeEventFilter, Arg("filter_obj"))
            .define_method("notify", &QCoreApplication::notify, Arg("receiver"), Arg("event"))
            .define_method("remove_native_event_filter", &QCoreApplication::removeNativeEventFilter, Arg("filter_obj"))
            // Public Slots
            .define_singleton_function("exit", &QCoreApplication::exit, Arg("retcode") = static_cast<int>(0))
            .define_singleton_function("quit", &QCoreApplication::quit)
            // Signals
            // .define_method("about_to_quit", &QCoreApplication::aboutToQuit)
            // .define_method("application_name_changed", &QCoreApplication::applicationNameChanged)
            // .define_method("application_version_changed", &QCoreApplication::applicationVersionChanged)
            // .define_method("organization_domain_changed", &QCoreApplication::organizationDomainChanged)
            // .define_method("organization_name_changed", &QCoreApplication::organizationNameChanged)
            // Static Public Members
            .define_singleton_function("add_library_path", &QCoreApplication::addLibraryPath, Arg("path"))
            .define_singleton_function("application_dir_path", &QCoreApplication::applicationDirPath)
            .define_singleton_function("application_file_path", &QCoreApplication::applicationFilePath)
            .define_singleton_function("application_name", &QCoreApplication::applicationName)
            .define_singleton_function("application_version", &QCoreApplication::applicationVersion)
            .define_singleton_function("arguments", &QCoreApplication::arguments)
            .define_singleton_function("closing_down", &QCoreApplication::closingDown)
            .define_singleton_function("event_dispatcher", &QCoreApplication::eventDispatcher)
            .define_singleton_function("exec", &QCoreApplication::exec)
            .define_singleton_function("install_translator", &QCoreApplication::installTranslator, Arg("message_file"))
            // .define_singleton_function("instance", &QCoreApplication::instance)
            .define_singleton_function("quit_lock_enabled?", &QCoreApplication::isQuitLockEnabled)
            .define_singleton_function("setuid_allowed?", &QCoreApplication::isSetuidAllowed)
            .define_singleton_function("library_paths", &QCoreApplication::libraryPaths)
            .define_singleton_function("organization_domain", &QCoreApplication::organizationDomain)
            .define_singleton_function("organization_name", &QCoreApplication::organizationName)
            .define_singleton_function("post_event", &QCoreApplication::postEvent, Arg("receiver"), Arg("event"), Arg("priority") = static_cast<int>(Qt::NormalEventPriority))
            .define_singleton_function<void (*)(QEventLoop::ProcessEventsFlags)>("process_events", &QCoreApplication::processEvents, Arg("flags") = static_cast<QEventLoop::ProcessEventsFlags>(QEventLoop::ProcessEventsFlag::AllEvents))
            .define_singleton_function<void (*)(QEventLoop::ProcessEventsFlags, QDeadlineTimer)>("process_events", &QCoreApplication::processEvents, Arg("flags"), Arg("deadline"))
            .define_singleton_function<void (*)(QEventLoop::ProcessEventsFlags, int)>("process_events", &QCoreApplication::processEvents, Arg("flags"), Arg("maxtime"))
            .define_singleton_function("remove_library_path", &QCoreApplication::removeLibraryPath, Arg("path"))
            .define_singleton_function("remove_posted_events", &QCoreApplication::removePostedEvents, Arg("receiver"), Arg("event_type") = static_cast<int>(0))
            .define_singleton_function("remove_translator", &QCoreApplication::removeTranslator, Arg("message_file"))
            .define_singleton_function("send_event", &QCoreApplication::sendEvent, Arg("receiver"), Arg("event"))
            .define_singleton_function("send_posted_events", &QCoreApplication::sendPostedEvents, Arg("receiver") = static_cast<QObject *>(nullptr), Arg("event_type") = static_cast<int>(0))
            .define_singleton_function("_set_application_name", &QCoreApplication::setApplicationName, Arg("name"))
            .define_singleton_function("_set_application_version", &QCoreApplication::setApplicationVersion, Arg("version"))
            .define_singleton_function("set_attribute", &QCoreApplication::setAttribute, Arg("attribute"), Arg("on") = static_cast<bool>(true))
            .define_singleton_function("set_event_dispatcher", &QCoreApplication::setEventDispatcher, Arg("event_dispatcher"))
            .define_singleton_function("set_library_paths", &QCoreApplication::setLibraryPaths, Arg("path"))
            .define_singleton_function("_set_organization_domain", &QCoreApplication::setOrganizationDomain, Arg("org_domain"))
            .define_singleton_function("_set_organization_name", &QCoreApplication::setOrganizationName, Arg("org_name"))
            .define_singleton_function("set_quit_lock_enabled", &QCoreApplication::setQuitLockEnabled, Arg("enabled"))
            .define_singleton_function("set_setuid_allowed", &QCoreApplication::setSetuidAllowed, Arg("allow"))
            .define_singleton_function("starting_up", &QCoreApplication::startingUp)
            .define_singleton_function("test_attribute", &QCoreApplication::testAttribute, Arg("attribute"))
            .define_singleton_function("translate", &QCoreApplication::translate, Arg("context"), Arg("key"), Arg("disambiguation") = static_cast<const char *>(nullptr), Arg("n") = static_cast<int>(-1));
}
