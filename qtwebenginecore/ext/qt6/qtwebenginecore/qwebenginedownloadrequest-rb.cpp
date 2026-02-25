#include "qwebenginedownloadrequest-rb.hpp"
#include <qwebenginedownloadrequest.h>
#include <rice/qt6/qenum.hpp>

#include <QWebEnginePage>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQWebEngineDownloadRequest;

void Init_qwebenginedownloadrequest(Module rb_mQt6QtWebEngineCore)
{
    rb_cQWebEngineDownloadRequest =
        // RubyQt6::QtWebEngineCore::QWebEngineDownloadRequest
        define_qlass_under<QWebEngineDownloadRequest, QObject>(rb_mQt6QtWebEngineCore, "QWebEngineDownloadRequest")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QWebEngineDownloadRequest * { return qobject_cast<QWebEngineDownloadRequest *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QWebEngineDownloadRequest::staticMetaObject; })
            // Public Functions
            .define_method("download_directory", &QWebEngineDownloadRequest::downloadDirectory)
            .define_method("download_file_name", &QWebEngineDownloadRequest::downloadFileName)
            .define_method("id", &QWebEngineDownloadRequest::id)
            .define_method("interrupt_reason", &QWebEngineDownloadRequest::interruptReason)
            .define_method("interrupt_reason_string", &QWebEngineDownloadRequest::interruptReasonString)
            .define_method("finished?", &QWebEngineDownloadRequest::isFinished)
            .define_method("paused?", &QWebEngineDownloadRequest::isPaused)
            .define_method("save_page_download?", &QWebEngineDownloadRequest::isSavePageDownload)
            .define_method("mime_type", &QWebEngineDownloadRequest::mimeType)
            .define_method("page", &QWebEngineDownloadRequest::page)
            .define_method("received_bytes", &QWebEngineDownloadRequest::receivedBytes)
            .define_method("save_page_format", &QWebEngineDownloadRequest::savePageFormat)
            .define_method("set_download_directory", &QWebEngineDownloadRequest::setDownloadDirectory, Arg("directory"))
            .define_method("set_download_file_name", &QWebEngineDownloadRequest::setDownloadFileName, Arg("file_name"))
            .define_method("set_save_page_format", &QWebEngineDownloadRequest::setSavePageFormat, Arg("format"))
            .define_method("state", &QWebEngineDownloadRequest::state)
            .define_method("suggested_file_name", &QWebEngineDownloadRequest::suggestedFileName)
            .define_method("total_bytes", &QWebEngineDownloadRequest::totalBytes)
            .define_method("url", &QWebEngineDownloadRequest::url)
            // Public Slots
            .define_method("accept", &QWebEngineDownloadRequest::accept)
            .define_method("cancel", &QWebEngineDownloadRequest::cancel)
            .define_method("pause", &QWebEngineDownloadRequest::pause)
            .define_method("resume", &QWebEngineDownloadRequest::resume);
            // Signals
            // .define_method("download_directory_changed", &QWebEngineDownloadRequest::downloadDirectoryChanged)
            // .define_method("download_file_name_changed", &QWebEngineDownloadRequest::downloadFileNameChanged)
            // .define_method("interrupt_reason_changed", &QWebEngineDownloadRequest::interruptReasonChanged)
            // .define_method("is_finished_changed", &QWebEngineDownloadRequest::isFinishedChanged)
            // .define_method("is_paused_changed", &QWebEngineDownloadRequest::isPausedChanged)
            // .define_method("received_bytes_changed", &QWebEngineDownloadRequest::receivedBytesChanged)
            // .define_method("save_page_format_changed", &QWebEngineDownloadRequest::savePageFormatChanged)
            // .define_method("state_changed", &QWebEngineDownloadRequest::stateChanged, Arg("state"))
            // .define_method("total_bytes_changed", &QWebEngineDownloadRequest::totalBytesChanged);

    Data_Type<QWebEngineDownloadRequest::DownloadState> rb_cQWebEngineDownloadRequestDownloadState =
        // RubyQt6::QtWebEngineCore::QWebEngineDownloadRequest::DownloadState
        define_qenum_under<QWebEngineDownloadRequest::DownloadState>(rb_cQWebEngineDownloadRequest, "DownloadState");
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadState, "DownloadRequested", QWebEngineDownloadRequest::DownloadState::DownloadRequested);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadState, "DownloadInProgress", QWebEngineDownloadRequest::DownloadState::DownloadInProgress);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadState, "DownloadCompleted", QWebEngineDownloadRequest::DownloadState::DownloadCompleted);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadState, "DownloadCancelled", QWebEngineDownloadRequest::DownloadState::DownloadCancelled);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadState, "DownloadInterrupted", QWebEngineDownloadRequest::DownloadState::DownloadInterrupted);

    Data_Type<QWebEngineDownloadRequest::SavePageFormat> rb_cQWebEngineDownloadRequestSavePageFormat =
        // RubyQt6::QtWebEngineCore::QWebEngineDownloadRequest::SavePageFormat
        define_qenum_under<QWebEngineDownloadRequest::SavePageFormat>(rb_cQWebEngineDownloadRequest, "SavePageFormat");
        define_qenum_value_under(rb_cQWebEngineDownloadRequestSavePageFormat, "UnknownSaveFormat", QWebEngineDownloadRequest::SavePageFormat::UnknownSaveFormat);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestSavePageFormat, "SingleHtmlSaveFormat", QWebEngineDownloadRequest::SavePageFormat::SingleHtmlSaveFormat);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestSavePageFormat, "CompleteHtmlSaveFormat", QWebEngineDownloadRequest::SavePageFormat::CompleteHtmlSaveFormat);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestSavePageFormat, "MimeHtmlSaveFormat", QWebEngineDownloadRequest::SavePageFormat::MimeHtmlSaveFormat);

    Data_Type<QWebEngineDownloadRequest::DownloadInterruptReason> rb_cQWebEngineDownloadRequestDownloadInterruptReason =
        // RubyQt6::QtWebEngineCore::QWebEngineDownloadRequest::DownloadInterruptReason
        define_qenum_under<QWebEngineDownloadRequest::DownloadInterruptReason>(rb_cQWebEngineDownloadRequest, "DownloadInterruptReason");
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadInterruptReason, "NoReason", QWebEngineDownloadRequest::DownloadInterruptReason::NoReason);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadInterruptReason, "FileFailed", QWebEngineDownloadRequest::DownloadInterruptReason::FileFailed);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadInterruptReason, "FileAccessDenied", QWebEngineDownloadRequest::DownloadInterruptReason::FileAccessDenied);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadInterruptReason, "FileNoSpace", QWebEngineDownloadRequest::DownloadInterruptReason::FileNoSpace);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadInterruptReason, "FileNameTooLong", QWebEngineDownloadRequest::DownloadInterruptReason::FileNameTooLong);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadInterruptReason, "FileTooLarge", QWebEngineDownloadRequest::DownloadInterruptReason::FileTooLarge);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadInterruptReason, "FileVirusInfected", QWebEngineDownloadRequest::DownloadInterruptReason::FileVirusInfected);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadInterruptReason, "FileTransientError", QWebEngineDownloadRequest::DownloadInterruptReason::FileTransientError);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadInterruptReason, "FileBlocked", QWebEngineDownloadRequest::DownloadInterruptReason::FileBlocked);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadInterruptReason, "FileSecurityCheckFailed", QWebEngineDownloadRequest::DownloadInterruptReason::FileSecurityCheckFailed);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadInterruptReason, "FileTooShort", QWebEngineDownloadRequest::DownloadInterruptReason::FileTooShort);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadInterruptReason, "FileHashMismatch", QWebEngineDownloadRequest::DownloadInterruptReason::FileHashMismatch);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadInterruptReason, "NetworkFailed", QWebEngineDownloadRequest::DownloadInterruptReason::NetworkFailed);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadInterruptReason, "NetworkTimeout", QWebEngineDownloadRequest::DownloadInterruptReason::NetworkTimeout);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadInterruptReason, "NetworkDisconnected", QWebEngineDownloadRequest::DownloadInterruptReason::NetworkDisconnected);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadInterruptReason, "NetworkServerDown", QWebEngineDownloadRequest::DownloadInterruptReason::NetworkServerDown);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadInterruptReason, "NetworkInvalidRequest", QWebEngineDownloadRequest::DownloadInterruptReason::NetworkInvalidRequest);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadInterruptReason, "ServerFailed", QWebEngineDownloadRequest::DownloadInterruptReason::ServerFailed);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadInterruptReason, "ServerBadContent", QWebEngineDownloadRequest::DownloadInterruptReason::ServerBadContent);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadInterruptReason, "ServerUnauthorized", QWebEngineDownloadRequest::DownloadInterruptReason::ServerUnauthorized);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadInterruptReason, "ServerCertProblem", QWebEngineDownloadRequest::DownloadInterruptReason::ServerCertProblem);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadInterruptReason, "ServerForbidden", QWebEngineDownloadRequest::DownloadInterruptReason::ServerForbidden);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadInterruptReason, "ServerUnreachable", QWebEngineDownloadRequest::DownloadInterruptReason::ServerUnreachable);
        define_qenum_value_under(rb_cQWebEngineDownloadRequestDownloadInterruptReason, "UserCanceled", QWebEngineDownloadRequest::DownloadInterruptReason::UserCanceled);
}
