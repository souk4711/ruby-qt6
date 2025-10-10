#include "bando-qitemselectionmodel-rb.hpp"
#include <bando/qobject.hpp>

#include <QItemSelectionModel>

using namespace Rice;

using Bando_QItemSelectionModel = BandoQObject<QItemSelectionModel, QAbstractItemModel *, QObject *>;

Rice::Class rb_mBando_cQItemSelectionModel;

void Init_bando_qitemselectionmodel(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQItemSelectionModel =
        define_bando_qobject_under<Bando_QItemSelectionModel, QItemSelectionModel>(rb_mQt6Bando, "QItemSelectionModel")
            .define_constructor(Constructor<Bando_QItemSelectionModel, QAbstractItemModel *, QObject *>(), Arg("model"), Arg("parent"));
}
