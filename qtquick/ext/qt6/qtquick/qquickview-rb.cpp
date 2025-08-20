#include "qquickview-rb.hpp"
#include <QQuickView>

using namespace Rice;

Rice::Class rb_cQQuickView;

void Init_QQuickView(Rice::Module rb_mQt6QtQucik)
{
    rb_cQQuickView =
        // Qt6::QtQucik::QQuickView
        define_class<QQuickView, QQuickWindow>("QQuickView");
}
