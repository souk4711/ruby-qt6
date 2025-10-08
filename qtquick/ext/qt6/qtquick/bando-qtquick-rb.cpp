#include "bando-qtquick-rb.hpp"
#include <bando/qquickitem.hpp>
#include <bando/qwindow.hpp>

#include <QQuickItem>
#include <QQuickWindow>
#include <QQuickView>

using namespace Rice;

using Bando_QQuickItem = BandoQQuickItem<QQuickItem, QQuickItem *>;
using Bando_QQuickWindow = BandoQWindow<QQuickWindow, QWindow *>;
using Bando_QQuickView = BandoQWindow<QQuickView, QWindow *>;

Rice::Class rb_mBando_cQQuickItem;
Rice::Class rb_mBando_cQQuickWindow;
Rice::Class rb_mBando_cQQuickView;

void Init_bando_qtquick(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQQuickItem =
        define_bando_qquickitem_under<Bando_QQuickItem, QQuickItem>(rb_mQt6Bando, "QQuickItem")
            .define_constructor(Constructor<Bando_QQuickItem, QQuickItem *>(), Arg("parent"));

    rb_mBando_cQQuickWindow =
        define_bando_qwindow_under<Bando_QQuickWindow, QQuickWindow>(rb_mQt6Bando, "QQuickWindow")
            .define_constructor(Constructor<Bando_QQuickWindow, QWindow *>(), Arg("parent"));

    rb_mBando_cQQuickView =
        define_bando_qwindow_under<Bando_QQuickView, QQuickView>(rb_mQt6Bando, "QQuickView")
            .define_constructor(Constructor<Bando_QQuickView, QWindow *>(), Arg("parent"));
}
