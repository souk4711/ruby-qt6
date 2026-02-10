#include "qaction-rb.hpp"
#include <qaction.h>
#include <rice/qt6/qenum.hpp>

#include <QActionGroup>
#include <QFont>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQAction;

void Init_qaction(Module rb_mQt6QtGui)
{
    rb_cQAction =
        // RubyQt6::QtGui::QAction
        define_class_under<QAction, QObject>(rb_mQt6QtGui, "QAction")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qvariant_register_metatype", []() -> int { return qRegisterMetaType<QAction *>(); })
            .define_singleton_function("_qvariant_from_value", [](QAction *value) -> QVariant { return QVariant::fromValue(value); })
            .define_singleton_function("_qvariant_to_value", [](const QVariant &qvariant) -> QAction * { return qvariant.value<QAction *>(); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QAction::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QAction, const QIcon &, const QString &, QObject *>(), Arg("icon"), Arg("text"), Arg("parent"))
            // Public Functions
            .define_method("action_group", &QAction::actionGroup)
            .define_method("activate", &QAction::activate, Arg("event"))
            .define_method("associated_objects", &QAction::associatedObjects)
            .define_method("auto_repeat", &QAction::autoRepeat)
            .define_method("data", &QAction::data)
            .define_method("font", &QAction::font)
            .define_method("icon", &QAction::icon)
            .define_method("icon_text", &QAction::iconText)
            .define_method("checkable?", &QAction::isCheckable)
            .define_method("checked?", &QAction::isChecked)
            .define_method("enabled?", &QAction::isEnabled)
            .define_method("icon_visible_in_menu?", &QAction::isIconVisibleInMenu)
            .define_method("separator?", &QAction::isSeparator)
            .define_method("shortcut_visible_in_context_menu?", &QAction::isShortcutVisibleInContextMenu)
            .define_method("visible?", &QAction::isVisible)
            .define_method("menu_role", &QAction::menuRole)
            .define_method("priority", &QAction::priority)
            .define_method("set_action_group", &QAction::setActionGroup, Arg("group"))
            .define_method("set_auto_repeat", &QAction::setAutoRepeat, Arg("b"))
            .define_method("set_checkable", &QAction::setCheckable, Arg("b"))
            .define_method("set_data", &QAction::setData, Arg("var"))
            .define_method("set_font", &QAction::setFont, Arg("font"))
            .define_method("set_icon", &QAction::setIcon, Arg("icon"))
            .define_method("set_icon_text", &QAction::setIconText, Arg("text"))
            .define_method("set_icon_visible_in_menu", &QAction::setIconVisibleInMenu, Arg("visible"))
            .define_method("set_menu_role", &QAction::setMenuRole, Arg("menu_role"))
            .define_method("set_priority", &QAction::setPriority, Arg("priority"))
            .define_method("set_separator", &QAction::setSeparator, Arg("b"))
            .define_method("_set_shortcut", &QAction::setShortcut, Arg("shortcut"))
            .define_method("set_shortcut_context", &QAction::setShortcutContext, Arg("context"))
            .define_method("set_shortcut_visible_in_context_menu", &QAction::setShortcutVisibleInContextMenu, Arg("show"))
            .define_method<void (QAction::*)(QKeySequence::StandardKey)>("set_shortcuts", &QAction::setShortcuts, Arg("shortcuts"))
            .define_method<void (QAction::*)(const QList<QKeySequence> &)>("set_shortcuts", &QAction::setShortcuts, Arg("shortcuts"))
            .define_method("_set_status_tip", &QAction::setStatusTip, Arg("status_tip"))
            .define_method("_set_text", &QAction::setText, Arg("text"))
            .define_method("_set_tool_tip", &QAction::setToolTip, Arg("tip"))
            .define_method("_set_whats_this", &QAction::setWhatsThis, Arg("what"))
            .define_method("shortcut", &QAction::shortcut)
            .define_method("shortcut_context", &QAction::shortcutContext)
            .define_method("shortcuts", &QAction::shortcuts)
            .define_method("show_status_text", &QAction::showStatusText, Arg("object") = static_cast<QObject *>(nullptr))
            .define_method("status_tip", &QAction::statusTip)
            .define_method("text", &QAction::text)
            .define_method("tool_tip", &QAction::toolTip)
            .define_method("whats_this", &QAction::whatsThis)
            // Public Slots
            .define_method("hover", &QAction::hover)
            .define_method("reset_enabled", &QAction::resetEnabled)
            .define_method("set_checked", &QAction::setChecked, Arg("b"))
            .define_method("set_disabled", &QAction::setDisabled, Arg("b"))
            .define_method("set_enabled", &QAction::setEnabled, Arg("b"))
            .define_method("set_visible", &QAction::setVisible, Arg("b"))
            .define_method("toggle", &QAction::toggle)
            .define_method("trigger", &QAction::trigger);
            // Signals
            // .define_method("changed", &QAction::changed)
            // .define_method("checkable_changed", &QAction::checkableChanged, Arg("checkable"))
            // .define_method("enabled_changed", &QAction::enabledChanged, Arg("enabled"))
            // .define_method("hovered", &QAction::hovered)
            // .define_method("toggled", &QAction::toggled, Arg("checked"))
            // .define_method("triggered", &QAction::triggered, Arg("checked") = static_cast<bool>(false))
            // .define_method("visible_changed", &QAction::visibleChanged);

    Data_Type<QAction::MenuRole> rb_cQActionMenuRole =
        // RubyQt6::QtGui::QAction::MenuRole
        define_qenum_under<QAction::MenuRole>(rb_cQAction, "MenuRole");
        define_qenum_value_under(rb_cQActionMenuRole, "NoRole", QAction::MenuRole::NoRole);
        define_qenum_value_under(rb_cQActionMenuRole, "TextHeuristicRole", QAction::MenuRole::TextHeuristicRole);
        define_qenum_value_under(rb_cQActionMenuRole, "ApplicationSpecificRole", QAction::MenuRole::ApplicationSpecificRole);
        define_qenum_value_under(rb_cQActionMenuRole, "AboutQtRole", QAction::MenuRole::AboutQtRole);
        define_qenum_value_under(rb_cQActionMenuRole, "AboutRole", QAction::MenuRole::AboutRole);
        define_qenum_value_under(rb_cQActionMenuRole, "PreferencesRole", QAction::MenuRole::PreferencesRole);
        define_qenum_value_under(rb_cQActionMenuRole, "QuitRole", QAction::MenuRole::QuitRole);

    Data_Type<QAction::Priority> rb_cQActionPriority =
        // RubyQt6::QtGui::QAction::Priority
        define_qenum_under<QAction::Priority>(rb_cQAction, "Priority");
        define_qenum_value_under(rb_cQActionPriority, "LowPriority", QAction::Priority::LowPriority);
        define_qenum_value_under(rb_cQActionPriority, "NormalPriority", QAction::Priority::NormalPriority);
        define_qenum_value_under(rb_cQActionPriority, "HighPriority", QAction::Priority::HighPriority);

    Data_Type<QAction::ActionEvent> rb_cQActionActionEvent =
        // RubyQt6::QtGui::QAction::ActionEvent
        define_qenum_under<QAction::ActionEvent>(rb_cQAction, "ActionEvent");
        define_qenum_value_under(rb_cQActionActionEvent, "Trigger", QAction::ActionEvent::Trigger);
        define_qenum_value_under(rb_cQActionActionEvent, "Hover", QAction::ActionEvent::Hover);
}
