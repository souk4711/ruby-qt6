#include "bando-qvalidator-rb.hpp"
#include <bando/qobject.hpp>

#include <QDoubleValidator>
#include <QIntValidator>
#include <QRegularExpressionValidator>

using namespace Rice;

using Bando_QDoubleValidator = BandoQObject<QDoubleValidator, QObject *>;
using Bando_QIntValidator = BandoQObject<QIntValidator, QObject *>;
using Bando_QRegularExpressionValidator = BandoQObject<QRegularExpressionValidator, QObject *>;

Rice::Class rb_mBando_cQDoubleValidator;
Rice::Class rb_mBando_cQIntValidator;
Rice::Class rb_mBando_cQRegularExpressionValidator;

void Init_bando_qvalidator(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQDoubleValidator =
        define_bando_qobject_under<Bando_QDoubleValidator, QDoubleValidator>(rb_mQt6Bando, "QDoubleValidator")
            .define_constructor(Constructor<Bando_QDoubleValidator, QObject *>(), Arg("parent"));

    rb_mBando_cQIntValidator =
        define_bando_qobject_under<Bando_QIntValidator, QIntValidator>(rb_mQt6Bando, "QIntValidator")
            .define_constructor(Constructor<Bando_QIntValidator, QObject *>(), Arg("parent"));

    rb_mBando_cQRegularExpressionValidator =
        define_bando_qobject_under<Bando_QRegularExpressionValidator, QRegularExpressionValidator>(rb_mQt6Bando, "QRegularExpressionValidator")
            .define_constructor(Constructor<Bando_QRegularExpressionValidator, QObject *>(), Arg("parent"));
}
