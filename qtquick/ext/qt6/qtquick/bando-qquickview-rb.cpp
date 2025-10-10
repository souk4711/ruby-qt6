#include "bando-qquickview-rb.hpp"
#include <bando/qwindow.hpp>

#include <QQuickView>

using namespace Rice;

using Bando_QQuickView = BandoQWindow<QQuickView, QWindow *>;

Rice::Class rb_mBando_cQQuickView;

void Init_bando_qquickview(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQQuickView =
        define_bando_qwindow_under<Bando_QQuickView, QQuickView>(rb_mQt6Bando, "QQuickView")
            .define_constructor(Constructor<Bando_QQuickView, QWindow *>(), Arg("parent"));
}
