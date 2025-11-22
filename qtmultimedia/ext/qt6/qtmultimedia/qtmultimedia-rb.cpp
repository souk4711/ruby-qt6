#include "qtmultimedia-rb.hpp"
#include "qtmultimediaversion-rb.hpp"
#include "qtaudio-rb.hpp"
#include "qtvideo-rb.hpp"

#include "qaudiodevice-rb.hpp"
#include "qaudioformat-rb.hpp"
#include "qcameradevice-rb.hpp"
#include "qcameraformat-rb.hpp"
#include "qmediaformat-rb.hpp"

#include "qaudioinput-rb.hpp"
#include "qaudiooutput-rb.hpp"
#include "qaudiosink-rb.hpp"
#include "qaudiosource-rb.hpp"

#include "qmediadevices-rb.hpp"
#include "qmediaplayer-rb.hpp"

#include "t-qtmultimedia-rb.hpp"

extern "C" void Init_qtmultimedia()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtMultimedia = define_module_under(rb_mQt6, "QtMultimedia");

        Init_qtmultimediaversion(rb_mQt6QtMultimedia);
        Init_qtaudio(rb_mQt6QtMultimedia);
        Init_qtvideo(rb_mQt6QtMultimedia);

        Init_qaudiodevice(rb_mQt6QtMultimedia);
        Init_qaudioformat(rb_mQt6QtMultimedia);
        Init_qcameradevice(rb_mQt6QtMultimedia);
        Init_qcameraformat(rb_mQt6QtMultimedia);
        Init_qmediaformat(rb_mQt6QtMultimedia);

        Init_qaudioinput(rb_mQt6QtMultimedia);
        Init_qaudiooutput(rb_mQt6QtMultimedia);
        Init_qaudiosink(rb_mQt6QtMultimedia);
        Init_qaudiosource(rb_mQt6QtMultimedia);
        Init_qmediadevices(rb_mQt6QtMultimedia);
        Init_qmediaplayer(rb_mQt6QtMultimedia);

        Rice::Module rb_mQt6T = define_module_under(rb_mQt6, "T");
        Init_t_qtmultimedia(rb_mQt6T);
    });
}
