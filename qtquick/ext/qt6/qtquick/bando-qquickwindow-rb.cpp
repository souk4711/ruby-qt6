#include "bando-qquickwindow-rb.hpp"
#include <bando/qobject/qwindow.hpp>

#include <QQuickWindow>

using namespace Rice;

using Bando_QQuickWindow = BandoQWindow<QQuickWindow, QWindow *>;

Rice::Class rb_mBando_cQQuickWindow;

void Init_bando_qquickwindow(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQQuickWindow =
        define_bando_qwindow_under<Bando_QQuickWindow, QQuickWindow>(rb_mQt6Bando, "QQuickWindow")
            .define_constructor(Constructor<Bando_QQuickWindow, QWindow *>(), Arg("parent"));
}
