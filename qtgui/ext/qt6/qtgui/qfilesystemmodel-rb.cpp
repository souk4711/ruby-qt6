#include "qfilesystemmodel-rb.hpp"
#include <qfilesystemmodel.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

#include <QAbstractFileIconProvider>
#include <QMimeData>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQFileSystemModel;

void Init_qfilesystemmodel(Module rb_mQt6QtGui)
{
    rb_cQFileSystemModel =
        // RubyQt6::QtGui::QFileSystemModel
        define_qlass_under<QFileSystemModel, QAbstractItemModel>(rb_mQt6QtGui, "QFileSystemModel")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QFileSystemModel::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QFileSystemModel, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("can_fetch_more", &QFileSystemModel::canFetchMore, Arg("parent"))
            .define_method("column_count", &QFileSystemModel::columnCount, Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("data", &QFileSystemModel::data, Arg("index"), Arg("role") = static_cast<int>(Qt::DisplayRole))
            .define_method("drop_mime_data", &QFileSystemModel::dropMimeData, Arg("data"), Arg("action"), Arg("row"), Arg("column"), Arg("parent"))
            .define_method("fetch_more", &QFileSystemModel::fetchMore, Arg("parent"))
            .define_method("file_icon", &QFileSystemModel::fileIcon, Arg("index"))
            .define_method("file_info", &QFileSystemModel::fileInfo, Arg("index"))
            .define_method("file_name", &QFileSystemModel::fileName, Arg("index"))
            .define_method("file_path", &QFileSystemModel::filePath, Arg("index"))
            .define_method("filter", &QFileSystemModel::filter)
            .define_method("flags", &QFileSystemModel::flags, Arg("index"))
            .define_method("has_children", &QFileSystemModel::hasChildren, Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("header_data", &QFileSystemModel::headerData, Arg("section"), Arg("orientation"), Arg("role") = static_cast<int>(Qt::DisplayRole))
            .define_method("icon_provider", &QFileSystemModel::iconProvider)
            .define_method<QModelIndex (QFileSystemModel::*)(const QString &, int) const>("index", &QFileSystemModel::index, Arg("path"), Arg("column") = static_cast<int>(0))
            .define_method<QModelIndex (QFileSystemModel::*)(int, int, const QModelIndex &) const>("index", &QFileSystemModel::index, Arg("row"), Arg("column"), Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("dir?", &QFileSystemModel::isDir, Arg("index"))
            .define_method("read_only?", &QFileSystemModel::isReadOnly)
            .define_method<QDateTime (QFileSystemModel::*)(const QModelIndex &) const>("last_modified", &QFileSystemModel::lastModified, Arg("index"))
            .define_method<QDateTime (QFileSystemModel::*)(const QModelIndex &, const QTimeZone &) const>("last_modified", &QFileSystemModel::lastModified, Arg("index"), Arg("tz"))
            .define_method("mime_data", &QFileSystemModel::mimeData, Arg("indexes"))
            .define_method("mime_types", &QFileSystemModel::mimeTypes)
            .define_method("mkdir", &QFileSystemModel::mkdir, Arg("parent"), Arg("name"))
            .define_method("my_computer", &QFileSystemModel::myComputer, Arg("role") = static_cast<int>(Qt::DisplayRole))
            .define_method("name_filter_disables", &QFileSystemModel::nameFilterDisables)
            .define_method("name_filters", &QFileSystemModel::nameFilters)
            .define_method("options", &QFileSystemModel::options)
            // .define_method("parent", &QFileSystemModel::parent, Arg("child"))
            .define_method("permissions", &QFileSystemModel::permissions, Arg("index"))
            .define_method("remove", &QFileSystemModel::remove, Arg("index"))
            .define_method("resolve_symlinks", &QFileSystemModel::resolveSymlinks)
            .define_method("rmdir", &QFileSystemModel::rmdir, Arg("index"))
            .define_method("role_names", &QFileSystemModel::roleNames)
            .define_method("root_directory", &QFileSystemModel::rootDirectory)
            .define_method("root_path", &QFileSystemModel::rootPath)
            .define_method("row_count", &QFileSystemModel::rowCount, Arg("parent") = static_cast<const QModelIndex &>(QModelIndex()))
            .define_method("set_data", &QFileSystemModel::setData, Arg("index"), Arg("value"), Arg("role") = static_cast<int>(Qt::EditRole))
            .define_method("set_filter", &QFileSystemModel::setFilter, Arg("filters"))
            .define_method("set_icon_provider", &QFileSystemModel::setIconProvider, Arg("provider"))
            .define_method("set_name_filter_disables", &QFileSystemModel::setNameFilterDisables, Arg("enable"))
            .define_method("set_name_filters", &QFileSystemModel::setNameFilters, Arg("filters"))
            .define_method("set_option", &QFileSystemModel::setOption, Arg("option"), Arg("on") = static_cast<bool>(true))
            .define_method("set_options", &QFileSystemModel::setOptions, Arg("options"))
            .define_method("set_read_only", &QFileSystemModel::setReadOnly, Arg("enable"))
            .define_method("set_resolve_symlinks", &QFileSystemModel::setResolveSymlinks, Arg("enable"))
            .define_method("set_root_path", &QFileSystemModel::setRootPath, Arg("path"))
            .define_method("sibling", &QFileSystemModel::sibling, Arg("row"), Arg("column"), Arg("idx"))
            .define_method("size", &QFileSystemModel::size, Arg("index"))
            .define_method("sort", &QFileSystemModel::sort, Arg("column"), Arg("order") = static_cast<Qt::SortOrder>(Qt::AscendingOrder))
            .define_method("supported_drop_actions", &QFileSystemModel::supportedDropActions)
            .define_method("test_option", &QFileSystemModel::testOption, Arg("option"))
            .define_method("type", &QFileSystemModel::type, Arg("index"));
            // Signals
            // .define_method("directory_loaded", &QFileSystemModel::directoryLoaded, Arg("path"))
            // .define_method("file_renamed", &QFileSystemModel::fileRenamed, Arg("path"), Arg("old_name"), Arg("new_name"))
            // .define_method("root_path_changed", &QFileSystemModel::rootPathChanged, Arg("new_path"));

    Data_Type<QFileSystemModel::Roles> rb_cQFileSystemModelRoles =
        // RubyQt6::QtGui::QFileSystemModel::Roles
        define_qenum_under<QFileSystemModel::Roles>(rb_cQFileSystemModel, "Roles");
        define_qenum_value_under(rb_cQFileSystemModelRoles, "FileIconRole", QFileSystemModel::Roles::FileIconRole);
        define_qenum_value_under(rb_cQFileSystemModelRoles, "FileInfoRole", QFileSystemModel::Roles::FileInfoRole);

    Data_Type<QFileSystemModel::Option> rb_cQFileSystemModelOption =
        // RubyQt6::QtGui::QFileSystemModel::Option
        define_qenum_under<QFileSystemModel::Option>(rb_cQFileSystemModel, "Option");
        define_qenum_value_under(rb_cQFileSystemModelOption, "DontWatchForChanges", QFileSystemModel::Option::DontWatchForChanges);
        define_qenum_value_under(rb_cQFileSystemModelOption, "DontResolveSymlinks", QFileSystemModel::Option::DontResolveSymlinks);
        define_qenum_value_under(rb_cQFileSystemModelOption, "DontUseCustomDirectoryIcons", QFileSystemModel::Option::DontUseCustomDirectoryIcons);

    Data_Type<QFlags<QFileSystemModel::Option>> rb_cQFileSystemModelOptions =
        // RubyQt6::QtGui::QFileSystemModel::Options
        define_qflags_under<QFileSystemModel::Option>(rb_cQFileSystemModel, "Options");
}
