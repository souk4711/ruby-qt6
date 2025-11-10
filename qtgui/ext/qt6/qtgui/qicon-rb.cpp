#include "qicon-rb.hpp"
#include <qicon.h>
#include <rice/qt6/qenum.hpp>

#include <QPainter>
#include <QWindow>

using namespace Rice;

Rice::Class rb_cQIcon;

void Init_qicon(Rice::Module rb_mQt6QtGui)
{
    rb_cQIcon =
        // RubyQt6::QtGui::QIcon
        define_class_under<QIcon>(rb_mQt6QtGui, "QIcon")
            // Constructor
            .define_constructor(Constructor<QIcon>())
            .define_constructor(Constructor<QIcon, const QString &>(), Arg("file_name"))
            .define_constructor(Constructor<QIcon, const QPixmap &>(), Arg("pixmap"))
            // Public Functions
            .define_method<QSize (QIcon::*)(const QSize &, QIcon::Mode, QIcon::State) const>("actual_size", &QIcon::actualSize, Arg("size"), Arg("mode") = static_cast<QIcon::Mode>(QIcon::Mode::Normal), Arg("state") = static_cast<QIcon::State>(QIcon::State::Off))
            .define_method("add_file", &QIcon::addFile, Arg("file_name"), Arg("size") = static_cast<const QSize &>(QSize()), Arg("mode") = static_cast<QIcon::Mode>(QIcon::Mode::Normal), Arg("state") = static_cast<QIcon::State>(QIcon::State::Off))
            .define_method("add_pixmap", &QIcon::addPixmap, Arg("pixmap"), Arg("mode") = static_cast<QIcon::Mode>(QIcon::Mode::Normal), Arg("state") = static_cast<QIcon::State>(QIcon::State::Off))
            .define_method("available_sizes", &QIcon::availableSizes, Arg("mode") = static_cast<QIcon::Mode>(QIcon::Mode::Normal), Arg("state") = static_cast<QIcon::State>(QIcon::State::Off))
            .define_method("cache_key", &QIcon::cacheKey)
            .define_method("detach", &QIcon::detach)
            .define_method("detached?", &QIcon::isDetached)
            .define_method("mask?", &QIcon::isMask)
            .define_method("null?", &QIcon::isNull)
            .define_method("name", &QIcon::name)
            .define_method<void (QIcon::*)(QPainter *, const QRect &, Qt::Alignment, QIcon::Mode, QIcon::State) const>("paint", &QIcon::paint, Arg("painter"), Arg("rect"), Arg("alignment") = static_cast<Qt::Alignment>(Qt::AlignCenter), Arg("mode") = static_cast<QIcon::Mode>(QIcon::Mode::Normal), Arg("state") = static_cast<QIcon::State>(QIcon::State::Off))
            .define_method<void (QIcon::*)(QPainter *, int, int, int, int, Qt::Alignment, QIcon::Mode, QIcon::State) const>("paint", &QIcon::paint, Arg("painter"), Arg("x"), Arg("y"), Arg("w"), Arg("h"), Arg("alignment") = static_cast<Qt::Alignment>(Qt::AlignCenter), Arg("mode") = static_cast<QIcon::Mode>(QIcon::Mode::Normal), Arg("state") = static_cast<QIcon::State>(QIcon::State::Off))
            .define_method<QPixmap (QIcon::*)(const QSize &, QIcon::Mode, QIcon::State) const>("pixmap", &QIcon::pixmap, Arg("size"), Arg("mode") = static_cast<QIcon::Mode>(QIcon::Mode::Normal), Arg("state") = static_cast<QIcon::State>(QIcon::State::Off))
            .define_method<QPixmap (QIcon::*)(const QSize &, qreal, QIcon::Mode, QIcon::State) const>("pixmap", &QIcon::pixmap, Arg("size"), Arg("device_pixel_ratio"), Arg("mode") = static_cast<QIcon::Mode>(QIcon::Mode::Normal), Arg("state") = static_cast<QIcon::State>(QIcon::State::Off))
            .define_method<QPixmap (QIcon::*)(int, QIcon::Mode, QIcon::State) const>("pixmap", &QIcon::pixmap, Arg("extent"), Arg("mode") = static_cast<QIcon::Mode>(QIcon::Mode::Normal), Arg("state") = static_cast<QIcon::State>(QIcon::State::Off))
            .define_method<QPixmap (QIcon::*)(int, int, QIcon::Mode, QIcon::State) const>("pixmap", &QIcon::pixmap, Arg("w"), Arg("h"), Arg("mode") = static_cast<QIcon::Mode>(QIcon::Mode::Normal), Arg("state") = static_cast<QIcon::State>(QIcon::State::Off))
            .define_method("set_is_mask", &QIcon::setIsMask, Arg("is_mask"))
            // Static Public Members
            .define_singleton_function("fallback_search_paths", &QIcon::fallbackSearchPaths)
            .define_singleton_function("fallback_theme_name", &QIcon::fallbackThemeName)
            .define_singleton_function<QIcon (*)(QIcon::ThemeIcon)>("from_theme", &QIcon::fromTheme, Arg("icon"))
            .define_singleton_function<QIcon (*)(QIcon::ThemeIcon, const QIcon &)>("from_theme", &QIcon::fromTheme, Arg("icon"), Arg("fallback"))
            .define_singleton_function<QIcon (*)(const QString &)>("from_theme", &QIcon::fromTheme, Arg("name"))
            .define_singleton_function<QIcon (*)(const QString &, const QIcon &)>("from_theme", &QIcon::fromTheme, Arg("name"), Arg("fallback"))
            .define_singleton_function<bool (*)(QIcon::ThemeIcon)>("has_theme_icon", &QIcon::hasThemeIcon, Arg("icon"))
            .define_singleton_function<bool (*)(const QString &)>("has_theme_icon", &QIcon::hasThemeIcon, Arg("name"))
            .define_singleton_function("set_fallback_search_paths", &QIcon::setFallbackSearchPaths, Arg("paths"))
            .define_singleton_function("set_fallback_theme_name", &QIcon::setFallbackThemeName, Arg("name"))
            .define_singleton_function("set_theme_name", &QIcon::setThemeName, Arg("path"))
            .define_singleton_function("set_theme_search_paths", &QIcon::setThemeSearchPaths, Arg("searchpath"))
            .define_singleton_function("theme_name", &QIcon::themeName)
            .define_singleton_function("theme_search_paths", &QIcon::themeSearchPaths);

    Data_Type<QIcon::Mode> rb_cQIconMode =
        // RubyQt6::QtGui::QIcon::Mode
        define_qenum_under<QIcon::Mode>(rb_cQIcon, "Mode");
        define_qenum_value_under(rb_cQIconMode, "Normal", QIcon::Mode::Normal);
        define_qenum_value_under(rb_cQIconMode, "Disabled", QIcon::Mode::Disabled);
        define_qenum_value_under(rb_cQIconMode, "Active", QIcon::Mode::Active);
        define_qenum_value_under(rb_cQIconMode, "Selected", QIcon::Mode::Selected);

    Data_Type<QIcon::State> rb_cQIconState =
        // RubyQt6::QtGui::QIcon::State
        define_qenum_under<QIcon::State>(rb_cQIcon, "State");
        define_qenum_value_under(rb_cQIconState, "On", QIcon::State::On);
        define_qenum_value_under(rb_cQIconState, "Off", QIcon::State::Off);

    Data_Type<QIcon::ThemeIcon> rb_cQIconThemeIcon =
        // RubyQt6::QtGui::QIcon::ThemeIcon
        define_qenum_under<QIcon::ThemeIcon>(rb_cQIcon, "ThemeIcon");
        define_qenum_value_under(rb_cQIconThemeIcon, "AddressBookNew", QIcon::ThemeIcon::AddressBookNew);
        define_qenum_value_under(rb_cQIconThemeIcon, "ApplicationExit", QIcon::ThemeIcon::ApplicationExit);
        define_qenum_value_under(rb_cQIconThemeIcon, "AppointmentNew", QIcon::ThemeIcon::AppointmentNew);
        define_qenum_value_under(rb_cQIconThemeIcon, "CallStart", QIcon::ThemeIcon::CallStart);
        define_qenum_value_under(rb_cQIconThemeIcon, "CallStop", QIcon::ThemeIcon::CallStop);
        define_qenum_value_under(rb_cQIconThemeIcon, "ContactNew", QIcon::ThemeIcon::ContactNew);
        define_qenum_value_under(rb_cQIconThemeIcon, "DocumentNew", QIcon::ThemeIcon::DocumentNew);
        define_qenum_value_under(rb_cQIconThemeIcon, "DocumentOpen", QIcon::ThemeIcon::DocumentOpen);
        define_qenum_value_under(rb_cQIconThemeIcon, "DocumentOpenRecent", QIcon::ThemeIcon::DocumentOpenRecent);
        define_qenum_value_under(rb_cQIconThemeIcon, "DocumentPageSetup", QIcon::ThemeIcon::DocumentPageSetup);
        define_qenum_value_under(rb_cQIconThemeIcon, "DocumentPrint", QIcon::ThemeIcon::DocumentPrint);
        define_qenum_value_under(rb_cQIconThemeIcon, "DocumentPrintPreview", QIcon::ThemeIcon::DocumentPrintPreview);
        define_qenum_value_under(rb_cQIconThemeIcon, "DocumentProperties", QIcon::ThemeIcon::DocumentProperties);
        define_qenum_value_under(rb_cQIconThemeIcon, "DocumentRevert", QIcon::ThemeIcon::DocumentRevert);
        define_qenum_value_under(rb_cQIconThemeIcon, "DocumentSave", QIcon::ThemeIcon::DocumentSave);
        define_qenum_value_under(rb_cQIconThemeIcon, "DocumentSaveAs", QIcon::ThemeIcon::DocumentSaveAs);
        define_qenum_value_under(rb_cQIconThemeIcon, "DocumentSend", QIcon::ThemeIcon::DocumentSend);
        define_qenum_value_under(rb_cQIconThemeIcon, "EditClear", QIcon::ThemeIcon::EditClear);
        define_qenum_value_under(rb_cQIconThemeIcon, "EditCopy", QIcon::ThemeIcon::EditCopy);
        define_qenum_value_under(rb_cQIconThemeIcon, "EditCut", QIcon::ThemeIcon::EditCut);
        define_qenum_value_under(rb_cQIconThemeIcon, "EditDelete", QIcon::ThemeIcon::EditDelete);
        define_qenum_value_under(rb_cQIconThemeIcon, "EditFind", QIcon::ThemeIcon::EditFind);
        define_qenum_value_under(rb_cQIconThemeIcon, "EditPaste", QIcon::ThemeIcon::EditPaste);
        define_qenum_value_under(rb_cQIconThemeIcon, "EditRedo", QIcon::ThemeIcon::EditRedo);
        define_qenum_value_under(rb_cQIconThemeIcon, "EditSelectAll", QIcon::ThemeIcon::EditSelectAll);
        define_qenum_value_under(rb_cQIconThemeIcon, "EditUndo", QIcon::ThemeIcon::EditUndo);
        define_qenum_value_under(rb_cQIconThemeIcon, "FolderNew", QIcon::ThemeIcon::FolderNew);
        define_qenum_value_under(rb_cQIconThemeIcon, "FormatIndentLess", QIcon::ThemeIcon::FormatIndentLess);
        define_qenum_value_under(rb_cQIconThemeIcon, "FormatIndentMore", QIcon::ThemeIcon::FormatIndentMore);
        define_qenum_value_under(rb_cQIconThemeIcon, "FormatJustifyCenter", QIcon::ThemeIcon::FormatJustifyCenter);
        define_qenum_value_under(rb_cQIconThemeIcon, "FormatJustifyFill", QIcon::ThemeIcon::FormatJustifyFill);
        define_qenum_value_under(rb_cQIconThemeIcon, "FormatJustifyLeft", QIcon::ThemeIcon::FormatJustifyLeft);
        define_qenum_value_under(rb_cQIconThemeIcon, "FormatJustifyRight", QIcon::ThemeIcon::FormatJustifyRight);
        define_qenum_value_under(rb_cQIconThemeIcon, "FormatTextDirectionLtr", QIcon::ThemeIcon::FormatTextDirectionLtr);
        define_qenum_value_under(rb_cQIconThemeIcon, "FormatTextDirectionRtl", QIcon::ThemeIcon::FormatTextDirectionRtl);
        define_qenum_value_under(rb_cQIconThemeIcon, "FormatTextBold", QIcon::ThemeIcon::FormatTextBold);
        define_qenum_value_under(rb_cQIconThemeIcon, "FormatTextItalic", QIcon::ThemeIcon::FormatTextItalic);
        define_qenum_value_under(rb_cQIconThemeIcon, "FormatTextUnderline", QIcon::ThemeIcon::FormatTextUnderline);
        define_qenum_value_under(rb_cQIconThemeIcon, "FormatTextStrikethrough", QIcon::ThemeIcon::FormatTextStrikethrough);
        define_qenum_value_under(rb_cQIconThemeIcon, "GoDown", QIcon::ThemeIcon::GoDown);
        define_qenum_value_under(rb_cQIconThemeIcon, "GoHome", QIcon::ThemeIcon::GoHome);
        define_qenum_value_under(rb_cQIconThemeIcon, "GoNext", QIcon::ThemeIcon::GoNext);
        define_qenum_value_under(rb_cQIconThemeIcon, "GoPrevious", QIcon::ThemeIcon::GoPrevious);
        define_qenum_value_under(rb_cQIconThemeIcon, "GoUp", QIcon::ThemeIcon::GoUp);
        define_qenum_value_under(rb_cQIconThemeIcon, "HelpAbout", QIcon::ThemeIcon::HelpAbout);
        define_qenum_value_under(rb_cQIconThemeIcon, "HelpFaq", QIcon::ThemeIcon::HelpFaq);
        define_qenum_value_under(rb_cQIconThemeIcon, "InsertImage", QIcon::ThemeIcon::InsertImage);
        define_qenum_value_under(rb_cQIconThemeIcon, "InsertLink", QIcon::ThemeIcon::InsertLink);
        define_qenum_value_under(rb_cQIconThemeIcon, "InsertText", QIcon::ThemeIcon::InsertText);
        define_qenum_value_under(rb_cQIconThemeIcon, "ListAdd", QIcon::ThemeIcon::ListAdd);
        define_qenum_value_under(rb_cQIconThemeIcon, "ListRemove", QIcon::ThemeIcon::ListRemove);
        define_qenum_value_under(rb_cQIconThemeIcon, "MailForward", QIcon::ThemeIcon::MailForward);
        define_qenum_value_under(rb_cQIconThemeIcon, "MailMarkImportant", QIcon::ThemeIcon::MailMarkImportant);
        define_qenum_value_under(rb_cQIconThemeIcon, "MailMarkRead", QIcon::ThemeIcon::MailMarkRead);
        define_qenum_value_under(rb_cQIconThemeIcon, "MailMarkUnread", QIcon::ThemeIcon::MailMarkUnread);
        define_qenum_value_under(rb_cQIconThemeIcon, "MailMessageNew", QIcon::ThemeIcon::MailMessageNew);
        define_qenum_value_under(rb_cQIconThemeIcon, "MailReplyAll", QIcon::ThemeIcon::MailReplyAll);
        define_qenum_value_under(rb_cQIconThemeIcon, "MailReplySender", QIcon::ThemeIcon::MailReplySender);
        define_qenum_value_under(rb_cQIconThemeIcon, "MailSend", QIcon::ThemeIcon::MailSend);
        define_qenum_value_under(rb_cQIconThemeIcon, "MediaEject", QIcon::ThemeIcon::MediaEject);
        define_qenum_value_under(rb_cQIconThemeIcon, "MediaPlaybackPause", QIcon::ThemeIcon::MediaPlaybackPause);
        define_qenum_value_under(rb_cQIconThemeIcon, "MediaPlaybackStart", QIcon::ThemeIcon::MediaPlaybackStart);
        define_qenum_value_under(rb_cQIconThemeIcon, "MediaPlaybackStop", QIcon::ThemeIcon::MediaPlaybackStop);
        define_qenum_value_under(rb_cQIconThemeIcon, "MediaRecord", QIcon::ThemeIcon::MediaRecord);
        define_qenum_value_under(rb_cQIconThemeIcon, "MediaSeekBackward", QIcon::ThemeIcon::MediaSeekBackward);
        define_qenum_value_under(rb_cQIconThemeIcon, "MediaSeekForward", QIcon::ThemeIcon::MediaSeekForward);
        define_qenum_value_under(rb_cQIconThemeIcon, "MediaSkipBackward", QIcon::ThemeIcon::MediaSkipBackward);
        define_qenum_value_under(rb_cQIconThemeIcon, "MediaSkipForward", QIcon::ThemeIcon::MediaSkipForward);
        define_qenum_value_under(rb_cQIconThemeIcon, "ObjectRotateLeft", QIcon::ThemeIcon::ObjectRotateLeft);
        define_qenum_value_under(rb_cQIconThemeIcon, "ObjectRotateRight", QIcon::ThemeIcon::ObjectRotateRight);
        define_qenum_value_under(rb_cQIconThemeIcon, "ProcessStop", QIcon::ThemeIcon::ProcessStop);
        define_qenum_value_under(rb_cQIconThemeIcon, "SystemLockScreen", QIcon::ThemeIcon::SystemLockScreen);
        define_qenum_value_under(rb_cQIconThemeIcon, "SystemLogOut", QIcon::ThemeIcon::SystemLogOut);
        define_qenum_value_under(rb_cQIconThemeIcon, "SystemSearch", QIcon::ThemeIcon::SystemSearch);
        define_qenum_value_under(rb_cQIconThemeIcon, "SystemReboot", QIcon::ThemeIcon::SystemReboot);
        define_qenum_value_under(rb_cQIconThemeIcon, "SystemShutdown", QIcon::ThemeIcon::SystemShutdown);
        define_qenum_value_under(rb_cQIconThemeIcon, "ToolsCheckSpelling", QIcon::ThemeIcon::ToolsCheckSpelling);
        define_qenum_value_under(rb_cQIconThemeIcon, "ViewFullscreen", QIcon::ThemeIcon::ViewFullscreen);
        define_qenum_value_under(rb_cQIconThemeIcon, "ViewRefresh", QIcon::ThemeIcon::ViewRefresh);
        define_qenum_value_under(rb_cQIconThemeIcon, "ViewRestore", QIcon::ThemeIcon::ViewRestore);
        define_qenum_value_under(rb_cQIconThemeIcon, "WindowClose", QIcon::ThemeIcon::WindowClose);
        define_qenum_value_under(rb_cQIconThemeIcon, "WindowNew", QIcon::ThemeIcon::WindowNew);
        define_qenum_value_under(rb_cQIconThemeIcon, "ZoomFitBest", QIcon::ThemeIcon::ZoomFitBest);
        define_qenum_value_under(rb_cQIconThemeIcon, "ZoomIn", QIcon::ThemeIcon::ZoomIn);
        define_qenum_value_under(rb_cQIconThemeIcon, "ZoomOut", QIcon::ThemeIcon::ZoomOut);
        define_qenum_value_under(rb_cQIconThemeIcon, "AudioCard", QIcon::ThemeIcon::AudioCard);
        define_qenum_value_under(rb_cQIconThemeIcon, "AudioInputMicrophone", QIcon::ThemeIcon::AudioInputMicrophone);
        define_qenum_value_under(rb_cQIconThemeIcon, "Battery", QIcon::ThemeIcon::Battery);
        define_qenum_value_under(rb_cQIconThemeIcon, "CameraPhoto", QIcon::ThemeIcon::CameraPhoto);
        define_qenum_value_under(rb_cQIconThemeIcon, "CameraVideo", QIcon::ThemeIcon::CameraVideo);
        define_qenum_value_under(rb_cQIconThemeIcon, "CameraWeb", QIcon::ThemeIcon::CameraWeb);
        define_qenum_value_under(rb_cQIconThemeIcon, "Computer", QIcon::ThemeIcon::Computer);
        define_qenum_value_under(rb_cQIconThemeIcon, "DriveHarddisk", QIcon::ThemeIcon::DriveHarddisk);
        define_qenum_value_under(rb_cQIconThemeIcon, "DriveOptical", QIcon::ThemeIcon::DriveOptical);
        define_qenum_value_under(rb_cQIconThemeIcon, "InputGaming", QIcon::ThemeIcon::InputGaming);
        define_qenum_value_under(rb_cQIconThemeIcon, "InputKeyboard", QIcon::ThemeIcon::InputKeyboard);
        define_qenum_value_under(rb_cQIconThemeIcon, "InputMouse", QIcon::ThemeIcon::InputMouse);
        define_qenum_value_under(rb_cQIconThemeIcon, "InputTablet", QIcon::ThemeIcon::InputTablet);
        define_qenum_value_under(rb_cQIconThemeIcon, "MediaFlash", QIcon::ThemeIcon::MediaFlash);
        define_qenum_value_under(rb_cQIconThemeIcon, "MediaOptical", QIcon::ThemeIcon::MediaOptical);
        define_qenum_value_under(rb_cQIconThemeIcon, "MediaTape", QIcon::ThemeIcon::MediaTape);
        define_qenum_value_under(rb_cQIconThemeIcon, "MultimediaPlayer", QIcon::ThemeIcon::MultimediaPlayer);
        define_qenum_value_under(rb_cQIconThemeIcon, "NetworkWired", QIcon::ThemeIcon::NetworkWired);
        define_qenum_value_under(rb_cQIconThemeIcon, "NetworkWireless", QIcon::ThemeIcon::NetworkWireless);
        define_qenum_value_under(rb_cQIconThemeIcon, "Phone", QIcon::ThemeIcon::Phone);
        define_qenum_value_under(rb_cQIconThemeIcon, "Printer", QIcon::ThemeIcon::Printer);
        define_qenum_value_under(rb_cQIconThemeIcon, "Scanner", QIcon::ThemeIcon::Scanner);
        define_qenum_value_under(rb_cQIconThemeIcon, "VideoDisplay", QIcon::ThemeIcon::VideoDisplay);
        define_qenum_value_under(rb_cQIconThemeIcon, "AppointmentMissed", QIcon::ThemeIcon::AppointmentMissed);
        define_qenum_value_under(rb_cQIconThemeIcon, "AppointmentSoon", QIcon::ThemeIcon::AppointmentSoon);
        define_qenum_value_under(rb_cQIconThemeIcon, "AudioVolumeHigh", QIcon::ThemeIcon::AudioVolumeHigh);
        define_qenum_value_under(rb_cQIconThemeIcon, "AudioVolumeLow", QIcon::ThemeIcon::AudioVolumeLow);
        define_qenum_value_under(rb_cQIconThemeIcon, "AudioVolumeMedium", QIcon::ThemeIcon::AudioVolumeMedium);
        define_qenum_value_under(rb_cQIconThemeIcon, "AudioVolumeMuted", QIcon::ThemeIcon::AudioVolumeMuted);
        define_qenum_value_under(rb_cQIconThemeIcon, "BatteryCaution", QIcon::ThemeIcon::BatteryCaution);
        define_qenum_value_under(rb_cQIconThemeIcon, "BatteryLow", QIcon::ThemeIcon::BatteryLow);
        define_qenum_value_under(rb_cQIconThemeIcon, "DialogError", QIcon::ThemeIcon::DialogError);
        define_qenum_value_under(rb_cQIconThemeIcon, "DialogInformation", QIcon::ThemeIcon::DialogInformation);
        define_qenum_value_under(rb_cQIconThemeIcon, "DialogPassword", QIcon::ThemeIcon::DialogPassword);
        define_qenum_value_under(rb_cQIconThemeIcon, "DialogQuestion", QIcon::ThemeIcon::DialogQuestion);
        define_qenum_value_under(rb_cQIconThemeIcon, "DialogWarning", QIcon::ThemeIcon::DialogWarning);
        define_qenum_value_under(rb_cQIconThemeIcon, "FolderDragAccept", QIcon::ThemeIcon::FolderDragAccept);
        define_qenum_value_under(rb_cQIconThemeIcon, "FolderOpen", QIcon::ThemeIcon::FolderOpen);
        define_qenum_value_under(rb_cQIconThemeIcon, "FolderVisiting", QIcon::ThemeIcon::FolderVisiting);
        define_qenum_value_under(rb_cQIconThemeIcon, "ImageLoading", QIcon::ThemeIcon::ImageLoading);
        define_qenum_value_under(rb_cQIconThemeIcon, "ImageMissing", QIcon::ThemeIcon::ImageMissing);
        define_qenum_value_under(rb_cQIconThemeIcon, "MailAttachment", QIcon::ThemeIcon::MailAttachment);
        define_qenum_value_under(rb_cQIconThemeIcon, "MailUnread", QIcon::ThemeIcon::MailUnread);
        define_qenum_value_under(rb_cQIconThemeIcon, "MailRead", QIcon::ThemeIcon::MailRead);
        define_qenum_value_under(rb_cQIconThemeIcon, "MailReplied", QIcon::ThemeIcon::MailReplied);
        define_qenum_value_under(rb_cQIconThemeIcon, "MediaPlaylistRepeat", QIcon::ThemeIcon::MediaPlaylistRepeat);
        define_qenum_value_under(rb_cQIconThemeIcon, "MediaPlaylistShuffle", QIcon::ThemeIcon::MediaPlaylistShuffle);
        define_qenum_value_under(rb_cQIconThemeIcon, "NetworkOffline", QIcon::ThemeIcon::NetworkOffline);
        define_qenum_value_under(rb_cQIconThemeIcon, "PrinterPrinting", QIcon::ThemeIcon::PrinterPrinting);
        define_qenum_value_under(rb_cQIconThemeIcon, "SecurityHigh", QIcon::ThemeIcon::SecurityHigh);
        define_qenum_value_under(rb_cQIconThemeIcon, "SecurityLow", QIcon::ThemeIcon::SecurityLow);
        define_qenum_value_under(rb_cQIconThemeIcon, "SoftwareUpdateAvailable", QIcon::ThemeIcon::SoftwareUpdateAvailable);
        define_qenum_value_under(rb_cQIconThemeIcon, "SoftwareUpdateUrgent", QIcon::ThemeIcon::SoftwareUpdateUrgent);
        define_qenum_value_under(rb_cQIconThemeIcon, "SyncError", QIcon::ThemeIcon::SyncError);
        define_qenum_value_under(rb_cQIconThemeIcon, "SyncSynchronizing", QIcon::ThemeIcon::SyncSynchronizing);
        define_qenum_value_under(rb_cQIconThemeIcon, "UserAvailable", QIcon::ThemeIcon::UserAvailable);
        define_qenum_value_under(rb_cQIconThemeIcon, "UserOffline", QIcon::ThemeIcon::UserOffline);
        define_qenum_value_under(rb_cQIconThemeIcon, "WeatherClear", QIcon::ThemeIcon::WeatherClear);
        define_qenum_value_under(rb_cQIconThemeIcon, "WeatherClearNight", QIcon::ThemeIcon::WeatherClearNight);
        define_qenum_value_under(rb_cQIconThemeIcon, "WeatherFewClouds", QIcon::ThemeIcon::WeatherFewClouds);
        define_qenum_value_under(rb_cQIconThemeIcon, "WeatherFewCloudsNight", QIcon::ThemeIcon::WeatherFewCloudsNight);
        define_qenum_value_under(rb_cQIconThemeIcon, "WeatherFog", QIcon::ThemeIcon::WeatherFog);
        define_qenum_value_under(rb_cQIconThemeIcon, "WeatherShowers", QIcon::ThemeIcon::WeatherShowers);
        define_qenum_value_under(rb_cQIconThemeIcon, "WeatherSnow", QIcon::ThemeIcon::WeatherSnow);
        define_qenum_value_under(rb_cQIconThemeIcon, "WeatherStorm", QIcon::ThemeIcon::WeatherStorm);
        define_qenum_value_under(rb_cQIconThemeIcon, "NThemeIcons", QIcon::ThemeIcon::NThemeIcons);
}
