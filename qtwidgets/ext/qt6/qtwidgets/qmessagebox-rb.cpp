#include "qmessagebox-rb.hpp"
#include <qmessagebox.h>
#include <rice/qenum.hpp>
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
            .define_method<void (QMessageBox::*)(QAbstractButton *, QMessageBox::ButtonRole)>("add_button", &QMessageBox::addButton, Arg("button").takeOwnership(), Arg("role"))
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
            .define_method("set_check_box", &QMessageBox::setCheckBox, Arg("check_box").takeOwnership())
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
            .define_singleton_function("_about", &QMessageBox::about, Arg("parent"), Arg("title"), Arg("text"))
            .define_singleton_function("_about_qt", &QMessageBox::aboutQt, Arg("parent"), Arg("title") = static_cast<const QString &>(QString()))
            .define_singleton_function<QMessageBox::StandardButton (*)(QWidget *, const QString &, const QString &, QMessageBox::StandardButtons, QMessageBox::StandardButton)>("_critical", &QMessageBox::critical, Arg("parent"), Arg("title"), Arg("text"), Arg("buttons") = static_cast<QMessageBox::StandardButtons>(QMessageBox::StandardButton::Ok), Arg("default_button") = static_cast<QMessageBox::StandardButton>(QMessageBox::StandardButton::NoButton))
            .define_singleton_function<QMessageBox::StandardButton (*)(QWidget *, const QString &, const QString &, QMessageBox::StandardButtons, QMessageBox::StandardButton)>("_information", &QMessageBox::information, Arg("parent"), Arg("title"), Arg("text"), Arg("buttons") = static_cast<QMessageBox::StandardButtons>(QMessageBox::StandardButton::Ok), Arg("default_button") = static_cast<QMessageBox::StandardButton>(QMessageBox::StandardButton::NoButton))
            .define_singleton_function<QMessageBox::StandardButton (*)(QWidget *, const QString &, const QString &, QMessageBox::StandardButtons, QMessageBox::StandardButton)>("_question", &QMessageBox::question, Arg("parent"), Arg("title"), Arg("text"), Arg("buttons") = static_cast<QMessageBox::StandardButtons>(QMessageBox::StandardButtons(QMessageBox::StandardButton::Yes | QMessageBox::StandardButton::No)), Arg("default_button") = static_cast<QMessageBox::StandardButton>(QMessageBox::StandardButton::NoButton))
            .define_singleton_function<QMessageBox::StandardButton (*)(QWidget *, const QString &, const QString &, QMessageBox::StandardButtons, QMessageBox::StandardButton)>("_warning", &QMessageBox::warning, Arg("parent"), Arg("title"), Arg("text"), Arg("buttons") = static_cast<QMessageBox::StandardButtons>(QMessageBox::StandardButton::Ok), Arg("default_button") = static_cast<QMessageBox::StandardButton>(QMessageBox::StandardButton::NoButton));

    Data_Type<QMessageBox::ButtonRole> rb_cQMessageBoxButtonRole =
        // RubyQt6::QtWidgets::QMessageBox::ButtonRole
        define_qenum_under<QMessageBox::ButtonRole>(rb_cQMessageBox, "ButtonRole");
        define_qenum_value_under(rb_cQMessageBoxButtonRole, "InvalidRole", QMessageBox::ButtonRole::InvalidRole);
        define_qenum_value_under(rb_cQMessageBoxButtonRole, "AcceptRole", QMessageBox::ButtonRole::AcceptRole);
        define_qenum_value_under(rb_cQMessageBoxButtonRole, "RejectRole", QMessageBox::ButtonRole::RejectRole);
        define_qenum_value_under(rb_cQMessageBoxButtonRole, "DestructiveRole", QMessageBox::ButtonRole::DestructiveRole);
        define_qenum_value_under(rb_cQMessageBoxButtonRole, "ActionRole", QMessageBox::ButtonRole::ActionRole);
        define_qenum_value_under(rb_cQMessageBoxButtonRole, "HelpRole", QMessageBox::ButtonRole::HelpRole);
        define_qenum_value_under(rb_cQMessageBoxButtonRole, "YesRole", QMessageBox::ButtonRole::YesRole);
        define_qenum_value_under(rb_cQMessageBoxButtonRole, "NoRole", QMessageBox::ButtonRole::NoRole);
        define_qenum_value_under(rb_cQMessageBoxButtonRole, "ResetRole", QMessageBox::ButtonRole::ResetRole);
        define_qenum_value_under(rb_cQMessageBoxButtonRole, "ApplyRole", QMessageBox::ButtonRole::ApplyRole);
        define_qenum_value_under(rb_cQMessageBoxButtonRole, "NRoles", QMessageBox::ButtonRole::NRoles);

    Data_Type<QMessageBox::Icon> rb_cQMessageBoxIcon =
        // RubyQt6::QtWidgets::QMessageBox::Icon
        define_qenum_under<QMessageBox::Icon>(rb_cQMessageBox, "Icon");
        define_qenum_value_under(rb_cQMessageBoxIcon, "NoIcon", QMessageBox::Icon::NoIcon);
        define_qenum_value_under(rb_cQMessageBoxIcon, "Information", QMessageBox::Icon::Information);
        define_qenum_value_under(rb_cQMessageBoxIcon, "Warning", QMessageBox::Icon::Warning);
        define_qenum_value_under(rb_cQMessageBoxIcon, "Critical", QMessageBox::Icon::Critical);
        define_qenum_value_under(rb_cQMessageBoxIcon, "Question", QMessageBox::Icon::Question);

    Data_Type<QMessageBox::Option> rb_cQMessageBoxOption =
        // RubyQt6::QtWidgets::QMessageBox::Option
        define_qenum_under<QMessageBox::Option>(rb_cQMessageBox, "Option");
        define_qenum_value_under(rb_cQMessageBoxOption, "DontUseNativeDialog", QMessageBox::Option::DontUseNativeDialog);

    Data_Type<QMessageBox::StandardButton> rb_cQMessageBoxStandardButton =
        // RubyQt6::QtWidgets::QMessageBox::StandardButton
        define_qenum_under<QMessageBox::StandardButton>(rb_cQMessageBox, "StandardButton");
        define_qenum_value_under(rb_cQMessageBoxStandardButton, "NoButton", QMessageBox::StandardButton::NoButton);
        define_qenum_value_under(rb_cQMessageBoxStandardButton, "Ok", QMessageBox::StandardButton::Ok);
        define_qenum_value_under(rb_cQMessageBoxStandardButton, "Save", QMessageBox::StandardButton::Save);
        define_qenum_value_under(rb_cQMessageBoxStandardButton, "SaveAll", QMessageBox::StandardButton::SaveAll);
        define_qenum_value_under(rb_cQMessageBoxStandardButton, "Open", QMessageBox::StandardButton::Open);
        define_qenum_value_under(rb_cQMessageBoxStandardButton, "Yes", QMessageBox::StandardButton::Yes);
        define_qenum_value_under(rb_cQMessageBoxStandardButton, "YesToAll", QMessageBox::StandardButton::YesToAll);
        define_qenum_value_under(rb_cQMessageBoxStandardButton, "No", QMessageBox::StandardButton::No);
        define_qenum_value_under(rb_cQMessageBoxStandardButton, "NoToAll", QMessageBox::StandardButton::NoToAll);
        define_qenum_value_under(rb_cQMessageBoxStandardButton, "Abort", QMessageBox::StandardButton::Abort);
        define_qenum_value_under(rb_cQMessageBoxStandardButton, "Retry", QMessageBox::StandardButton::Retry);
        define_qenum_value_under(rb_cQMessageBoxStandardButton, "Ignore", QMessageBox::StandardButton::Ignore);
        define_qenum_value_under(rb_cQMessageBoxStandardButton, "Close", QMessageBox::StandardButton::Close);
        define_qenum_value_under(rb_cQMessageBoxStandardButton, "Cancel", QMessageBox::StandardButton::Cancel);
        define_qenum_value_under(rb_cQMessageBoxStandardButton, "Discard", QMessageBox::StandardButton::Discard);
        define_qenum_value_under(rb_cQMessageBoxStandardButton, "Help", QMessageBox::StandardButton::Help);
        define_qenum_value_under(rb_cQMessageBoxStandardButton, "Apply", QMessageBox::StandardButton::Apply);
        define_qenum_value_under(rb_cQMessageBoxStandardButton, "Reset", QMessageBox::StandardButton::Reset);
        define_qenum_value_under(rb_cQMessageBoxStandardButton, "RestoreDefaults", QMessageBox::StandardButton::RestoreDefaults);
        define_qenum_value_under(rb_cQMessageBoxStandardButton, "FirstButton", QMessageBox::StandardButton::FirstButton);
        define_qenum_value_under(rb_cQMessageBoxStandardButton, "LastButton", QMessageBox::StandardButton::LastButton);
        define_qenum_value_under(rb_cQMessageBoxStandardButton, "YesAll", QMessageBox::StandardButton::YesAll);
        define_qenum_value_under(rb_cQMessageBoxStandardButton, "NoAll", QMessageBox::StandardButton::NoAll);
        define_qenum_value_under(rb_cQMessageBoxStandardButton, "Default", QMessageBox::StandardButton::Default);
        define_qenum_value_under(rb_cQMessageBoxStandardButton, "Escape", QMessageBox::StandardButton::Escape);
        define_qenum_value_under(rb_cQMessageBoxStandardButton, "FlagMask", QMessageBox::StandardButton::FlagMask);
        define_qenum_value_under(rb_cQMessageBoxStandardButton, "ButtonMask", QMessageBox::StandardButton::ButtonMask);

    Data_Type<QFlags<QMessageBox::StandardButton>> rb_cQMessageBoxStandardButtons =
        // RubyQt6::QtWidgets::QMessageBox::StandardButtons
        define_qflags_under<QMessageBox::StandardButton>(rb_cQMessageBox, "StandardButtons");
}
