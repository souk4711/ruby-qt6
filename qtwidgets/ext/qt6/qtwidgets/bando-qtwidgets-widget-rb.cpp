#include "bando-qtwidgets-widget-rb.hpp"
#include <bando/qwidget.hpp>

#include <QWidget>
#include <QPushButton>
#include <QSlider>
#include <QDialog>
#include <QFrame>
#include <QAbstractScrollArea>
#include <QLabel>
#include <QLineEdit>
#include <QLCDNumber>

using namespace Rice;

using Bando_QWidget = BandoQWidget<QWidget, QWidget *>;
using Bando_QPushButton = BandoQWidget<QPushButton, const QString &, QWidget *>;
using Bando_QSlider = BandoQWidget<QSlider, Qt::Orientation, QWidget *>;
using Bando_QDialog = BandoQWidget<QDialog, QWidget *>;
using Bando_QFrame = BandoQWidget<QFrame, QWidget *>;
using Bando_QAbstractScrollArea = BandoQWidget<QAbstractScrollArea, QWidget *>;
using Bando_QLabel = BandoQWidget<QLabel, const QString &, QWidget *>;
using Bando_QLineEdit = BandoQWidget<QLineEdit, const QString &, QWidget *>;
using Bando_QLCDNumber = BandoQWidget<QLCDNumber, uint, QWidget *>;

Rice::Class rb_mBando_cQWidget;
Rice::Class rb_mBando_cQPushButton;
Rice::Class rb_mBando_cQSlider;
Rice::Class rb_mBando_cQDialog;
Rice::Class rb_mBando_cQFrame;
Rice::Class rb_mBando_cQAbstractScrollArea;
Rice::Class rb_mBando_cQLabel;
Rice::Class rb_mBando_cQLineEdit;
Rice::Class rb_mBando_cQLCDNumber;

void Init_bando_qtwidgets_widget(Rice::Module rb_mQt6Bando)
{
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

    rb_mBando_cQDialog =
        define_class_under<Bando_QDialog, QDialog>(rb_mQt6Bando, "QDialog")
            .define_constructor(Constructor<Bando_QDialog, QWidget *>(), Arg("parent"))
            .define_method("_initialize_value", &Bando_QDialog::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQFrame =
        define_class_under<Bando_QFrame, QFrame>(rb_mQt6Bando, "QFrame")
            .define_constructor(Constructor<Bando_QFrame, QWidget *>(), Arg("parent"))
            .define_method("_initialize_value", &Bando_QFrame::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQAbstractScrollArea =
        define_class_under<Bando_QAbstractScrollArea, QAbstractScrollArea>(rb_mQt6Bando, "QAbstractScrollArea")
            .define_constructor(Constructor<Bando_QAbstractScrollArea, QWidget *>(), Arg("parent"))
            .define_method("_initialize_value", &Bando_QAbstractScrollArea::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQLabel =
        define_class_under<Bando_QLabel, QLabel>(rb_mQt6Bando, "QLabel")
            .define_constructor(Constructor<Bando_QLabel, const QString &, QWidget *>(), Arg("text"), Arg("parent"))
            .define_method("_initialize_value", &Bando_QLabel::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQLineEdit =
        define_class_under<Bando_QLineEdit, QLineEdit>(rb_mQt6Bando, "QLineEdit")
            .define_constructor(Constructor<Bando_QLineEdit, const QString &, QWidget *>(), Arg("contents"), Arg("parent"))
            .define_method("_initialize_value", &Bando_QLineEdit::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQLCDNumber =
        define_class_under<Bando_QLCDNumber, QLCDNumber>(rb_mQt6Bando, "QLCDNumber")
            .define_constructor(Constructor<Bando_QLCDNumber, uint, QWidget *>(), Arg("num"), Arg("parent"))
            .define_method("_initialize_value", &Bando_QLCDNumber::initializeValue, Arg("mo"), Arg("value"));
}
