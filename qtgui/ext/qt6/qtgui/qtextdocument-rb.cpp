#include "qtextdocument-rb.hpp"
#include <qtextdocument.h>

#include <QAbstractTextDocumentLayout>
#include <QPagedPaintDevice>
#include <QPainter>
#include <QRegularExpression>
#include <QTextCursor>
#include <QTextFormat>
#include <QTextObject>

using namespace Rice;

Rice::Class rb_cQTextDocument;

void Init_qtextdocument(Rice::Module rb_mQt6QtGui)
{
    rb_cQTextDocument =
        // RubyQt6::QtGui::QTextDocument
        define_class_under<QTextDocument, QObject>(rb_mQt6QtGui, "QTextDocument")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QTextDocument::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QTextDocument, const QString &, QObject *>(), Arg("text"), Arg("parent"))
            // Public Functions
            .define_method("add_resource", &QTextDocument::addResource, Arg("type"), Arg("name"), Arg("resource"))
            .define_method("adjust_size", &QTextDocument::adjustSize)
            .define_method("all_formats", &QTextDocument::allFormats)
            .define_method("append_undo_item", &QTextDocument::appendUndoItem, Arg("item"))
            .define_method("available_redo_steps", &QTextDocument::availableRedoSteps)
            .define_method("available_undo_steps", &QTextDocument::availableUndoSteps)
            .define_method("base_url", &QTextDocument::baseUrl)
            .define_method("baseline_offset", &QTextDocument::baselineOffset)
            .define_method("block_count", &QTextDocument::blockCount)
            .define_method("character_at", &QTextDocument::characterAt, Arg("pos"))
            .define_method("character_count", &QTextDocument::characterCount)
            .define_method("clear", &QTextDocument::clear)
            .define_method("clear_undo_redo_stacks", &QTextDocument::clearUndoRedoStacks, Arg("history_to_clear") = static_cast<QTextDocument::Stacks>(QTextDocument::Stacks::UndoAndRedoStacks))
            .define_method("clone", &QTextDocument::clone, Arg("parent") = static_cast<QObject *>(nullptr))
            .define_method("default_cursor_move_style", &QTextDocument::defaultCursorMoveStyle)
            .define_method("default_font", &QTextDocument::defaultFont)
            .define_method("default_style_sheet", &QTextDocument::defaultStyleSheet)
            .define_method("default_text_option", &QTextDocument::defaultTextOption)
            .define_method("document_layout", &QTextDocument::documentLayout)
            .define_method("document_margin", &QTextDocument::documentMargin)
            .define_method("draw_contents", &QTextDocument::drawContents, Arg("painter"), Arg("rect") = static_cast<const QRectF &>(QRectF()))
            .define_method<QTextCursor (QTextDocument::*)(const QRegularExpression &, const QTextCursor &, QTextDocument::FindFlags) const>("find", &QTextDocument::find, Arg("expr"), Arg("cursor"), Arg("options") = static_cast<QTextDocument::FindFlags>(QTextDocument::FindFlags()))
            .define_method<QTextCursor (QTextDocument::*)(const QRegularExpression &, int, QTextDocument::FindFlags) const>("find", &QTextDocument::find, Arg("expr"), Arg("from") = static_cast<int>(0), Arg("options") = static_cast<QTextDocument::FindFlags>(QTextDocument::FindFlags()))
            .define_method<QTextCursor (QTextDocument::*)(const QString &, const QTextCursor &, QTextDocument::FindFlags) const>("find", &QTextDocument::find, Arg("sub_string"), Arg("cursor"), Arg("options") = static_cast<QTextDocument::FindFlags>(QTextDocument::FindFlags()))
            .define_method<QTextCursor (QTextDocument::*)(const QString &, int, QTextDocument::FindFlags) const>("find", &QTextDocument::find, Arg("sub_string"), Arg("from") = static_cast<int>(0), Arg("options") = static_cast<QTextDocument::FindFlags>(QTextDocument::FindFlags()))
            .define_method("find_block", &QTextDocument::findBlock, Arg("pos"))
            .define_method("find_block_by_line_number", &QTextDocument::findBlockByLineNumber, Arg("block_number"))
            .define_method("find_block_by_number", &QTextDocument::findBlockByNumber, Arg("block_number"))
            .define_method("first_block", &QTextDocument::firstBlock)
            .define_method("frame_at", &QTextDocument::frameAt, Arg("pos"))
            .define_method("ideal_width", &QTextDocument::idealWidth)
            .define_method("indent_width", &QTextDocument::indentWidth)
            .define_method("empty?", &QTextDocument::isEmpty)
            .define_method("layout_enabled?", &QTextDocument::isLayoutEnabled)
            .define_method("modified?", &QTextDocument::isModified)
            .define_method("redo_available?", &QTextDocument::isRedoAvailable)
            .define_method("undo_available?", &QTextDocument::isUndoAvailable)
            .define_method("undo_redo_enabled?", &QTextDocument::isUndoRedoEnabled)
            .define_method("last_block", &QTextDocument::lastBlock)
            .define_method("line_count", &QTextDocument::lineCount)
            .define_method("mark_contents_dirty", &QTextDocument::markContentsDirty, Arg("from"), Arg("length"))
            .define_method("maximum_block_count", &QTextDocument::maximumBlockCount)
            .define_method("meta_information", &QTextDocument::metaInformation, Arg("info"))
            .define_method("object", &QTextDocument::object, Arg("object_index"))
            .define_method("object_for_format", &QTextDocument::objectForFormat, Arg("f"))
            .define_method("page_count", &QTextDocument::pageCount)
            .define_method("page_size", &QTextDocument::pageSize)
            .define_method("print", &QTextDocument::print, Arg("printer"))
            .define_method<void (QTextDocument::*)(QTextCursor *)>("redo", &QTextDocument::redo, Arg("cursor"))
            .define_method("resource", &QTextDocument::resource, Arg("type"), Arg("name"))
            .define_method("resource_provider", &QTextDocument::resourceProvider)
            .define_method("revision", &QTextDocument::revision)
            .define_method("root_frame", &QTextDocument::rootFrame)
            .define_method("set_base_url", &QTextDocument::setBaseUrl, Arg("url"))
            .define_method("set_baseline_offset", &QTextDocument::setBaselineOffset, Arg("baseline"))
            .define_method("set_default_cursor_move_style", &QTextDocument::setDefaultCursorMoveStyle, Arg("style"))
            .define_method("set_default_font", &QTextDocument::setDefaultFont, Arg("font"))
            .define_method("set_default_style_sheet", &QTextDocument::setDefaultStyleSheet, Arg("sheet"))
            .define_method("set_default_text_option", &QTextDocument::setDefaultTextOption, Arg("option"))
            .define_method("set_document_layout", &QTextDocument::setDocumentLayout, Arg("layout"))
            .define_method("set_document_margin", &QTextDocument::setDocumentMargin, Arg("margin"))
            .define_method("set_html", &QTextDocument::setHtml, Arg("html"))
            .define_method("set_indent_width", &QTextDocument::setIndentWidth, Arg("width"))
            .define_method("set_layout_enabled", &QTextDocument::setLayoutEnabled, Arg("b"))
            .define_method("set_markdown", &QTextDocument::setMarkdown, Arg("markdown"), Arg("features") = static_cast<QTextDocument::MarkdownFeatures>(QTextDocument::MarkdownFeature::MarkdownDialectGitHub))
            .define_method("set_maximum_block_count", &QTextDocument::setMaximumBlockCount, Arg("maximum"))
            .define_method("set_meta_information", &QTextDocument::setMetaInformation, Arg("info"), Arg("str"))
            .define_method("set_page_size", &QTextDocument::setPageSize, Arg("size"))
            .define_method("set_plain_text", &QTextDocument::setPlainText, Arg("text"))
            .define_method("set_resource_provider", &QTextDocument::setResourceProvider, Arg("provider"))
            .define_method("set_sub_script_baseline", &QTextDocument::setSubScriptBaseline, Arg("baseline"))
            .define_method("set_super_script_baseline", &QTextDocument::setSuperScriptBaseline, Arg("baseline"))
            .define_method("set_text_width", &QTextDocument::setTextWidth, Arg("width"))
            .define_method("set_undo_redo_enabled", &QTextDocument::setUndoRedoEnabled, Arg("enable"))
            .define_method("set_use_design_metrics", &QTextDocument::setUseDesignMetrics, Arg("b"))
            .define_method("size", &QTextDocument::size)
            .define_method("sub_script_baseline", &QTextDocument::subScriptBaseline)
            .define_method("super_script_baseline", &QTextDocument::superScriptBaseline)
            .define_method("text_width", &QTextDocument::textWidth)
            .define_method("to_html", &QTextDocument::toHtml)
            .define_method("to_markdown", &QTextDocument::toMarkdown, Arg("features") = static_cast<QTextDocument::MarkdownFeatures>(QTextDocument::MarkdownFeature::MarkdownDialectGitHub))
            .define_method("to_plain_text", &QTextDocument::toPlainText)
            .define_method("to_raw_text", &QTextDocument::toRawText)
            .define_method<void (QTextDocument::*)(QTextCursor *)>("undo", &QTextDocument::undo, Arg("cursor"))
            .define_method("use_design_metrics", &QTextDocument::useDesignMetrics)
            // Public Slots
            .define_method<void (QTextDocument::*)()>("redo", &QTextDocument::redo)
            .define_method("set_modified", &QTextDocument::setModified, Arg("m") = static_cast<bool>(true))
            .define_method<void (QTextDocument::*)()>("undo", &QTextDocument::undo)
            // Signals
            .define_method("base_url_changed", &QTextDocument::baseUrlChanged, Arg("url"))
            .define_method("block_count_changed", &QTextDocument::blockCountChanged, Arg("new_block_count"))
            .define_method("contents_change", &QTextDocument::contentsChange, Arg("from"), Arg("chars_removed"), Arg("chars_added"))
            .define_method("contents_changed", &QTextDocument::contentsChanged)
            .define_method("cursor_position_changed", &QTextDocument::cursorPositionChanged, Arg("cursor"))
            .define_method("document_layout_changed", &QTextDocument::documentLayoutChanged)
            .define_method("modification_changed", &QTextDocument::modificationChanged, Arg("m"))
            .define_method("redo_available", &QTextDocument::redoAvailable, Arg("available"))
            .define_method("undo_available", &QTextDocument::undoAvailable, Arg("available"))
            .define_method("undo_command_added", &QTextDocument::undoCommandAdded)
            // Static Public Members
            .define_singleton_function("default_resource_provider", &QTextDocument::defaultResourceProvider)
            .define_singleton_function("set_default_resource_provider", &QTextDocument::setDefaultResourceProvider, Arg("provider"));

    Enum<QTextDocument::FindFlag> rb_cQTextDocumentFindFlag =
        // RubyQt6::QtGui::QTextDocument::FindFlag
        define_enum_under<QTextDocument::FindFlag>("FindFlag", rb_cQTextDocument)
            .define_value("FindBackward", QTextDocument::FindFlag::FindBackward)
            .define_value("FindCaseSensitively", QTextDocument::FindFlag::FindCaseSensitively)
            .define_value("FindWholeWords", QTextDocument::FindFlag::FindWholeWords);

    Enum<QTextDocument::MarkdownFeature> rb_cQTextDocumentMarkdownFeature =
        // RubyQt6::QtGui::QTextDocument::MarkdownFeature
        define_enum_under<QTextDocument::MarkdownFeature>("MarkdownFeature", rb_cQTextDocument)
            .define_value("MarkdownNoHTML", QTextDocument::MarkdownFeature::MarkdownNoHTML)
            .define_value("MarkdownDialectCommonMark", QTextDocument::MarkdownFeature::MarkdownDialectCommonMark)
            .define_value("MarkdownDialectGitHub", QTextDocument::MarkdownFeature::MarkdownDialectGitHub);

    Enum<QTextDocument::MetaInformation> rb_cQTextDocumentMetaInformation =
        // RubyQt6::QtGui::QTextDocument::MetaInformation
        define_enum_under<QTextDocument::MetaInformation>("MetaInformation", rb_cQTextDocument)
            .define_value("DocumentTitle", QTextDocument::MetaInformation::DocumentTitle)
            .define_value("DocumentUrl", QTextDocument::MetaInformation::DocumentUrl)
            .define_value("CssMedia", QTextDocument::MetaInformation::CssMedia)
            .define_value("FrontMatter", QTextDocument::MetaInformation::FrontMatter);

    Enum<QTextDocument::ResourceType> rb_cQTextDocumentResourceType =
        // RubyQt6::QtGui::QTextDocument::ResourceType
        define_enum_under<QTextDocument::ResourceType>("ResourceType", rb_cQTextDocument)
            .define_value("UnknownResource", QTextDocument::ResourceType::UnknownResource)
            .define_value("HtmlResource", QTextDocument::ResourceType::HtmlResource)
            .define_value("ImageResource", QTextDocument::ResourceType::ImageResource)
            .define_value("StyleSheetResource", QTextDocument::ResourceType::StyleSheetResource)
            .define_value("MarkdownResource", QTextDocument::ResourceType::MarkdownResource)
            .define_value("UserResource", QTextDocument::ResourceType::UserResource);

    Enum<QTextDocument::Stacks> rb_cQTextDocumentStacks =
        // RubyQt6::QtGui::QTextDocument::Stacks
        define_enum_under<QTextDocument::Stacks>("Stacks", rb_cQTextDocument)
            .define_value("UndoStack", QTextDocument::Stacks::UndoStack)
            .define_value("RedoStack", QTextDocument::Stacks::RedoStack)
            .define_value("UndoAndRedoStacks", QTextDocument::Stacks::UndoAndRedoStacks);
}
