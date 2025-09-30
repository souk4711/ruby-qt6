#include "t-qtwidgets-rb.hpp"

#include <rice/qlist.hpp>
#include <QTreeWidgetItem>

using namespace Rice;

void Init_t_qtwidgets(Rice::Module rb_mQt6T)
{
    define_qlist_under<QTreeWidgetItem*>(rb_mQt6T);
}
