#include "bando-qtwidgets-widget-rb.hpp"
#include <bando/qwidget.hpp>

#include <QWidget>
#include <QCheckBox>
#include <QPushButton>
#include <QCommandLinkButton>
#include <QRadioButton>
#include <QToolButton>
#include <QDial>
#include <QScrollBar>
#include <QSlider>
#include <QDateTimeEdit>
#include <QDateEdit>
#include <QTimeEdit>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QDialog>
#include <QFrame>
#include <QAbstractScrollArea>
#include <QLabel>
#include <QLCDNumber>
#include <QLineEdit>

using namespace Rice;

using Bando_QWidget = BandoQWidget<QWidget, QWidget *>;
using Bando_QCheckBox = BandoQWidget<QCheckBox, const QString &, QWidget *>;
using Bando_QPushButton = BandoQWidget<QPushButton, const QString &, QWidget *>;
using Bando_QCommandLinkButton = BandoQWidget<QCommandLinkButton, const QString &, const QString &, QWidget *>;
using Bando_QRadioButton = BandoQWidget<QRadioButton, const QString &, QWidget *>;
using Bando_QToolButton = BandoQWidget<QToolButton, QWidget *>;
using Bando_QDial = BandoQWidget<QDial, QWidget *>;
using Bando_QScrollBar = BandoQWidget<QScrollBar, Qt::Orientation, QWidget *>;
using Bando_QSlider = BandoQWidget<QSlider, Qt::Orientation, QWidget *>;
using Bando_QDateTimeEdit = BandoQWidget<QDateTimeEdit, const QDateTime &, QWidget *>;
using Bando_QDateEdit = BandoQWidget<QDateEdit, QDate, QWidget *>;
using Bando_QTimeEdit = BandoQWidget<QTimeEdit, QTime, QWidget *>;
using Bando_QDoubleSpinBox = BandoQWidget<QDoubleSpinBox, QWidget *>;
using Bando_QSpinBox = BandoQWidget<QSpinBox, QWidget *>;
using Bando_QDialog = BandoQWidget<QDialog, QWidget *>;
using Bando_QFrame = BandoQWidget<QFrame, QWidget *>;
using Bando_QAbstractScrollArea = BandoQWidget<QAbstractScrollArea, QWidget *>;
using Bando_QLabel = BandoQWidget<QLabel, const QString &, QWidget *>;
using Bando_QLCDNumber = BandoQWidget<QLCDNumber, uint, QWidget *>;
using Bando_QLineEdit = BandoQWidget<QLineEdit, const QString &, QWidget *>;

Rice::Class rb_mBando_cQWidget;
Rice::Class rb_mBando_cQCheckBox;
Rice::Class rb_mBando_cQPushButton;
Rice::Class rb_mBando_cQCommandLinkButton;
Rice::Class rb_mBando_cQRadioButton;
Rice::Class rb_mBando_cQToolButton;
Rice::Class rb_mBando_cQDial;
Rice::Class rb_mBando_cQScrollBar;
Rice::Class rb_mBando_cQSlider;
Rice::Class rb_mBando_cQDateTimeEdit;
Rice::Class rb_mBando_cQDateEdit;
Rice::Class rb_mBando_cQTimeEdit;
Rice::Class rb_mBando_cQDoubleSpinBox;
Rice::Class rb_mBando_cQSpinBox;
Rice::Class rb_mBando_cQDialog;
Rice::Class rb_mBando_cQFrame;
Rice::Class rb_mBando_cQAbstractScrollArea;
Rice::Class rb_mBando_cQLabel;
Rice::Class rb_mBando_cQLCDNumber;
Rice::Class rb_mBando_cQLineEdit;

