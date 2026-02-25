#include "qqmlengine-rb.hpp"
#include <qqmlengine.h>

#include <QQmlContext>
#include <QQmlIncubationController>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQQmlEngine;

void Init_qqmlengine(Module rb_mQt6QtQml)
{
    rb_cQQmlEngine =
        // RubyQt6::QtQml::QQmlEngine
        define_qlass_under<QQmlEngine, QJSEngine>(rb_mQt6QtQml, "QQmlEngine")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QQmlEngine * { return qobject_cast<QQmlEngine *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QQmlEngine::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QQmlEngine, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("add_image_provider", &QQmlEngine::addImageProvider, Arg("id"), Arg("provider"))
            .define_method("_add_import_path", &QQmlEngine::addImportPath, Arg("dir"))
            .define_method("add_plugin_path", &QQmlEngine::addPluginPath, Arg("dir"))
            .define_method("add_url_interceptor", &QQmlEngine::addUrlInterceptor, Arg("url_interceptor"))
            .define_method("base_url", &QQmlEngine::baseUrl)
            .define_method("capture_property", &QQmlEngine::captureProperty, Arg("object"), Arg("property"))
            .define_method("clear_component_cache", &QQmlEngine::clearComponentCache)
            .define_method("clear_singletons", &QQmlEngine::clearSingletons)
            .define_method("image_provider", &QQmlEngine::imageProvider, Arg("id"))
            .define_method("import_path_list", &QQmlEngine::importPathList)
            .define_method("incubation_controller", &QQmlEngine::incubationController)
            .define_method("intercept_url", &QQmlEngine::interceptUrl, Arg("url"), Arg("type"))
            .define_method("mark_current_function_as_translation_binding", &QQmlEngine::markCurrentFunctionAsTranslationBinding)
            // .define_method("network_access_manager", &QQmlEngine::networkAccessManager)
            // .define_method("network_access_manager_factory", &QQmlEngine::networkAccessManagerFactory)
            .define_method("offline_storage_database_file_path", &QQmlEngine::offlineStorageDatabaseFilePath, Arg("database_name"))
            .define_method("offline_storage_path", &QQmlEngine::offlineStoragePath)
            .define_method("output_warnings_to_standard_error", &QQmlEngine::outputWarningsToStandardError)
            .define_method("plugin_path_list", &QQmlEngine::pluginPathList)
            .define_method("remove_image_provider", &QQmlEngine::removeImageProvider, Arg("id"))
            .define_method("remove_url_interceptor", &QQmlEngine::removeUrlInterceptor, Arg("url_interceptor"))
            .define_method("root_context", &QQmlEngine::rootContext)
            .define_method("set_base_url", &QQmlEngine::setBaseUrl, Arg("url"))
            .define_method("set_import_path_list", &QQmlEngine::setImportPathList, Arg("paths"))
            .define_method("set_incubation_controller", &QQmlEngine::setIncubationController, Arg("controller"))
            // .define_method("set_network_access_manager_factory", &QQmlEngine::setNetworkAccessManagerFactory, Arg("factory"))
            .define_method("set_offline_storage_path", &QQmlEngine::setOfflineStoragePath, Arg("dir"))
            .define_method("set_output_warnings_to_standard_error", &QQmlEngine::setOutputWarningsToStandardError, Arg("enabled"))
            .define_method("set_plugin_path_list", &QQmlEngine::setPluginPathList, Arg("paths"))
            .define_method("trim_component_cache", &QQmlEngine::trimComponentCache)
            .define_method("url_interceptors", &QQmlEngine::urlInterceptors)
            // Public Slots
            .define_method("retranslate", &QQmlEngine::retranslate)
            // Signals
            // .define_method("exit", &QQmlEngine::exit, Arg("ret_code"))
            // .define_method("offline_storage_path_changed", &QQmlEngine::offlineStoragePathChanged)
            // .define_method("quit", &QQmlEngine::quit)
            // .define_method("warnings", &QQmlEngine::warnings, Arg("warnings"))
            // Static Public Members
            .define_singleton_function("context_for_object", &QQmlEngine::contextForObject, Arg("obj"))
            .define_singleton_function("set_context_for_object", &QQmlEngine::setContextForObject, Arg("obj"), Arg("context"));
}
