#include "qmessagebox-rb.hpp"
#include <qmessagebox.h>
#include <rice/qflags.hpp>

#include <QAbstractButton>
#include <QCheckBox>
#include <QPushButton>

using namespace Rice;

Rice::Class rb_cQMessageBox;

void Init_qmessagebox(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQMessageBox =
        // RubyQt6::QtWidgets::QMessageBox
        define_class_under<QMessageBox, QDialog>(rb_mQt6QtWidgets, "QMessageBox")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QMessageBox::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QMessageBox, QMessageBox::Icon, const QString &, const QString &, QMessageBox::StandardButtons, QWidget *>(), Arg("icon"), Arg("title"), Arg("text"), Arg("buttons"), Arg("parent"))
            // Public Functions
            .define_method<QPushButton *(QMessageBox::*)(QMessageBox::StandardButton)>("add_button", &QMessageBox::addButton, Arg("button"))
            .define_method<QPushButton *(QMessageBox::*)(const QString &, QMessageBox::ButtonRole)>("add_button", &QMessageBox::addButton, Arg("text"), Arg("role"))
            .define_method<void (QMessageBox::*)(QAbstractButton *, QMessageBox::ButtonRole)>("add_button", &QMessageBox::addButton, Arg("button"), Arg("role"))
            .define_method("button", &QMessageBox::button, Arg("which"))
            .define_method("button_role", &QMessageBox::buttonRole, Arg("button"))
            .define_method("buttons", &QMessageBox::buttons)
            .define_method("check_box", &QMessageBox::checkBox)
            .define_method("clicked_button", &QMessageBox::clickedButton)
            .define_method("default_button", &QMessageBox::defaultButton)
            .define_method("detailed_text", &QMessageBox::detailedText)
            .define_method("escape_button", &QMessageBox::escapeButton)
            .define_method("icon", &QMessageBox::icon)
            .define_method("icon_pixmap", &QMessageBox::iconPixmap)
            .define_method("informative_text", &QMessageBox::informativeText)
            .define_method<void (QMessageBox::*)(QObject *, const char *)>("open", &QMessageBox::open, Arg("receiver"), Arg("member"))
            .define_method("options", &QMessageBox::options)
            .define_method("remove_button", &QMessageBox::removeButton, Arg("button"))
            .define_method("set_check_box", &QMessageBox::setCheckBox, Arg("cb"))
            .define_method<void (QMessageBox::*)(QMessageBox::StandardButton)>("set_default_button", &QMessageBox::setDefaultButton, Arg("button"))
            .define_method<void (QMessageBox::*)(QPushButton *)>("set_default_button", &QMessageBox::setDefaultButton, Arg("button"))
            .define_method("set_detailed_text", &QMessageBox::setDetailedText, Arg("text"))
            .define_method<void (QMessageBox::*)(QAbstractButton *)>("set_escape_button", &QMessageBox::setEscapeButton, Arg("button"))
            .define_method<void (QMessageBox::*)(QMessageBox::StandardButton)>("set_escape_button", &QMessageBox::setEscapeButton, Arg("button"))
            .define_method("set_icon", &QMessageBox::setIcon, Arg("icon"))
            .define_method("set_icon_pixmap", &QMessageBox::setIconPixmap, Arg("pixmap"))
            .define_method("set_informative_text", &QMessageBox::setInformativeText, Arg("text"))
            .define_method("set_option", &QMessageBox::setOption, Arg("option"), Arg("on") = static_cast<bool>(true))
            .define_method("set_options", &QMessageBox::setOptions, Arg("options"))
            .define_method("set_standard_buttons", &QMessageBox::setStandardButtons, Arg("buttons"))
            .define_method("set_text", &QMessageBox::setText, Arg("text"))
            .define_method("set_text_format", &QMessageBox::setTextFormat, Arg("format"))
            .define_method("set_text_interaction_flags", &QMessageBox::setTextInteractionFlags, Arg("flags"))
            .define_method("set_window_modality", &QMessageBox::setWindowModality, Arg("window_modality"))
            .define_method("set_window_title", &QMessageBox::setWindowTitle, Arg("title"))
            .define_method("standard_button", &QMessageBox::standardButton, Arg("button"))
            .define_method("standard_buttons", &QMessageBox::standardButtons)
            .define_method("test_option", &QMessageBox::testOption, Arg("option"))
            .define_method("text", &QMessageBox::text)
            .define_method("text_format", &QMessageBox::textFormat)
            .define_method("text_interaction_flags", &QMessageBox::textInteractionFlags)
            // Public Slots
            // Signals
            .define_method("button_clicked", &QMessageBox::buttonClicked, Arg("button"))
            // Static Public Members
            .define_singleton_function("about", &QMessageBox::about, Arg("parent"), Arg("title"), Arg("text"))
            .define_singleton_function("about_qt", &QMessageBox::aboutQt, Arg("parent"), Arg("title") = static_cast<const QString &>(QString()))
            .define_singleton_function<QMessageBox::StandardButton (*)(QWidget *, const QString &, const QString &, QMessageBox::StandardButtons, QMessageBox::StandardButton)>("critical", &QMessageBox::critical, Arg("parent"), Arg("title"), Arg("text"), Arg("buttons") = static_cast<QMessageBox::StandardButtons>(QMessageBox::StandardButton::Ok), Arg("default_button") = static_cast<QMessageBox::StandardButton>(QMessageBox::StandardButton::NoButton))
            .define_singleton_function<int (*)(QWidget *, const QString &, const QString &, QMessageBox::StandardButton, QMessageBox::StandardButton)>("critical", &QMessageBox::critical, Arg("parent"), Arg("title"), Arg("text"), Arg("button0"), Arg("button1"))
            .define_singleton_function<QMessageBox::StandardButton (*)(QWidget *, const QString &, const QString &, QMessageBox::StandardButton, QMessageBox::StandardButton)>("information", &QMessageBox::information, Arg("parent"), Arg("title"), Arg("text"), Arg("button0"), Arg("button1") = static_cast<QMessageBox::StandardButton>(QMessageBox::StandardButton::NoButton))
            .define_singleton_function<QMessageBox::StandardButton (*)(QWidget *, const QString &, const QString &, QMessageBox::StandardButtons, QMessageBox::StandardButton)>("information", &QMessageBox::information, Arg("parent"), Arg("title"), Arg("text"), Arg("buttons") = static_cast<QMessageBox::StandardButtons>(QMessageBox::StandardButton::Ok), Arg("default_button") = static_cast<QMessageBox::StandardButton>(QMessageBox::StandardButton::NoButton))
            .define_singleton_function<QMessageBox::StandardButton (*)(QWidget *, const QString &, const QString &, QMessageBox::StandardButtons, QMessageBox::StandardButton)>("question", &QMessageBox::question, Arg("parent"), Arg("title"), Arg("text"), Arg("buttons") = static_cast<QMessageBox::StandardButtons>(QMessageBox::StandardButtons(QMessageBox::StandardButton::Yes | QMessageBox::StandardButton::No)), Arg("default_button") = static_cast<QMessageBox::StandardButton>(QMessageBox::StandardButton::NoButton))
            .define_singleton_function<int (*)(QWidget *, const QString &, const QString &, QMessageBox::StandardButton, QMessageBox::StandardButton)>("question", &QMessageBox::question, Arg("parent"), Arg("title"), Arg("text"), Arg("button0"), Arg("button1"))
            .define_singleton_function<QMessageBox::StandardButton (*)(QWidget *, const QString &, const QString &, QMessageBox::StandardButtons, QMessageBox::StandardButton)>("warning", &QMessageBox::warning, Arg("parent"), Arg("title"), Arg("text"), Arg("buttons") = static_cast<QMessageBox::StandardButtons>(QMessageBox::StandardButton::Ok), Arg("default_button") = static_cast<QMessageBox::StandardButton>(QMessageBox::StandardButton::NoButton))
            .define_singleton_function<int (*)(QWidget *, const QString &, const QString &, QMessageBox::StandardButton, QMessageBox::StandardButton)>("warning", &QMessageBox::warning, Arg("parent"), Arg("title"), Arg("text"), Arg("button0"), Arg("button1"));

    Enum<QMessageBox::ButtonRole> rb_cQMessageBoxButtonRole =
        // RubyQt6::QtWidgets::QMessageBox::ButtonRole
        define_enum_under<QMessageBox::ButtonRole>("ButtonRole", rb_cQMessageBox)
            .define_value("InvalidRole", QMessageBox::ButtonRole::InvalidRole)
            .define_value("AcceptRole", QMessageBox::ButtonRole::AcceptRole)
            .define_value("RejectRole", QMessageBox::ButtonRole::RejectRole)
            .define_value("DestructiveRole", QMessageBox::ButtonRole::DestructiveRole)
            .define_value("ActionRole", QMessageBox::ButtonRole::ActionRole)
            .define_value("HelpRole", QMessageBox::ButtonRole::HelpRole)
            .define_value("YesRole", QMessageBox::ButtonRole::YesRole)
            .define_value("NoRole", QMessageBox::ButtonRole::NoRole)
            .define_value("ResetRole", QMessageBox::ButtonRole::ResetRole)
            .define_value("ApplyRole", QMessageBox::ButtonRole::ApplyRole)
            .define_value("NRoles", QMessageBox::ButtonRole::NRoles);

    Enum<QMessageBox::Icon> rb_cQMessageBoxIcon =
        // RubyQt6::QtWidgets::QMessageBox::Icon
        define_enum_under<QMessageBox::Icon>("Icon", rb_cQMessageBox)
            .define_value("NoIcon", QMessageBox::Icon::NoIcon)
            .define_value("Information", QMessageBox::Icon::Information)
            .define_value("Warning", QMessageBox::Icon::Warning)
            .define_value("Critical", QMessageBox::Icon::Critical)
            .define_value("Question", QMessageBox::Icon::Question);

    Enum<QMessageBox::Option> rb_cQMessageBoxOption =
        // RubyQt6::QtWidgets::QMessageBox::Option
        define_enum_under<QMessageBox::Option>("Option", rb_cQMessageBox)
            .define_value("DontUseNativeDialog", QMessageBox::Option::DontUseNativeDialog);

    Enum<QMessageBox::StandardButton> rb_cQMessageBoxStandardButton =
        // RubyQt6::QtWidgets::QMessageBox::StandardButton
        define_enum_under<QMessageBox::StandardButton>("StandardButton", rb_cQMessageBox)
            .define_value("NoButton", QMessageBox::StandardButton::NoButton)
            .define_value("Ok", QMessageBox::StandardButton::Ok)
            .define_value("Save", QMessageBox::StandardButton::Save)
            .define_value("SaveAll", QMessageBox::StandardButton::SaveAll)
            .define_value("Open", QMessageBox::StandardButton::Open)
            .define_value("Yes", QMessageBox::StandardButton::Yes)
            .define_value("YesToAll", QMessageBox::StandardButton::YesToAll)
            .define_value("No", QMessageBox::StandardButton::No)
            .define_value("NoToAll", QMessageBox::StandardButton::NoToAll)
            .define_value("Abort", QMessageBox::StandardButton::Abort)
            .define_value("Retry", QMessageBox::StandardButton::Retry)
            .define_value("Ignore", QMessageBox::StandardButton::Ignore)
            .define_value("Close", QMessageBox::StandardButton::Close)
            .define_value("Cancel", QMessageBox::StandardButton::Cancel)
            .define_value("Discard", QMessageBox::StandardButton::Discard)
            .define_value("Help", QMessageBox::StandardButton::Help)
            .define_value("Apply", QMessageBox::StandardButton::Apply)
            .define_value("Reset", QMessageBox::StandardButton::Reset)
            .define_value("RestoreDefaults", QMessageBox::StandardButton::RestoreDefaults)
            .define_value("FirstButton", QMessageBox::StandardButton::FirstButton)
            .define_value("LastButton", QMessageBox::StandardButton::LastButton)
            .define_value("YesAll", QMessageBox::StandardButton::YesAll)
            .define_value("NoAll", QMessageBox::StandardButton::NoAll)
            .define_value("Default", QMessageBox::StandardButton::Default)
            .define_value("Escape", QMessageBox::StandardButton::Escape)
            .define_value("FlagMask", QMessageBox::StandardButton::FlagMask)
            .define_value("ButtonMask", QMessageBox::StandardButton::ButtonMask);

    Data_Type<QFlags<QMessageBox::StandardButton>> rb_cQMessageBoxStandardButtons =
        // RubyQt6::QtWidgets::QMessageBox::StandardButtons
        define_qflags_under<QMessageBox::StandardButton>(rb_cQMessageBox, "StandardButtons");
}
