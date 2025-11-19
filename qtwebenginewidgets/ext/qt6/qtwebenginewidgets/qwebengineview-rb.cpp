#include "qwebengineview-rb.hpp"
#include <qwebengineview.h>

#include <QMenu>
#include <QWebEngineContextMenuRequest>
#include <QWebEngineHistory>
#include <QWebEngineHttpRequest>
#include <QWebEngineProfile>
#include <QWebEngineSettings>

using namespace Rice;

Rice::Class rb_cQWebEngineView;

void Init_qwebengineview(Rice::Module rb_mQt6QtWebEngineWidgets)
{
    rb_cQWebEngineView =
        // RubyQt6::QtWebEngineWidgets::QWebEngineView
        define_class_under<QWebEngineView, QWidget>(rb_mQt6QtWebEngineWidgets, "QWebEngineView")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QWebEngineView::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QWebEngineView, QWidget*>(), Arg("parent"))
            // Public Functions
            .define_method("create_standard_context_menu", &QWebEngineView::createStandardContextMenu)
            .define_method("has_selection", &QWebEngineView::hasSelection)
            .define_method("history", &QWebEngineView::history)
            .define_method("icon", &QWebEngineView::icon)
            .define_method("icon_url", &QWebEngineView::iconUrl)
            .define_method("last_context_menu_request", &QWebEngineView::lastContextMenuRequest)
            .define_method<void(QWebEngineView::*)(const QUrl&)>("load", &QWebEngineView::load, Arg("url"))
            .define_method<void(QWebEngineView::*)(const QWebEngineHttpRequest&)>("load", &QWebEngineView::load, Arg("request"))
            .define_method("page", &QWebEngineView::page)
            .define_method("page_action", &QWebEngineView::pageAction, Arg("action"))
            .define_method("selected_text", &QWebEngineView::selectedText)
            .define_method("set_content", &QWebEngineView::setContent, Arg("data"), Arg("mime_type") = static_cast<const QString &>(QString()), Arg("base_url") = static_cast<const QUrl &>(QUrl()))
            .define_method("set_html", &QWebEngineView::setHtml, Arg("html"), Arg("base_url") = static_cast<const QUrl &>(QUrl()))
            .define_method("set_page", &QWebEngineView::setPage, Arg("page"))
            .define_method("set_url", &QWebEngineView::setUrl, Arg("url"))
            .define_method("set_zoom_factor", &QWebEngineView::setZoomFactor, Arg("factor"))
            .define_method("settings", &QWebEngineView::settings)
            .define_method("title", &QWebEngineView::title)
            .define_method("trigger_page_action", &QWebEngineView::triggerPageAction, Arg("action"), Arg("checked") = static_cast<bool>(false))
            .define_method("url", &QWebEngineView::url)
            .define_method("zoom_factor", &QWebEngineView::zoomFactor)
            // Public Slots
            .define_method("back", &QWebEngineView::back)
            .define_method("forward", &QWebEngineView::forward)
            .define_method("reload", &QWebEngineView::reload)
            .define_method("stop", &QWebEngineView::stop)
            // Signals
            .define_method("icon_changed", &QWebEngineView::iconChanged, Arg("icon"))
            .define_method("icon_url_changed", &QWebEngineView::iconUrlChanged, Arg("url"))
            .define_method("load_finished", &QWebEngineView::loadFinished, Arg("ok"))
            .define_method("load_progress", &QWebEngineView::loadProgress, Arg("progress"))
            .define_method("load_started", &QWebEngineView::loadStarted)
            .define_method("pdf_printing_finished", &QWebEngineView::pdfPrintingFinished, Arg("file_path"), Arg("success"))
            .define_method("print_finished", &QWebEngineView::printFinished, Arg("success"))
            .define_method("print_requested", &QWebEngineView::printRequested)
            .define_method("print_requested_by_frame", &QWebEngineView::printRequestedByFrame, Arg("frame"))
            .define_method("render_process_terminated", &QWebEngineView::renderProcessTerminated, Arg("termination_status"), Arg("exit_code"))
            .define_method("selection_changed", &QWebEngineView::selectionChanged)
            .define_method("title_changed", &QWebEngineView::titleChanged, Arg("title"))
            .define_method("url_changed", &QWebEngineView::urlChanged, Arg("url"))
            // Static Public Members
            .define_singleton_function("for_page", &QWebEngineView::forPage, Arg("page"));
}
