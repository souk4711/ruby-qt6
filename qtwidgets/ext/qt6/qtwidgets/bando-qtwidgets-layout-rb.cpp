#include "bando-qtwidgets-layout-rb.hpp"
#include <bando/qlayout.hpp>
#include <bando/qobject.hpp>

#include <QApplication>
#include <QBoxLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QGridLayout>
#include <QStackedLayout>
#include <QWidget>

using namespace Rice;

using Bando_QApplication = BandoQObject<QApplication, int &, char **>;
using Bando_QBoxLayout = BandoQLayout<QBoxLayout, QBoxLayout::Direction, QWidget *>;
using Bando_QHBoxLayout = BandoQLayout<QHBoxLayout, QWidget *>;
using Bando_QVBoxLayout = BandoQLayout<QVBoxLayout, QWidget *>;
using Bando_QFormLayout = BandoQLayout<QFormLayout, QWidget *>;
using Bando_QGridLayout = BandoQLayout<QGridLayout, QWidget *>;
using Bando_QStackedLayout = BandoQLayout<QStackedLayout, QWidget *>;

Rice::Class rb_mBando_cQApplication;
Rice::Class rb_mBando_cQBoxLayout;
Rice::Class rb_mBando_cQHBoxLayout;
Rice::Class rb_mBando_cQVBoxLayout;
Rice::Class rb_mBando_cQFormLayout;
Rice::Class rb_mBando_cQGridLayout;
Rice::Class rb_mBando_cQStackedLayout;

void Init_bando_qtwidgets_layout(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQApplication =
        define_class_under<Bando_QApplication, QApplication>(rb_mQt6Bando, "QApplication")
            .define_constructor(Constructor<Bando_QApplication, int &, char **>(), Arg("argc"), Arg("argv"))
            .define_method("_initialize_value", &Bando_QApplication::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQBoxLayout =
        define_class_under<Bando_QBoxLayout, QBoxLayout>(rb_mQt6Bando, "QBoxLayout")
            .define_constructor(Constructor<Bando_QBoxLayout, QBoxLayout::Direction, QWidget *>(), Arg("direction"), Arg("parent"))
            .define_method("_initialize_value", &Bando_QBoxLayout::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQHBoxLayout =
        define_class_under<Bando_QHBoxLayout, QHBoxLayout>(rb_mQt6Bando, "QHBoxLayout")
            .define_constructor(Constructor<Bando_QHBoxLayout, QWidget *>(), Arg("parent"))
            .define_method("_initialize_value", &Bando_QHBoxLayout::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQVBoxLayout =
        define_class_under<Bando_QVBoxLayout, QVBoxLayout>(rb_mQt6Bando, "QVBoxLayout")
            .define_constructor(Constructor<Bando_QVBoxLayout, QWidget *>(), Arg("parent"))
            .define_method("_initialize_value", &Bando_QVBoxLayout::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQFormLayout =
        define_class_under<Bando_QFormLayout, QFormLayout>(rb_mQt6Bando, "QFormLayout")
            .define_constructor(Constructor<Bando_QFormLayout, QWidget *>(), Arg("parent"))
            .define_method("_initialize_value", &Bando_QFormLayout::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQGridLayout =
        define_class_under<Bando_QGridLayout, QGridLayout>(rb_mQt6Bando, "QGridLayout")
            .define_constructor(Constructor<Bando_QGridLayout, QWidget *>(), Arg("parent"))
            .define_method("_initialize_value", &Bando_QGridLayout::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQStackedLayout =
        define_class_under<Bando_QStackedLayout, QStackedLayout>(rb_mQt6Bando, "QStackedLayout")
            .define_constructor(Constructor<Bando_QStackedLayout, QWidget *>(), Arg("parent"))
            .define_method("_initialize_value", &Bando_QStackedLayout::initializeValue, Arg("mo"), Arg("value"));
}
