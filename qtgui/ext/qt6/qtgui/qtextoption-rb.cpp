#include "qtextoption-rb.hpp"
#include <qtextoption.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

#include <QList>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQTextOption;

void Init_qtextoption(Module rb_mQt6QtGui)
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

    Data_Type<QTextOption::Flag> rb_cQTextOptionFlag =
        // RubyQt6::QtGui::QTextOption::Flag
        define_qenum_under<QTextOption::Flag>(rb_cQTextOption, "Flag");
        define_qenum_value_under(rb_cQTextOptionFlag, "ShowTabsAndSpaces", QTextOption::Flag::ShowTabsAndSpaces);
        define_qenum_value_under(rb_cQTextOptionFlag, "ShowLineAndParagraphSeparators", QTextOption::Flag::ShowLineAndParagraphSeparators);
        define_qenum_value_under(rb_cQTextOptionFlag, "AddSpaceForLineAndParagraphSeparators", QTextOption::Flag::AddSpaceForLineAndParagraphSeparators);
        define_qenum_value_under(rb_cQTextOptionFlag, "SuppressColors", QTextOption::Flag::SuppressColors);
        define_qenum_value_under(rb_cQTextOptionFlag, "ShowDocumentTerminator", QTextOption::Flag::ShowDocumentTerminator);
        define_qenum_value_under(rb_cQTextOptionFlag, "ShowDefaultIgnorables", QTextOption::Flag::ShowDefaultIgnorables);
        define_qenum_value_under(rb_cQTextOptionFlag, "DisableEmojiParsing", QTextOption::Flag::DisableEmojiParsing);
        define_qenum_value_under(rb_cQTextOptionFlag, "IncludeTrailingSpaces", QTextOption::Flag::IncludeTrailingSpaces);

    Data_Type<QTextOption::TabType> rb_cQTextOptionTabType =
        // RubyQt6::QtGui::QTextOption::TabType
        define_qenum_under<QTextOption::TabType>(rb_cQTextOption, "TabType");
        define_qenum_value_under(rb_cQTextOptionTabType, "LeftTab", QTextOption::TabType::LeftTab);
        define_qenum_value_under(rb_cQTextOptionTabType, "RightTab", QTextOption::TabType::RightTab);
        define_qenum_value_under(rb_cQTextOptionTabType, "CenterTab", QTextOption::TabType::CenterTab);
        define_qenum_value_under(rb_cQTextOptionTabType, "DelimiterTab", QTextOption::TabType::DelimiterTab);

    Data_Type<QTextOption::WrapMode> rb_cQTextOptionWrapMode =
        // RubyQt6::QtGui::QTextOption::WrapMode
        define_qenum_under<QTextOption::WrapMode>(rb_cQTextOption, "WrapMode");
        define_qenum_value_under(rb_cQTextOptionWrapMode, "NoWrap", QTextOption::WrapMode::NoWrap);
        define_qenum_value_under(rb_cQTextOptionWrapMode, "WordWrap", QTextOption::WrapMode::WordWrap);
        define_qenum_value_under(rb_cQTextOptionWrapMode, "ManualWrap", QTextOption::WrapMode::ManualWrap);
        define_qenum_value_under(rb_cQTextOptionWrapMode, "WrapAnywhere", QTextOption::WrapMode::WrapAnywhere);
        define_qenum_value_under(rb_cQTextOptionWrapMode, "WrapAtWordBoundaryOrAnywhere", QTextOption::WrapMode::WrapAtWordBoundaryOrAnywhere);

    Data_Type<QFlags<QTextOption::Flag>> rb_cQTextOptionFlags =
        // RubyQt6::QtGui::QTextOption::Flags
        define_qflags_under<QTextOption::Flag>(rb_cQTextOption, "Flags");
}
