#include "t-qtmultimedia-rb.hpp"
#include <rice/qt6/qlist.hpp>

#include <QAudioDevice>
#include <QCameraDevice>
#include <QMediaFormat>

RICE4RUBYQT6_USE_NAMESPACE

void Init_t_qtmultimedia(Module rb_mQt6T)
{
    // QList<QAudioDevice>
    define_qlist_under<QAudioDevice>(rb_mQt6T);

    // QList<QCameraDevice>
    define_qlist_under<QCameraDevice>(rb_mQt6T);

    // QList<QMediaFormat::FileFormat>
    define_qlist_under<QMediaFormat::FileFormat>(rb_mQt6T);
}
