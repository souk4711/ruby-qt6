#include "qlibraryinfo-rb.hpp"
#include <qlibraryinfo.h>
#include <rice/qt6/qenum.hpp>

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

    Data_Type<QLibraryInfo::LibraryPath> rb_cQLibraryInfoLibraryPath =
        // RubyQt6::QtCore::QLibraryInfo::LibraryPath
        define_qenum_under<QLibraryInfo::LibraryPath>(rb_cQLibraryInfo, "LibraryPath");
        define_qenum_value_under(rb_cQLibraryInfoLibraryPath, "PrefixPath", QLibraryInfo::LibraryPath::PrefixPath);
        define_qenum_value_under(rb_cQLibraryInfoLibraryPath, "DocumentationPath", QLibraryInfo::LibraryPath::DocumentationPath);
        define_qenum_value_under(rb_cQLibraryInfoLibraryPath, "HeadersPath", QLibraryInfo::LibraryPath::HeadersPath);
        define_qenum_value_under(rb_cQLibraryInfoLibraryPath, "LibrariesPath", QLibraryInfo::LibraryPath::LibrariesPath);
        define_qenum_value_under(rb_cQLibraryInfoLibraryPath, "LibraryExecutablesPath", QLibraryInfo::LibraryPath::LibraryExecutablesPath);
        define_qenum_value_under(rb_cQLibraryInfoLibraryPath, "BinariesPath", QLibraryInfo::LibraryPath::BinariesPath);
        define_qenum_value_under(rb_cQLibraryInfoLibraryPath, "PluginsPath", QLibraryInfo::LibraryPath::PluginsPath);
        define_qenum_value_under(rb_cQLibraryInfoLibraryPath, "QmlImportsPath", QLibraryInfo::LibraryPath::QmlImportsPath);
        define_qenum_value_under(rb_cQLibraryInfoLibraryPath, "Qml2ImportsPath", QLibraryInfo::LibraryPath::Qml2ImportsPath);
        define_qenum_value_under(rb_cQLibraryInfoLibraryPath, "ArchDataPath", QLibraryInfo::LibraryPath::ArchDataPath);
        define_qenum_value_under(rb_cQLibraryInfoLibraryPath, "DataPath", QLibraryInfo::LibraryPath::DataPath);
        define_qenum_value_under(rb_cQLibraryInfoLibraryPath, "TranslationsPath", QLibraryInfo::LibraryPath::TranslationsPath);
        define_qenum_value_under(rb_cQLibraryInfoLibraryPath, "ExamplesPath", QLibraryInfo::LibraryPath::ExamplesPath);
        define_qenum_value_under(rb_cQLibraryInfoLibraryPath, "TestsPath", QLibraryInfo::LibraryPath::TestsPath);
        define_qenum_value_under(rb_cQLibraryInfoLibraryPath, "SettingsPath", QLibraryInfo::LibraryPath::SettingsPath);
}
