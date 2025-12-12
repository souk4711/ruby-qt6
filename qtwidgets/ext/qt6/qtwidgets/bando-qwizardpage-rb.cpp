#include "bando-qwizardpage-rb.hpp"
#include <bando/qwidget.hpp>

#include <QWizardPage>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QWizardPage = BandoQWidget<QWizardPage, QWidget *>;

Class rb_mBando_cQWizardPage;

void Init_bando_qwizardpage(Module rb_mQt6Bando)
{
    rb_mBando_cQWizardPage =
        define_bando_qwidget_under<Bando_QWizardPage, QWizardPage>(rb_mQt6Bando, "QWizardPage")
            .define_constructor(Constructor<Bando_QWizardPage, QWidget *>(), Arg("parent"));
}
