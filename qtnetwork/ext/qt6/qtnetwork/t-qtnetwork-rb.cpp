#include "t-qtnetwork-rb.hpp"
#include <rice/qt6/qlist.hpp>

#include <QNetworkProxy>

using namespace Rice;

void Init_t_qtnetwork(Rice::Module rb_mQt6T)
{
    // QList<QNetworkProxy>
    define_qlist_under<QNetworkProxy>(rb_mQt6T);
}
