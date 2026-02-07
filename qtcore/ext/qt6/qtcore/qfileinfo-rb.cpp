#include "qfileinfo-rb.hpp"
#include <qfileinfo.h>

#include <QDir>
#include <QFileDevice>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQFileInfo;

void Init_qfileinfo(Module rb_mQt6QtCore)
{
    rb_cQFileInfo =
        // RubyQt6::QtCore::QFileInfo
        define_class_under<QFileInfo>(rb_mQt6QtCore, "QFileInfo")
            // Constructor
            .define_constructor(Constructor<QFileInfo>())
            .define_constructor(Constructor<QFileInfo, const QString &>(), Arg("file"))
            .define_constructor(Constructor<QFileInfo, const QFileDevice &>(), Arg("file"))
            .define_constructor(Constructor<QFileInfo, const QDir &, const QString &>(), Arg("dir"), Arg("file"))
            .define_constructor(Constructor<QFileInfo, const QFileInfo &>(), Arg("other"))
            // Public Functions
            .define_method("absolute_dir", &QFileInfo::absoluteDir)
            .define_method("absolute_file_path", &QFileInfo::absoluteFilePath)
            .define_method("absolute_path", &QFileInfo::absolutePath)
            .define_method("base_name", &QFileInfo::baseName)
            .define_method<QDateTime (QFileInfo::*)() const>("birth_time", &QFileInfo::birthTime)
            .define_method<QDateTime (QFileInfo::*)(const QTimeZone &) const>("birth_time", &QFileInfo::birthTime, Arg("tz"))
            .define_method("bundle_name", &QFileInfo::bundleName)
            .define_method("caching", &QFileInfo::caching)
            .define_method("canonical_file_path", &QFileInfo::canonicalFilePath)
            .define_method("canonical_path", &QFileInfo::canonicalPath)
            .define_method("complete_base_name", &QFileInfo::completeBaseName)
            .define_method("complete_suffix", &QFileInfo::completeSuffix)
            .define_method("dir", &QFileInfo::dir)
            .define_method<bool (QFileInfo::*)() const>("exists", &QFileInfo::exists)
            .define_method("file_name", &QFileInfo::fileName)
            .define_method("file_path", &QFileInfo::filePath)
            .define_method<QDateTime (QFileInfo::*)(QFileDevice::FileTime) const>("file_time", &QFileInfo::fileTime, Arg("time"))
            .define_method<QDateTime (QFileInfo::*)(QFileDevice::FileTime, const QTimeZone &) const>("file_time", &QFileInfo::fileTime, Arg("time"), Arg("tz"))
            .define_method("filesystem_absolute_file_path", &QFileInfo::filesystemAbsoluteFilePath)
            .define_method("filesystem_absolute_path", &QFileInfo::filesystemAbsolutePath)
            .define_method("filesystem_canonical_file_path", &QFileInfo::filesystemCanonicalFilePath)
            .define_method("filesystem_canonical_path", &QFileInfo::filesystemCanonicalPath)
            .define_method("filesystem_file_path", &QFileInfo::filesystemFilePath)
            .define_method("filesystem_junction_target", &QFileInfo::filesystemJunctionTarget)
            .define_method("filesystem_path", &QFileInfo::filesystemPath)
            .define_method("filesystem_read_sym_link", &QFileInfo::filesystemReadSymLink)
            .define_method("filesystem_sym_link_target", &QFileInfo::filesystemSymLinkTarget)
            .define_method("group", &QFileInfo::group)
            .define_method("group_id", &QFileInfo::groupId)
            .define_method("absolute?", &QFileInfo::isAbsolute)
            .define_method("alias?", &QFileInfo::isAlias)
            .define_method("bundle?", &QFileInfo::isBundle)
            .define_method("dir?", &QFileInfo::isDir)
            .define_method("executable?", &QFileInfo::isExecutable)
            .define_method("file?", &QFileInfo::isFile)
            .define_method("hidden?", &QFileInfo::isHidden)
            .define_method("junction?", &QFileInfo::isJunction)
            .define_method("native_path?", &QFileInfo::isNativePath)
            .define_method("readable?", &QFileInfo::isReadable)
            .define_method("relative?", &QFileInfo::isRelative)
            .define_method("root?", &QFileInfo::isRoot)
            .define_method("shortcut?", &QFileInfo::isShortcut)
            .define_method("sym_link?", &QFileInfo::isSymLink)
            .define_method("symbolic_link?", &QFileInfo::isSymbolicLink)
            .define_method("writable?", &QFileInfo::isWritable)
            .define_method("junction_target", &QFileInfo::junctionTarget)
            .define_method<QDateTime (QFileInfo::*)() const>("last_modified", &QFileInfo::lastModified)
            .define_method<QDateTime (QFileInfo::*)(const QTimeZone &) const>("last_modified", &QFileInfo::lastModified, Arg("tz"))
            .define_method<QDateTime (QFileInfo::*)() const>("last_read", &QFileInfo::lastRead)
            .define_method<QDateTime (QFileInfo::*)(const QTimeZone &) const>("last_read", &QFileInfo::lastRead, Arg("tz"))
            .define_method("make_absolute", &QFileInfo::makeAbsolute)
            .define_method<QDateTime (QFileInfo::*)() const>("metadata_change_time", &QFileInfo::metadataChangeTime)
            .define_method<QDateTime (QFileInfo::*)(const QTimeZone &) const>("metadata_change_time", &QFileInfo::metadataChangeTime, Arg("tz"))
            .define_method("owner", &QFileInfo::owner)
            .define_method("owner_id", &QFileInfo::ownerId)
            .define_method("path", &QFileInfo::path)
            .define_method("permission", &QFileInfo::permission, Arg("permissions"))
            .define_method("permissions", &QFileInfo::permissions)
            .define_method("read_sym_link", &QFileInfo::readSymLink)
            .define_method("refresh", &QFileInfo::refresh)
            .define_method("set_caching", &QFileInfo::setCaching, Arg("on"))
            .define_method<void (QFileInfo::*)(const QDir &, const QString &)>("set_file", &QFileInfo::setFile, Arg("dir"), Arg("file"))
            .define_method<void (QFileInfo::*)(const QFileDevice &)>("set_file", &QFileInfo::setFile, Arg("file"))
            .define_method<void (QFileInfo::*)(const QString &)>("set_file", &QFileInfo::setFile, Arg("file"))
            .define_method("size", &QFileInfo::size)
            .define_method("stat", &QFileInfo::stat)
            .define_method("suffix", &QFileInfo::suffix)
            .define_method("sym_link_target", &QFileInfo::symLinkTarget)
            // Static Public Members
            .define_singleton_function<bool (*)(const QString &)>("exists", &QFileInfo::exists, Arg("file"));
}
