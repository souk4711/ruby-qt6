#include "qlibraryinfo-rb.hpp"
#include <qlibraryinfo.h>

using namespace Rice;

Rice::Class rb_cQLibraryInfo;

void Init_qlibraryinfo(Rice::Module rb_mQt6QtCore)
{
    rb_cQLibraryInfo =
        // RubyQt6::QtCore::QLibraryInfo
        define_class_under<QLibraryInfo>(rb_mQt6QtCore, "QLibraryInfo")
            // Static Public Members
            .define_singleton_function("path", &QLibraryInfo::path, Arg("p"))
            .define_singleton_function("paths", &QLibraryInfo::paths, Arg("p"));

    Enum<QLibraryInfo::LibraryPath> rb_cQLibraryInfoLibraryPath =
        // RubyQt6::QtCore::QLibraryInfo::LibraryPath
        define_enum_under<QLibraryInfo::LibraryPath>("LibraryPath", rb_cQLibraryInfo)
            .define_value("PrefixPath", QLibraryInfo::LibraryPath::PrefixPath)
            .define_value("DocumentationPath", QLibraryInfo::LibraryPath::DocumentationPath)
            .define_value("HeadersPath", QLibraryInfo::LibraryPath::HeadersPath)
            .define_value("LibrariesPath", QLibraryInfo::LibraryPath::LibrariesPath)
            .define_value("LibraryExecutablesPath", QLibraryInfo::LibraryPath::LibraryExecutablesPath)
            .define_value("BinariesPath", QLibraryInfo::LibraryPath::BinariesPath)
            .define_value("PluginsPath", QLibraryInfo::LibraryPath::PluginsPath)
            .define_value("QmlImportsPath", QLibraryInfo::LibraryPath::QmlImportsPath)
            .define_value("Qml2ImportsPath", QLibraryInfo::LibraryPath::Qml2ImportsPath)
            .define_value("ArchDataPath", QLibraryInfo::LibraryPath::ArchDataPath)
            .define_value("DataPath", QLibraryInfo::LibraryPath::DataPath)
            .define_value("TranslationsPath", QLibraryInfo::LibraryPath::TranslationsPath)
            .define_value("ExamplesPath", QLibraryInfo::LibraryPath::ExamplesPath)
            .define_value("TestsPath", QLibraryInfo::LibraryPath::TestsPath)
            .define_value("SettingsPath", QLibraryInfo::LibraryPath::SettingsPath);
}
