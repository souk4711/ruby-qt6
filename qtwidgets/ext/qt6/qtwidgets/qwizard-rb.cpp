#include "qwizard-rb.hpp"
#include <qwizard.h>
#include <rice/qenum.hpp>
#include <rice/qflags.hpp>

#include <QAbstractButton>

using namespace Rice;

Rice::Class rb_cQWizard;
Rice::Class rb_cQWizardPage;

void Init_qwizard(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQWizard =
        // RubyQt6::QtWidgets::QWizard
        define_class_under<QWizard, QDialog>(rb_mQt6QtWidgets, "QWizard")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QWizard::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QWizard, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("add_page", &QWizard::addPage, Arg("page").takeOwnership())
            .define_method("button", &QWizard::button, Arg("which"))
            .define_method("button_text", &QWizard::buttonText, Arg("which"))
            .define_method("current_id", &QWizard::currentId)
            .define_method("current_page", &QWizard::currentPage)
            .define_method("field", &QWizard::field, Arg("name"))
            .define_method("has_visited_page", &QWizard::hasVisitedPage, Arg("id"))
            .define_method("next_id", &QWizard::nextId)
            .define_method("options", &QWizard::options)
            .define_method("page", &QWizard::page, Arg("id"))
            .define_method("page_ids", &QWizard::pageIds)
            .define_method("pixmap", &QWizard::pixmap, Arg("which"))
            .define_method("remove_page", &QWizard::removePage, Arg("id"))
            .define_method("set_button", &QWizard::setButton, Arg("which"), Arg("button").takeOwnership())
            .define_method("set_button_layout", &QWizard::setButtonLayout, Arg("layout"))
            .define_method("set_button_text", &QWizard::setButtonText, Arg("which"), Arg("text"))
            .define_method("set_default_property", &QWizard::setDefaultProperty, Arg("class_name"), Arg("property"), Arg("changed_signal"))
            .define_method("set_field", &QWizard::setField, Arg("name"), Arg("value"))
            .define_method("set_option", &QWizard::setOption, Arg("option"), Arg("on") = static_cast<bool>(true))
            .define_method("set_options", &QWizard::setOptions, Arg("options"))
            .define_method("set_page", &QWizard::setPage, Arg("id"), Arg("page").takeOwnership())
            .define_method("set_pixmap", &QWizard::setPixmap, Arg("which"), Arg("pixmap"))
            .define_method("set_side_widget", &QWizard::setSideWidget, Arg("widget").takeOwnership())
            .define_method("set_start_id", &QWizard::setStartId, Arg("id"))
            .define_method("set_sub_title_format", &QWizard::setSubTitleFormat, Arg("format"))
            .define_method("set_title_format", &QWizard::setTitleFormat, Arg("format"))
            .define_method("set_visible", &QWizard::setVisible, Arg("visible"))
            .define_method("set_wizard_style", &QWizard::setWizardStyle, Arg("style"))
            .define_method("side_widget", &QWizard::sideWidget)
            .define_method("start_id", &QWizard::startId)
            .define_method("sub_title_format", &QWizard::subTitleFormat)
            .define_method("test_option", &QWizard::testOption, Arg("option"))
            .define_method("title_format", &QWizard::titleFormat)
            .define_method("validate_current_page", &QWizard::validateCurrentPage)
            .define_method("visited_ids", &QWizard::visitedIds)
            .define_method("wizard_style", &QWizard::wizardStyle)
            // Public Slots
            .define_method("back", &QWizard::back)
            .define_method("next", &QWizard::next)
            .define_method("restart", &QWizard::restart)
            .define_method("set_current_id", &QWizard::setCurrentId, Arg("id"))
            // Signals
            .define_method("current_id_changed", &QWizard::currentIdChanged, Arg("id"))
            .define_method("custom_button_clicked", &QWizard::customButtonClicked, Arg("which"))
            .define_method("help_requested", &QWizard::helpRequested)
            .define_method("page_added", &QWizard::pageAdded, Arg("id"))
            .define_method("page_removed", &QWizard::pageRemoved, Arg("id"));

    Enum<QWizard::WizardButton> rb_cQWizardWizardButton =
        // RubyQt6::QtWidgets::QWizard::WizardButton
        define_qenum_under<QWizard::WizardButton>("WizardButton", rb_cQWizard)
            .define_value("BackButton", QWizard::WizardButton::BackButton)
            .define_value("NextButton", QWizard::WizardButton::NextButton)
            .define_value("CommitButton", QWizard::WizardButton::CommitButton)
            .define_value("FinishButton", QWizard::WizardButton::FinishButton)
            .define_value("CancelButton", QWizard::WizardButton::CancelButton)
            .define_value("HelpButton", QWizard::WizardButton::HelpButton)
            .define_value("CustomButton1", QWizard::WizardButton::CustomButton1)
            .define_value("CustomButton2", QWizard::WizardButton::CustomButton2)
            .define_value("CustomButton3", QWizard::WizardButton::CustomButton3)
            .define_value("Stretch", QWizard::WizardButton::Stretch)
            .define_value("NoButton", QWizard::WizardButton::NoButton)
            .define_value("NStandardButtons", QWizard::WizardButton::NStandardButtons)
            .define_value("NButtons", QWizard::WizardButton::NButtons);

    Enum<QWizard::WizardOption> rb_cQWizardWizardOption =
        // RubyQt6::QtWidgets::QWizard::WizardOption
        define_qenum_under<QWizard::WizardOption>("WizardOption", rb_cQWizard)
            .define_value("IndependentPages", QWizard::WizardOption::IndependentPages)
            .define_value("IgnoreSubTitles", QWizard::WizardOption::IgnoreSubTitles)
            .define_value("ExtendedWatermarkPixmap", QWizard::WizardOption::ExtendedWatermarkPixmap)
            .define_value("NoDefaultButton", QWizard::WizardOption::NoDefaultButton)
            .define_value("NoBackButtonOnStartPage", QWizard::WizardOption::NoBackButtonOnStartPage)
            .define_value("NoBackButtonOnLastPage", QWizard::WizardOption::NoBackButtonOnLastPage)
            .define_value("DisabledBackButtonOnLastPage", QWizard::WizardOption::DisabledBackButtonOnLastPage)
            .define_value("HaveNextButtonOnLastPage", QWizard::WizardOption::HaveNextButtonOnLastPage)
            .define_value("HaveFinishButtonOnEarlyPages", QWizard::WizardOption::HaveFinishButtonOnEarlyPages)
            .define_value("NoCancelButton", QWizard::WizardOption::NoCancelButton)
            .define_value("CancelButtonOnLeft", QWizard::WizardOption::CancelButtonOnLeft)
            .define_value("HaveHelpButton", QWizard::WizardOption::HaveHelpButton)
            .define_value("HelpButtonOnRight", QWizard::WizardOption::HelpButtonOnRight)
            .define_value("HaveCustomButton1", QWizard::WizardOption::HaveCustomButton1)
            .define_value("HaveCustomButton2", QWizard::WizardOption::HaveCustomButton2)
            .define_value("HaveCustomButton3", QWizard::WizardOption::HaveCustomButton3)
            .define_value("NoCancelButtonOnLastPage", QWizard::WizardOption::NoCancelButtonOnLastPage);

    Enum<QWizard::WizardPixmap> rb_cQWizardWizardPixmap =
        // RubyQt6::QtWidgets::QWizard::WizardPixmap
        define_qenum_under<QWizard::WizardPixmap>("WizardPixmap", rb_cQWizard)
            .define_value("WatermarkPixmap", QWizard::WizardPixmap::WatermarkPixmap)
            .define_value("LogoPixmap", QWizard::WizardPixmap::LogoPixmap)
            .define_value("BannerPixmap", QWizard::WizardPixmap::BannerPixmap)
            .define_value("BackgroundPixmap", QWizard::WizardPixmap::BackgroundPixmap)
            .define_value("NPixmaps", QWizard::WizardPixmap::NPixmaps);

    Enum<QWizard::WizardStyle> rb_cQWizardWizardStyle =
        // RubyQt6::QtWidgets::QWizard::WizardStyle
        define_qenum_under<QWizard::WizardStyle>("WizardStyle", rb_cQWizard)
            .define_value("ClassicStyle", QWizard::WizardStyle::ClassicStyle)
            .define_value("ModernStyle", QWizard::WizardStyle::ModernStyle)
            .define_value("MacStyle", QWizard::WizardStyle::MacStyle)
            .define_value("AeroStyle", QWizard::WizardStyle::AeroStyle)
            .define_value("NStyles", QWizard::WizardStyle::NStyles);

    Data_Type<QFlags<QWizard::WizardOption>> rb_cQWizardWizardOptions =
        // RubyQt6::QtWidgets::QWizard::WizardOptions
        define_qflags_under<QWizard::WizardOption>(rb_cQWizard, "WizardOptions");

    rb_cQWizardPage =
        // RubyQt6::QtWidgets::QWizardPage
        define_class_under<QWizardPage, QWidget>(rb_mQt6QtWidgets, "QWizardPage")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QWizardPage::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QWizardPage, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("button_text", &QWizardPage::buttonText, Arg("which"))
            .define_method("cleanup_page", &QWizardPage::cleanupPage)
            .define_method("initialize_page", &QWizardPage::initializePage)
            .define_method("commit_page?", &QWizardPage::isCommitPage)
            .define_method("complete?", &QWizardPage::isComplete)
            .define_method("final_page?", &QWizardPage::isFinalPage)
            .define_method("next_id", &QWizardPage::nextId)
            .define_method("pixmap", &QWizardPage::pixmap, Arg("which"))
            .define_method("set_button_text", &QWizardPage::setButtonText, Arg("which"), Arg("text"))
            .define_method("set_commit_page", &QWizardPage::setCommitPage, Arg("commit_page"))
            .define_method("set_final_page", &QWizardPage::setFinalPage, Arg("final_page"))
            .define_method("set_pixmap", &QWizardPage::setPixmap, Arg("which"), Arg("pixmap"))
            .define_method("set_sub_title", &QWizardPage::setSubTitle, Arg("sub_title"))
            .define_method("set_title", &QWizardPage::setTitle, Arg("title"))
            .define_method("sub_title", &QWizardPage::subTitle)
            .define_method("title", &QWizardPage::title)
            .define_method("validate_page", &QWizardPage::validatePage)
            // Signals
            .define_method("complete_changed", &QWizardPage::completeChanged);
}
