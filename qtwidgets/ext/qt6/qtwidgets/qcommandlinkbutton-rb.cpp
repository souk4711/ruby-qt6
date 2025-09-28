#include "qcommandlinkbutton-rb.hpp"
#include <qcommandlinkbutton.h>

#include <QStyleOptionButton>

using namespace Rice;

Rice::Class rb_cQCommandLinkButton;

void Init_qcommandlinkbutton(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQCommandLinkButton =
        // RubyQt6::QtWidgets::QCommandLinkButton
        define_class_under<QCommandLinkButton, QPushButton>(rb_mQt6QtWidgets, "QCommandLinkButton")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QCommandLinkButton::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QCommandLinkButton, const QString &, const QString &, QWidget *>(), Arg("text"), Arg("description"), Arg("parent"))
            // Public Functions
            .define_method("description", &QCommandLinkButton::description)
            .define_method("height_for_width", &QCommandLinkButton::heightForWidth, Arg("w"))
            .define_method("init_style_option", &QCommandLinkButton::initStyleOption, Arg("option"))
            .define_method("minimum_size_hint", &QCommandLinkButton::minimumSizeHint)
            .define_method("set_description", &QCommandLinkButton::setDescription, Arg("description"))
            .define_method("size_hint", &QCommandLinkButton::sizeHint);
}
