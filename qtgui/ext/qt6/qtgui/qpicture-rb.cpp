#include "qpicture-rb.hpp"
#include <qpicture.h>

#include <QPaintEngine>
#include <QPainter>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQPicture;

void Init_qpicture(Module rb_mQt6QtGui)
{
    rb_cQPicture =
        // RubyQt6::QtGui::QPicture
        define_qlass_under<QPicture, QPaintDevice>(rb_mQt6QtGui, "QPicture")
            // Constructor
            .define_constructor(Constructor<QPicture>())
            // Public Functions
            .define_method("bounding_rect", &QPicture::boundingRect)
            .define_method("data", &QPicture::data)
            .define_method("detach", &QPicture::detach)
            .define_method("dev_type", &QPicture::devType)
            .define_method("detached?", &QPicture::isDetached)
            .define_method("null?", &QPicture::isNull)
            .define_method<bool (QPicture::*)(QIODevice *)>("load", &QPicture::load, Arg("dev"))
            .define_method<bool (QPicture::*)(const QString &)>("load", &QPicture::load, Arg("file_name"))
            .define_method("play", &QPicture::play, Arg("p"))
            .define_method<bool (QPicture::*)(QIODevice *)>("save", &QPicture::save, Arg("dev"))
            .define_method<bool (QPicture::*)(const QString &)>("save", &QPicture::save, Arg("file_name"))
            .define_method("set_bounding_rect", &QPicture::setBoundingRect, Arg("r"))
            .define_method("set_data", &QPicture::setData, Arg("data"), Arg("size"))
            .define_method("size", &QPicture::size);
}
