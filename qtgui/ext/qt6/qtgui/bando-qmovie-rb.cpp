#include "bando-qmovie-rb.hpp"
#include <bando/qobject.hpp>

#include <QMovie>

using namespace Rice;

using Bando_QMovie = BandoQObject<QMovie, QObject *>;

Rice::Class rb_mBando_cQMovie;

void Init_bando_qmovie(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQMovie =
        define_bando_qobject_under<Bando_QMovie, QMovie>(rb_mQt6Bando, "QMovie")
            .define_constructor(Constructor<Bando_QMovie, QObject *>(), Arg("parent"));
}
