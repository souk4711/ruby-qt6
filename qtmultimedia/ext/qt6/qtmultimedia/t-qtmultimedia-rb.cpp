#include "t-qtwidgets-rb.hpp"
#include <rice/qt6/qlist.hpp>

#include <QAudioDevice>
#include <QCameraDevice>

using namespace Rice;

void Init_t_qtmultimedia(Rice::Module rb_mQt6T)
{
    // QList<QAudioDevice>
    define_qlist_under<QAudioDevice>(rb_mQt6T);

    // QList<QCameraDevice>
    define_qlist_under<QCameraDevice>(rb_mQt6T);
}