void Init_bando_qtwidgets_widget(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQWidget =
        define_class_under<Bando_QWidget, QWidget>(rb_mQt6Bando, "QWidget")
            .define_constructor(Constructor<Bando_QWidget, QWidget *>(), Arg("parent"))
            .define_method("_initialize_value", &Bando_QWidget::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQCheckBox =
        define_class_under<Bando_QCheckBox, QCheckBox>(rb_mQt6Bando, "QCheckBox")
            .define_constructor(Constructor<Bando_QCheckBox, const QString &, QWidget *>(), Arg("text"), Arg("parent"))
            .define_method("_initialize_value", &Bando_QCheckBox::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQPushButton =
        define_class_under<Bando_QPushButton, QPushButton>(rb_mQt6Bando, "QPushButton")
            .define_constructor(Constructor<Bando_QPushButton, const QString &, QWidget *>(), Arg("text"), Arg("parent"))
            .define_method("_initialize_value", &Bando_QPushButton::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQCommandLinkButton =
        define_class_under<Bando_QCommandLinkButton, QCommandLinkButton>(rb_mQt6Bando, "QCommandLinkButton")
            .define_constructor(Constructor<Bando_QCommandLinkButton, const QString &, const QString &, QWidget *>(), Arg("text"), Arg("description"), Arg("parent"))
            .define_method("_initialize_value", &Bando_QCommandLinkButton::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQRadioButton =
        define_class_under<Bando_QRadioButton, QRadioButton>(rb_mQt6Bando, "QRadioButton")
            .define_constructor(Constructor<Bando_QRadioButton, const QString &, QWidget *>(), Arg("text"), Arg("parent"))
            .define_method("_initialize_value", &Bando_QRadioButton::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQToolButton =
        define_class_under<Bando_QToolButton, QToolButton>(rb_mQt6Bando, "QToolButton")
            .define_constructor(Constructor<Bando_QToolButton, QWidget *>(), Arg("parent"))
            .define_method("_initialize_value", &Bando_QToolButton::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQDial =
        define_class_under<Bando_QDial, QDial>(rb_mQt6Bando, "QDial")
            .define_constructor(Constructor<Bando_QDial, QWidget *>(), Arg("parent"))
            .define_method("_initialize_value", &Bando_QDial::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQScrollBar =
        define_class_under<Bando_QScrollBar, QScrollBar>(rb_mQt6Bando, "QScrollBar")
            .define_constructor(Constructor<Bando_QScrollBar, Qt::Orientation, QWidget *>(), Arg("orientation"), Arg("parent"))
            .define_method("_initialize_value", &Bando_QScrollBar::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQSlider =
        define_class_under<Bando_QSlider, QSlider>(rb_mQt6Bando, "QSlider")
            .define_constructor(Constructor<Bando_QSlider, Qt::Orientation, QWidget *>(), Arg("orientation"), Arg("parent"))
            .define_method("_initialize_value", &Bando_QSlider::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQDateTimeEdit =
        define_class_under<Bando_QDateTimeEdit, QDateTimeEdit>(rb_mQt6Bando, "QDateTimeEdit")
            .define_constructor(Constructor<Bando_QDateTimeEdit, const QDateTime &, QWidget *>(), Arg("datetime"), Arg("parent"))
            .define_method("_initialize_value", &Bando_QDateTimeEdit::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQDateEdit =
        define_class_under<Bando_QDateEdit, QDateEdit>(rb_mQt6Bando, "QDateEdit")
            .define_constructor(Constructor<Bando_QDateEdit, QDate, QWidget *>(), Arg("date"), Arg("parent"))
            .define_method("_initialize_value", &Bando_QDateEdit::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQTimeEdit =
        define_class_under<Bando_QTimeEdit, QTimeEdit>(rb_mQt6Bando, "QTimeEdit")
            .define_constructor(Constructor<Bando_QTimeEdit, QTime, QWidget *>(), Arg("time"), Arg("parent"))
            .define_method("_initialize_value", &Bando_QTimeEdit::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQDoubleSpinBox =
        define_class_under<Bando_QDoubleSpinBox, QDoubleSpinBox>(rb_mQt6Bando, "QDoubleSpinBox")
            .define_constructor(Constructor<Bando_QDoubleSpinBox, QWidget *>(), Arg("parent"))
            .define_method("_initialize_value", &Bando_QDoubleSpinBox::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQSpinBox =
        define_class_under<Bando_QSpinBox, QSpinBox>(rb_mQt6Bando, "QSpinBox")
            .define_constructor(Constructor<Bando_QSpinBox, QWidget *>(), Arg("parent"))
            .define_method("_initialize_value", &Bando_QSpinBox::initializeValue, Arg("mo"), Arg("value"));

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

    rb_mBando_cQLCDNumber =
        define_class_under<Bando_QLCDNumber, QLCDNumber>(rb_mQt6Bando, "QLCDNumber")
            .define_constructor(Constructor<Bando_QLCDNumber, uint, QWidget *>(), Arg("num"), Arg("parent"))
            .define_method("_initialize_value", &Bando_QLCDNumber::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQLineEdit =
        define_class_under<Bando_QLineEdit, QLineEdit>(rb_mQt6Bando, "QLineEdit")
            .define_constructor(Constructor<Bando_QLineEdit, const QString &, QWidget *>(), Arg("contents"), Arg("parent"))
            .define_method("_initialize_value", &Bando_QLineEdit::initializeValue, Arg("mo"), Arg("value"));
}
