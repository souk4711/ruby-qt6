#include "qtaudio-rb.hpp"
#include <qtaudio.h>
#include <rice/qt6/qenum.hpp>

using namespace Rice;

void Init_qtaudio(Rice::Module rb_mQt6QtMultimedia)
{
    Module rb_mQtAudio =
        // RubyQt6::QtMultimedia::QtAudio
        define_module_under(rb_mQt6QtMultimedia, "QtAudio")
            .define_module_function("convert_volume", &QtAudio::convertVolume, Arg("volume"), Arg("from"), Arg("to"));

    Data_Type<QtAudio::Error> rb_cQtAudioError =
        // RubyQt6::QtMultimedia::QtAudio::Error
        define_qenum_under<QtAudio::Error>(rb_mQtAudio, "Error");
        define_qenum_value_under(rb_cQtAudioError, "NoError", QtAudio::Error::NoError);
        define_qenum_value_under(rb_cQtAudioError, "OpenError", QtAudio::Error::OpenError);
        define_qenum_value_under(rb_cQtAudioError, "IOError", QtAudio::Error::IOError);
        define_qenum_value_under(rb_cQtAudioError, "UnderrunError", QtAudio::Error::UnderrunError);
        define_qenum_value_under(rb_cQtAudioError, "FatalError", QtAudio::Error::FatalError);

    Data_Type<QtAudio::State> rb_cQtAudioState =
        // RubyQt6::QtMultimedia::QtAudio::State
        define_qenum_under<QtAudio::State>(rb_mQtAudio, "State");
        define_qenum_value_under(rb_cQtAudioState, "ActiveState", QtAudio::State::ActiveState);
        define_qenum_value_under(rb_cQtAudioState, "SuspendedState", QtAudio::State::SuspendedState);
        define_qenum_value_under(rb_cQtAudioState, "StoppedState", QtAudio::State::StoppedState);
        define_qenum_value_under(rb_cQtAudioState, "IdleState", QtAudio::State::IdleState);

    Data_Type<QtAudio::VolumeScale> rb_cQtAudioVolumeScale =
        // RubyQt6::QtMultimedia::QtAudio::VolumeScale
        define_qenum_under<QtAudio::VolumeScale>(rb_mQtAudio, "VolumeScale");
        define_qenum_value_under(rb_cQtAudioVolumeScale, "LinearVolumeScale", QtAudio::VolumeScale::LinearVolumeScale);
        define_qenum_value_under(rb_cQtAudioVolumeScale, "CubicVolumeScale", QtAudio::VolumeScale::CubicVolumeScale);
        define_qenum_value_under(rb_cQtAudioVolumeScale, "LogarithmicVolumeScale", QtAudio::VolumeScale::LogarithmicVolumeScale);
        define_qenum_value_under(rb_cQtAudioVolumeScale, "DecibelVolumeScale", QtAudio::VolumeScale::DecibelVolumeScale);
}
