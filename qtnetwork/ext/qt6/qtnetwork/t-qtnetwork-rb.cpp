#include "t-qtnetwork-rb.hpp"
#include <rice/qt6/qlist.hpp>

#include <QNetworkProxy>

RICE4RUBYQT6_USE_NAMESPACE

void Init_t_qtnetwork(Module rb_mQt6T)
{
    // QList<QNetworkProxy>
    define_qlist_under<QNetworkProxy>(rb_mQt6T);
}
