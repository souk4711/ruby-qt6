#include "qfiledialog-rb.hpp"
#include <qfiledialog.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

#include <QAbstractItemDelegate>
#include <QAbstractFileIconProvider>
#include <QAbstractProxyModel>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQFileDialog;

void Init_qfiledialog(Module rb_mQt6QtWidgets)
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
            .define_method("_select_file", &QFileDialog::selectFile, Arg("filename"))
            .define_method("_select_mime_type_filter", &QFileDialog::selectMimeTypeFilter, Arg("filter"))
            .define_method("_select_name_filter", &QFileDialog::selectNameFilter, Arg("filter"))
            .define_method("select_url", &QFileDialog::selectUrl, Arg("url"))
            .define_method("selected_files", &QFileDialog::selectedFiles)
            .define_method("selected_mime_type_filter", &QFileDialog::selectedMimeTypeFilter)
            .define_method("selected_name_filter", &QFileDialog::selectedNameFilter)
            .define_method("selected_urls", &QFileDialog::selectedUrls)
            .define_method("set_accept_mode", &QFileDialog::setAcceptMode, Arg("mode"))
            .define_method("_set_default_suffix", &QFileDialog::setDefaultSuffix, Arg("suffix"))
            .define_method<void (QFileDialog::*)(const QDir &)>("_set_directory", &QFileDialog::setDirectory, Arg("directory"))
            .define_method<void (QFileDialog::*)(const QString &)>("_set_directory", &QFileDialog::setDirectory, Arg("directory"))
            .define_method("set_directory_url", &QFileDialog::setDirectoryUrl, Arg("directory"))
            .define_method("set_file_mode", &QFileDialog::setFileMode, Arg("mode"))
            .define_method("set_filter", &QFileDialog::setFilter, Arg("filters"))
            .define_method("set_history", &QFileDialog::setHistory, Arg("paths"))
            .define_method("set_icon_provider", &QFileDialog::setIconProvider, Arg("provider"))
            .define_method("set_item_delegate", &QFileDialog::setItemDelegate, Arg("delegate"))
            .define_method("set_label_text", &QFileDialog::setLabelText, Arg("label"), Arg("text"))
            .define_method("set_mime_type_filters", &QFileDialog::setMimeTypeFilters, Arg("filters"))
            .define_method("_set_name_filter", &QFileDialog::setNameFilter, Arg("filter"))
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
            // .define_method("current_changed", &QFileDialog::currentChanged, Arg("path"))
            // .define_method("current_url_changed", &QFileDialog::currentUrlChanged, Arg("url"))
            // .define_method("directory_entered", &QFileDialog::directoryEntered, Arg("directory"))
            // .define_method("directory_url_entered", &QFileDialog::directoryUrlEntered, Arg("directory"))
            // .define_method("file_selected", &QFileDialog::fileSelected, Arg("file"))
            // .define_method("files_selected", &QFileDialog::filesSelected, Arg("files"))
            // .define_method("filter_selected", &QFileDialog::filterSelected, Arg("filter"))
            // .define_method("url_selected", &QFileDialog::urlSelected, Arg("url"))
            // .define_method("urls_selected", &QFileDialog::urlsSelected, Arg("urls"))
            // Static Public Members
            .define_singleton_function("_get_existing_directory", &QFileDialog::getExistingDirectory, Arg("parent") = static_cast<QWidget *>(nullptr), Arg("caption") = static_cast<const QString &>(QString()), Arg("dir") = static_cast<const QString &>(QString()), Arg("options") = static_cast<QFileDialog::Options>(QFileDialog::Option::ShowDirsOnly))
            .define_singleton_function("get_existing_directory_url", &QFileDialog::getExistingDirectoryUrl, Arg("parent") = static_cast<QWidget *>(nullptr), Arg("caption") = static_cast<const QString &>(QString()), Arg("dir") = static_cast<const QUrl &>(QUrl()), Arg("options") = static_cast<QFileDialog::Options>(QFileDialog::Option::ShowDirsOnly), Arg("supported_schemes") = static_cast<const QStringList &>(QStringList()))
            .define_singleton_function("_get_open_file_name", &QFileDialog::getOpenFileName, Arg("parent") = static_cast<QWidget *>(nullptr), Arg("caption") = static_cast<const QString &>(QString()), Arg("dir") = static_cast<const QString &>(QString()), Arg("filter") = static_cast<const QString &>(QString()), Arg("selected_filter") = static_cast<QString *>(nullptr), Arg("options") = static_cast<QFileDialog::Options>(QFileDialog::Options()))
            .define_singleton_function("_get_open_file_names", &QFileDialog::getOpenFileNames, Arg("parent") = static_cast<QWidget *>(nullptr), Arg("caption") = static_cast<const QString &>(QString()), Arg("dir") = static_cast<const QString &>(QString()), Arg("filter") = static_cast<const QString &>(QString()), Arg("selected_filter") = static_cast<QString *>(nullptr), Arg("options") = static_cast<QFileDialog::Options>(QFileDialog::Options()))
            .define_singleton_function("_get_save_file_name", &QFileDialog::getSaveFileName, Arg("parent") = static_cast<QWidget *>(nullptr), Arg("caption") = static_cast<const QString &>(QString()), Arg("dir") = static_cast<const QString &>(QString()), Arg("filter") = static_cast<const QString &>(QString()), Arg("selected_filter") = static_cast<QString *>(nullptr), Arg("options") = static_cast<QFileDialog::Options>(QFileDialog::Options()))
            .define_singleton_function("get_open_file_url", &QFileDialog::getOpenFileUrl, Arg("parent") = static_cast<QWidget *>(nullptr), Arg("caption") = static_cast<const QString &>(QString()), Arg("dir") = static_cast<const QUrl &>(QUrl()), Arg("filter") = static_cast<const QString &>(QString()), Arg("selected_filter") = static_cast<QString *>(nullptr), Arg("options") = static_cast<QFileDialog::Options>(QFileDialog::Options()), Arg("supported_schemes") = static_cast<const QStringList &>(QStringList()))
            .define_singleton_function("get_open_file_urls", &QFileDialog::getOpenFileUrls, Arg("parent") = static_cast<QWidget *>(nullptr), Arg("caption") = static_cast<const QString &>(QString()), Arg("dir") = static_cast<const QUrl &>(QUrl()), Arg("filter") = static_cast<const QString &>(QString()), Arg("selected_filter") = static_cast<QString *>(nullptr), Arg("options") = static_cast<QFileDialog::Options>(QFileDialog::Options()), Arg("supported_schemes") = static_cast<const QStringList &>(QStringList()))
            .define_singleton_function("get_save_file_url", &QFileDialog::getSaveFileUrl, Arg("parent") = static_cast<QWidget *>(nullptr), Arg("caption") = static_cast<const QString &>(QString()), Arg("dir") = static_cast<const QUrl &>(QUrl()), Arg("filter") = static_cast<const QString &>(QString()), Arg("selected_filter") = static_cast<QString *>(nullptr), Arg("options") = static_cast<QFileDialog::Options>(QFileDialog::Options()), Arg("supported_schemes") = static_cast<const QStringList &>(QStringList()))
            .define_singleton_function("get_open_file_content", &QFileDialog::getOpenFileContent, Arg("name_filter"), Arg("file_contents_ready"), Arg("parent") = static_cast<QWidget *>(nullptr))
            .define_singleton_function("save_file_content", &QFileDialog::saveFileContent, Arg("file_content"), Arg("file_name_hint"), Arg("parent") = static_cast<QWidget *>(nullptr));

    Data_Type<QFileDialog::AcceptMode> rb_cQFileDialogAcceptMode =
        // RubyQt6::QtWidgets::QFileDialog::AcceptMode
        define_qenum_under<QFileDialog::AcceptMode>(rb_cQFileDialog, "AcceptMode");
        define_qenum_value_under(rb_cQFileDialogAcceptMode, "AcceptOpen", QFileDialog::AcceptMode::AcceptOpen);
        define_qenum_value_under(rb_cQFileDialogAcceptMode, "AcceptSave", QFileDialog::AcceptMode::AcceptSave);

    Data_Type<QFileDialog::DialogLabel> rb_cQFileDialogDialogLabel =
        // RubyQt6::QtWidgets::QFileDialog::DialogLabel
        define_qenum_under<QFileDialog::DialogLabel>(rb_cQFileDialog, "DialogLabel");
        define_qenum_value_under(rb_cQFileDialogDialogLabel, "LookIn", QFileDialog::DialogLabel::LookIn);
        define_qenum_value_under(rb_cQFileDialogDialogLabel, "FileName", QFileDialog::DialogLabel::FileName);
        define_qenum_value_under(rb_cQFileDialogDialogLabel, "FileType", QFileDialog::DialogLabel::FileType);
        define_qenum_value_under(rb_cQFileDialogDialogLabel, "Accept", QFileDialog::DialogLabel::Accept);
        define_qenum_value_under(rb_cQFileDialogDialogLabel, "Reject", QFileDialog::DialogLabel::Reject);

    Data_Type<QFileDialog::FileMode> rb_cQFileDialogFileMode =
        // RubyQt6::QtWidgets::QFileDialog::FileMode
        define_qenum_under<QFileDialog::FileMode>(rb_cQFileDialog, "FileMode");
        define_qenum_value_under(rb_cQFileDialogFileMode, "AnyFile", QFileDialog::FileMode::AnyFile);
        define_qenum_value_under(rb_cQFileDialogFileMode, "ExistingFile", QFileDialog::FileMode::ExistingFile);
        define_qenum_value_under(rb_cQFileDialogFileMode, "Directory", QFileDialog::FileMode::Directory);
        define_qenum_value_under(rb_cQFileDialogFileMode, "ExistingFiles", QFileDialog::FileMode::ExistingFiles);

   Data_Type<QFileDialog::Option> rb_cQFileDialogOption =
        // RubyQt6::QtWidgets::QFileDialog::Option
        define_qenum_under<QFileDialog::Option>(rb_cQFileDialog, "Option");
        define_qenum_value_under(rb_cQFileDialogOption, "ShowDirsOnly", QFileDialog::Option::ShowDirsOnly);
        define_qenum_value_under(rb_cQFileDialogOption, "DontResolveSymlinks", QFileDialog::Option::DontResolveSymlinks);
        define_qenum_value_under(rb_cQFileDialogOption, "DontConfirmOverwrite", QFileDialog::Option::DontConfirmOverwrite);
        define_qenum_value_under(rb_cQFileDialogOption, "DontUseNativeDialog", QFileDialog::Option::DontUseNativeDialog);
        define_qenum_value_under(rb_cQFileDialogOption, "ReadOnly", QFileDialog::Option::ReadOnly);
        define_qenum_value_under(rb_cQFileDialogOption, "HideNameFilterDetails", QFileDialog::Option::HideNameFilterDetails);
        define_qenum_value_under(rb_cQFileDialogOption, "DontUseCustomDirectoryIcons", QFileDialog::Option::DontUseCustomDirectoryIcons);

    Data_Type<QFileDialog::ViewMode> rb_cQFileDialogViewMode =
        // RubyQt6::QtWidgets::QFileDialog::ViewMode
        define_qenum_under<QFileDialog::ViewMode>(rb_cQFileDialog, "ViewMode");
        define_qenum_value_under(rb_cQFileDialogViewMode, "Detail", QFileDialog::ViewMode::Detail);
        define_qenum_value_under(rb_cQFileDialogViewMode, "List", QFileDialog::ViewMode::List);

    Data_Type<QFlags<QFileDialog::Option>> rb_cQFileDialogOptions =
        // RubyQt6::QtWidgets::QFileDialog::Options
        define_qflags_under<QFileDialog::Option>(rb_cQFileDialog, "Options");
}
