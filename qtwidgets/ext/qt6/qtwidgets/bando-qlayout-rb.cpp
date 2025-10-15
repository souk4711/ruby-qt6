#include "bando-qlayout-rb.hpp"
#include <bando/qlayout.hpp>

#include <QLayout>

using namespace Rice;

using Bando_QLayout = BandoQLayout<QLayout, QWidget *>;

Rice::Class rb_mBando_cQLayout;

void Init_bando_qlayout(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQLayout =
        define_bando_qlayout_under<Bando_QLayout, QLayout>(rb_mQt6Bando, "QLayout")
            .define_constructor(Constructor<Bando_QLayout, QWidget *>(), Arg("parent"));
}
