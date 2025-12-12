#include "bando-qwizard-rb.hpp"
#include <bando/qwidget.hpp>

#include <QWizard>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QWizard = BandoQWidget<QWizard, QWidget *>;

Class rb_mBando_cQWizard;

void Init_bando_qwizard(Module rb_mQt6Bando)
{
    rb_mBando_cQWizard =
        define_bando_qwidget_under<Bando_QWizard, QWizard>(rb_mQt6Bando, "QWizard")
            .define_constructor(Constructor<Bando_QWizard, QWidget *>(), Arg("parent"));
}
