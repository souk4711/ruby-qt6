#include "bando-qsortfilterproxymodel-rb.hpp"
#include <bando/qobject/qsortfilterproxymodel.hpp>

#include <QSortFilterProxyModel>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QSortFilterProxyModel = BandoQSortFilterProxyModel<QSortFilterProxyModel, QSortFilterProxyModel *>;

Class rb_mBando_cQSortFilterProxyModel;

void Init_bando_qsortfilterproxymodel(Module rb_mQt6Bando)
{
    rb_mBando_cQSortFilterProxyModel =
        define_bando_qsortfilterproxymodel_under<Bando_QSortFilterProxyModel, QSortFilterProxyModel>(rb_mQt6Bando, "QSortFilterProxyModel")
            .define_constructor(Constructor<Bando_QSortFilterProxyModel, QSortFilterProxyModel *>(), Arg("parent"));
}
