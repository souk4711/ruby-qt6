#include "qtextbrowser-rb.hpp"
#include <qtextbrowser.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQTextBrowser;

void Init_qtextbrowser(Module rb_mQt6QtWidgets)
{
    rb_cQTextBrowser =
        // RubyQt6::QtWidgets::QTextBrowser
        define_qlass_under<QTextBrowser, QTextEdit>(rb_mQt6QtWidgets, "QTextBrowser")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QTextBrowser * { return qobject_cast<QTextBrowser *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QTextBrowser::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QTextBrowser, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("backward_history_count", &QTextBrowser::backwardHistoryCount)
            .define_method("clear_history", &QTextBrowser::clearHistory)
            .define_method("forward_history_count", &QTextBrowser::forwardHistoryCount)
            .define_method("history_title", &QTextBrowser::historyTitle, Arg("i"))
            .define_method("history_url", &QTextBrowser::historyUrl, Arg("i"))
            .define_method("backward_available?", &QTextBrowser::isBackwardAvailable)
            .define_method("forward_available?", &QTextBrowser::isForwardAvailable)
            .define_method("load_resource", &QTextBrowser::loadResource, Arg("type"), Arg("name"))
            .define_method("open_external_links", &QTextBrowser::openExternalLinks)
            .define_method("open_links", &QTextBrowser::openLinks)
            .define_method("search_paths", &QTextBrowser::searchPaths)
            .define_method("set_open_external_links", &QTextBrowser::setOpenExternalLinks, Arg("open"))
            .define_method("set_open_links", &QTextBrowser::setOpenLinks, Arg("open"))
            .define_method("set_search_paths", &QTextBrowser::setSearchPaths, Arg("paths"))
            .define_method("source", &QTextBrowser::source)
            .define_method("source_type", &QTextBrowser::sourceType)
            // Public Slots
            .define_method("backward", &QTextBrowser::backward)
            .define_method("forward", &QTextBrowser::forward)
            .define_method("home", &QTextBrowser::home)
            .define_method("reload", &QTextBrowser::reload)
            .define_method("set_source", &QTextBrowser::setSource, Arg("name"), Arg("type") = static_cast<QTextDocument::ResourceType>(QTextDocument::UnknownResource));
            // Signals
            // .define_method("anchor_clicked", &QTextBrowser::anchorClicked, Arg("link"))
            // .define_method("backward_available", &QTextBrowser::backwardAvailable, Arg("available"))
            // .define_method("forward_available", &QTextBrowser::forwardAvailable, Arg("available"))
            // .define_method("highlighted", &QTextBrowser::highlighted, Arg("link"))
            // .define_method("history_changed", &QTextBrowser::historyChanged)
            // .define_method("source_changed", &QTextBrowser::sourceChanged, Arg("src"));
}
