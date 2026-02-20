#include "kguiitem-rb.hpp"
#include <kguiitem.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cKGuiItem;

void Init_kguiitem(Module rb_mQt6KWidgetsAddons)
{
    rb_cKGuiItem =
        // RubyQt6::KWidgetsAddons::KGuiItem
        define_class_under<KGuiItem>(rb_mQt6KWidgetsAddons, "KGuiItem")
            // Constructor
            .define_constructor(Constructor<KGuiItem, const QString &, const QString &, const QString &, const QString &>(), Arg("text"), Arg("icon_name"), Arg("tool_tip"), Arg("whats_this"))
            // Public Functions
            .define_method("has_icon", &KGuiItem::hasIcon)
            .define_method("icon", &KGuiItem::icon)
            .define_method("icon_name", &KGuiItem::iconName)
            .define_method("enabled?", &KGuiItem::isEnabled)
            .define_method("plain_text", &KGuiItem::plainText)
            .define_method("set_enabled", &KGuiItem::setEnabled, Arg("enable"))
            .define_method("set_icon", &KGuiItem::setIcon, Arg("iconset"))
            .define_method("set_icon_name", &KGuiItem::setIconName, Arg("icon_name"))
            .define_method("set_text", &KGuiItem::setText, Arg("text"))
            .define_method("set_tool_tip", &KGuiItem::setToolTip, Arg("tooltip"))
            .define_method("set_whats_this", &KGuiItem::setWhatsThis, Arg("whats_this"))
            .define_method("text", &KGuiItem::text)
            .define_method("tool_tip", &KGuiItem::toolTip)
            .define_method("whats_this", &KGuiItem::whatsThis)
            // Static Public Members
            .define_singleton_function("assign", &KGuiItem::assign, Arg("button"), Arg("item"));
}
