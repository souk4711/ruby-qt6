#include "qtextlayout-rb.hpp"
#include <qtextlayout.h>
#include <rice/qt6/qenum.hpp>

#include <QPainter>
#include <QTextBlock>

using namespace Rice;

Rice::Class rb_cQTextLayout;
Rice::Class rb_cQTextLayoutFormatRange;

void Init_qtextlayout(Rice::Module rb_mQt6QtGui)
{
    rb_cQTextLayout =
        // RubyQt6::QtGui::QTextLayout
        define_class_under<QTextLayout>(rb_mQt6QtGui, "QTextLayout")
            // Constructor
            .define_constructor(Constructor<QTextLayout>())
            .define_constructor(Constructor<QTextLayout, const QString &>(), Arg("text"))
            .define_constructor(Constructor<QTextLayout, const QString &, const QFont &, const QPaintDevice *>(), Arg("text"), Arg("font"), Arg("paintdevice"))
            .define_constructor(Constructor<QTextLayout, const QTextBlock &>(), Arg("block"))
            // Public Functions
            .define_method("begin_layout", &QTextLayout::beginLayout)
            .define_method("bounding_rect", &QTextLayout::boundingRect)
            .define_method("cache_enabled", &QTextLayout::cacheEnabled)
            .define_method("clear_formats", &QTextLayout::clearFormats)
            .define_method("clear_layout", &QTextLayout::clearLayout)
            .define_method("create_line", &QTextLayout::createLine)
            .define_method("cursor_move_style", &QTextLayout::cursorMoveStyle)
            .define_method("draw", &QTextLayout::draw, Arg("p"), Arg("pos"), Arg("selections") = static_cast<const QList<QTextLayout::FormatRange> &>(QList<QTextLayout::FormatRange>()), Arg("clip") = static_cast<const QRectF &>(QRectF()))
            .define_method<void (QTextLayout::*)(QPainter *, const QPointF &, int) const>("draw_cursor", &QTextLayout::drawCursor, Arg("p"), Arg("pos"), Arg("cursor_position"))
            .define_method<void (QTextLayout::*)(QPainter *, const QPointF &, int, int) const>("draw_cursor", &QTextLayout::drawCursor, Arg("p"), Arg("pos"), Arg("cursor_position"), Arg("width"))
            .define_method("end_layout", &QTextLayout::endLayout)
            .define_method("font", &QTextLayout::font)
            .define_method("formats", &QTextLayout::formats)
            .define_method<QList<QGlyphRun> (QTextLayout::*)(int, int) const>("glyph_runs", &QTextLayout::glyphRuns, Arg("from") = static_cast<int>(-1), Arg("length") = static_cast<int>(-1))
            .define_method<QList<QGlyphRun> (QTextLayout::*)(int, int, QTextLayout::GlyphRunRetrievalFlags) const>("glyph_runs", &QTextLayout::glyphRuns, Arg("from"), Arg("length"), Arg("flags"))
            .define_method("valid_cursor_position?", &QTextLayout::isValidCursorPosition, Arg("pos"))
            .define_method("left_cursor_position", &QTextLayout::leftCursorPosition, Arg("old_pos"))
            .define_method("line_at", &QTextLayout::lineAt, Arg("i"))
            .define_method("line_count", &QTextLayout::lineCount)
            .define_method("line_for_text_position", &QTextLayout::lineForTextPosition, Arg("pos"))
            .define_method("maximum_width", &QTextLayout::maximumWidth)
            .define_method("minimum_width", &QTextLayout::minimumWidth)
            .define_method("next_cursor_position", &QTextLayout::nextCursorPosition, Arg("old_pos"), Arg("mode") = static_cast<QTextLayout::CursorMode>(QTextLayout::CursorMode::SkipCharacters))
            .define_method("position", &QTextLayout::position)
            .define_method("preedit_area_position", &QTextLayout::preeditAreaPosition)
            .define_method("preedit_area_text", &QTextLayout::preeditAreaText)
            .define_method("previous_cursor_position", &QTextLayout::previousCursorPosition, Arg("old_pos"), Arg("mode") = static_cast<QTextLayout::CursorMode>(QTextLayout::CursorMode::SkipCharacters))
            .define_method("right_cursor_position", &QTextLayout::rightCursorPosition, Arg("old_pos"))
            .define_method("set_cache_enabled", &QTextLayout::setCacheEnabled, Arg("enable"))
            .define_method("set_cursor_move_style", &QTextLayout::setCursorMoveStyle, Arg("style"))
            .define_method("set_flags", &QTextLayout::setFlags, Arg("flags"))
            .define_method("set_font", &QTextLayout::setFont, Arg("f"))
            .define_method("_set_formats", &QTextLayout::setFormats, Arg("overrides"))
            .define_method("set_position", &QTextLayout::setPosition, Arg("p"))
            .define_method("set_preedit_area", &QTextLayout::setPreeditArea, Arg("position"), Arg("text"))
            .define_method("set_raw_font", &QTextLayout::setRawFont, Arg("raw_font"))
            .define_method("set_text", &QTextLayout::setText, Arg("string"))
            .define_method("set_text_option", &QTextLayout::setTextOption, Arg("option"))
            .define_method("text", &QTextLayout::text)
            .define_method("text_option", &QTextLayout::textOption);

    Data_Type<QTextLayout::CursorMode> rb_cQTextLayoutCursorMode =
        // RubyQt6::QtGui::QTextLayout::CursorMode
        define_qenum_under<QTextLayout::CursorMode>(rb_cQTextLayout, "CursorMode");
        define_qenum_value_under(rb_cQTextLayoutCursorMode, "SkipCharacters", QTextLayout::CursorMode::SkipCharacters);
        define_qenum_value_under(rb_cQTextLayoutCursorMode, "SkipWords", QTextLayout::CursorMode::SkipWords);

    Data_Type<QTextLayout::GlyphRunRetrievalFlag> rb_cQTextLayoutGlyphRunRetrievalFlag =
        // RubyQt6::QtGui::QTextLayout::GlyphRunRetrievalFlag
        define_qenum_under<QTextLayout::GlyphRunRetrievalFlag>(rb_cQTextLayout, "GlyphRunRetrievalFlag");
        define_qenum_value_under(rb_cQTextLayoutGlyphRunRetrievalFlag, "RetrieveGlyphIndexes", QTextLayout::GlyphRunRetrievalFlag::RetrieveGlyphIndexes);
        define_qenum_value_under(rb_cQTextLayoutGlyphRunRetrievalFlag, "RetrieveGlyphPositions", QTextLayout::GlyphRunRetrievalFlag::RetrieveGlyphPositions);
        define_qenum_value_under(rb_cQTextLayoutGlyphRunRetrievalFlag, "RetrieveStringIndexes", QTextLayout::GlyphRunRetrievalFlag::RetrieveStringIndexes);
        define_qenum_value_under(rb_cQTextLayoutGlyphRunRetrievalFlag, "RetrieveString", QTextLayout::GlyphRunRetrievalFlag::RetrieveString);
        define_qenum_value_under(rb_cQTextLayoutGlyphRunRetrievalFlag, "DefaultRetrievalFlags", QTextLayout::GlyphRunRetrievalFlag::DefaultRetrievalFlags);
        define_qenum_value_under(rb_cQTextLayoutGlyphRunRetrievalFlag, "RetrieveAll", QTextLayout::GlyphRunRetrievalFlag::RetrieveAll);

    rb_cQTextLayoutFormatRange =
        // RubyQt6::QtGui::QTextLayout::FormatRange
        define_class_under<QTextLayout::FormatRange>(rb_cQTextLayout, "FormatRange")
            .define_constructor(Constructor<QTextLayout::FormatRange>())
            .define_attr("start", &QTextLayout::FormatRange::start)
            .define_attr("length", &QTextLayout::FormatRange::length)
            .define_attr("format", &QTextLayout::FormatRange::format);
}
