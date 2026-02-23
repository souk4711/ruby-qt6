#include "qdir-rb.hpp"
#include <qdir.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQDir;

void Init_qdir(Module rb_mQt6QtCore)
{
    rb_cQDir =
        // RubyQt6::QtCore::QDir
        define_qlass_under<QDir>(rb_mQt6QtCore, "QDir")
            // RubyQt6-Defined Functions
            .define_method("mkdir", [](QDir *self, const QString &dir_name) -> bool { return self->mkdir(dir_name); }, Arg("dir_name"))
            .define_method("mkdir", [](QDir *self, const QString &dir_name, QFileDevice::Permissions permissions) -> bool { return self->mkdir(dir_name, permissions); }, Arg("dir_name"), Arg("permissions"))
            // Constructor
            .define_constructor(Constructor<QDir, const QString &>(), Arg("path"))
            .define_constructor(Constructor<QDir, const QString &, const QString &>(), Arg("path"), Arg("name_filter"))
            // Public Functions
            .define_method("_absolute_file_path", &QDir::absoluteFilePath, Arg("file_name"))
            .define_method("absolute_path", &QDir::absolutePath)
            .define_method("canonical_path", &QDir::canonicalPath)
            .define_method("cd", &QDir::cd, Arg("dir_name"))
            .define_method("cd_up", &QDir::cdUp)
            .define_method("count", &QDir::count, Arg("_"))
            .define_method("dir_name", &QDir::dirName)
            .define_method<QFileInfoList (QDir::*)(QDir::Filters, QDir::SortFlags) const>("entry_info_list", &QDir::entryInfoList, Arg("filters") = static_cast<QDir::Filters>(QDir::Filter::NoFilter), Arg("sort") = static_cast<QDir::SortFlags>(QDir::SortFlag::NoSort))
            .define_method<QFileInfoList (QDir::*)(const QStringList &, QDir::Filters, QDir::SortFlags) const>("entry_info_list", &QDir::entryInfoList, Arg("name_filters"), Arg("filters") = static_cast<QDir::Filters>(QDir::Filter::NoFilter), Arg("sort") = static_cast<QDir::SortFlags>(QDir::SortFlag::NoSort))
            .define_method<QStringList (QDir::*)(QDir::Filters, QDir::SortFlags) const>("entry_list", &QDir::entryList, Arg("filters") = static_cast<QDir::Filters>(QDir::Filter::NoFilter), Arg("sort") = static_cast<QDir::SortFlags>(QDir::SortFlag::NoSort))
            .define_method<QStringList (QDir::*)(const QStringList &, QDir::Filters, QDir::SortFlags) const>("entry_list", &QDir::entryList, Arg("name_filters"), Arg("filters") = static_cast<QDir::Filters>(QDir::Filter::NoFilter), Arg("sort") = static_cast<QDir::SortFlags>(QDir::SortFlag::NoSort))
            .define_method<bool (QDir::*)() const>("_exists", &QDir::exists)
            .define_method<bool (QDir::*)(const QString &) const>("_exists", &QDir::exists, Arg("name"))
            .define_method("_file_path", &QDir::filePath, Arg("file_name"))
            .define_method("filesystem_absolute_path", &QDir::filesystemAbsolutePath)
            .define_method("filesystem_canonical_path", &QDir::filesystemCanonicalPath)
            .define_method("filesystem_path", &QDir::filesystemPath)
            .define_method("filter", &QDir::filter)
            .define_method("absolute?", &QDir::isAbsolute)
            .define_method("empty?", &QDir::isEmpty, Arg("filters") = static_cast<QDir::Filters>(QDir::Filters(QDir::Filter::AllEntries | QDir::Filter::NoDotAndDotDot)))
            .define_method("readable?", &QDir::isReadable)
            .define_method("relative?", &QDir::isRelative)
            .define_method("root?", &QDir::isRoot)
            .define_method("make_absolute", &QDir::makeAbsolute)
            .define_method("mkpath", &QDir::mkpath, Arg("dir_path"))
            .define_method("name_filters", &QDir::nameFilters)
            .define_method("path", &QDir::path)
            .define_method("refresh", &QDir::refresh)
            .define_method("relative_file_path", &QDir::relativeFilePath, Arg("file_name"))
            .define_method("remove", &QDir::remove, Arg("file_name"))
            .define_method("remove_recursively", &QDir::removeRecursively)
            .define_method("rename", &QDir::rename, Arg("old_name"), Arg("new_name"))
            .define_method("rmdir", &QDir::rmdir, Arg("dir_name"))
            .define_method("rmpath", &QDir::rmpath, Arg("dir_path"))
            .define_method("set_filter", &QDir::setFilter, Arg("filter"))
            .define_method("set_name_filters", &QDir::setNameFilters, Arg("name_filters"))
            .define_method<void (QDir::*)(const QString &path)>("set_path", &QDir::setPath, Arg("path"))
            .define_method("set_sorting", &QDir::setSorting, Arg("sort"))
            .define_method("sorting", &QDir::sorting)
            // Static Public Members
            .define_singleton_function<void (*)(const QString &, const QString &)>("add_search_path", &QDir::addSearchPath, Arg("prefix"), Arg("path"))
            .define_singleton_function("clean_path", &QDir::cleanPath, Arg("path"))
            .define_singleton_function("current", &QDir::current)
            .define_singleton_function("current_path", &QDir::currentPath)
            .define_singleton_function("drives", &QDir::drives)
            .define_singleton_function("from_native_separators", &QDir::fromNativeSeparators, Arg("path_name"))
            .define_singleton_function("home", &QDir::home)
            .define_singleton_function("home_path", &QDir::homePath)
            .define_singleton_function("absolute_path?", &QDir::isAbsolutePath, Arg("path"))
            .define_singleton_function("relative_path?", &QDir::isRelativePath, Arg("path"))
            // .define_singleton_function("list_separator", &QDir::listSeparator)
            .define_singleton_function<bool (*)(const QString &, const QString &)>("match", &QDir::match, Arg("filter"), Arg("file_name"))
            .define_singleton_function<bool (*)(const QStringList &, const QString &)>("match", &QDir::match, Arg("filters"), Arg("file_name"))
            .define_singleton_function("name_filters_from_string", &QDir::nameFiltersFromString, Arg("name_filter"))
            .define_singleton_function("root", &QDir::root)
            .define_singleton_function("root_path", &QDir::rootPath)
            .define_singleton_function("search_paths", &QDir::searchPaths, Arg("prefix"))
            .define_singleton_function("separator", &QDir::separator)
            .define_singleton_function("set_current", &QDir::setCurrent, Arg("path"))
            .define_singleton_function("set_search_paths", &QDir::setSearchPaths, Arg("prefix"), Arg("search_paths"))
            .define_singleton_function("temp", &QDir::temp)
            .define_singleton_function("temp_path", &QDir::tempPath)
            .define_singleton_function("to_native_separators", &QDir::toNativeSeparators, Arg("path_name"));

    Data_Type<QDir::Filter> rb_cQDirFilter =
        // RubyQt6::QtCore::QDir::Filter
        define_qenum_under<QDir::Filter>(rb_cQDir, "Filter");
        define_qenum_value_under(rb_cQDirFilter, "Dirs", QDir::Filter::Dirs);
        define_qenum_value_under(rb_cQDirFilter, "Files", QDir::Filter::Files);
        define_qenum_value_under(rb_cQDirFilter, "Drives", QDir::Filter::Drives);
        define_qenum_value_under(rb_cQDirFilter, "NoSymLinks", QDir::Filter::NoSymLinks);
        define_qenum_value_under(rb_cQDirFilter, "AllEntries", QDir::Filter::AllEntries);
        define_qenum_value_under(rb_cQDirFilter, "TypeMask", QDir::Filter::TypeMask);
        define_qenum_value_under(rb_cQDirFilter, "Readable", QDir::Filter::Readable);
        define_qenum_value_under(rb_cQDirFilter, "Writable", QDir::Filter::Writable);
        define_qenum_value_under(rb_cQDirFilter, "Executable", QDir::Filter::Executable);
        define_qenum_value_under(rb_cQDirFilter, "PermissionMask", QDir::Filter::PermissionMask);
        define_qenum_value_under(rb_cQDirFilter, "Modified", QDir::Filter::Modified);
        define_qenum_value_under(rb_cQDirFilter, "Hidden", QDir::Filter::Hidden);
        define_qenum_value_under(rb_cQDirFilter, "System", QDir::Filter::System);
        define_qenum_value_under(rb_cQDirFilter, "AccessMask", QDir::Filter::AccessMask);
        define_qenum_value_under(rb_cQDirFilter, "AllDirs", QDir::Filter::AllDirs);
        define_qenum_value_under(rb_cQDirFilter, "CaseSensitive", QDir::Filter::CaseSensitive);
        define_qenum_value_under(rb_cQDirFilter, "NoDot", QDir::Filter::NoDot);
        define_qenum_value_under(rb_cQDirFilter, "NoDotDot", QDir::Filter::NoDotDot);
        define_qenum_value_under(rb_cQDirFilter, "NoDotAndDotDot", QDir::Filter::NoDotAndDotDot);
        define_qenum_value_under(rb_cQDirFilter, "NoFilter", QDir::Filter::NoFilter);

    Data_Type<QDir::SortFlag> rb_cQDirSortFlag =
        // RubyQt6::QtCore::QDir::SortFlag
        define_qenum_under<QDir::SortFlag>(rb_cQDir, "SortFlag");
        define_qenum_value_under(rb_cQDirSortFlag, "Name", QDir::SortFlag::Name);
        define_qenum_value_under(rb_cQDirSortFlag, "Time", QDir::SortFlag::Time);
        define_qenum_value_under(rb_cQDirSortFlag, "Size", QDir::SortFlag::Size);
        define_qenum_value_under(rb_cQDirSortFlag, "Unsorted", QDir::SortFlag::Unsorted);
        define_qenum_value_under(rb_cQDirSortFlag, "SortByMask", QDir::SortFlag::SortByMask);
        define_qenum_value_under(rb_cQDirSortFlag, "DirsFirst", QDir::SortFlag::DirsFirst);
        define_qenum_value_under(rb_cQDirSortFlag, "Reversed", QDir::SortFlag::Reversed);
        define_qenum_value_under(rb_cQDirSortFlag, "IgnoreCase", QDir::SortFlag::IgnoreCase);
        define_qenum_value_under(rb_cQDirSortFlag, "DirsLast", QDir::SortFlag::DirsLast);
        define_qenum_value_under(rb_cQDirSortFlag, "LocaleAware", QDir::SortFlag::LocaleAware);
        define_qenum_value_under(rb_cQDirSortFlag, "Type", QDir::SortFlag::Type);
        define_qenum_value_under(rb_cQDirSortFlag, "NoSort", QDir::SortFlag::NoSort);

    Data_Type<QFlags<QDir::Filter>> rb_cQDirFilters =
        // RubyQt6::QtCore::QDir::Filters
        define_qflags_under<QDir::Filter>(rb_cQDir, "Filters");

    Data_Type<QFlags<QDir::SortFlag>> rb_cQDirSortFlags =
        // RubyQt6::QtCore::QDir::SortFlags
        define_qflags_under<QDir::SortFlag>(rb_cQDir, "SortFlags");
}
