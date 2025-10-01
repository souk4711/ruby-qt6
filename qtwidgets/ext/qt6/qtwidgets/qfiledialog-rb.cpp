#include "qfiledialog-rb.hpp"
#include <qfiledialog.h>

#include <QAbstractItemDelegate>
#include <QAbstractFileIconProvider>
#include <QAbstractProxyModel>

using namespace Rice;

Rice::Class rb_cQFileDialog;

void Init_qfiledialog(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQFileDialog =
        // RubyQt6::QtWidgets::QFileDialog
        define_class_under<QFileDialog, QDialog>(rb_mQt6QtWidgets, "QFileDialog")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QFileDialog::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QFileDialog, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("accept_mode", &QFileDialog::acceptMode)
            .define_method("default_suffix", &QFileDialog::defaultSuffix)
            .define_method("directory", &QFileDialog::directory)
            .define_method("directory_url", &QFileDialog::directoryUrl)
            .define_method("file_mode", &QFileDialog::fileMode)
            .define_method("filter", &QFileDialog::filter)
            .define_method("history", &QFileDialog::history)
            .define_method("icon_provider", &QFileDialog::iconProvider)
            .define_method("item_delegate", &QFileDialog::itemDelegate)
            .define_method("label_text", &QFileDialog::labelText, Arg("label"))
            .define_method("mime_type_filters", &QFileDialog::mimeTypeFilters)
            .define_method("name_filters", &QFileDialog::nameFilters)
            .define_method<void (QFileDialog::*)(QObject *, const char *)>("open", &QFileDialog::open, Arg("receiver"), Arg("member"))
            .define_method("options", &QFileDialog::options)
            .define_method("proxy_model", &QFileDialog::proxyModel)
            .define_method("restore_state", &QFileDialog::restoreState, Arg("state"))
            .define_method("save_state", &QFileDialog::saveState)
            .define_method("select_file", &QFileDialog::selectFile, Arg("filename"))
            .define_method("select_mime_type_filter", &QFileDialog::selectMimeTypeFilter, Arg("filter"))
            .define_method("select_name_filter", &QFileDialog::selectNameFilter, Arg("filter"))
            .define_method("select_url", &QFileDialog::selectUrl, Arg("url"))
            .define_method("selected_files", &QFileDialog::selectedFiles)
            .define_method("selected_mime_type_filter", &QFileDialog::selectedMimeTypeFilter)
            .define_method("selected_name_filter", &QFileDialog::selectedNameFilter)
            .define_method("selected_urls", &QFileDialog::selectedUrls)
            .define_method("set_accept_mode", &QFileDialog::setAcceptMode, Arg("mode"))
            .define_method("set_default_suffix", &QFileDialog::setDefaultSuffix, Arg("suffix"))
            .define_method<void (QFileDialog::*)(const QDir &)>("set_directory", &QFileDialog::setDirectory, Arg("directory"))
            .define_method<void (QFileDialog::*)(const QString &)>("set_directory", &QFileDialog::setDirectory, Arg("directory"))
            .define_method("set_directory_url", &QFileDialog::setDirectoryUrl, Arg("directory"))
            .define_method("set_file_mode", &QFileDialog::setFileMode, Arg("mode"))
            .define_method("set_filter", &QFileDialog::setFilter, Arg("filters"))
            .define_method("set_history", &QFileDialog::setHistory, Arg("paths"))
            .define_method("set_icon_provider", &QFileDialog::setIconProvider, Arg("provider"))
            .define_method("set_item_delegate", &QFileDialog::setItemDelegate, Arg("delegate"))
            .define_method("set_label_text", &QFileDialog::setLabelText, Arg("label"), Arg("text"))
            .define_method("set_mime_type_filters", &QFileDialog::setMimeTypeFilters, Arg("filters"))
            .define_method("set_name_filter", &QFileDialog::setNameFilter, Arg("filter"))
            .define_method("set_name_filters", &QFileDialog::setNameFilters, Arg("filters"))
            .define_method("set_option", &QFileDialog::setOption, Arg("option"), Arg("on") = static_cast<bool>(true))
            .define_method("set_options", &QFileDialog::setOptions, Arg("options"))
            .define_method("set_proxy_model", &QFileDialog::setProxyModel, Arg("model"))
            .define_method("set_sidebar_urls", &QFileDialog::setSidebarUrls, Arg("urls"))
            .define_method("set_supported_schemes", &QFileDialog::setSupportedSchemes, Arg("schemes"))
            .define_method("set_view_mode", &QFileDialog::setViewMode, Arg("mode"))
            .define_method("set_visible", &QFileDialog::setVisible, Arg("visible"))
            .define_method("sidebar_urls", &QFileDialog::sidebarUrls)
            .define_method("supported_schemes", &QFileDialog::supportedSchemes)
            .define_method("test_option", &QFileDialog::testOption, Arg("option"))
            .define_method("view_mode", &QFileDialog::viewMode)
            // Signals
            .define_method("current_changed", &QFileDialog::currentChanged, Arg("path"))
            .define_method("current_url_changed", &QFileDialog::currentUrlChanged, Arg("url"))
            .define_method("directory_entered", &QFileDialog::directoryEntered, Arg("directory"))
            .define_method("directory_url_entered", &QFileDialog::directoryUrlEntered, Arg("directory"))
            .define_method("file_selected", &QFileDialog::fileSelected, Arg("file"))
            .define_method("files_selected", &QFileDialog::filesSelected, Arg("files"))
            .define_method("filter_selected", &QFileDialog::filterSelected, Arg("filter"))
            .define_method("url_selected", &QFileDialog::urlSelected, Arg("url"))
            .define_method("urls_selected", &QFileDialog::urlsSelected, Arg("urls"))
            // Static Public Members
            .define_singleton_function("get_existing_directory", &QFileDialog::getExistingDirectory, Arg("parent") = static_cast<QWidget *>(nullptr), Arg("caption") = static_cast<const QString &>(QString()), Arg("dir") = static_cast<const QString &>(QString()), Arg("options") = static_cast<QFileDialog::Options>(QFileDialog::Option::ShowDirsOnly))
            .define_singleton_function("get_existing_directory_url", &QFileDialog::getExistingDirectoryUrl, Arg("parent") = static_cast<QWidget *>(nullptr), Arg("caption") = static_cast<const QString &>(QString()), Arg("dir") = static_cast<const QUrl &>(QUrl()), Arg("options") = static_cast<QFileDialog::Options>(QFileDialog::Option::ShowDirsOnly), Arg("supported_schemes") = static_cast<const QStringList &>(QStringList()))
            .define_singleton_function("get_open_file_content", &QFileDialog::getOpenFileContent, Arg("name_filter"), Arg("file_contents_ready"), Arg("parent") = static_cast<QWidget *>(nullptr))
            .define_singleton_function("get_open_file_name", &QFileDialog::getOpenFileName, Arg("parent") = static_cast<QWidget *>(nullptr), Arg("caption") = static_cast<const QString &>(QString()), Arg("dir") = static_cast<const QString &>(QString()), Arg("filter") = static_cast<const QString &>(QString()), Arg("selected_filter") = static_cast<QString *>(nullptr), Arg("options") = static_cast<QFileDialog::Options>(QFileDialog::Options()))
            .define_singleton_function("get_open_file_names", &QFileDialog::getOpenFileNames, Arg("parent") = static_cast<QWidget *>(nullptr), Arg("caption") = static_cast<const QString &>(QString()), Arg("dir") = static_cast<const QString &>(QString()), Arg("filter") = static_cast<const QString &>(QString()), Arg("selected_filter") = static_cast<QString *>(nullptr), Arg("options") = static_cast<QFileDialog::Options>(QFileDialog::Options()))
            .define_singleton_function("get_open_file_url", &QFileDialog::getOpenFileUrl, Arg("parent") = static_cast<QWidget *>(nullptr), Arg("caption") = static_cast<const QString &>(QString()), Arg("dir") = static_cast<const QUrl &>(QUrl()), Arg("filter") = static_cast<const QString &>(QString()), Arg("selected_filter") = static_cast<QString *>(nullptr), Arg("options") = static_cast<QFileDialog::Options>(QFileDialog::Options()), Arg("supported_schemes") = static_cast<const QStringList &>(QStringList()))
            .define_singleton_function("get_open_file_urls", &QFileDialog::getOpenFileUrls, Arg("parent") = static_cast<QWidget *>(nullptr), Arg("caption") = static_cast<const QString &>(QString()), Arg("dir") = static_cast<const QUrl &>(QUrl()), Arg("filter") = static_cast<const QString &>(QString()), Arg("selected_filter") = static_cast<QString *>(nullptr), Arg("options") = static_cast<QFileDialog::Options>(QFileDialog::Options()), Arg("supported_schemes") = static_cast<const QStringList &>(QStringList()))
            .define_singleton_function("get_save_file_name", &QFileDialog::getSaveFileName, Arg("parent") = static_cast<QWidget *>(nullptr), Arg("caption") = static_cast<const QString &>(QString()), Arg("dir") = static_cast<const QString &>(QString()), Arg("filter") = static_cast<const QString &>(QString()), Arg("selected_filter") = static_cast<QString *>(nullptr), Arg("options") = static_cast<QFileDialog::Options>(QFileDialog::Options()))
            .define_singleton_function("get_save_file_url", &QFileDialog::getSaveFileUrl, Arg("parent") = static_cast<QWidget *>(nullptr), Arg("caption") = static_cast<const QString &>(QString()), Arg("dir") = static_cast<const QUrl &>(QUrl()), Arg("filter") = static_cast<const QString &>(QString()), Arg("selected_filter") = static_cast<QString *>(nullptr), Arg("options") = static_cast<QFileDialog::Options>(QFileDialog::Options()), Arg("supported_schemes") = static_cast<const QStringList &>(QStringList()))
            .define_singleton_function("save_file_content", &QFileDialog::saveFileContent, Arg("file_content"), Arg("file_name_hint"), Arg("parent") = static_cast<QWidget *>(nullptr));

    Enum<QFileDialog::AcceptMode> rb_cQFileDialogAcceptMode =
        // RubyQt6::QtWidgets::QFileDialog::AcceptMode
        define_enum_under<QFileDialog::AcceptMode>("AcceptMode", rb_cQFileDialog)
            .define_value("AcceptOpen", QFileDialog::AcceptMode::AcceptOpen)
            .define_value("AcceptSave", QFileDialog::AcceptMode::AcceptSave);

    Enum<QFileDialog::DialogLabel> rb_cQFileDialogDialogLabel =
        // RubyQt6::QtWidgets::QFileDialog::DialogLabel
        define_enum_under<QFileDialog::DialogLabel>("DialogLabel", rb_cQFileDialog)
            .define_value("LookIn", QFileDialog::DialogLabel::LookIn)
            .define_value("FileName", QFileDialog::DialogLabel::FileName)
            .define_value("FileType", QFileDialog::DialogLabel::FileType)
            .define_value("Accept", QFileDialog::DialogLabel::Accept)
            .define_value("Reject", QFileDialog::DialogLabel::Reject);

    Enum<QFileDialog::FileMode> rb_cQFileDialogFileMode =
        // RubyQt6::QtWidgets::QFileDialog::FileMode
        define_enum_under<QFileDialog::FileMode>("FileMode", rb_cQFileDialog)
            .define_value("AnyFile", QFileDialog::FileMode::AnyFile)
            .define_value("ExistingFile", QFileDialog::FileMode::ExistingFile)
            .define_value("Directory", QFileDialog::FileMode::Directory)
            .define_value("ExistingFiles", QFileDialog::FileMode::ExistingFiles);

   Enum<QFileDialog::Option> rb_cQFileDialogOption =
        // RubyQt6::QtWidgets::QFileDialog::Option
        define_enum_under<QFileDialog::Option>("Option", rb_cQFileDialog)
            .define_value("ShowDirsOnly", QFileDialog::Option::ShowDirsOnly)
            .define_value("DontResolveSymlinks", QFileDialog::Option::DontResolveSymlinks)
            .define_value("DontConfirmOverwrite", QFileDialog::Option::DontConfirmOverwrite)
            .define_value("DontUseNativeDialog", QFileDialog::Option::DontUseNativeDialog)
            .define_value("ReadOnly", QFileDialog::Option::ReadOnly)
            .define_value("HideNameFilterDetails", QFileDialog::Option::HideNameFilterDetails)
            .define_value("DontUseCustomDirectoryIcons", QFileDialog::Option::DontUseCustomDirectoryIcons);

    Enum<QFileDialog::ViewMode> rb_cQFileDialogViewMode =
        // RubyQt6::QtWidgets::QFileDialog::ViewMode
        define_enum_under<QFileDialog::ViewMode>("ViewMode", rb_cQFileDialog)
            .define_value("Detail", QFileDialog::ViewMode::Detail)
            .define_value("List", QFileDialog::ViewMode::List);
}
