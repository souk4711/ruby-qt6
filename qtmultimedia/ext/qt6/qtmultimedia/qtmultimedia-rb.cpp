#include "qtmultimedia-rb.hpp"
#include "qtmultimediaversion-rb.hpp"
#include "qtaudio-rb.hpp"
#include "qtvideo-rb.hpp"

#include "qaudiodevice-rb.hpp"
#include "qaudioformat-rb.hpp"
#include "qcameradevice-rb.hpp"
#include "qcameraformat-rb.hpp"
#include "qcapturablewindow-rb.hpp"
#include "qmediaformat-rb.hpp"
#include "qmediametadata-rb.hpp"
#include "qvideoframe-rb.hpp"
#include "qvideoframeformat-rb.hpp"

#include "qaudioinput-rb.hpp"
#include "qaudiooutput-rb.hpp"
#include "qaudiosink-rb.hpp"
#include "qaudiosource-rb.hpp"
#include "qcamera-rb.hpp"
#include "qimagecapture-rb.hpp"
#include "qmediacapturesession-rb.hpp"
#include "qmediadevices-rb.hpp"
#include "qmediaplayer-rb.hpp"
#include "qmediarecorder-rb.hpp"
#include "qscreencapture-rb.hpp"
#include "qsoundeffect-rb.hpp"
#include "qwindowcapture-rb.hpp"
#include "qvideoframeinput-rb.hpp"
#include "qvideosink-rb.hpp"

#include "t-qtmultimedia-rb.hpp"

RICE4RUBYQT6_USE_NAMESPACE

extern "C" void Init_qtmultimedia()
{
    return detail::cpp_protect([] {
        Module rb_mQt6 = define_module("RubyQt6");
        Module rb_mQt6QtMultimedia = define_module_under(rb_mQt6, "QtMultimedia");

        Init_qtmultimediaversion(rb_mQt6QtMultimedia);
        Init_qtaudio(rb_mQt6QtMultimedia);
        Init_qtvideo(rb_mQt6QtMultimedia);

        Init_qaudiodevice(rb_mQt6QtMultimedia);
        Init_qaudioformat(rb_mQt6QtMultimedia);
        Init_qcameradevice(rb_mQt6QtMultimedia);
        Init_qcameraformat(rb_mQt6QtMultimedia);
        Init_qcapturablewindow(rb_mQt6QtMultimedia);
        Init_qmediaformat(rb_mQt6QtMultimedia);
        Init_qmediametadata(rb_mQt6QtMultimedia);
        Init_qvideoframe(rb_mQt6QtMultimedia);
        Init_qvideoframeformat(rb_mQt6QtMultimedia);

        Init_qaudioinput(rb_mQt6QtMultimedia);
        Init_qaudiooutput(rb_mQt6QtMultimedia);
        Init_qaudiosink(rb_mQt6QtMultimedia);
        Init_qaudiosource(rb_mQt6QtMultimedia);
        Init_qcamera(rb_mQt6QtMultimedia);
        Init_qimagecapture(rb_mQt6QtMultimedia);
        Init_qmediacapturesession(rb_mQt6QtMultimedia);
        Init_qmediadevices(rb_mQt6QtMultimedia);
        Init_qmediaplayer(rb_mQt6QtMultimedia);
        Init_qmediarecorder(rb_mQt6QtMultimedia);
        Init_qsoundeffect(rb_mQt6QtMultimedia);
        Init_qscreencapture(rb_mQt6QtMultimedia);
        Init_qvideoframeinput(rb_mQt6QtMultimedia);
        Init_qvideosink(rb_mQt6QtMultimedia);
        Init_qwindowcapture(rb_mQt6QtMultimedia);

        Module rb_mQt6T = define_module_under(rb_mQt6, "T");
        Init_t_qtmultimedia(rb_mQt6T);
    });
}
