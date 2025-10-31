#include "qpalette-rb.hpp"
#include <qpalette.h>
#include <rice/qenum.hpp>

using namespace Rice;

Rice::Class rb_cQPalette;

void Init_qpalette(Rice::Module rb_mQt6QtGui)
{
    rb_cQPalette =
        // RubyQt6::QtGui::QPalette
        define_class_under<QPalette>(rb_mQt6QtGui, "QPalette")
            // Constructor
            .define_constructor(Constructor<QPalette>())
            .define_constructor(Constructor<QPalette, const QColor &>(), Arg("button"))
            .define_constructor(Constructor<QPalette, const QColor &, const QColor &>(), Arg("button"), Arg("window"))
            // Public Functions
            .define_method("accent", &QPalette::accent)
            .define_method("alternate_base", &QPalette::alternateBase)
            .define_method("base", &QPalette::base)
            .define_method("bright_text", &QPalette::brightText)
            .define_method<const QBrush &(QPalette::*)(QPalette::ColorGroup, QPalette::ColorRole) const>("brush", &QPalette::brush, Arg("cg"), Arg("cr"))
            .define_method<const QBrush &(QPalette::*)(QPalette::ColorRole) const>("brush", &QPalette::brush, Arg("cr"))
            .define_method("button", &QPalette::button)
            .define_method("button_text", &QPalette::buttonText)
            .define_method("cache_key", &QPalette::cacheKey)
            .define_method<const QColor &(QPalette::*)(QPalette::ColorGroup, QPalette::ColorRole) const>("color", &QPalette::color, Arg("cg"), Arg("cr"))
            .define_method<const QColor &(QPalette::*)(QPalette::ColorRole) const>("color", &QPalette::color, Arg("cr"))
            .define_method("current_color_group", &QPalette::currentColorGroup)
            .define_method("dark", &QPalette::dark)
            .define_method("highlight", &QPalette::highlight)
            .define_method("highlighted_text", &QPalette::highlightedText)
            .define_method("brush_set?", &QPalette::isBrushSet, Arg("cg"), Arg("cr"))
            .define_method("copy_of?", &QPalette::isCopyOf, Arg("p"))
            .define_method("equal?", &QPalette::isEqual, Arg("cr1"), Arg("cr2"))
            .define_method("light", &QPalette::light)
            .define_method("link", &QPalette::link)
            .define_method("link_visited", &QPalette::linkVisited)
            .define_method("mid", &QPalette::mid)
            .define_method("midlight", &QPalette::midlight)
            .define_method("placeholder_text", &QPalette::placeholderText)
            .define_method("resolve", &QPalette::resolve, Arg("other"))
            .define_method("resolve_mask", &QPalette::resolveMask)
            .define_method<void (QPalette::*)(QPalette::ColorGroup, QPalette::ColorRole, const QBrush &)>("set_brush", &QPalette::setBrush, Arg("cg"), Arg("cr"), Arg("brush"))
            .define_method<void (QPalette::*)(QPalette::ColorRole, const QBrush &)>("set_brush", &QPalette::setBrush, Arg("cr"), Arg("brush"))
            .define_method<void (QPalette::*)(QPalette::ColorGroup, QPalette::ColorRole, const QColor &)>("set_color", &QPalette::setColor, Arg("cg"), Arg("cr"), Arg("color"))
            .define_method<void (QPalette::*)(QPalette::ColorRole, const QColor &)>("set_color", &QPalette::setColor, Arg("cr"), Arg("color"))
            .define_method<void (QPalette::*)(QPalette::ColorGroup, const QBrush &, const QBrush &, const QBrush &, const QBrush &, const QBrush &, const QBrush &, const QBrush &, const QBrush &, const QBrush &)>("set_color_group", &QPalette::setColorGroup, Arg("cr"), Arg("window_text"), Arg("button"), Arg("light"), Arg("dark"), Arg("mid"), Arg("text"), Arg("bright_text"), Arg("base"), Arg("window"))
            .define_method("set_current_color_group", &QPalette::setCurrentColorGroup, Arg("cg"))
            .define_method("set_resolve_mask", &QPalette::setResolveMask, Arg("mask"))
            .define_method("shadow", &QPalette::shadow)
            .define_method("swap", &QPalette::swap, Arg("other"))
            .define_method("text", &QPalette::text)
            .define_method("tool_tip_base", &QPalette::toolTipBase)
            .define_method("tool_tip_text", &QPalette::toolTipText)
            .define_method("window", &QPalette::window)
            .define_method("window_text", &QPalette::windowText);

    Data_Type<QPalette::ColorGroup> rb_cQPaletteColorGroup =
        // RubyQt6::QtGui::QPalette::ColorGroup
        define_qenum_under<QPalette::ColorGroup>(rb_cQPalette, "ColorGroup");
        define_qenum_value_under(rb_cQPaletteColorGroup, "Active", QPalette::ColorGroup::Active);
        define_qenum_value_under(rb_cQPaletteColorGroup, "Disabled", QPalette::ColorGroup::Disabled);
        define_qenum_value_under(rb_cQPaletteColorGroup, "Inactive", QPalette::ColorGroup::Inactive);
        define_qenum_value_under(rb_cQPaletteColorGroup, "NColorGroups", QPalette::ColorGroup::NColorGroups);
        define_qenum_value_under(rb_cQPaletteColorGroup, "Current", QPalette::ColorGroup::Current);
        define_qenum_value_under(rb_cQPaletteColorGroup, "All", QPalette::ColorGroup::All);
        define_qenum_value_under(rb_cQPaletteColorGroup, "Normal", QPalette::ColorGroup::Normal);

    Data_Type<QPalette::ColorRole> rb_cQPaletteColorRole =
        // RubyQt6::QtGui::QPalette::ColorRole
        define_qenum_under<QPalette::ColorRole>(rb_cQPalette, "ColorRole");
        define_qenum_value_under(rb_cQPaletteColorRole, "WindowText", QPalette::ColorRole::WindowText);
        define_qenum_value_under(rb_cQPaletteColorRole, "Button", QPalette::ColorRole::Button);
        define_qenum_value_under(rb_cQPaletteColorRole, "Light", QPalette::ColorRole::Light);
        define_qenum_value_under(rb_cQPaletteColorRole, "Midlight", QPalette::ColorRole::Midlight);
        define_qenum_value_under(rb_cQPaletteColorRole, "Dark", QPalette::ColorRole::Dark);
        define_qenum_value_under(rb_cQPaletteColorRole, "Mid", QPalette::ColorRole::Mid);
        define_qenum_value_under(rb_cQPaletteColorRole, "Text", QPalette::ColorRole::Text);
        define_qenum_value_under(rb_cQPaletteColorRole, "BrightText", QPalette::ColorRole::BrightText);
        define_qenum_value_under(rb_cQPaletteColorRole, "ButtonText", QPalette::ColorRole::ButtonText);
        define_qenum_value_under(rb_cQPaletteColorRole, "Base", QPalette::ColorRole::Base);
        define_qenum_value_under(rb_cQPaletteColorRole, "Window", QPalette::ColorRole::Window);
        define_qenum_value_under(rb_cQPaletteColorRole, "Shadow", QPalette::ColorRole::Shadow);
        define_qenum_value_under(rb_cQPaletteColorRole, "Highlight", QPalette::ColorRole::Highlight);
        define_qenum_value_under(rb_cQPaletteColorRole, "HighlightedText", QPalette::ColorRole::HighlightedText);
        define_qenum_value_under(rb_cQPaletteColorRole, "Link", QPalette::ColorRole::Link);
        define_qenum_value_under(rb_cQPaletteColorRole, "LinkVisited", QPalette::ColorRole::LinkVisited);
        define_qenum_value_under(rb_cQPaletteColorRole, "AlternateBase", QPalette::ColorRole::AlternateBase);
        define_qenum_value_under(rb_cQPaletteColorRole, "NoRole", QPalette::ColorRole::NoRole);
        define_qenum_value_under(rb_cQPaletteColorRole, "ToolTipBase", QPalette::ColorRole::ToolTipBase);
        define_qenum_value_under(rb_cQPaletteColorRole, "ToolTipText", QPalette::ColorRole::ToolTipText);
        define_qenum_value_under(rb_cQPaletteColorRole, "PlaceholderText", QPalette::ColorRole::PlaceholderText);
        define_qenum_value_under(rb_cQPaletteColorRole, "Accent", QPalette::ColorRole::Accent);
        define_qenum_value_under(rb_cQPaletteColorRole, "NColorRoles", QPalette::ColorRole::NColorRoles);
}
