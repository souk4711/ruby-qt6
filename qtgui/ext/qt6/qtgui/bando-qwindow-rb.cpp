#include "bando-qwindow-rb.hpp"
#include <bando/qobject/qwindow.hpp>

#include <QWindow>

using namespace Rice;

using Bando_QWindow = BandoQWindow<QWindow, QWindow *>;

Rice::Class rb_mBando_cQWindow;

void Init_bando_qwindow(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQWindow =
        define_bando_qwindow_under<Bando_QWindow, QWindow>(rb_mQt6Bando, "QWindow")
            .define_constructor(Constructor<Bando_QWindow, QWindow *>(), Arg("parent"));
}
