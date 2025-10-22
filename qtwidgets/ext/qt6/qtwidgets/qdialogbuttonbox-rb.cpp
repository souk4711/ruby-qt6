#include "qdialogbuttonbox-rb.hpp"
#include <qdialogbuttonbox.h>
#include <rice/qenum.hpp>
#include <rice/qflags.hpp>

#include <QAbstractButton>
#include <QPushButton>

using namespace Rice;

Rice::Class rb_cQDialogButtonBox;

void Init_qdialogbuttonbox(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQDialogButtonBox =
        // RubyQt6::QtWidgets::QDialogButtonBox
        define_class_under<QDialogButtonBox, QWidget>(rb_mQt6QtWidgets, "QDialogButtonBox")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QDialogButtonBox::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QDialogButtonBox, QDialogButtonBox::StandardButtons, Qt::Orientation, QWidget *>(), Arg("buttons"), Arg("orientation"), Arg("parent"))
            // Public Functions
            .define_method<QPushButton *(QDialogButtonBox::*)(QDialogButtonBox::StandardButton)>("add_button", &QDialogButtonBox::addButton, Arg("button"))
            .define_method<QPushButton *(QDialogButtonBox::*)(const QString &, QDialogButtonBox::ButtonRole)>("add_button", &QDialogButtonBox::addButton, Arg("text"), Arg("role"))
            .define_method<void (QDialogButtonBox::*)(QAbstractButton *, QDialogButtonBox::ButtonRole)>("add_button", &QDialogButtonBox::addButton, Arg("button").takeOwnership(), Arg("role"))
            .define_method("button", &QDialogButtonBox::button, Arg("which"))
            .define_method("button_role", &QDialogButtonBox::buttonRole, Arg("button"))
            .define_method("buttons", &QDialogButtonBox::buttons)
            .define_method("center_buttons", &QDialogButtonBox::centerButtons)
            .define_method("clear", &QDialogButtonBox::clear)
            .define_method("orientation", &QDialogButtonBox::orientation)
            .define_method("remove_button", &QDialogButtonBox::removeButton, Arg("button"))
            .define_method("set_center_buttons", &QDialogButtonBox::setCenterButtons, Arg("center"))
            .define_method("set_orientation", &QDialogButtonBox::setOrientation, Arg("orientation"))
            .define_method("set_standard_buttons", &QDialogButtonBox::setStandardButtons, Arg("buttons"))
            .define_method("standard_button", &QDialogButtonBox::standardButton, Arg("button"))
            .define_method("standard_buttons", &QDialogButtonBox::standardButtons)
            // Signals
            .define_method("accepted", &QDialogButtonBox::accepted)
            .define_method("clicked", &QDialogButtonBox::clicked, Arg("button"))
            .define_method("help_requested", &QDialogButtonBox::helpRequested)
            .define_method("rejected", &QDialogButtonBox::rejected);

    Enum<QDialogButtonBox::ButtonLayout> rb_cQDialogButtonBoxButtonLayout =
        // RubyQt6::QtWidgets::QDialogButtonBox::ButtonLayout
        define_qenum_under<QDialogButtonBox::ButtonLayout>("ButtonLayout", rb_cQDialogButtonBox)
            .define_value("WinLayout", QDialogButtonBox::ButtonLayout::WinLayout)
            .define_value("MacLayout", QDialogButtonBox::ButtonLayout::MacLayout)
            .define_value("KdeLayout", QDialogButtonBox::ButtonLayout::KdeLayout)
            .define_value("GnomeLayout", QDialogButtonBox::ButtonLayout::GnomeLayout)
            .define_value("AndroidLayout", QDialogButtonBox::ButtonLayout::AndroidLayout);

    Enum<QDialogButtonBox::ButtonRole> rb_cQDialogButtonBoxButtonRole =
        // RubyQt6::QtWidgets::QDialogButtonBox::ButtonRole
        define_qenum_under<QDialogButtonBox::ButtonRole>("ButtonRole", rb_cQDialogButtonBox)
            .define_value("InvalidRole", QDialogButtonBox::ButtonRole::InvalidRole)
            .define_value("AcceptRole", QDialogButtonBox::ButtonRole::AcceptRole)
            .define_value("RejectRole", QDialogButtonBox::ButtonRole::RejectRole)
            .define_value("DestructiveRole", QDialogButtonBox::ButtonRole::DestructiveRole)
            .define_value("ActionRole", QDialogButtonBox::ButtonRole::ActionRole)
            .define_value("HelpRole", QDialogButtonBox::ButtonRole::HelpRole)
            .define_value("YesRole", QDialogButtonBox::ButtonRole::YesRole)
            .define_value("NoRole", QDialogButtonBox::ButtonRole::NoRole)
            .define_value("ResetRole", QDialogButtonBox::ButtonRole::ResetRole)
            .define_value("ApplyRole", QDialogButtonBox::ButtonRole::ApplyRole)
            .define_value("NRoles", QDialogButtonBox::ButtonRole::NRoles);

    Enum<QDialogButtonBox::StandardButton> rb_cQDialogButtonBoxStandardButton =
        // RubyQt6::QtWidgets::QDialogButtonBox::StandardButton
        define_qenum_under<QDialogButtonBox::StandardButton>("StandardButton", rb_cQDialogButtonBox)
            .define_value("NoButton", QDialogButtonBox::StandardButton::NoButton)
            .define_value("Ok", QDialogButtonBox::StandardButton::Ok)
            .define_value("Save", QDialogButtonBox::StandardButton::Save)
            .define_value("SaveAll", QDialogButtonBox::StandardButton::SaveAll)
            .define_value("Open", QDialogButtonBox::StandardButton::Open)
            .define_value("Yes", QDialogButtonBox::StandardButton::Yes)
            .define_value("YesToAll", QDialogButtonBox::StandardButton::YesToAll)
            .define_value("No", QDialogButtonBox::StandardButton::No)
            .define_value("NoToAll", QDialogButtonBox::StandardButton::NoToAll)
            .define_value("Abort", QDialogButtonBox::StandardButton::Abort)
            .define_value("Retry", QDialogButtonBox::StandardButton::Retry)
            .define_value("Ignore", QDialogButtonBox::StandardButton::Ignore)
            .define_value("Close", QDialogButtonBox::StandardButton::Close)
            .define_value("Cancel", QDialogButtonBox::StandardButton::Cancel)
            .define_value("Discard", QDialogButtonBox::StandardButton::Discard)
            .define_value("Help", QDialogButtonBox::StandardButton::Help)
            .define_value("Apply", QDialogButtonBox::StandardButton::Apply)
            .define_value("Reset", QDialogButtonBox::StandardButton::Reset)
            .define_value("RestoreDefaults", QDialogButtonBox::StandardButton::RestoreDefaults)
            .define_value("FirstButton", QDialogButtonBox::StandardButton::FirstButton)
            .define_value("LastButton", QDialogButtonBox::StandardButton::LastButton);

    Data_Type<QFlags<QDialogButtonBox::StandardButton>> rb_cQDialogButtonBoxStandardButtons =
        // RubyQt6::QtWidgets::QDialogButtonBox::StandardButtons
        define_qflags_under<QDialogButtonBox::StandardButton>(rb_cQDialogButtonBox, "StandardButtons");
}
