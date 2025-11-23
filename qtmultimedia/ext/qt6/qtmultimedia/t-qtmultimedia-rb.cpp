#include "t-qtmultimedia-rb.hpp"
#include <rice/qt6/qlist.hpp>

#include <QAudioDevice>
#include <QCameraDevice>
#include <QMediaFormat>

using namespace Rice;

void Init_t_qtmultimedia(Rice::Module rb_mQt6T)
{
    // QList<QAudioDevice>
    define_qlist_under<QAudioDevice>(rb_mQt6T);

    // QList<QCameraDevice>
    define_qlist_under<QCameraDevice>(rb_mQt6T);

    // QList<QMediaFormat::FileFormat>
    define_qlist_under<QMediaFormat::FileFormat>(rb_mQt6T);
}
