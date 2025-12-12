#include "t-qtdbus-rb.hpp"
#include <rice/qt6/qdbusreply.hpp>

#include <QList>

RICE4RUBYQT6_USE_NAMESPACE

void Init_t_qtdbus(Module rb_mQt6T)
{
    // QDBusReply<QList<QString>>
    define_qdbusreply_under<QList<QString>>(rb_mQt6T);
}
