#include "t-qtcore-rb.hpp"

#include <rice/qlist.hpp>

using namespace Rice;

void Init_t_qtcore(Rice::Module rb_mQt6T)
{
    define_qlist_under<QString>(rb_mQt6T);
}
