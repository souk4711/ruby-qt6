#include "bando-qtcore-rb.hpp"
#include <bando/qobject.hpp>

#include <QObject>
#include <QCoreApplication>
#include <QItemSelectionModel>
#include <QSettings>
#include <QSignalMapper>
#include <QTimer>
#include <QTranslator>

using namespace Rice;

using Bando_QObject = BandoQObject<QObject, QObject *>;
using Bando_QCoreApplication = BandoQObject<QCoreApplication, int &, char **>;
using Bando_QItemSelectionModel = BandoQObject<QItemSelectionModel, QAbstractItemModel *, QObject *>;
using Bando_QSettings = BandoQObject<QSettings, QSettings::Format, QSettings::Scope, const QString &, const QString &, QObject *>;
using Bando_QSignalMapper = BandoQObject<QSignalMapper, QObject *>;
using Bando_QTimer = BandoQObject<QTimer, QObject *>;
using Bando_QTranslator = BandoQObject<QTranslator, QObject *>;

Rice::Class rb_mBando_cQObject;
Rice::Class rb_mBando_cQCoreApplication;
Rice::Class rb_mBando_cQItemSelectionModel;
Rice::Class rb_mBando_cQSettings;
Rice::Class rb_mBando_cQSignalMapper;
Rice::Class rb_mBando_cQTimer;
Rice::Class rb_mBando_cQTranslator;

void Init_bando_qtcore(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQObject =
        define_class_under<Bando_QObject, QObject>(rb_mQt6Bando, "QObject")
            .define_constructor(Constructor<Bando_QObject, QObject *>(), Arg("parent"))
            .define_method("_initialize_value", &Bando_QObject::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQCoreApplication =
        define_class_under<Bando_QCoreApplication, QCoreApplication>(rb_mQt6Bando, "QCoreApplication")
            .define_constructor(Constructor<Bando_QCoreApplication, int &, char **>(), Arg("argc"), Arg("argv"))
            .define_method("_initialize_value", &Bando_QCoreApplication::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQItemSelectionModel =
        define_class_under<Bando_QItemSelectionModel, QItemSelectionModel>(rb_mQt6Bando, "QItemSelectionModel")
            .define_constructor(Constructor<Bando_QItemSelectionModel, QAbstractItemModel *, QObject *>(), Arg("model"), Arg("parent"))
            .define_method("_initialize_value", &Bando_QItemSelectionModel::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQSettings =
        define_class_under<Bando_QSettings, QSettings>(rb_mQt6Bando, "QSettings")
            .define_constructor(Constructor<Bando_QSettings, QSettings::Format, QSettings::Scope, const QString &, const QString &, QObject *>(), Arg("format"), Arg("scope"), Arg("organization"), Arg("application"), Arg("parent"))
            .define_method("_initialize_value", &Bando_QSettings::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQSignalMapper =
        define_class_under<Bando_QSignalMapper, QSignalMapper>(rb_mQt6Bando, "QSignalMapper")
            .define_constructor(Constructor<Bando_QSignalMapper, QObject *>(), Arg("parent"))
            .define_method("_initialize_value", &Bando_QSignalMapper::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQTimer =
        define_class_under<Bando_QTimer, QTimer>(rb_mQt6Bando, "QTimer")
            .define_constructor(Constructor<Bando_QTimer, QObject *>(), Arg("parent"))
            .define_method("_initialize_value", &Bando_QTimer::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQTranslator =
        define_class_under<Bando_QTranslator, QTranslator>(rb_mQt6Bando, "QTranslator")
            .define_constructor(Constructor<Bando_QTranslator, QObject *>(), Arg("parent"))
            .define_method("_initialize_value", &Bando_QTranslator::initializeValue, Arg("mo"), Arg("value"));
}
