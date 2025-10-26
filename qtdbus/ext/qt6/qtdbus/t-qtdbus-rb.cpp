#include "t-qtdbus-rb.hpp"
#include <rice/qdbusreply.hpp>

#include <QList>

using namespace Rice;

void Init_t_qtdbus(Rice::Module rb_mQt6T)
{
    // QDBusReply<QList<QString>>
    define_qdbusreply_under<QList<QString>>(rb_mQt6T);
}
