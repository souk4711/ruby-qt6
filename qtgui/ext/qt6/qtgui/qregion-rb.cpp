#include "qregion-rb.hpp"
#include <qregion.h>

#include <QBitmap>
#include <QPolygon>

using namespace Rice;

Rice::Class rb_cQRegion;

void Init_qregion(Rice::Module rb_mQt6QtGui)
{
    rb_cQRegion =
        // RubyQt6::QtGui::QRegion
        define_class_under<QRegion>(rb_mQt6QtGui, "QRegion")
            // Constructor
            .define_constructor(Constructor<QRegion, int, int, int, int, QRegion::RegionType>(), Arg("x"), Arg("y"), Arg("w"), Arg("h"), Arg("t") = static_cast<QRegion::RegionType>(QRegion::RegionType::Rectangle))
            .define_constructor(Constructor<QRegion, const QRect &, QRegion::RegionType>(), Arg("r"), Arg("t") = static_cast<QRegion::RegionType>(QRegion::RegionType::Rectangle))
            // Public Functions
            .define_method("bounding_rect", &QRegion::boundingRect)
            .define_method("cbegin", &QRegion::cbegin)
            .define_method("cend", &QRegion::cend)
            .define_method<bool (QRegion::*)(const QPoint &) const>("contains", &QRegion::contains, Arg("p"))
            .define_method<bool (QRegion::*)(const QRect &) const>("contains", &QRegion::contains, Arg("r"))
            .define_method("crbegin", &QRegion::crbegin)
            .define_method("crend", &QRegion::crend)
            .define_method<QRegion (QRegion::*)(const QRect &) const>("intersected", &QRegion::intersected, Arg("r"))
            .define_method<QRegion (QRegion::*)(const QRegion &) const>("intersected", &QRegion::intersected, Arg("r"))
            .define_method<bool (QRegion::*)(const QRect &) const>("intersects", &QRegion::intersects, Arg("r"))
            .define_method<bool (QRegion::*)(const QRegion &) const>("intersects", &QRegion::intersects, Arg("r"))
            .define_method("empty?", &QRegion::isEmpty)
            .define_method("null?", &QRegion::isNull)
            .define_method("rect_count", &QRegion::rectCount)
            .define_method("rects", &QRegion::rects)
            .define_method<void (QRegion::*)(const QRect *, int)>("set_rects", &QRegion::setRects, Arg("rect"), Arg("num"))
            .define_method("subtracted", &QRegion::subtracted, Arg("r"))
            .define_method("swap", &QRegion::swap, Arg("other"))
            .define_method<void (QRegion::*)(const QPoint &)>("translate", &QRegion::translate, Arg("p"))
            .define_method<void (QRegion::*)(int, int)>("translate", &QRegion::translate, Arg("dx"), Arg("dy"))
            .define_method<QRegion (QRegion::*)(const QPoint &) const>("translated", &QRegion::translated, Arg("p"))
            .define_method<QRegion (QRegion::*)(int, int) const>("translated", &QRegion::translated, Arg("dx"), Arg("dy"))
            .define_method<QRegion (QRegion::*)(const QRect &) const>("united", &QRegion::united, Arg("r"))
            .define_method<QRegion (QRegion::*)(const QRegion &) const>("united", &QRegion::united, Arg("r"))
            .define_method("xored", &QRegion::xored, Arg("r"));

    Enum<QRegion::RegionType> rb_cQRegionRegionType =
        // RubyQt6::QtGui::QRegion::RegionType
        define_enum_under<QRegion::RegionType>("RegionType", rb_cQRegion)
            .define_value("Rectangle", QRegion::RegionType::Rectangle)
            .define_value("Ellipse", QRegion::RegionType::Ellipse);
}
