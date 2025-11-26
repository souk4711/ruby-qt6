#include "qmovie-rb.hpp"
#include <qmovie.h>
#include <rice/qt6/qenum.hpp>

#include <QBindable>
#include <QPixmap>

using namespace Rice;

Rice::Class rb_cQMovie;

void Init_qmovie(Rice::Module rb_mQt6QtGui)
{
    rb_cQMovie =
        // RubyQt6::QtGui::QMovie
        define_class_under<QMovie, QObject>(rb_mQt6QtGui, "QMovie")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QMovie::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QMovie, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("background_color", &QMovie::backgroundColor)
            .define_method("bindable_cache_mode", &QMovie::bindableCacheMode)
            .define_method("bindable_speed", &QMovie::bindableSpeed)
            .define_method("cache_mode", &QMovie::cacheMode)
            .define_method("current_frame_number", &QMovie::currentFrameNumber)
            .define_method("current_image", &QMovie::currentImage)
            .define_method("current_pixmap", &QMovie::currentPixmap)
            .define_method("device", &QMovie::device)
            .define_method("file_name", &QMovie::fileName)
            .define_method("format", &QMovie::format)
            .define_method("frame_count", &QMovie::frameCount)
            .define_method("frame_rect", &QMovie::frameRect)
            .define_method("valid?", &QMovie::isValid)
            .define_method("jump_to_frame", &QMovie::jumpToFrame, Arg("frame_number"))
            .define_method("last_error", &QMovie::lastError)
            .define_method("last_error_string", &QMovie::lastErrorString)
            .define_method("loop_count", &QMovie::loopCount)
            .define_method("next_frame_delay", &QMovie::nextFrameDelay)
            .define_method("scaled_size", &QMovie::scaledSize)
            .define_method("set_background_color", &QMovie::setBackgroundColor, Arg("color"))
            .define_method("set_cache_mode", &QMovie::setCacheMode, Arg("mode"))
            .define_method("set_device", &QMovie::setDevice, Arg("device"))
            .define_method("set_file_name", &QMovie::setFileName, Arg("file_name"))
            .define_method("set_format", &QMovie::setFormat, Arg("format"))
            .define_method("set_scaled_size", &QMovie::setScaledSize, Arg("size"))
            .define_method("speed", &QMovie::speed)
            .define_method("state", &QMovie::state)
            // Public Slots
            .define_method("jump_to_next_frame", &QMovie::jumpToNextFrame)
            .define_method("set_paused", &QMovie::setPaused, Arg("paused"))
            .define_method("set_speed", &QMovie::setSpeed, Arg("percent_speed"))
            .define_method("start", &QMovie::start)
            .define_method("stop", &QMovie::stop)
            // Signals
            // .define_method("error", &QMovie::error, Arg("error"))
            // .define_method("finished", &QMovie::finished)
            // .define_method("frame_changed", &QMovie::frameChanged, Arg("frame_number"))
            // .define_method("resized", &QMovie::resized, Arg("size"))
            // .define_method("started", &QMovie::started)
            // .define_method("state_changed", &QMovie::stateChanged, Arg("state"))
            // .define_method("updated", &QMovie::updated, Arg("rect"))
            // Static Public Members
            .define_singleton_function("supported_formats", &QMovie::supportedFormats);

    Data_Type<QMovie::CacheMode> rb_cQMovieCacheMode =
        // RubyQt6::QtGui::QMovie::CacheMode
        define_qenum_under<QMovie::CacheMode>(rb_cQMovie, "CacheMode");
        define_qenum_value_under(rb_cQMovieCacheMode, "CacheNone", QMovie::CacheMode::CacheNone);
        define_qenum_value_under(rb_cQMovieCacheMode, "CacheAll", QMovie::CacheMode::CacheAll);

    Data_Type<QMovie::MovieState> rb_cQMovieMovieState =
        // RubyQt6::QtGui::QMovie::MovieState
        define_qenum_under<QMovie::MovieState>(rb_cQMovie, "MovieState");
        define_qenum_value_under(rb_cQMovieMovieState, "NotRunning", QMovie::MovieState::NotRunning);
        define_qenum_value_under(rb_cQMovieMovieState, "Paused", QMovie::MovieState::Paused);
        define_qenum_value_under(rb_cQMovieMovieState, "Running", QMovie::MovieState::Running);
}
