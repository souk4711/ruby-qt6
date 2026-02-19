#include "t-kcoreaddons-rb.hpp"
#include <rice/qt6/qlist.hpp>

#include <KAboutData>

RICE4RUBYQT6_USE_NAMESPACE

void Init_t_kcoreaddons(Module rb_mQt6T)
{
    // QList<KAboutPerson>
    define_qlist_under<KAboutPerson>(rb_mQt6T);
}
