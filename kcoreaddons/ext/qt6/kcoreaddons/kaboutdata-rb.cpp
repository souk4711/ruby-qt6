#include "kaboutdata-rb.hpp"
#include <kaboutdata.h>
#include <rice/qt6/qenum.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cKAboutData;
Class rb_cKAboutLicense;
Class rb_cKAboutPerson;

void Init_kaboutdata(Module rb_mQt6KCoreAddons)
{
    rb_cKAboutData =
        // RubyQt6::KCoreAddons::KAboutData
        define_class_under<KAboutData>(rb_mQt6KCoreAddons, "KAboutData")
            // Constructor
            .define_constructor(Constructor<KAboutData, const QString &, const QString &, const QString &>(), Arg("component_name"), Arg("display_name"), Arg("version"))
            // Public Functions
            .define_method<KAboutData &(KAboutData::*)(const KAboutPerson &)>("add_author", &KAboutData::addAuthor, Arg("author"))
            .define_method<KAboutData &(KAboutData::*)(const QString &, const QString &, const QString &, const QString &, const QString &)>("add_author", &KAboutData::addAuthor, Arg("name"), Arg("task"), Arg("email_address"), Arg("web_address"), Arg("kde_store_username"))
            .define_method<KAboutData &(KAboutData::*)(const QString &, const QString &, const QString &, const QString &, const QUrl &)>("add_author", &KAboutData::addAuthor, Arg("name"), Arg("task") = static_cast<const QString &>(QString()), Arg("email_address") = static_cast<const QString &>(QString()), Arg("web_address") = static_cast<const QString &>(QString()), Arg("avatar_url") = static_cast<const QUrl &>(QUrl()))
            .define_method<KAboutData &(KAboutData::*)(const KAboutComponent &)>("add_component", &KAboutData::addComponent, Arg("component"))
            .define_method<KAboutData &(KAboutData::*)(const QString &, const QString &, const QString &, const QString &, KAboutLicense::LicenseKey)>("add_component", &KAboutData::addComponent, Arg("name"), Arg("description") = static_cast<const QString &>(QString()), Arg("version") = static_cast<const QString &>(QString()), Arg("web_address") = static_cast<const QString &>(QString()), Arg("license_key") = static_cast<KAboutLicense::LicenseKey>(KAboutLicense::Unknown))
            .define_method<KAboutData &(KAboutData::*)(const QString &, const QString &, const QString &, const QString &, const QString &)>("add_component", &KAboutData::addComponent, Arg("name"), Arg("description"), Arg("version"), Arg("web_address"), Arg("path_to_license_file"))
            .define_method<KAboutData &(KAboutData::*)(const KAboutPerson &)>("add_credit", &KAboutData::addCredit, Arg("person"))
            .define_method<KAboutData &(KAboutData::*)(const QString &, const QString &, const QString &, const QString &, const QString &)>("add_credit", &KAboutData::addCredit, Arg("name"), Arg("task"), Arg("email_address"), Arg("web_address"), Arg("kde_store_username"))
            .define_method<KAboutData &(KAboutData::*)(const QString &, const QString &, const QString &, const QString &, const QUrl &)>("add_credit", &KAboutData::addCredit, Arg("name"), Arg("task") = static_cast<const QString &>(QString()), Arg("email_address") = static_cast<const QString &>(QString()), Arg("web_address") = static_cast<const QString &>(QString()), Arg("avatar_url") = static_cast<const QUrl &>(QUrl()))
            .define_method<KAboutData &(KAboutData::*)(KAboutLicense::LicenseKey)>("add_license", &KAboutData::addLicense, Arg("license_key"))
            .define_method<KAboutData &(KAboutData::*)(KAboutLicense::LicenseKey, KAboutLicense::VersionRestriction)>("add_license", &KAboutData::addLicense, Arg("license_key"), Arg("version_restriction"))
            .define_method("add_license_text", &KAboutData::addLicenseText, Arg("license"))
            .define_method("add_license_text_file", &KAboutData::addLicenseTextFile, Arg("file"))
            .define_method("authors", &KAboutData::authors)
            .define_method("bug_address", &KAboutData::bugAddress)
            .define_method("component_name", &KAboutData::componentName)
            .define_method("components", &KAboutData::components)
            .define_method("copyright_statement", &KAboutData::copyrightStatement)
            .define_method("credits", &KAboutData::credits)
            .define_method("custom_author_plain_text", &KAboutData::customAuthorPlainText)
            .define_method("custom_author_rich_text", &KAboutData::customAuthorRichText)
            .define_method("custom_author_text_enabled", &KAboutData::customAuthorTextEnabled)
            .define_method("desktop_file_name", &KAboutData::desktopFileName)
            .define_method("display_name", &KAboutData::displayName)
            .define_method("homepage", &KAboutData::homepage)
            .define_method("licenses", &KAboutData::licenses)
            .define_method("organization_domain", &KAboutData::organizationDomain)
            .define_method("other_text", &KAboutData::otherText)
            .define_method("process_command_line", &KAboutData::processCommandLine, Arg("parser"))
            .define_method("product_name", &KAboutData::productName)
            .define_method("program_logo", &KAboutData::programLogo)
            .define_method("set_bug_address", &KAboutData::setBugAddress, Arg("bug_address"))
            .define_method("set_component_name", &KAboutData::setComponentName, Arg("component_name"))
            .define_method("set_copyright_statement", &KAboutData::setCopyrightStatement, Arg("copyright_statement"))
            .define_method("set_custom_author_text", &KAboutData::setCustomAuthorText, Arg("plain_text"), Arg("rich_text"))
            .define_method("set_desktop_file_name", &KAboutData::setDesktopFileName, Arg("desktop_file_name"))
            .define_method("set_display_name", &KAboutData::setDisplayName, Arg("display_name"))
            .define_method("set_homepage", &KAboutData::setHomepage, Arg("homepage"))
            .define_method<KAboutData &(KAboutData::*)(KAboutLicense::LicenseKey)>("set_license", &KAboutData::setLicense, Arg("license_key"))
            .define_method<KAboutData &(KAboutData::*)(KAboutLicense::LicenseKey, KAboutLicense::VersionRestriction)>("set_license", &KAboutData::setLicense, Arg("license_key"), Arg("version_restriction"))
            .define_method("set_license_text", &KAboutData::setLicenseText, Arg("license"))
            .define_method("set_license_text_file", &KAboutData::setLicenseTextFile, Arg("file"))
            .define_method("set_organization_domain", &KAboutData::setOrganizationDomain, Arg("domain"))
            .define_method("set_other_text", &KAboutData::setOtherText, Arg("other_text"))
            .define_method("set_product_name", &KAboutData::setProductName, Arg("name"))
            .define_method("set_program_logo", &KAboutData::setProgramLogo, Arg("image"))
            .define_method("set_short_description", &KAboutData::setShortDescription, Arg("short_description"))
            .define_method("set_translator", &KAboutData::setTranslator, Arg("name"), Arg("email_address"))
            .define_method("set_version", &KAboutData::setVersion, Arg("version"))
            .define_method("setup_command_line", &KAboutData::setupCommandLine, Arg("parser"))
            .define_method("short_description", &KAboutData::shortDescription)
            .define_method("translators", &KAboutData::translators)
            .define_method("unset_custom_author_text", &KAboutData::unsetCustomAuthorText)
            .define_method("version", &KAboutData::version)
            // Static Public Members
            .define_singleton_function("about_translation_team", &KAboutData::aboutTranslationTeam)
            .define_singleton_function("application_data", &KAboutData::applicationData)
            .define_singleton_function("set_application_data", &KAboutData::setApplicationData, Arg("about_data"));

    rb_cKAboutLicense =
        // RubyQt6::KCoreAddons::KAboutLicense
        define_class_under<KAboutLicense>(rb_mQt6KCoreAddons, "KAboutLicense")
            // Constructor
            .define_constructor(Constructor<KAboutLicense>())
            // Public Functions
            .define_method("key", &KAboutLicense::key)
            .define_method("name", &KAboutLicense::name, Arg("format_name") = static_cast<KAboutLicense::NameFormat>(KAboutLicense::ShortName))
            .define_method("spdx", &KAboutLicense::spdx)
            .define_method("text", &KAboutLicense::text)
            // Static Public Members
            .define_singleton_function("by_keyword", &KAboutLicense::byKeyword, Arg("keyword"));

    Data_Type<KAboutLicense::LicenseKey> rb_cKAboutLicenseLicenseKey =
        // RubyQt6::KCoreAddons::KAboutLicense::LicenseKey
        define_qenum_under<KAboutLicense::LicenseKey>(rb_cKAboutLicense, "LicenseKey");
        define_qenum_value_under(rb_cKAboutLicenseLicenseKey, "Custom", KAboutLicense::LicenseKey::Custom);
        define_qenum_value_under(rb_cKAboutLicenseLicenseKey, "File", KAboutLicense::LicenseKey::File);
        define_qenum_value_under(rb_cKAboutLicenseLicenseKey, "Unknown", KAboutLicense::LicenseKey::Unknown);
        define_qenum_value_under(rb_cKAboutLicenseLicenseKey, "GPL", KAboutLicense::LicenseKey::GPL);
        define_qenum_value_under(rb_cKAboutLicenseLicenseKey, "GPL_V2", KAboutLicense::LicenseKey::GPL_V2);
        define_qenum_value_under(rb_cKAboutLicenseLicenseKey, "LGPL", KAboutLicense::LicenseKey::LGPL);
        define_qenum_value_under(rb_cKAboutLicenseLicenseKey, "LGPL_V2", KAboutLicense::LicenseKey::LGPL_V2);
        define_qenum_value_under(rb_cKAboutLicenseLicenseKey, "BSD_2_Clause", KAboutLicense::LicenseKey::BSD_2_Clause);
        define_qenum_value_under(rb_cKAboutLicenseLicenseKey, "Artistic", KAboutLicense::LicenseKey::Artistic);
        define_qenum_value_under(rb_cKAboutLicenseLicenseKey, "GPL_V3", KAboutLicense::LicenseKey::GPL_V3);
        define_qenum_value_under(rb_cKAboutLicenseLicenseKey, "LGPL_V3", KAboutLicense::LicenseKey::LGPL_V3);
        define_qenum_value_under(rb_cKAboutLicenseLicenseKey, "LGPL_V2_1", KAboutLicense::LicenseKey::LGPL_V2_1);
        define_qenum_value_under(rb_cKAboutLicenseLicenseKey, "MIT", KAboutLicense::LicenseKey::MIT);
        define_qenum_value_under(rb_cKAboutLicenseLicenseKey, "ODbL_V1", KAboutLicense::LicenseKey::ODbL_V1);
        define_qenum_value_under(rb_cKAboutLicenseLicenseKey, "Apache_V2", KAboutLicense::LicenseKey::Apache_V2);
        define_qenum_value_under(rb_cKAboutLicenseLicenseKey, "FTL", KAboutLicense::LicenseKey::FTL);
        define_qenum_value_under(rb_cKAboutLicenseLicenseKey, "BSL_V1", KAboutLicense::LicenseKey::BSL_V1);
        define_qenum_value_under(rb_cKAboutLicenseLicenseKey, "BSD_3_Clause", KAboutLicense::LicenseKey::BSD_3_Clause);
        define_qenum_value_under(rb_cKAboutLicenseLicenseKey, "CC0_V1", KAboutLicense::LicenseKey::CC0_V1);
        define_qenum_value_under(rb_cKAboutLicenseLicenseKey, "MPL_V2", KAboutLicense::LicenseKey::MPL_V2);

    Data_Type<KAboutLicense::NameFormat> rb_cKAboutLicenseNameFormat =
        // RubyQt6::KCoreAddons::KAboutLicense::NameFormat
        define_qenum_under<KAboutLicense::NameFormat>(rb_cKAboutLicense, "NameFormat");
        define_qenum_value_under(rb_cKAboutLicenseNameFormat, "ShortName", KAboutLicense::NameFormat::ShortName);
        define_qenum_value_under(rb_cKAboutLicenseNameFormat, "FullName", KAboutLicense::NameFormat::FullName);

    Data_Type<KAboutLicense::VersionRestriction> rb_cKAboutLicenseVersionRestriction =
        // RubyQt6::KCoreAddons::KAboutLicense::VersionRestriction
        define_qenum_under<KAboutLicense::VersionRestriction>(rb_cKAboutLicense, "VersionRestriction");
        define_qenum_value_under(rb_cKAboutLicenseVersionRestriction, "OnlyThisVersion", KAboutLicense::VersionRestriction::OnlyThisVersion);
        define_qenum_value_under(rb_cKAboutLicenseVersionRestriction, "OrLaterVersions", KAboutLicense::VersionRestriction::OrLaterVersions);

    rb_cKAboutPerson =
        // RubyQt6::KCoreAddons::KAboutPerson
        define_class_under<KAboutPerson>(rb_mQt6KCoreAddons, "KAboutPerson")
            // Constructor
            .define_constructor(Constructor<KAboutPerson, const QString &, const QString &, const QString &, const QString &, const QUrl &>(), Arg("name"), Arg("task"), Arg("email"), Arg("webaddress"), Arg("avatar"))
            // Public Functions
            .define_method("avatar_url", &KAboutPerson::avatarUrl)
            .define_method("email_address", &KAboutPerson::emailAddress)
            .define_method("name", &KAboutPerson::name)
            .define_method("task", &KAboutPerson::task)
            .define_method("web_address", &KAboutPerson::webAddress)
            // Static Public Members
            .define_singleton_function("from_json", &KAboutPerson::fromJSON, Arg("obj"));
}
