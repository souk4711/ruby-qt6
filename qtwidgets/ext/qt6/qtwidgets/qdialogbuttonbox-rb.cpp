#include "qdialogbuttonbox-rb.hpp"
#include <qdialogbuttonbox.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

#include <QAbstractButton>
#include <QPushButton>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQDialogButtonBox;

void Init_qdialogbuttonbox(Module rb_mQt6QtWidgets)
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
            .define_method<void (QDialogButtonBox::*)(QAbstractButton *, QDialogButtonBox::ButtonRole)>("add_button", &QDialogButtonBox::addButton, Arg("button"), Arg("role"))
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
            .define_method("standard_buttons", &QDialogButtonBox::standardButtons);
            // Signals
            // .define_method("accepted", &QDialogButtonBox::accepted)
            // .define_method("clicked", &QDialogButtonBox::clicked, Arg("button"))
            // .define_method("help_requested", &QDialogButtonBox::helpRequested)
            // .define_method("rejected", &QDialogButtonBox::rejected);

    Data_Type<QDialogButtonBox::ButtonLayout> rb_cQDialogButtonBoxButtonLayout =
        // RubyQt6::QtWidgets::QDialogButtonBox::ButtonLayout
        define_qenum_under<QDialogButtonBox::ButtonLayout>(rb_cQDialogButtonBox, "ButtonLayout");
        define_qenum_value_under(rb_cQDialogButtonBoxButtonLayout, "WinLayout", QDialogButtonBox::ButtonLayout::WinLayout);
        define_qenum_value_under(rb_cQDialogButtonBoxButtonLayout, "MacLayout", QDialogButtonBox::ButtonLayout::MacLayout);
        define_qenum_value_under(rb_cQDialogButtonBoxButtonLayout, "KdeLayout", QDialogButtonBox::ButtonLayout::KdeLayout);
        define_qenum_value_under(rb_cQDialogButtonBoxButtonLayout, "GnomeLayout", QDialogButtonBox::ButtonLayout::GnomeLayout);
        define_qenum_value_under(rb_cQDialogButtonBoxButtonLayout, "AndroidLayout", QDialogButtonBox::ButtonLayout::AndroidLayout);

    Data_Type<QDialogButtonBox::ButtonRole> rb_cQDialogButtonBoxButtonRole =
        // RubyQt6::QtWidgets::QDialogButtonBox::ButtonRole
        define_qenum_under<QDialogButtonBox::ButtonRole>(rb_cQDialogButtonBox, "ButtonRole");
        define_qenum_value_under(rb_cQDialogButtonBoxButtonRole, "InvalidRole", QDialogButtonBox::ButtonRole::InvalidRole);
        define_qenum_value_under(rb_cQDialogButtonBoxButtonRole, "AcceptRole", QDialogButtonBox::ButtonRole::AcceptRole);
        define_qenum_value_under(rb_cQDialogButtonBoxButtonRole, "RejectRole", QDialogButtonBox::ButtonRole::RejectRole);
        define_qenum_value_under(rb_cQDialogButtonBoxButtonRole, "DestructiveRole", QDialogButtonBox::ButtonRole::DestructiveRole);
        define_qenum_value_under(rb_cQDialogButtonBoxButtonRole, "ActionRole", QDialogButtonBox::ButtonRole::ActionRole);
        define_qenum_value_under(rb_cQDialogButtonBoxButtonRole, "HelpRole", QDialogButtonBox::ButtonRole::HelpRole);
        define_qenum_value_under(rb_cQDialogButtonBoxButtonRole, "YesRole", QDialogButtonBox::ButtonRole::YesRole);
        define_qenum_value_under(rb_cQDialogButtonBoxButtonRole, "NoRole", QDialogButtonBox::ButtonRole::NoRole);
        define_qenum_value_under(rb_cQDialogButtonBoxButtonRole, "ResetRole", QDialogButtonBox::ButtonRole::ResetRole);
        define_qenum_value_under(rb_cQDialogButtonBoxButtonRole, "ApplyRole", QDialogButtonBox::ButtonRole::ApplyRole);
        define_qenum_value_under(rb_cQDialogButtonBoxButtonRole, "NRoles", QDialogButtonBox::ButtonRole::NRoles);

    Data_Type<QDialogButtonBox::StandardButton> rb_cQDialogButtonBoxStandardButton =
        // RubyQt6::QtWidgets::QDialogButtonBox::StandardButton
        define_qenum_under<QDialogButtonBox::StandardButton>(rb_cQDialogButtonBox, "StandardButton");
        define_qenum_value_under(rb_cQDialogButtonBoxStandardButton, "NoButton", QDialogButtonBox::StandardButton::NoButton);
        define_qenum_value_under(rb_cQDialogButtonBoxStandardButton, "Ok", QDialogButtonBox::StandardButton::Ok);
        define_qenum_value_under(rb_cQDialogButtonBoxStandardButton, "Save", QDialogButtonBox::StandardButton::Save);
        define_qenum_value_under(rb_cQDialogButtonBoxStandardButton, "SaveAll", QDialogButtonBox::StandardButton::SaveAll);
        define_qenum_value_under(rb_cQDialogButtonBoxStandardButton, "Open", QDialogButtonBox::StandardButton::Open);
        define_qenum_value_under(rb_cQDialogButtonBoxStandardButton, "Yes", QDialogButtonBox::StandardButton::Yes);
        define_qenum_value_under(rb_cQDialogButtonBoxStandardButton, "YesToAll", QDialogButtonBox::StandardButton::YesToAll);
        define_qenum_value_under(rb_cQDialogButtonBoxStandardButton, "No", QDialogButtonBox::StandardButton::No);
        define_qenum_value_under(rb_cQDialogButtonBoxStandardButton, "NoToAll", QDialogButtonBox::StandardButton::NoToAll);
        define_qenum_value_under(rb_cQDialogButtonBoxStandardButton, "Abort", QDialogButtonBox::StandardButton::Abort);
        define_qenum_value_under(rb_cQDialogButtonBoxStandardButton, "Retry", QDialogButtonBox::StandardButton::Retry);
        define_qenum_value_under(rb_cQDialogButtonBoxStandardButton, "Ignore", QDialogButtonBox::StandardButton::Ignore);
        define_qenum_value_under(rb_cQDialogButtonBoxStandardButton, "Close", QDialogButtonBox::StandardButton::Close);
        define_qenum_value_under(rb_cQDialogButtonBoxStandardButton, "Cancel", QDialogButtonBox::StandardButton::Cancel);
        define_qenum_value_under(rb_cQDialogButtonBoxStandardButton, "Discard", QDialogButtonBox::StandardButton::Discard);
        define_qenum_value_under(rb_cQDialogButtonBoxStandardButton, "Help", QDialogButtonBox::StandardButton::Help);
        define_qenum_value_under(rb_cQDialogButtonBoxStandardButton, "Apply", QDialogButtonBox::StandardButton::Apply);
        define_qenum_value_under(rb_cQDialogButtonBoxStandardButton, "Reset", QDialogButtonBox::StandardButton::Reset);
        define_qenum_value_under(rb_cQDialogButtonBoxStandardButton, "RestoreDefaults", QDialogButtonBox::StandardButton::RestoreDefaults);
        define_qenum_value_under(rb_cQDialogButtonBoxStandardButton, "FirstButton", QDialogButtonBox::StandardButton::FirstButton);
        define_qenum_value_under(rb_cQDialogButtonBoxStandardButton, "LastButton", QDialogButtonBox::StandardButton::LastButton);

    Data_Type<QFlags<QDialogButtonBox::StandardButton>> rb_cQDialogButtonBoxStandardButtons =
        // RubyQt6::QtWidgets::QDialogButtonBox::StandardButtons
        define_qflags_under<QDialogButtonBox::StandardButton>(rb_cQDialogButtonBox, "StandardButtons");
}
