#include "qstandardpaths-rb.hpp"
#include <qstandardpaths.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQStandardPaths;

void Init_qstandardpaths(Module rb_mQt6QtCore)
{
    rb_cQStandardPaths =
        // RubyQt6::QtCore::QStandardPaths
        define_class_under<QStandardPaths>(rb_mQt6QtCore, "QStandardPaths")
            // Static Public Members
            .define_singleton_function("display_name", &QStandardPaths::displayName, Arg("type"))
            .define_singleton_function("find_executable", &QStandardPaths::findExecutable, Arg("executable_name"), Arg("paths") = static_cast<const QStringList &>(QStringList()))
            .define_singleton_function("test_mode_enabled?", &QStandardPaths::isTestModeEnabled)
            .define_singleton_function("locate", &QStandardPaths::locate, Arg("type"), Arg("file_name"), Arg("options") = static_cast<QStandardPaths::LocateOptions>(QStandardPaths::LocateFile))
            .define_singleton_function("locate_all", &QStandardPaths::locateAll, Arg("type"), Arg("file_name"), Arg("options") = static_cast<QStandardPaths::LocateOptions>(QStandardPaths::LocateFile))
            .define_singleton_function("set_test_mode_enabled", &QStandardPaths::setTestModeEnabled, Arg("test_mode"))
            .define_singleton_function("standard_locations", &QStandardPaths::standardLocations, Arg("type"))
            .define_singleton_function("writable_location", &QStandardPaths::writableLocation, Arg("type"));

    Data_Type<QStandardPaths::LocateOption> rb_cQStandardPathsLocateOption =
        // RubyQt6::QtCore::QStandardPaths::LocateOption
        define_qenum_under<QStandardPaths::LocateOption>(rb_cQStandardPaths, "LocateOption");
        define_qenum_value_under(rb_cQStandardPathsLocateOption, "LocateFile", QStandardPaths::LocateOption::LocateFile);
        define_qenum_value_under(rb_cQStandardPathsLocateOption, "LocateDirectory", QStandardPaths::LocateOption::LocateDirectory);

    Data_Type<QStandardPaths::StandardLocation> rb_cQStandardPathsStandardLocation =
        // RubyQt6::QtCore::QStandardPaths::StandardLocation
        define_qenum_under<QStandardPaths::StandardLocation>(rb_cQStandardPaths, "StandardLocation");
        define_qenum_value_under(rb_cQStandardPathsStandardLocation, "DesktopLocation", QStandardPaths::StandardLocation::DesktopLocation);
        define_qenum_value_under(rb_cQStandardPathsStandardLocation, "DocumentsLocation", QStandardPaths::StandardLocation::DocumentsLocation);
        define_qenum_value_under(rb_cQStandardPathsStandardLocation, "FontsLocation", QStandardPaths::StandardLocation::FontsLocation);
        define_qenum_value_under(rb_cQStandardPathsStandardLocation, "ApplicationsLocation", QStandardPaths::StandardLocation::ApplicationsLocation);
        define_qenum_value_under(rb_cQStandardPathsStandardLocation, "MusicLocation", QStandardPaths::StandardLocation::MusicLocation);
        define_qenum_value_under(rb_cQStandardPathsStandardLocation, "MoviesLocation", QStandardPaths::StandardLocation::MoviesLocation);
        define_qenum_value_under(rb_cQStandardPathsStandardLocation, "PicturesLocation", QStandardPaths::StandardLocation::PicturesLocation);
        define_qenum_value_under(rb_cQStandardPathsStandardLocation, "TempLocation", QStandardPaths::StandardLocation::TempLocation);
        define_qenum_value_under(rb_cQStandardPathsStandardLocation, "HomeLocation", QStandardPaths::StandardLocation::HomeLocation);
        define_qenum_value_under(rb_cQStandardPathsStandardLocation, "AppLocalDataLocation", QStandardPaths::StandardLocation::AppLocalDataLocation);
        define_qenum_value_under(rb_cQStandardPathsStandardLocation, "CacheLocation", QStandardPaths::StandardLocation::CacheLocation);
        define_qenum_value_under(rb_cQStandardPathsStandardLocation, "GenericDataLocation", QStandardPaths::StandardLocation::GenericDataLocation);
        define_qenum_value_under(rb_cQStandardPathsStandardLocation, "RuntimeLocation", QStandardPaths::StandardLocation::RuntimeLocation);
        define_qenum_value_under(rb_cQStandardPathsStandardLocation, "ConfigLocation", QStandardPaths::StandardLocation::ConfigLocation);
        define_qenum_value_under(rb_cQStandardPathsStandardLocation, "DownloadLocation", QStandardPaths::StandardLocation::DownloadLocation);
        define_qenum_value_under(rb_cQStandardPathsStandardLocation, "GenericCacheLocation", QStandardPaths::StandardLocation::GenericCacheLocation);
        define_qenum_value_under(rb_cQStandardPathsStandardLocation, "GenericConfigLocation", QStandardPaths::StandardLocation::GenericConfigLocation);
        define_qenum_value_under(rb_cQStandardPathsStandardLocation, "AppDataLocation", QStandardPaths::StandardLocation::AppDataLocation);
        define_qenum_value_under(rb_cQStandardPathsStandardLocation, "AppConfigLocation", QStandardPaths::StandardLocation::AppConfigLocation);
        define_qenum_value_under(rb_cQStandardPathsStandardLocation, "PublicShareLocation", QStandardPaths::StandardLocation::PublicShareLocation);
        define_qenum_value_under(rb_cQStandardPathsStandardLocation, "TemplatesLocation", QStandardPaths::StandardLocation::TemplatesLocation);
        define_qenum_value_under(rb_cQStandardPathsStandardLocation, "StateLocation", QStandardPaths::StandardLocation::StateLocation);
        define_qenum_value_under(rb_cQStandardPathsStandardLocation, "GenericStateLocation", QStandardPaths::StandardLocation::GenericStateLocation);

    Data_Type<QFlags<QStandardPaths::LocateOption>> rb_cQStandardPathsLocateOptions =
        // RubyQt6::QtCore::QStandardPaths::LocateOptions
        define_qflags_under<QStandardPaths::LocateOption>(rb_cQStandardPaths, "LocateOptions");
}
