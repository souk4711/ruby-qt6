#include "bando-qtwidgets-rb.hpp"
#include <bando/qobject.hpp>
#include <bando/qwidget.hpp>

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QSlider>

using namespace Rice;

using Bando_QApplication = BandoQObject<QApplication, int &, char **>;
using Bando_QWidget = BandoQWidget<QWidget, QWidget *>;
using Bando_QPushButton = BandoQWidget<QPushButton, const QString &, QWidget *>;
using Bando_QSlider = BandoQWidget<QSlider, Qt::Orientation, QWidget *>;

Rice::Class rb_mBando_cQApplication;
Rice::Class rb_mBando_cQWidget;
Rice::Class rb_mBando_cQPushButton;
Rice::Class rb_mBando_cQSlider;

void Init_bando_qtwidgets(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQApplication =
        define_class_under<Bando_QApplication, QApplication>(rb_mQt6Bando, "QApplication")
            .define_constructor(Constructor<Bando_QApplication, int &, char **>(), Arg("argc"), Arg("argv"))
            .define_method("_initialize_value", &Bando_QApplication::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQWidget =
        define_class_under<Bando_QWidget, QWidget>(rb_mQt6Bando, "QWidget")
            .define_constructor(Constructor<Bando_QWidget, QWidget *>(), Arg("parent"))
            .define_method("_initialize_value", &Bando_QWidget::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQPushButton =
        define_class_under<Bando_QPushButton, QPushButton>(rb_mQt6Bando, "QPushButton")
            .define_constructor(Constructor<Bando_QPushButton, const QString &, QWidget *>(), Arg("text"), Arg("parent"))
            .define_method("_initialize_value", &Bando_QPushButton::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQSlider =
        define_class_under<Bando_QSlider, QSlider>(rb_mQt6Bando, "QSlider")
            .define_constructor(Constructor<Bando_QSlider, Qt::Orientation, QWidget *>(), Arg("orientation"), Arg("parent"))
            .define_method("_initialize_value", &Bando_QSlider::initializeValue, Arg("mo"), Arg("value"));
}
