#include "qtextoption-rb.hpp"
#include <qtextoption.h>
#include <rice/qenum.hpp>
#include <rice/qflags.hpp>

#include <QList>

using namespace Rice;

Rice::Class rb_cQTextOption;

void Init_qtextoption(Rice::Module rb_mQt6QtGui)
{
    rb_cQTextOption =
        // RubyQt6::QtGui::QTextOption
        define_class_under<QTextOption>(rb_mQt6QtGui, "QTextOption")
            // RubyQt6-Defined Functions
            .define_method("set_alignment", [](QTextOption *self, Qt::AlignmentFlag alignment) -> void { return self->setAlignment(alignment); }, Arg("alignment"))
            // Public Functions
            .define_method("alignment", &QTextOption::alignment)
            .define_method("flags", &QTextOption::flags)
            .define_method("set_alignment", &QTextOption::setAlignment, Arg("alignment"))
            .define_method("set_flags", &QTextOption::setFlags, Arg("flags"))
            .define_method("set_tab_array", &QTextOption::setTabArray, Arg("tab_stops"))
            .define_method("set_tab_stop_distance", &QTextOption::setTabStopDistance, Arg("tab_stop_distance"))
            .define_method("set_tabs", &QTextOption::setTabs, Arg("tab_stops"))
            .define_method("set_text_direction", &QTextOption::setTextDirection, Arg("a_direction"))
            .define_method("set_use_design_metrics", &QTextOption::setUseDesignMetrics, Arg("b"))
            .define_method("set_wrap_mode", &QTextOption::setWrapMode, Arg("wrap"))
            .define_method("tab_array", &QTextOption::tabArray)
            .define_method("tab_stop_distance", &QTextOption::tabStopDistance)
            .define_method("tabs", &QTextOption::tabs)
            .define_method("text_direction", &QTextOption::textDirection)
            .define_method("use_design_metrics", &QTextOption::useDesignMetrics)
            .define_method("wrap_mode", &QTextOption::wrapMode);

    Enum<QTextOption::Flag> rb_cQTextOptionFlag =
        // RubyQt6::QtGui::QTextOption::Flag
        define_qenum_under<QTextOption::Flag>("Flag", rb_cQTextOption)
            .define_value("ShowTabsAndSpaces", QTextOption::Flag::ShowTabsAndSpaces)
            .define_value("ShowLineAndParagraphSeparators", QTextOption::Flag::ShowLineAndParagraphSeparators)
            .define_value("AddSpaceForLineAndParagraphSeparators", QTextOption::Flag::AddSpaceForLineAndParagraphSeparators)
            .define_value("SuppressColors", QTextOption::Flag::SuppressColors)
            .define_value("ShowDocumentTerminator", QTextOption::Flag::ShowDocumentTerminator)
            .define_value("ShowDefaultIgnorables", QTextOption::Flag::ShowDefaultIgnorables)
            .define_value("DisableEmojiParsing", QTextOption::Flag::DisableEmojiParsing)
            .define_value("IncludeTrailingSpaces", QTextOption::Flag::IncludeTrailingSpaces);

    Enum<QTextOption::TabType> rb_cQTextOptionTabType =
        // RubyQt6::QtGui::QTextOption::TabType
        define_qenum_under<QTextOption::TabType>("TabType", rb_cQTextOption)
            .define_value("LeftTab", QTextOption::TabType::LeftTab)
            .define_value("RightTab", QTextOption::TabType::RightTab)
            .define_value("CenterTab", QTextOption::TabType::CenterTab)
            .define_value("DelimiterTab", QTextOption::TabType::DelimiterTab);

    Enum<QTextOption::WrapMode> rb_cQTextOptionWrapMode =
        // RubyQt6::QtGui::QTextOption::WrapMode
        define_qenum_under<QTextOption::WrapMode>("WrapMode", rb_cQTextOption)
            .define_value("NoWrap", QTextOption::WrapMode::NoWrap)
            .define_value("WordWrap", QTextOption::WrapMode::WordWrap)
            .define_value("ManualWrap", QTextOption::WrapMode::ManualWrap)
            .define_value("WrapAnywhere", QTextOption::WrapMode::WrapAnywhere)
            .define_value("WrapAtWordBoundaryOrAnywhere", QTextOption::WrapMode::WrapAtWordBoundaryOrAnywhere);

    Data_Type<QFlags<QTextOption::Flag>> rb_cQTextOptionFlags =
        // RubyQt6::QtGui::QTextOption::Flags
        define_qflags_under<QTextOption::Flag>(rb_cQTextOption, "Flags");
}
