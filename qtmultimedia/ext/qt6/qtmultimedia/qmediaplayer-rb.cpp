#include "qmediaplayer-rb.hpp"
#include <qmediaplayer.h>
#include <rice/qt6/qenum.hpp>

#include <QIODevice>
#include <QAudioBufferOutput>
#include <QAudioOutput>
#include <QMediaMetaData>
#include <QMediaTimeRange>
#include <QVideoSink>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQMediaPlayer;

void Init_qmediaplayer(Module rb_mQt6QtMultimedia)
{
    rb_cQMediaPlayer =
        // RubyQt6::QtMultimedia::QMediaPlayer
        define_class_under<QMediaPlayer, QObject>(rb_mQt6QtMultimedia, "QMediaPlayer")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QMediaPlayer::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QMediaPlayer, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("active_audio_track", &QMediaPlayer::activeAudioTrack)
            .define_method("active_subtitle_track", &QMediaPlayer::activeSubtitleTrack)
            .define_method("active_video_track", &QMediaPlayer::activeVideoTrack)
            .define_method("audio_buffer_output", &QMediaPlayer::audioBufferOutput)
            .define_method("audio_output", &QMediaPlayer::audioOutput)
            .define_method("audio_tracks", &QMediaPlayer::audioTracks)
            .define_method("buffer_progress", &QMediaPlayer::bufferProgress)
            .define_method("buffered_time_range", &QMediaPlayer::bufferedTimeRange)
            .define_method("duration", &QMediaPlayer::duration)
            .define_method("error", &QMediaPlayer::error)
            .define_method("error_string", &QMediaPlayer::errorString)
            .define_method("has_audio", &QMediaPlayer::hasAudio)
            .define_method("has_video", &QMediaPlayer::hasVideo)
            .define_method("available?", &QMediaPlayer::isAvailable)
            .define_method("playing?", &QMediaPlayer::isPlaying)
            .define_method("seekable?", &QMediaPlayer::isSeekable)
            .define_method("loops", &QMediaPlayer::loops)
            .define_method("media_status", &QMediaPlayer::mediaStatus)
            .define_method("meta_data", &QMediaPlayer::metaData)
            .define_method("playback_rate", &QMediaPlayer::playbackRate)
            .define_method("playback_state", &QMediaPlayer::playbackState)
            .define_method("position", &QMediaPlayer::position)
            .define_method("set_active_audio_track", &QMediaPlayer::setActiveAudioTrack, Arg("index"))
            .define_method("set_active_subtitle_track", &QMediaPlayer::setActiveSubtitleTrack, Arg("index"))
            .define_method("set_active_video_track", &QMediaPlayer::setActiveVideoTrack, Arg("index"))
            .define_method("set_audio_buffer_output", &QMediaPlayer::setAudioBufferOutput, Arg("output"))
            .define_method("set_audio_output", &QMediaPlayer::setAudioOutput, Arg("output"))
            .define_method("set_loops", &QMediaPlayer::setLoops, Arg("loops"))
            .define_method("set_video_output", &QMediaPlayer::setVideoOutput, Arg("output"))
            .define_method("set_video_sink", &QMediaPlayer::setVideoSink, Arg("sink"))
            .define_method("source", &QMediaPlayer::source)
            .define_method("source_device", &QMediaPlayer::sourceDevice)
            .define_method("subtitle_tracks", &QMediaPlayer::subtitleTracks)
            .define_method("video_output", &QMediaPlayer::videoOutput)
            .define_method("video_sink", &QMediaPlayer::videoSink)
            .define_method("video_tracks", &QMediaPlayer::videoTracks)
            // Public Slots
            .define_method("pause", &QMediaPlayer::pause)
            .define_method("play", &QMediaPlayer::play)
            .define_method("set_playback_rate", &QMediaPlayer::setPlaybackRate, Arg("rate"))
            .define_method("set_position", &QMediaPlayer::setPosition, Arg("position"))
            .define_method("set_source", &QMediaPlayer::setSource, Arg("source"))
            .define_method("set_source_device", &QMediaPlayer::setSourceDevice, Arg("device"), Arg("source_url") = static_cast<const QUrl &>(QUrl()))
            .define_method("stop", &QMediaPlayer::stop);
            // Signals
            // .define_method("active_tracks_changed", &QMediaPlayer::activeTracksChanged)
            // .define_method("audio_buffer_output_changed", &QMediaPlayer::audioBufferOutputChanged)
            // .define_method("audio_output_changed", &QMediaPlayer::audioOutputChanged)
            // .define_method("buffer_progress_changed", &QMediaPlayer::bufferProgressChanged, Arg("progress"))
            // .define_method("duration_changed", &QMediaPlayer::durationChanged, Arg("duration"))
            // .define_method("error_changed", &QMediaPlayer::errorChanged)
            // .define_method("error_occurred", &QMediaPlayer::errorOccurred, Arg("error"), Arg("error_string"))
            // .define_method("has_audio_changed", &QMediaPlayer::hasAudioChanged, Arg("available"))
            // .define_method("has_video_changed", &QMediaPlayer::hasVideoChanged, Arg("video_available"))
            // .define_method("loops_changed", &QMediaPlayer::loopsChanged)
            // .define_method("media_status_changed", &QMediaPlayer::mediaStatusChanged, Arg("status"))
            // .define_method("meta_data_changed", &QMediaPlayer::metaDataChanged)
            // .define_method("playback_rate_changed", &QMediaPlayer::playbackRateChanged, Arg("rate"))
            // .define_method("playback_state_changed", &QMediaPlayer::playbackStateChanged, Arg("new_state"))
            // .define_method("playing_changed", &QMediaPlayer::playingChanged, Arg("playing"))
            // .define_method("position_changed", &QMediaPlayer::positionChanged, Arg("position"))
            // .define_method("seekable_changed", &QMediaPlayer::seekableChanged, Arg("seekable"))
            // .define_method("source_changed", &QMediaPlayer::sourceChanged, Arg("media"))
            // .define_method("tracks_changed", &QMediaPlayer::tracksChanged)
            // .define_method("video_output_changed", &QMediaPlayer::videoOutputChanged);

    Data_Type<QMediaPlayer::Error> rb_cQMediaPlayerError =
        // RubyQt6::QtMultimedia::QMediaPlayer::Error
        define_qenum_under<QMediaPlayer::Error>(rb_cQMediaPlayer, "Error");
        define_qenum_value_under(rb_cQMediaPlayerError, "NoError", QMediaPlayer::Error::NoError);
        define_qenum_value_under(rb_cQMediaPlayerError, "ResourceError", QMediaPlayer::Error::ResourceError);
        define_qenum_value_under(rb_cQMediaPlayerError, "FormatError", QMediaPlayer::Error::FormatError);
        define_qenum_value_under(rb_cQMediaPlayerError, "NetworkError", QMediaPlayer::Error::NetworkError);
        define_qenum_value_under(rb_cQMediaPlayerError, "AccessDeniedError", QMediaPlayer::Error::AccessDeniedError);

    Data_Type<QMediaPlayer::Loops> rb_cQMediaPlayerLoops =
        // RubyQt6::QtMultimedia::QMediaPlayer::Loops
        define_qenum_under<QMediaPlayer::Loops>(rb_cQMediaPlayer, "Loops");
        define_qenum_value_under(rb_cQMediaPlayerLoops, "Infinite", QMediaPlayer::Loops::Infinite);
        define_qenum_value_under(rb_cQMediaPlayerLoops, "Once", QMediaPlayer::Loops::Once);

    Data_Type<QMediaPlayer::MediaStatus> rb_cQMediaPlayerMediaStatus =
        // RubyQt6::QtMultimedia::QMediaPlayer::MediaStatus
        define_qenum_under<QMediaPlayer::MediaStatus>(rb_cQMediaPlayer, "MediaStatus");
        define_qenum_value_under(rb_cQMediaPlayerMediaStatus, "NoMedia", QMediaPlayer::MediaStatus::NoMedia);
        define_qenum_value_under(rb_cQMediaPlayerMediaStatus, "LoadingMedia", QMediaPlayer::MediaStatus::LoadingMedia);
        define_qenum_value_under(rb_cQMediaPlayerMediaStatus, "LoadedMedia", QMediaPlayer::MediaStatus::LoadedMedia);
        define_qenum_value_under(rb_cQMediaPlayerMediaStatus, "StalledMedia", QMediaPlayer::MediaStatus::StalledMedia);
        define_qenum_value_under(rb_cQMediaPlayerMediaStatus, "BufferingMedia", QMediaPlayer::MediaStatus::BufferingMedia);
        define_qenum_value_under(rb_cQMediaPlayerMediaStatus, "BufferedMedia", QMediaPlayer::MediaStatus::BufferedMedia);
        define_qenum_value_under(rb_cQMediaPlayerMediaStatus, "EndOfMedia", QMediaPlayer::MediaStatus::EndOfMedia);
        define_qenum_value_under(rb_cQMediaPlayerMediaStatus, "InvalidMedia", QMediaPlayer::MediaStatus::InvalidMedia);

    Data_Type<QMediaPlayer::PlaybackState> rb_cQMediaPlayerPlaybackState =
        // RubyQt6::QtMultimedia::QMediaPlayer::PlaybackState
        define_qenum_under<QMediaPlayer::PlaybackState>(rb_cQMediaPlayer, "PlaybackState");
        define_qenum_value_under(rb_cQMediaPlayerPlaybackState, "StoppedState", QMediaPlayer::PlaybackState::StoppedState);
        define_qenum_value_under(rb_cQMediaPlayerPlaybackState, "PlayingState", QMediaPlayer::PlaybackState::PlayingState);
        define_qenum_value_under(rb_cQMediaPlayerPlaybackState, "PausedState", QMediaPlayer::PlaybackState::PausedState);
}
