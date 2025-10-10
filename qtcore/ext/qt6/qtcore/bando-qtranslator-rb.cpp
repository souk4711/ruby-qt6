#include "bando-qtranslator-rb.hpp"
#include <bando/qobject.hpp>

#include <QTranslator>

using namespace Rice;

using Bando_QTranslator = BandoQObject<QTranslator, QObject *>;

Rice::Class rb_mBando_cQTranslator;

void Init_bando_qtranslator(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQTranslator =
        define_bando_qobject_under<Bando_QTranslator, QTranslator>(rb_mQt6Bando, "QTranslator")
            .define_constructor(Constructor<Bando_QTranslator, QObject *>(), Arg("parent"));
}
