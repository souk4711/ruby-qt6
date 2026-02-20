#include "bando-kseparator-rb.hpp"
#include <bando/qwidget.hpp>

#include <KSeparator>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_KSeparator = BandoQWidget<KSeparator, Qt::Orientation, QWidget *>;

Class rb_mBando_cKSeparator;

void Init_bando_kseparator(Module rb_mQt6Bando)
{
    rb_mBando_cKSeparator =
        define_bando_qwidget_under<Bando_KSeparator, KSeparator>(rb_mQt6Bando, "KSeparator")
            .define_constructor(Constructor<Bando_KSeparator, Qt::Orientation, QWidget *>(), Arg("orientation"), Arg("parent"));
}
