#include "quiloader-rb.hpp"
#include <quiloader.h>

#include <QDir>
#include <QIODevice>
#include <QWidget>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQUiLoader;

void Init_quiloader(Module rb_mQt6QtUiTools)
{
    rb_cQUiLoader =
        // RubyQt6::QtUiTools::QUiLoader
        define_qlass_under<QUiLoader, QObject>(rb_mQt6QtUiTools, "QUiLoader")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QUiLoader * { return qobject_cast<QUiLoader *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QUiLoader::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QUiLoader>())
            // Public Functions
            .define_method("add_plugin_path", &QUiLoader::addPluginPath, Arg("path"))
            .define_method("available_layouts", &QUiLoader::availableLayouts)
            .define_method("available_widgets", &QUiLoader::availableWidgets)
            .define_method("clear_plugin_paths", &QUiLoader::clearPluginPaths)
            .define_method("error_string", &QUiLoader::errorString)
            .define_method("language_change_enabled?", &QUiLoader::isLanguageChangeEnabled)
            .define_method("load", &QUiLoader::load, Arg("device"), Arg("parent") = static_cast<QWidget *>(nullptr))
            .define_method("plugin_paths", &QUiLoader::pluginPaths)
            .define_method("set_language_change_enabled", &QUiLoader::setLanguageChangeEnabled, Arg("enabled"))
            .define_method("set_working_directory", &QUiLoader::setWorkingDirectory, Arg("dir"))
            .define_method("working_directory", &QUiLoader::workingDirectory);
}
