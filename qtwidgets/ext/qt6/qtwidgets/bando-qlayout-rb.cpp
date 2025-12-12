#include "bando-qlayout-rb.hpp"
#include <bando/qobject/qlayout.hpp>

#include <QLayout>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QLayout = BandoQLayout<QLayout, QWidget *>;

Class rb_mBando_cQLayout;

void Init_bando_qlayout(Module rb_mQt6Bando)
{
    rb_mBando_cQLayout =
        define_bando_qlayout_under<Bando_QLayout, QLayout>(rb_mQt6Bando, "QLayout")
            .define_constructor(Constructor<Bando_QLayout, QWidget *>(), Arg("parent"));
}
