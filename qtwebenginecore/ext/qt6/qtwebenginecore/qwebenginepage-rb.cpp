#include "qwebenginepage-rb.hpp"
#include <qwebenginepage.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

#include <QAction>
#include <QEvent>
#include <QWebEngineCertificateError>
#include <QWebEngineDesktopMediaRequest>
#include <QWebEngineFileSystemAccessRequest>
#include <QWebEngineFindTextResult>
#include <QWebEngineFullScreenRequest>
#include <QWebEngineHistory>
#include <QWebEngineHttpRequest>
#include <QWebEngineLoadingInfo>
#include <QWebEngineNavigationRequest>
#include <QWebEngineNewWindowRequest>
#include <QWebEngineProfile>
#include <QWebEngineRegisterProtocolHandlerRequest>
#include <QWebEngineScriptCollection>
#include <QWebEngineSettings>
#include <QWebEngineUrlRequestInterceptor>
#include <QWebEngineWebAuthUxRequest>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQWebEnginePage;

void Init_qwebenginepage(Module rb_mQt6QtWebEngineCore)
{
    rb_cQWebEnginePage =
        // RubyQt6::QtWebEngineCore::QWebEnginePage
        define_qlass_under<QWebEnginePage, QObject>(rb_mQt6QtWebEngineCore, "QWebEnginePage")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QWebEnginePage * { return qobject_cast<QWebEnginePage *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QWebEnginePage::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QWebEnginePage, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("accept_as_new_window", &QWebEnginePage::acceptAsNewWindow, Arg("request"))
            .define_method("action", &QWebEnginePage::action, Arg("action"))
            .define_method("background_color", &QWebEnginePage::backgroundColor)
            .define_method("contents_size", &QWebEnginePage::contentsSize)
            .define_method("dev_tools_id", &QWebEnginePage::devToolsId)
            .define_method("dev_tools_page", &QWebEnginePage::devToolsPage)
            .define_method("download", &QWebEnginePage::download, Arg("url"), Arg("filename") = static_cast<const QString &>(QString()))
            .define_method("find_frame_by_name", &QWebEnginePage::findFrameByName, Arg("name"))
            .define_method("has_selection", &QWebEnginePage::hasSelection)
            .define_method("history", &QWebEnginePage::history)
            .define_method("icon", &QWebEnginePage::icon)
            .define_method("icon_url", &QWebEnginePage::iconUrl)
            .define_method("inspected_page", &QWebEnginePage::inspectedPage)
            .define_method("audio_muted?", &QWebEnginePage::isAudioMuted)
            .define_method("loading?", &QWebEnginePage::isLoading)
            .define_method("visible?", &QWebEnginePage::isVisible)
            .define_method("lifecycle_state", &QWebEnginePage::lifecycleState)
            .define_method<void (QWebEnginePage::*)(const QUrl &)>("load", &QWebEnginePage::load, Arg("url"))
            .define_method<void (QWebEnginePage::*)(const QWebEngineHttpRequest &)>("load", &QWebEnginePage::load, Arg("request"))
            .define_method("main_frame", &QWebEnginePage::mainFrame)
            .define_method<void (QWebEnginePage::*)(const QString &, const QPageLayout &, const QPageRanges &)>("print_to_pdf", &QWebEnginePage::printToPdf, Arg("file_path"), Arg("layout") = static_cast<const QPageLayout &>(QPageLayout(QPageSize(QPageSize::A4), QPageLayout::Portrait, QMarginsF())), Arg("ranges") = static_cast<const QPageRanges &>(QPageRanges {}))
            .define_method("profile", &QWebEnginePage::profile)
            .define_method("recently_audible", &QWebEnginePage::recentlyAudible)
            .define_method("recommended_state", &QWebEnginePage::recommendedState)
            .define_method("render_process_pid", &QWebEnginePage::renderProcessPid)
            .define_method("replace_misspelled_word", &QWebEnginePage::replaceMisspelledWord, Arg("replacement"))
            .define_method("requested_url", &QWebEnginePage::requestedUrl)
            .define_method("save", &QWebEnginePage::save, Arg("file_path"), Arg("format") = static_cast<QWebEngineDownloadRequest::SavePageFormat>(QWebEngineDownloadRequest::MimeHtmlSaveFormat))
            .define_method("scripts", &QWebEnginePage::scripts)
            .define_method("scroll_position", &QWebEnginePage::scrollPosition)
            .define_method("selected_text", &QWebEnginePage::selectedText)
            .define_method("set_audio_muted", &QWebEnginePage::setAudioMuted, Arg("muted"))
            .define_method("set_background_color", &QWebEnginePage::setBackgroundColor, Arg("color"))
            .define_method("set_content", &QWebEnginePage::setContent, Arg("data"), Arg("mime_type") = static_cast<const QString &>(QString()), Arg("base_url") = static_cast<const QUrl &>(QUrl()))
            .define_method("set_dev_tools_page", &QWebEnginePage::setDevToolsPage, Arg("page"))
            .define_method("set_html", &QWebEnginePage::setHtml, Arg("html"), Arg("base_url") = static_cast<const QUrl &>(QUrl()))
            .define_method("set_inspected_page", &QWebEnginePage::setInspectedPage, Arg("page"))
            .define_method("set_lifecycle_state", &QWebEnginePage::setLifecycleState, Arg("state"))
            .define_method("set_url", &QWebEnginePage::setUrl, Arg("url"))
            .define_method("set_url_request_interceptor", &QWebEnginePage::setUrlRequestInterceptor, Arg("interceptor"))
            .define_method("set_visible", &QWebEnginePage::setVisible, Arg("visible"))
            // .define_method("set_web_channel", &QWebEnginePage::setWebChannel, Arg(""), Arg("world_id") = static_cast<quint32>(0))
            .define_method("set_zoom_factor", &QWebEnginePage::setZoomFactor, Arg("factor"))
            .define_method("settings", &QWebEnginePage::settings)
            .define_method("title", &QWebEnginePage::title)
            .define_method("to_html", &QWebEnginePage::toHtml, Arg("result_callback"))
            .define_method("to_plain_text", &QWebEnginePage::toPlainText, Arg("result_callback"))
            .define_method("trigger_action", &QWebEnginePage::triggerAction, Arg("action"), Arg("checked") = static_cast<bool>(false))
            .define_method("url", &QWebEnginePage::url)
            // .define_method("web_channel", &QWebEnginePage::webChannel)
            .define_method("zoom_factor", &QWebEnginePage::zoomFactor);
            // Signals
            // .define_method("audio_muted_changed", &QWebEnginePage::audioMutedChanged, Arg("muted"))
            // .define_method("authentication_required", &QWebEnginePage::authenticationRequired, Arg("request_url"), Arg("authenticator"))
            // .define_method("certificate_error", &QWebEnginePage::certificateError, Arg("certificate_error"))
            // .define_method("contents_size_changed", &QWebEnginePage::contentsSizeChanged, Arg("size"))
            // .define_method("desktop_media_requested", &QWebEnginePage::desktopMediaRequested, Arg("request"))
            // .define_method("file_system_access_requested", &QWebEnginePage::fileSystemAccessRequested, Arg("request"))
            // .define_method("find_text_finished", &QWebEnginePage::findTextFinished, Arg("result"))
            // .define_method("full_screen_requested", &QWebEnginePage::fullScreenRequested, Arg("full_screen_request"))
            // .define_method("geometry_change_requested", &QWebEnginePage::geometryChangeRequested, Arg("geom"))
            // .define_method("icon_changed", &QWebEnginePage::iconChanged, Arg("icon"))
            // .define_method("icon_url_changed", &QWebEnginePage::iconUrlChanged, Arg("url"))
            // .define_method("lifecycle_state_changed", &QWebEnginePage::lifecycleStateChanged, Arg("state"))
            // .define_method("link_hovered", &QWebEnginePage::linkHovered, Arg("url"))
            // .define_method("load_finished", &QWebEnginePage::loadFinished, Arg("ok"))
            // .define_method("load_progress", &QWebEnginePage::loadProgress, Arg("progress"))
            // .define_method("load_started", &QWebEnginePage::loadStarted)
            // .define_method("loading_changed", &QWebEnginePage::loadingChanged, Arg("loading_info"))
            // .define_method("navigation_requested", &QWebEnginePage::navigationRequested, Arg("request"))
            // .define_method("new_window_requested", &QWebEnginePage::newWindowRequested, Arg("request"))
            // .define_method("pdf_printing_finished", &QWebEnginePage::pdfPrintingFinished, Arg("file_path"), Arg("success"))
            // .define_method("permission_requested", &QWebEnginePage::permissionRequested, Arg("permission_request"))
            // .define_method("print_requested", &QWebEnginePage::printRequested)
            // .define_method("print_requested_by_frame", &QWebEnginePage::printRequestedByFrame, Arg("frame"))
            // .define_method("proxy_authentication_required", &QWebEnginePage::proxyAuthenticationRequired, Arg("request_url"), Arg("authenticator"), Arg("proxy_host"))
            // .define_method("recently_audible_changed", &QWebEnginePage::recentlyAudibleChanged, Arg("recently_audible"))
            // .define_method("recommended_state_changed", &QWebEnginePage::recommendedStateChanged, Arg("state"))
            // .define_method("register_protocol_handler_requested", &QWebEnginePage::registerProtocolHandlerRequested, Arg("request"))
            // .define_method("render_process_pid_changed", &QWebEnginePage::renderProcessPidChanged, Arg("pid"))
            // .define_method("render_process_terminated", &QWebEnginePage::renderProcessTerminated, Arg("termination_status"), Arg("exit_code"))
            // .define_method("scroll_position_changed", &QWebEnginePage::scrollPositionChanged, Arg("position"))
            // .define_method("select_client_certificate", &QWebEnginePage::selectClientCertificate, Arg("client_cert_selection"))
            // .define_method("selection_changed", &QWebEnginePage::selectionChanged)
            // .define_method("title_changed", &QWebEnginePage::titleChanged, Arg("title"))
            // .define_method("url_changed", &QWebEnginePage::urlChanged, Arg("url"))
            // .define_method("visible_changed", &QWebEnginePage::visibleChanged, Arg("visible"))
            // .define_method("web_auth_ux_requested", &QWebEnginePage::webAuthUxRequested, Arg("request"))
            // .define_method("window_close_requested", &QWebEnginePage::windowCloseRequested)
            // .define_method("zoom_factor_changed", &QWebEnginePage::zoomFactorChanged, Arg("factor"));

    Data_Type<QWebEnginePage::FileSelectionMode> rb_cQWebEnginePageFileSelectionMode =
        // RubyQt6::QtWebEngineCore::QWebEnginePage::FileSelectionMode
        define_qenum_under<QWebEnginePage::FileSelectionMode>(rb_cQWebEnginePage, "FileSelectionMode");
        define_qenum_value_under(rb_cQWebEnginePageFileSelectionMode, "FileSelectOpen", QWebEnginePage::FileSelectionMode::FileSelectOpen);
        define_qenum_value_under(rb_cQWebEnginePageFileSelectionMode, "FileSelectOpenMultiple", QWebEnginePage::FileSelectionMode::FileSelectOpenMultiple);
        define_qenum_value_under(rb_cQWebEnginePageFileSelectionMode, "FileSelectUploadFolder", QWebEnginePage::FileSelectionMode::FileSelectUploadFolder);
        define_qenum_value_under(rb_cQWebEnginePageFileSelectionMode, "FileSelectSave", QWebEnginePage::FileSelectionMode::FileSelectSave);

    Data_Type<QWebEnginePage::FindFlag> rb_cQWebEnginePageFindFlag =
        // RubyQt6::QtWebEngineCore::QWebEnginePage::FindFlag
        define_qenum_under<QWebEnginePage::FindFlag>(rb_cQWebEnginePage, "FindFlag");
        define_qenum_value_under(rb_cQWebEnginePageFindFlag, "FindBackward", QWebEnginePage::FindFlag::FindBackward);
        define_qenum_value_under(rb_cQWebEnginePageFindFlag, "FindCaseSensitively", QWebEnginePage::FindFlag::FindCaseSensitively);

    Data_Type<QWebEnginePage::JavaScriptConsoleMessageLevel> rb_cQWebEnginePageJavaScriptConsoleMessageLevel =
        // RubyQt6::QtWebEngineCore::QWebEnginePage::JavaScriptConsoleMessageLevel
        define_qenum_under<QWebEnginePage::JavaScriptConsoleMessageLevel>(rb_cQWebEnginePage, "JavaScriptConsoleMessageLevel");
        define_qenum_value_under(rb_cQWebEnginePageJavaScriptConsoleMessageLevel, "InfoMessageLevel", QWebEnginePage::JavaScriptConsoleMessageLevel::InfoMessageLevel);
        define_qenum_value_under(rb_cQWebEnginePageJavaScriptConsoleMessageLevel, "WarningMessageLevel", QWebEnginePage::JavaScriptConsoleMessageLevel::WarningMessageLevel);
        define_qenum_value_under(rb_cQWebEnginePageJavaScriptConsoleMessageLevel, "ErrorMessageLevel", QWebEnginePage::JavaScriptConsoleMessageLevel::ErrorMessageLevel);

    Data_Type<QWebEnginePage::LifecycleState> rb_cQWebEnginePageLifecycleState =
        // RubyQt6::QtWebEngineCore::QWebEnginePage::LifecycleState
        define_qenum_under<QWebEnginePage::LifecycleState>(rb_cQWebEnginePage, "LifecycleState");
        define_qenum_value_under(rb_cQWebEnginePageLifecycleState, "Active", QWebEnginePage::LifecycleState::Active);
        define_qenum_value_under(rb_cQWebEnginePageLifecycleState, "Frozen", QWebEnginePage::LifecycleState::Frozen);
        define_qenum_value_under(rb_cQWebEnginePageLifecycleState, "Discarded", QWebEnginePage::LifecycleState::Discarded);

    Data_Type<QWebEnginePage::NavigationType> rb_cQWebEnginePageNavigationType =
        // RubyQt6::QtWebEngineCore::QWebEnginePage::NavigationType
        define_qenum_under<QWebEnginePage::NavigationType>(rb_cQWebEnginePage, "NavigationType");
        define_qenum_value_under(rb_cQWebEnginePageNavigationType, "NavigationTypeLinkClicked", QWebEnginePage::NavigationType::NavigationTypeLinkClicked);
        define_qenum_value_under(rb_cQWebEnginePageNavigationType, "NavigationTypeTyped", QWebEnginePage::NavigationType::NavigationTypeTyped);
        define_qenum_value_under(rb_cQWebEnginePageNavigationType, "NavigationTypeFormSubmitted", QWebEnginePage::NavigationType::NavigationTypeFormSubmitted);
        define_qenum_value_under(rb_cQWebEnginePageNavigationType, "NavigationTypeBackForward", QWebEnginePage::NavigationType::NavigationTypeBackForward);
        define_qenum_value_under(rb_cQWebEnginePageNavigationType, "NavigationTypeReload", QWebEnginePage::NavigationType::NavigationTypeReload);
        define_qenum_value_under(rb_cQWebEnginePageNavigationType, "NavigationTypeOther", QWebEnginePage::NavigationType::NavigationTypeOther);
        define_qenum_value_under(rb_cQWebEnginePageNavigationType, "NavigationTypeRedirect", QWebEnginePage::NavigationType::NavigationTypeRedirect);

    Data_Type<QWebEnginePage::RenderProcessTerminationStatus> rb_cQWebEnginePageRenderProcessTerminationStatus =
        // RubyQt6::QtWebEngineCore::QWebEnginePage::RenderProcessTerminationStatus
        define_qenum_under<QWebEnginePage::RenderProcessTerminationStatus>(rb_cQWebEnginePage, "RenderProcessTerminationStatus");
        define_qenum_value_under(rb_cQWebEnginePageRenderProcessTerminationStatus, "NormalTerminationStatus", QWebEnginePage::RenderProcessTerminationStatus::NormalTerminationStatus);
        define_qenum_value_under(rb_cQWebEnginePageRenderProcessTerminationStatus, "AbnormalTerminationStatus", QWebEnginePage::RenderProcessTerminationStatus::AbnormalTerminationStatus);
        define_qenum_value_under(rb_cQWebEnginePageRenderProcessTerminationStatus, "CrashedTerminationStatus", QWebEnginePage::RenderProcessTerminationStatus::CrashedTerminationStatus);
        define_qenum_value_under(rb_cQWebEnginePageRenderProcessTerminationStatus, "KilledTerminationStatus", QWebEnginePage::RenderProcessTerminationStatus::KilledTerminationStatus);

    Data_Type<QWebEnginePage::WebAction> rb_cQWebEnginePageWebAction =
        // RubyQt6::QtWebEngineCore::QWebEnginePage::WebAction
        define_qenum_under<QWebEnginePage::WebAction>(rb_cQWebEnginePage, "WebAction");
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "NoWebAction", QWebEnginePage::WebAction::NoWebAction);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "Back", QWebEnginePage::WebAction::Back);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "Forward", QWebEnginePage::WebAction::Forward);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "Stop", QWebEnginePage::WebAction::Stop);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "Reload", QWebEnginePage::WebAction::Reload);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "Cut", QWebEnginePage::WebAction::Cut);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "Copy", QWebEnginePage::WebAction::Copy);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "Paste", QWebEnginePage::WebAction::Paste);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "Undo", QWebEnginePage::WebAction::Undo);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "Redo", QWebEnginePage::WebAction::Redo);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "SelectAll", QWebEnginePage::WebAction::SelectAll);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "ReloadAndBypassCache", QWebEnginePage::WebAction::ReloadAndBypassCache);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "PasteAndMatchStyle", QWebEnginePage::WebAction::PasteAndMatchStyle);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "OpenLinkInThisWindow", QWebEnginePage::WebAction::OpenLinkInThisWindow);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "OpenLinkInNewWindow", QWebEnginePage::WebAction::OpenLinkInNewWindow);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "OpenLinkInNewTab", QWebEnginePage::WebAction::OpenLinkInNewTab);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "CopyLinkToClipboard", QWebEnginePage::WebAction::CopyLinkToClipboard);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "DownloadLinkToDisk", QWebEnginePage::WebAction::DownloadLinkToDisk);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "CopyImageToClipboard", QWebEnginePage::WebAction::CopyImageToClipboard);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "CopyImageUrlToClipboard", QWebEnginePage::WebAction::CopyImageUrlToClipboard);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "DownloadImageToDisk", QWebEnginePage::WebAction::DownloadImageToDisk);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "CopyMediaUrlToClipboard", QWebEnginePage::WebAction::CopyMediaUrlToClipboard);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "ToggleMediaControls", QWebEnginePage::WebAction::ToggleMediaControls);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "ToggleMediaLoop", QWebEnginePage::WebAction::ToggleMediaLoop);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "ToggleMediaPlayPause", QWebEnginePage::WebAction::ToggleMediaPlayPause);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "ToggleMediaMute", QWebEnginePage::WebAction::ToggleMediaMute);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "DownloadMediaToDisk", QWebEnginePage::WebAction::DownloadMediaToDisk);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "InspectElement", QWebEnginePage::WebAction::InspectElement);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "ExitFullScreen", QWebEnginePage::WebAction::ExitFullScreen);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "RequestClose", QWebEnginePage::WebAction::RequestClose);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "Unselect", QWebEnginePage::WebAction::Unselect);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "SavePage", QWebEnginePage::WebAction::SavePage);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "OpenLinkInNewBackgroundTab", QWebEnginePage::WebAction::OpenLinkInNewBackgroundTab);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "ViewSource", QWebEnginePage::WebAction::ViewSource);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "ToggleBold", QWebEnginePage::WebAction::ToggleBold);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "ToggleItalic", QWebEnginePage::WebAction::ToggleItalic);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "ToggleUnderline", QWebEnginePage::WebAction::ToggleUnderline);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "ToggleStrikethrough", QWebEnginePage::WebAction::ToggleStrikethrough);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "AlignLeft", QWebEnginePage::WebAction::AlignLeft);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "AlignCenter", QWebEnginePage::WebAction::AlignCenter);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "AlignRight", QWebEnginePage::WebAction::AlignRight);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "AlignJustified", QWebEnginePage::WebAction::AlignJustified);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "Indent", QWebEnginePage::WebAction::Indent);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "Outdent", QWebEnginePage::WebAction::Outdent);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "InsertOrderedList", QWebEnginePage::WebAction::InsertOrderedList);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "InsertUnorderedList", QWebEnginePage::WebAction::InsertUnorderedList);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "ChangeTextDirectionLTR", QWebEnginePage::WebAction::ChangeTextDirectionLTR);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "ChangeTextDirectionRTL", QWebEnginePage::WebAction::ChangeTextDirectionRTL);
        define_qenum_value_under(rb_cQWebEnginePageWebAction, "WebActionCount", QWebEnginePage::WebAction::WebActionCount);

    Data_Type<QWebEnginePage::WebWindowType> rb_cQWebEnginePageWebWindowType =
        // RubyQt6::QtWebEngineCore::QWebEnginePage::WebWindowType
        define_qenum_under<QWebEnginePage::WebWindowType>(rb_cQWebEnginePage, "WebWindowType");
        define_qenum_value_under(rb_cQWebEnginePageWebWindowType, "WebBrowserWindow", QWebEnginePage::WebWindowType::WebBrowserWindow);
        define_qenum_value_under(rb_cQWebEnginePageWebWindowType, "WebBrowserTab", QWebEnginePage::WebWindowType::WebBrowserTab);
        define_qenum_value_under(rb_cQWebEnginePageWebWindowType, "WebDialog", QWebEnginePage::WebWindowType::WebDialog);
        define_qenum_value_under(rb_cQWebEnginePageWebWindowType, "WebBrowserBackgroundTab", QWebEnginePage::WebWindowType::WebBrowserBackgroundTab);

    Data_Type<QFlags<QWebEnginePage::FindFlag>> rb_cQWebEnginePageFindFlags =
        // RubyQt6::QtWebEngineCore::QWebEnginePage::FindFlags
        define_qflags_under<QWebEnginePage::FindFlag>(rb_cQWebEnginePage, "FindFlags");
}
