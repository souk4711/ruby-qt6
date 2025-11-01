#include "qfontmetrics-rb.hpp"
#include <qfontmetrics.h>

#include <QTextOption>

using namespace Rice;

Rice::Class rb_cQFontMetrics;
Rice::Class rb_cQFontMetricsF;

void Init_qfontmetrics(Rice::Module rb_mQt6QtGui)
{
    rb_cQFontMetrics =
        // RubyQt6::QtGui::QFontMetrics
        define_class_under<QFontMetrics>(rb_mQt6QtGui, "QFontMetrics")
            // Constructor
            .define_constructor(Constructor<QFontMetrics, const QFont &>(), Arg("font"))
            // Public Functions
            .define_method("ascent", &QFontMetrics::ascent)
            .define_method("average_char_width", &QFontMetrics::averageCharWidth)
            .define_method<QRect (QFontMetrics::*)(QChar) const>("bounding_rect", &QFontMetrics::boundingRect, Arg("char"))
            .define_method<QRect (QFontMetrics::*)(const QRect &, int, const QString &, int, int *) const>("bounding_rect", &QFontMetrics::boundingRect, Arg("r"), Arg("flags"), Arg("text"), Arg("tabstops") = static_cast<int>(0), Arg("tabarray") = static_cast<int *>(nullptr))
            .define_method<QRect (QFontMetrics::*)(const QString &) const>("bounding_rect", &QFontMetrics::boundingRect, Arg("text"))
            .define_method<QRect (QFontMetrics::*)(const QString &, const QTextOption &) const>("bounding_rect", &QFontMetrics::boundingRect, Arg("text"), Arg("text_option"))
            .define_method<QRect (QFontMetrics::*)(int, int, int, int, int, const QString &, int, int *) const>("bounding_rect", &QFontMetrics::boundingRect, Arg("x"), Arg("y"), Arg("w"), Arg("h"), Arg("flags"), Arg("text"), Arg("tabstops") = static_cast<int>(0), Arg("tabarray") = static_cast<int *>(nullptr))
            .define_method("cap_height", &QFontMetrics::capHeight)
            .define_method("descent", &QFontMetrics::descent)
            .define_method("elided_text", &QFontMetrics::elidedText, Arg("text"), Arg("mode"), Arg("width"), Arg("flags") = static_cast<int>(0))
            .define_method("font_dpi", &QFontMetrics::fontDpi)
            .define_method("height", &QFontMetrics::height)
            .define_method<int (QFontMetrics::*)(QChar) const>("horizontal_advance", &QFontMetrics::horizontalAdvance, Arg("char"))
            .define_method<int (QFontMetrics::*)(const QString &, const QTextOption &) const>("horizontal_advance", &QFontMetrics::horizontalAdvance, Arg("text"), Arg("text_option"))
            .define_method<int (QFontMetrics::*)(const QString &, int) const>("horizontal_advance", &QFontMetrics::horizontalAdvance, Arg("text"), Arg("len") = static_cast<int>(-1))
            .define_method("in_font", &QFontMetrics::inFont, Arg("char"))
            .define_method("in_font_ucs4", &QFontMetrics::inFontUcs4, Arg("ucs4"))
            .define_method("leading", &QFontMetrics::leading)
            .define_method("left_bearing", &QFontMetrics::leftBearing, Arg("char"))
            .define_method("line_spacing", &QFontMetrics::lineSpacing)
            .define_method("line_width", &QFontMetrics::lineWidth)
            .define_method("max_width", &QFontMetrics::maxWidth)
            .define_method("min_left_bearing", &QFontMetrics::minLeftBearing)
            .define_method("min_right_bearing", &QFontMetrics::minRightBearing)
            .define_method("overline_pos", &QFontMetrics::overlinePos)
            .define_method("right_bearing", &QFontMetrics::rightBearing, Arg("char"))
            .define_method("size", &QFontMetrics::size, Arg("flags"), Arg("str"), Arg("tabstops") = static_cast<int>(0), Arg("tabarray") = static_cast<int *>(nullptr))
            .define_method("strike_out_pos", &QFontMetrics::strikeOutPos)
            .define_method<QRect (QFontMetrics::*)(const QString &) const>("tight_bounding_rect", &QFontMetrics::tightBoundingRect, Arg("text"))
            .define_method<QRect (QFontMetrics::*)(const QString &, const QTextOption &) const>("tight_bounding_rect", &QFontMetrics::tightBoundingRect, Arg("text"), Arg("text_option"))
            .define_method("underline_pos", &QFontMetrics::underlinePos)
            .define_method("x_height", &QFontMetrics::xHeight);

    rb_cQFontMetricsF =
        // RubyQt6::QtGui::QFontMetricsF
        define_class_under<QFontMetricsF>(rb_mQt6QtGui, "QFontMetricsF")
            // Constructor
            .define_constructor(Constructor<QFontMetricsF, const QFont &>(), Arg("font"))
            .define_constructor(Constructor<QFontMetricsF, const QFontMetrics &>(), Arg("font_metrics"))
            // Public Functions
            .define_method("ascent", &QFontMetricsF::ascent)
            .define_method("average_char_width", &QFontMetricsF::averageCharWidth)
            .define_method<QRectF (QFontMetricsF::*)(QChar) const>("bounding_rect", &QFontMetricsF::boundingRect, Arg("char"))
            .define_method<QRectF (QFontMetricsF::*)(const QRectF &, int, const QString &, int, int *) const>("bounding_rect", &QFontMetricsF::boundingRect, Arg("r"), Arg("flags"), Arg("string"), Arg("tabstops") = static_cast<int>(0), Arg("tabarray") = static_cast<int *>(nullptr))
            .define_method<QRectF (QFontMetricsF::*)(const QString &) const>("bounding_rect", &QFontMetricsF::boundingRect, Arg("string"))
            .define_method<QRectF (QFontMetricsF::*)(const QString &, const QTextOption &) const>("bounding_rect", &QFontMetricsF::boundingRect, Arg("text"), Arg("text_option"))
            .define_method("cap_height", &QFontMetricsF::capHeight)
            .define_method("descent", &QFontMetricsF::descent)
            .define_method("elided_text", &QFontMetricsF::elidedText, Arg("text"), Arg("mode"), Arg("width"), Arg("flags") = static_cast<int>(0))
            .define_method("font_dpi", &QFontMetricsF::fontDpi)
            .define_method("height", &QFontMetricsF::height)
            .define_method<qreal (QFontMetricsF::*)(QChar) const>("horizontal_advance", &QFontMetricsF::horizontalAdvance, Arg("char"))
            .define_method<qreal (QFontMetricsF::*)(const QString &, const QTextOption &) const>("horizontal_advance", &QFontMetricsF::horizontalAdvance, Arg("string"), Arg("text_option"))
            .define_method<qreal (QFontMetricsF::*)(const QString &, int) const>("horizontal_advance", &QFontMetricsF::horizontalAdvance, Arg("string"), Arg("length") = static_cast<int>(-1))
            .define_method("in_font", &QFontMetricsF::inFont, Arg("font"))
            .define_method("in_font_ucs4", &QFontMetricsF::inFontUcs4, Arg("ucs4"))
            .define_method("leading", &QFontMetricsF::leading)
            .define_method("left_bearing", &QFontMetricsF::leftBearing, Arg("char"))
            .define_method("line_spacing", &QFontMetricsF::lineSpacing)
            .define_method("line_width", &QFontMetricsF::lineWidth)
            .define_method("max_width", &QFontMetricsF::maxWidth)
            .define_method("min_left_bearing", &QFontMetricsF::minLeftBearing)
            .define_method("min_right_bearing", &QFontMetricsF::minRightBearing)
            .define_method("overline_pos", &QFontMetricsF::overlinePos)
            .define_method("right_bearing", &QFontMetricsF::rightBearing, Arg("char"))
            .define_method("size", &QFontMetricsF::size, Arg("flags"), Arg("str"), Arg("tabstops") = static_cast<int>(0), Arg("tabarray") = static_cast<int *>(nullptr))
            .define_method("strike_out_pos", &QFontMetricsF::strikeOutPos)
            .define_method<QRectF (QFontMetricsF::*)(const QString &) const>("tight_bounding_rect", &QFontMetricsF::tightBoundingRect, Arg("text"))
            .define_method<QRectF (QFontMetricsF::*)(const QString &, const QTextOption &) const>("tight_bounding_rect", &QFontMetricsF::tightBoundingRect, Arg("text"), Arg("text_option"))
            .define_method("underline_pos", &QFontMetricsF::underlinePos)
            .define_method("x_height", &QFontMetricsF::xHeight);
}
