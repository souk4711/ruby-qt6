#include "qqmlengine-rb.hpp"
#include <qqmlengine.h>

#include <QQmlContext>
#include <QQmlIncubationController>
#include <QQmlNetworkAccessManagerFactory>
#include <QtNetwork/QNetworkAccessManager>

using namespace Rice;

Rice::Class rb_cQQmlEngine;
Rice::Class rb_cQQmlImageProviderBase;

void Init_qqmlengine(Rice::Module rb_mQt6QtQml)
{
    rb_cQQmlImageProviderBase =
        // Qt6::QtQml::QQmlImageProviderBase
        define_class_under<QQmlImageProviderBase, QObject>(rb_mQt6QtQml, "QQmlImageProviderBase")
            .define_method("image_type", &QQmlImageProviderBase::imageType)
            .define_method("flags", &QQmlImageProviderBase::flags);

    Enum<QQmlImageProviderBase::ImageType> rb_cQQmlImageProviderBaseImageType =
        // Qt6::QtQml::QQmlImageProviderBase::ImageType
        define_enum_under<QQmlImageProviderBase::ImageType>("ImageType", rb_cQQmlImageProviderBase)
            .define_value("Invalid", QQmlImageProviderBase::ImageType::Invalid)
            .define_value("Image", QQmlImageProviderBase::ImageType::Image)
            .define_value("Pixmap", QQmlImageProviderBase::ImageType::Pixmap)
            .define_value("Texture", QQmlImageProviderBase::ImageType::Texture)
            .define_value("ImageResponse", QQmlImageProviderBase::ImageType::ImageResponse);

    Enum<QQmlImageProviderBase::Flag> rb_cQQmlImageProviderBaseFlag =
        // Qt6::QtQml::QQmlImageProviderBase::Flag
        define_enum_under<QQmlImageProviderBase::Flag>("Flag", rb_cQQmlImageProviderBase)
            .define_value("ForceAsynchronousImageLoading", QQmlImageProviderBase::Flag::ForceAsynchronousImageLoading);

    rb_cQQmlEngine =
        // Qt6::QtQml::QQmlEngine
        define_class_under<QQmlEngine, QJSEngine>(rb_mQt6QtQml, "QQmlEngine")
            .define_constructor(Constructor<QQmlEngine, QObject *>(), Arg("p") = static_cast<QObject *>(nullptr))
            .define_method("root_context", &QQmlEngine::rootContext)
            .define_method("clear_component_cache", &QQmlEngine::clearComponentCache)
            .define_method("trim_component_cache", &QQmlEngine::trimComponentCache)
            .define_method("clear_singletons", &QQmlEngine::clearSingletons)
            .define_method("import_path_list", &QQmlEngine::importPathList)
            .define_method("set_import_path_list", &QQmlEngine::setImportPathList, Arg("paths"))
            .define_method("add_import_path", &QQmlEngine::addImportPath, Arg("dir"))
            .define_method("plugin_path_list", &QQmlEngine::pluginPathList)
            .define_method("set_plugin_path_list", &QQmlEngine::setPluginPathList, Arg("paths"))
            .define_method("add_plugin_path", &QQmlEngine::addPluginPath, Arg("dir"))
            .define_method("set_network_access_manager_factory", &QQmlEngine::setNetworkAccessManagerFactory, Arg(""))
            .define_method("network_access_manager_factory", &QQmlEngine::networkAccessManagerFactory)
            .define_method("network_access_manager", &QQmlEngine::networkAccessManager)
            .define_method("add_url_interceptor", &QQmlEngine::addUrlInterceptor, Arg("url_interceptor"))
            .define_method("remove_url_interceptor", &QQmlEngine::removeUrlInterceptor, Arg("url_interceptor"))
            .define_method("url_interceptors", &QQmlEngine::urlInterceptors)
            .define_method("intercept_url", &QQmlEngine::interceptUrl, Arg("url"), Arg("type"))
            .define_method("add_image_provider", &QQmlEngine::addImageProvider, Arg("id"), Arg(""))
            .define_method("image_provider", &QQmlEngine::imageProvider, Arg("id"))
            .define_method("remove_image_provider", &QQmlEngine::removeImageProvider, Arg("id"))
            .define_method("set_incubation_controller", &QQmlEngine::setIncubationController, Arg(""))
            .define_method("incubation_controller", &QQmlEngine::incubationController)
            .define_method("set_offline_storage_path", &QQmlEngine::setOfflineStoragePath, Arg("dir"))
            .define_method("offline_storage_path", &QQmlEngine::offlineStoragePath)
            .define_method("offline_storage_database_file_path", &QQmlEngine::offlineStorageDatabaseFilePath, Arg("database_name"))
            .define_method("base_url", &QQmlEngine::baseUrl)
            .define_method("set_base_url", &QQmlEngine::setBaseUrl, Arg(""))
            .define_method("output_warnings_to_standard_error", &QQmlEngine::outputWarningsToStandardError)
            .define_method("set_output_warnings_to_standard_error", &QQmlEngine::setOutputWarningsToStandardError, Arg(""))
            .define_method("mark_current_function_as_translation_binding", &QQmlEngine::markCurrentFunctionAsTranslationBinding)
            .define_method("capture_property", &QQmlEngine::captureProperty, Arg("object"), Arg("property"))
            .define_method("retranslate", &QQmlEngine::retranslate)
            .define_method("offline_storage_path_changed", &QQmlEngine::offlineStoragePathChanged)
            .define_singleton_function("context_for_object", &QQmlEngine::contextForObject, Arg(""))
            .define_singleton_function("set_context_for_object", &QQmlEngine::setContextForObject, Arg(""), Arg(""))
            .define_method("quit", &QQmlEngine::quit)
            .define_method("exit", &QQmlEngine::exit, Arg("ret_code"))
            .define_method("warnings", &QQmlEngine::warnings, Arg("warnings"));
}
