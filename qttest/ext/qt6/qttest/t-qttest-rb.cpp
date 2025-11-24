#include "t-qttest-rb.hpp"
#include <rice/qt6/qlist.hpp>

#include <QVariant>

void Init_t_qttest(Rice::Module rb_mQt6T)
{
    // QList<QList<QVariant>>
    define_qlist_under<QList<QVariant>>(rb_mQt6T);
}
