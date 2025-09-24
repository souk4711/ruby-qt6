#include "qpicture-rb.hpp"
#include <qpicture.h>

#include <QPaintEngine>
#include <QPainter>

using namespace Rice;

Rice::Class rb_cQPicture;

void Init_qpicture(Rice::Module rb_mQt6QtGui)
{
    rb_cQPicture =
        // RubyQt6::QtGui::QPicture
        define_class_under<QPicture, QPaintDevice>(rb_mQt6QtGui, "QPicture")
            // Constructor
            .define_constructor(Constructor<QPicture, int>(), Arg("format_version") = static_cast<int>(-1))
            // Public Functions
            .define_method("bounding_rect", &QPicture::boundingRect)
            .define_method("data", &QPicture::data)
            .define_method("detach", &QPicture::detach)
            .define_method("dev_type", &QPicture::devType)
            .define_method("detached?", &QPicture::isDetached)
            .define_method("null?", &QPicture::isNull)
            .define_method<bool (QPicture::*)(QIODevice *)>("load", &QPicture::load, Arg("dev"))
            .define_method<bool (QPicture::*)(const QString &)>("load", &QPicture::load, Arg("file_name"))
            .define_method("paint_engine", &QPicture::paintEngine)
            .define_method("play", &QPicture::play, Arg("p"))
            .define_method<bool (QPicture::*)(QIODevice *)>("save", &QPicture::save, Arg("dev"))
            .define_method<bool (QPicture::*)(const QString &)>("save", &QPicture::save, Arg("file_name"))
            .define_method("set_bounding_rect", &QPicture::setBoundingRect, Arg("r"))
            .define_method("set_data", &QPicture::setData, Arg("data"), Arg("size"))
            .define_method("size", &QPicture::size)
            .define_method("swap", &QPicture::swap, Arg("other"));
}
