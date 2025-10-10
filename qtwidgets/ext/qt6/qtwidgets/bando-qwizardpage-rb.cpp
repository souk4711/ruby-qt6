#include "bando-qwizardpage-rb.hpp"
#include <bando/qwidget.hpp>

#include <QWizardPage>

using namespace Rice;

using Bando_QWizardPage = BandoQWidget<QWizardPage, QWidget *>;

Rice::Class rb_mBando_cQWizardPage;

void Init_bando_qwizardpage(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQWizardPage =
        define_bando_qwidget_under<Bando_QWizardPage, QWizardPage>(rb_mQt6Bando, "QWizardPage")
            .define_constructor(Constructor<Bando_QWizardPage, QWidget *>(), Arg("parent"));
}
