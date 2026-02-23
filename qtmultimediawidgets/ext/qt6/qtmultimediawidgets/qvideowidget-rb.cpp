#include "qvideowidget-rb.hpp"
#include <qvideowidget.h>

#include <QVideoSink>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQVideoWidget;

void Init_qvideowidget(Module rb_mQt6QtMultimediaWidgets)
{
    rb_cQVideoWidget =
        // RubyQt6::QtMultimediaWidgets::QVideoWidget
        define_qlass_under<QVideoWidget, QWidget>(rb_mQt6QtMultimediaWidgets, "QVideoWidget")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QVideoWidget::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QVideoWidget, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("aspect_ratio_mode", &QVideoWidget::aspectRatioMode)
            .define_method("video_sink", &QVideoWidget::videoSink)
            // Public Slots
            .define_method("set_aspect_ratio_mode", &QVideoWidget::setAspectRatioMode, Arg("mode"))
            .define_method("set_full_screen", &QVideoWidget::setFullScreen, Arg("full_screen"));
            // Signals
            // .define_method("aspect_ratio_mode_changed", &QVideoWidget::aspectRatioModeChanged, Arg("mode"))
            // .define_method("full_screen_changed", &QVideoWidget::fullScreenChanged, Arg("full_screen"));
}
