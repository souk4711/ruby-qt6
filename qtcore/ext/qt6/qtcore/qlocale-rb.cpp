#include "qlocale-rb.hpp"
#include <qlocale.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

#include <QCalendar>
#include <QDateTime>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQLocale;

void Init_qlocale(Module rb_mQt6QtCore)
{
    rb_cQLocale =
        // RubyQt6::QtCore::QLocale
        define_class_under<QLocale>(rb_mQt6QtCore, "QLocale")
            // Public Functions
            .define_method("am_text", &QLocale::amText)
            .define_method("bcp47_name", &QLocale::bcp47Name, Arg("separator") = static_cast<QLocale::TagSeparator>(QLocale::TagSeparator::Dash))
            .define_method("collation", &QLocale::collation)
            .define_method("create_separated_list", &QLocale::createSeparatedList, Arg("strl"))
            .define_method("currency_symbol", &QLocale::currencySymbol, Arg("format") = static_cast<QLocale::CurrencySymbolFormat>(QLocale::CurrencySymbolFormat::CurrencySymbol))
            .define_method("date_format", &QLocale::dateFormat, Arg("format") = static_cast<QLocale::FormatType>(QLocale::FormatType::LongFormat))
            .define_method("date_time_format", &QLocale::dateTimeFormat, Arg("format") = static_cast<QLocale::FormatType>(QLocale::FormatType::LongFormat))
            .define_method("day_name", &QLocale::dayName, Arg("day"), Arg("format") = static_cast<QLocale::FormatType>(QLocale::FormatType::LongFormat))
            .define_method("decimal_point", &QLocale::decimalPoint)
            .define_method("exponential", &QLocale::exponential)
            .define_method("first_day_of_week", &QLocale::firstDayOfWeek)
            .define_method("formatted_data_size", &QLocale::formattedDataSize, Arg("bytes"), Arg("precision") = static_cast<int>(2), Arg("format") = static_cast<QLocale::DataSizeFormats>(QLocale::DataSizeFormat::DataSizeIecFormat))
            .define_method("group_separator", &QLocale::groupSeparator)
            .define_method("language", &QLocale::language)
            .define_method("measurement_system", &QLocale::measurementSystem)
            .define_method("month_name", &QLocale::monthName, Arg("month"), Arg("format") = static_cast<QLocale::FormatType>(QLocale::FormatType::LongFormat))
            .define_method("name", &QLocale::name, Arg("separator") = static_cast<QLocale::TagSeparator>(QLocale::TagSeparator::Underscore))
            .define_method("native_language_name", &QLocale::nativeLanguageName)
            .define_method("native_territory_name", &QLocale::nativeTerritoryName)
            .define_method("negative_sign", &QLocale::negativeSign)
            .define_method("number_options", &QLocale::numberOptions)
            .define_method("percent", &QLocale::percent)
            .define_method("pm_text", &QLocale::pmText)
            .define_method("positive_sign", &QLocale::positiveSign)
            .define_method<QString (QLocale::*)(QStringView, QLocale::QuotationStyle) const>("quote_string", &QLocale::quoteString, Arg("str"), Arg("style") = static_cast<QLocale::QuotationStyle>(QLocale::QuotationStyle::StandardQuotation))
            .define_method<QString (QLocale::*)(const QString &, QLocale::QuotationStyle) const>("quote_string", &QLocale::quoteString, Arg("str"), Arg("style") = static_cast<QLocale::QuotationStyle>(QLocale::QuotationStyle::StandardQuotation))
            .define_method("script", &QLocale::script)
            .define_method("set_number_options", &QLocale::setNumberOptions, Arg("options"))
            .define_method("standalone_day_name", &QLocale::standaloneDayName, Arg("day"), Arg("format") = static_cast<QLocale::FormatType>(QLocale::FormatType::LongFormat))
            .define_method("standalone_month_name", &QLocale::standaloneMonthName, Arg("month"), Arg("format") = static_cast<QLocale::FormatType>(QLocale::FormatType::LongFormat))
            .define_method("territory", &QLocale::territory)
            .define_method("text_direction", &QLocale::textDirection)
            .define_method("time_format", &QLocale::timeFormat, Arg("format") = static_cast<QLocale::FormatType>(QLocale::FormatType::LongFormat))
            .define_method<QString (QLocale::*)(uint, const QString &) const>("to_currency_string", &QLocale::toCurrencyString, Arg("i"), Arg("symbol") = static_cast<const QString &>(QString()))
            .define_method<QString (QLocale::*)(ushort, const QString &) const>("to_currency_string", &QLocale::toCurrencyString, Arg("i"), Arg("symbol") = static_cast<const QString &>(QString()))
            .define_method<QString (QLocale::*)(double, const QString &, int) const>("to_currency_string", &QLocale::toCurrencyString, Arg("i"), Arg("symbol") = static_cast<const QString &>(QString()), Arg("precision") = static_cast<int>(-1))
            .define_method<QString (QLocale::*)(float, const QString &, int) const>("to_currency_string", &QLocale::toCurrencyString, Arg("i"), Arg("symbol") = static_cast<const QString &>(QString()), Arg("precision") = static_cast<int>(-1))
            .define_method<QString (QLocale::*)(int, const QString &) const>("to_currency_string", &QLocale::toCurrencyString, Arg("i"), Arg("symbol") = static_cast<const QString &>(QString()))
            .define_method<QString (QLocale::*)(qlonglong, const QString &) const>("to_currency_string", &QLocale::toCurrencyString, Arg("i"), Arg("symbol") = static_cast<const QString &>(QString()))
            .define_method<QString (QLocale::*)(qulonglong, const QString &) const>("to_currency_string", &QLocale::toCurrencyString, Arg("i"), Arg("symbol") = static_cast<const QString &>(QString()))
            .define_method<QString (QLocale::*)(short, const QString &) const>("to_currency_string", &QLocale::toCurrencyString, Arg("i"), Arg("symbol") = static_cast<const QString &>(QString()))
            .define_method<QDate (QLocale::*)(const QString &, QLocale::FormatType, QCalendar, int) const>("to_date", &QLocale::toDate, Arg("string"), Arg("format"), Arg("cal"), Arg("base_year") = static_cast<int>(QLocale::DefaultTwoDigitBaseYear))
            .define_method<QDate (QLocale::*)(const QString &, QLocale::FormatType, int) const>("to_date", &QLocale::toDate, Arg("string"), Arg("format") = static_cast<QLocale::FormatType>(QLocale::FormatType::LongFormat), Arg("base_year") = static_cast<int>(QLocale::DefaultTwoDigitBaseYear))
            .define_method<QDate (QLocale::*)(const QString &, const QString &, QCalendar, int) const>("to_date", &QLocale::toDate, Arg("string"), Arg("format"), Arg("cal"), Arg("base_year") = static_cast<int>(QLocale::DefaultTwoDigitBaseYear))
            .define_method<QDate (QLocale::*)(const QString &, const QString &, int) const>("to_date", &QLocale::toDate, Arg("string"), Arg("format"), Arg("base_year") = static_cast<int>(QLocale::DefaultTwoDigitBaseYear))
            .define_method<QDateTime (QLocale::*)(const QString &, QLocale::FormatType, QCalendar, int) const>("to_date_time", &QLocale::toDateTime, Arg("string"), Arg("format"), Arg("cal"), Arg("base_year") = static_cast<int>(QLocale::DefaultTwoDigitBaseYear))
            .define_method<QDateTime (QLocale::*)(const QString &, QLocale::FormatType, int) const>("to_date_time", &QLocale::toDateTime, Arg("string"), Arg("format") = static_cast<QLocale::FormatType>(QLocale::FormatType::LongFormat), Arg("base_year") = static_cast<int>(QLocale::DefaultTwoDigitBaseYear))
            .define_method<QDateTime (QLocale::*)(const QString &, const QString &, QCalendar, int) const>("to_date_time", &QLocale::toDateTime, Arg("string"), Arg("format"), Arg("cal"), Arg("base_year") = static_cast<int>(QLocale::DefaultTwoDigitBaseYear))
            .define_method<QDateTime (QLocale::*)(const QString &, const QString &, int) const>("to_date_time", &QLocale::toDateTime, Arg("string"), Arg("format"), Arg("base_year") = static_cast<int>(QLocale::DefaultTwoDigitBaseYear))
            .define_method<double (QLocale::*)(QStringView, bool *) const>("to_double", &QLocale::toDouble, Arg("s"), Arg("ok") = static_cast<bool *>(nullptr))
            .define_method<double (QLocale::*)(const QString &, bool *) const>("to_double", &QLocale::toDouble, Arg("s"), Arg("ok") = static_cast<bool *>(nullptr))
            .define_method<float (QLocale::*)(QStringView, bool *) const>("to_float", &QLocale::toFloat, Arg("s"), Arg("ok") = static_cast<bool *>(nullptr))
            .define_method<float (QLocale::*)(const QString &, bool *) const>("to_float", &QLocale::toFloat, Arg("s"), Arg("ok") = static_cast<bool *>(nullptr))
            .define_method<int (QLocale::*)(QStringView, bool *) const>("to_int", &QLocale::toInt, Arg("s"), Arg("ok") = static_cast<bool *>(nullptr))
            .define_method<int (QLocale::*)(const QString &, bool *) const>("to_int", &QLocale::toInt, Arg("s"), Arg("ok") = static_cast<bool *>(nullptr))
            .define_method<long (QLocale::*)(QStringView, bool *) const>("to_long", &QLocale::toLong, Arg("s"), Arg("ok") = static_cast<bool *>(nullptr))
            .define_method<long (QLocale::*)(const QString &, bool *) const>("to_long", &QLocale::toLong, Arg("s"), Arg("ok") = static_cast<bool *>(nullptr))
            .define_method<qlonglong (QLocale::*)(QStringView, bool *) const>("to_longlong", &QLocale::toLongLong, Arg("s"), Arg("ok") = static_cast<bool *>(nullptr))
            .define_method<qlonglong (QLocale::*)(const QString &, bool *) const>("to_longlong", &QLocale::toLongLong, Arg("s"), Arg("ok") = static_cast<bool *>(nullptr))
            .define_method("to_lower", &QLocale::toLower, Arg("str"))
            .define_method<short (QLocale::*)(QStringView, bool *) const>("to_short", &QLocale::toShort, Arg("s"), Arg("ok") = static_cast<bool *>(nullptr))
            .define_method<short (QLocale::*)(const QString &, bool *) const>("to_short", &QLocale::toShort, Arg("s"), Arg("ok") = static_cast<bool *>(nullptr))
            .define_method<QString (QLocale::*)(uint) const>("to_string", &QLocale::toString, Arg("i"))
            .define_method<QString (QLocale::*)(ulong) const>("to_string", &QLocale::toString, Arg("i"))
            .define_method<QString (QLocale::*)(ushort) const>("to_string", &QLocale::toString, Arg("i"))
            .define_method<QString (QLocale::*)(QDate, QLocale::FormatType) const>("to_string", &QLocale::toString, Arg("date"), Arg("format") = static_cast<QLocale::FormatType>(QLocale::FormatType::LongFormat))
            .define_method<QString (QLocale::*)(QDate, QLocale::FormatType, QCalendar) const>("to_string", &QLocale::toString, Arg("date"), Arg("format"), Arg("cal"))
            .define_method<QString (QLocale::*)(QDate, QStringView) const>("to_string", &QLocale::toString, Arg("date"), Arg("format"))
            .define_method<QString (QLocale::*)(QDate, QStringView, QCalendar) const>("to_string", &QLocale::toString, Arg("date"), Arg("format"), Arg("cal"))
            .define_method<QString (QLocale::*)(QDate, const QString &) const>("to_string", &QLocale::toString, Arg("date"), Arg("format"))
            .define_method<QString (QLocale::*)(QTime, QLocale::FormatType) const>("to_string", &QLocale::toString, Arg("time"), Arg("format") = static_cast<QLocale::FormatType>(QLocale::FormatType::LongFormat))
            .define_method<QString (QLocale::*)(QTime, QStringView) const>("to_string", &QLocale::toString, Arg("time"), Arg("format"))
            .define_method<QString (QLocale::*)(QTime, const QString &) const>("to_string", &QLocale::toString, Arg("time"), Arg("format"))
            .define_method<QString (QLocale::*)(const QDateTime &, QLocale::FormatType) const>("to_string", &QLocale::toString, Arg("date_time"), Arg("format") = static_cast<QLocale::FormatType>(QLocale::FormatType::LongFormat))
            .define_method<QString (QLocale::*)(const QDateTime &, QLocale::FormatType, QCalendar) const>("to_string", &QLocale::toString, Arg("date_time"), Arg("format"), Arg("cal"))
            .define_method<QString (QLocale::*)(const QDateTime &, QStringView) const>("to_string", &QLocale::toString, Arg("date_time"), Arg("format"))
            .define_method<QString (QLocale::*)(const QDateTime &, QStringView, QCalendar) const>("to_string", &QLocale::toString, Arg("date_time"), Arg("format"), Arg("cal"))
            .define_method<QString (QLocale::*)(const QDateTime &, const QString &) const>("to_string", &QLocale::toString, Arg("date_time"), Arg("format"))
            .define_method<QString (QLocale::*)(double, char, int) const>("to_string", &QLocale::toString, Arg("f"), Arg("format") = static_cast<char>('g'), Arg("precision") = static_cast<int>(6))
            .define_method<QString (QLocale::*)(float, char, int) const>("to_string", &QLocale::toString, Arg("f"), Arg("format") = static_cast<char>('g'), Arg("precision") = static_cast<int>(6))
            .define_method<QString (QLocale::*)(int) const>("to_string", &QLocale::toString, Arg("i"))
            .define_method<QString (QLocale::*)(long) const>("to_string", &QLocale::toString, Arg("i"))
            .define_method<QString (QLocale::*)(qlonglong) const>("to_string", &QLocale::toString, Arg("i"))
            .define_method<QString (QLocale::*)(qulonglong) const>("to_string", &QLocale::toString, Arg("i"))
            .define_method<QString (QLocale::*)(short) const>("to_string", &QLocale::toString, Arg("i"))
            .define_method<QTime (QLocale::*)(const QString &, QLocale::FormatType) const>("to_time", &QLocale::toTime, Arg("string"), Arg("format") = static_cast<QLocale::FormatType>(QLocale::FormatType::LongFormat))
            .define_method<QTime (QLocale::*)(const QString &, const QString &) const>("to_time", &QLocale::toTime, Arg("string"), Arg("format"))
            .define_method<uint (QLocale::*)(QStringView, bool *) const>("to_uint", &QLocale::toUInt, Arg("s"), Arg("ok") = static_cast<bool *>(nullptr))
            .define_method<uint (QLocale::*)(const QString &, bool *) const>("to_uint", &QLocale::toUInt, Arg("s"), Arg("ok") = static_cast<bool *>(nullptr))
            .define_method<ulong (QLocale::*)(QStringView, bool *) const>("to_ulong", &QLocale::toULong, Arg("s"), Arg("ok") = static_cast<bool *>(nullptr))
            .define_method<ulong (QLocale::*)(const QString &, bool *) const>("to_ulong", &QLocale::toULong, Arg("s"), Arg("ok") = static_cast<bool *>(nullptr))
            .define_method<qulonglong (QLocale::*)(QStringView, bool *) const>("to_ulonglong", &QLocale::toULongLong, Arg("s"), Arg("ok") = static_cast<bool *>(nullptr))
            .define_method<qulonglong (QLocale::*)(const QString &, bool *) const>("to_ulonglong", &QLocale::toULongLong, Arg("s"), Arg("ok") = static_cast<bool *>(nullptr))
            .define_method<ushort (QLocale::*)(QStringView, bool *) const>("to_ushort", &QLocale::toUShort, Arg("s"), Arg("ok") = static_cast<bool *>(nullptr))
            .define_method<ushort (QLocale::*)(const QString &, bool *) const>("to_ushort", &QLocale::toUShort, Arg("s"), Arg("ok") = static_cast<bool *>(nullptr))
            .define_method("to_upper", &QLocale::toUpper, Arg("str"))
            .define_method("ui_languages", &QLocale::uiLanguages, Arg("separator") = static_cast<QLocale::TagSeparator>(QLocale::TagSeparator::Dash))
            .define_method("weekdays", &QLocale::weekdays)
            .define_method("zero_digit", &QLocale::zeroDigit)
            // Static Public Members
            .define_singleton_function("c", &QLocale::c)
            // .define_singleton_function("code_to_language", &QLocale::codeToLanguage, Arg("language_code"), Arg("code_types") = static_cast<QLocale::LanguageCodeTypes>(QLocale::LanguageCodeType::AnyLanguageCode))
            // .define_singleton_function("code_to_script", &QLocale::codeToScript, Arg("script_code"))
            // .define_singleton_function("code_to_territory", &QLocale::codeToTerritory, Arg("territory_code"))
            .define_singleton_function("language_to_code", &QLocale::languageToCode, Arg("language"), Arg("code_types") = static_cast<QLocale::LanguageCodeTypes>(QLocale::LanguageCodeType::AnyLanguageCode))
            .define_singleton_function("language_to_string", &QLocale::languageToString, Arg("language"))
            .define_singleton_function("matching_locales", &QLocale::matchingLocales, Arg("language"), Arg("script"), Arg("territory"))
            .define_singleton_function("script_to_code", &QLocale::scriptToCode, Arg("script"))
            .define_singleton_function("script_to_string", &QLocale::scriptToString, Arg("script"))
            .define_singleton_function("set_default", &QLocale::setDefault, Arg("locale"))
            .define_singleton_function("system", &QLocale::system)
            .define_singleton_function("territory_to_code", &QLocale::territoryToCode, Arg("territory"))
            .define_singleton_function("territory_to_string", &QLocale::territoryToString, Arg("territory"));

    Data_Type<QLocale::Language> rb_cQLocaleLanguage =
        // RubyQt6::QtCore::QLocale::Language
        define_qenum_under<QLocale::Language>(rb_cQLocale, "Language");
        define_qenum_value_under(rb_cQLocaleLanguage, "AnyLanguage", QLocale::Language::AnyLanguage);
        define_qenum_value_under(rb_cQLocaleLanguage, "C", QLocale::Language::C);
        define_qenum_value_under(rb_cQLocaleLanguage, "Abkhazian", QLocale::Language::Abkhazian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Afar", QLocale::Language::Afar);
        define_qenum_value_under(rb_cQLocaleLanguage, "Afrikaans", QLocale::Language::Afrikaans);
        define_qenum_value_under(rb_cQLocaleLanguage, "Aghem", QLocale::Language::Aghem);
        define_qenum_value_under(rb_cQLocaleLanguage, "Akan", QLocale::Language::Akan);
        define_qenum_value_under(rb_cQLocaleLanguage, "Akkadian", QLocale::Language::Akkadian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Akoose", QLocale::Language::Akoose);
        define_qenum_value_under(rb_cQLocaleLanguage, "Albanian", QLocale::Language::Albanian);
        define_qenum_value_under(rb_cQLocaleLanguage, "AmericanSignLanguage", QLocale::Language::AmericanSignLanguage);
        define_qenum_value_under(rb_cQLocaleLanguage, "Amharic", QLocale::Language::Amharic);
        define_qenum_value_under(rb_cQLocaleLanguage, "AncientEgyptian", QLocale::Language::AncientEgyptian);
        define_qenum_value_under(rb_cQLocaleLanguage, "AncientGreek", QLocale::Language::AncientGreek);
        define_qenum_value_under(rb_cQLocaleLanguage, "Arabic", QLocale::Language::Arabic);
        define_qenum_value_under(rb_cQLocaleLanguage, "Aragonese", QLocale::Language::Aragonese);
        define_qenum_value_under(rb_cQLocaleLanguage, "Aramaic", QLocale::Language::Aramaic);
        define_qenum_value_under(rb_cQLocaleLanguage, "Armenian", QLocale::Language::Armenian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Assamese", QLocale::Language::Assamese);
        define_qenum_value_under(rb_cQLocaleLanguage, "Asturian", QLocale::Language::Asturian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Asu", QLocale::Language::Asu);
        define_qenum_value_under(rb_cQLocaleLanguage, "Atsam", QLocale::Language::Atsam);
        define_qenum_value_under(rb_cQLocaleLanguage, "Avaric", QLocale::Language::Avaric);
        define_qenum_value_under(rb_cQLocaleLanguage, "Avestan", QLocale::Language::Avestan);
        define_qenum_value_under(rb_cQLocaleLanguage, "Aymara", QLocale::Language::Aymara);
        define_qenum_value_under(rb_cQLocaleLanguage, "Azerbaijani", QLocale::Language::Azerbaijani);
        define_qenum_value_under(rb_cQLocaleLanguage, "Bafia", QLocale::Language::Bafia);
        define_qenum_value_under(rb_cQLocaleLanguage, "Balinese", QLocale::Language::Balinese);
        define_qenum_value_under(rb_cQLocaleLanguage, "Bambara", QLocale::Language::Bambara);
        define_qenum_value_under(rb_cQLocaleLanguage, "Bamun", QLocale::Language::Bamun);
        define_qenum_value_under(rb_cQLocaleLanguage, "Bangla", QLocale::Language::Bangla);
        define_qenum_value_under(rb_cQLocaleLanguage, "Basaa", QLocale::Language::Basaa);
        define_qenum_value_under(rb_cQLocaleLanguage, "Bashkir", QLocale::Language::Bashkir);
        define_qenum_value_under(rb_cQLocaleLanguage, "Basque", QLocale::Language::Basque);
        define_qenum_value_under(rb_cQLocaleLanguage, "BatakToba", QLocale::Language::BatakToba);
        define_qenum_value_under(rb_cQLocaleLanguage, "Belarusian", QLocale::Language::Belarusian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Bemba", QLocale::Language::Bemba);
        define_qenum_value_under(rb_cQLocaleLanguage, "Bena", QLocale::Language::Bena);
        define_qenum_value_under(rb_cQLocaleLanguage, "Bhojpuri", QLocale::Language::Bhojpuri);
        define_qenum_value_under(rb_cQLocaleLanguage, "Bislama", QLocale::Language::Bislama);
        define_qenum_value_under(rb_cQLocaleLanguage, "Blin", QLocale::Language::Blin);
        define_qenum_value_under(rb_cQLocaleLanguage, "Bodo", QLocale::Language::Bodo);
        define_qenum_value_under(rb_cQLocaleLanguage, "Bosnian", QLocale::Language::Bosnian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Breton", QLocale::Language::Breton);
        define_qenum_value_under(rb_cQLocaleLanguage, "Buginese", QLocale::Language::Buginese);
        define_qenum_value_under(rb_cQLocaleLanguage, "Bulgarian", QLocale::Language::Bulgarian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Burmese", QLocale::Language::Burmese);
        define_qenum_value_under(rb_cQLocaleLanguage, "Cantonese", QLocale::Language::Cantonese);
        define_qenum_value_under(rb_cQLocaleLanguage, "Catalan", QLocale::Language::Catalan);
        define_qenum_value_under(rb_cQLocaleLanguage, "Cebuano", QLocale::Language::Cebuano);
        define_qenum_value_under(rb_cQLocaleLanguage, "CentralAtlasTamazight", QLocale::Language::CentralAtlasTamazight);
        define_qenum_value_under(rb_cQLocaleLanguage, "CentralKurdish", QLocale::Language::CentralKurdish);
        define_qenum_value_under(rb_cQLocaleLanguage, "Chakma", QLocale::Language::Chakma);
        define_qenum_value_under(rb_cQLocaleLanguage, "Chamorro", QLocale::Language::Chamorro);
        define_qenum_value_under(rb_cQLocaleLanguage, "Chechen", QLocale::Language::Chechen);
        define_qenum_value_under(rb_cQLocaleLanguage, "Cherokee", QLocale::Language::Cherokee);
        define_qenum_value_under(rb_cQLocaleLanguage, "Chickasaw", QLocale::Language::Chickasaw);
        define_qenum_value_under(rb_cQLocaleLanguage, "Chiga", QLocale::Language::Chiga);
        define_qenum_value_under(rb_cQLocaleLanguage, "Chinese", QLocale::Language::Chinese);
        define_qenum_value_under(rb_cQLocaleLanguage, "Church", QLocale::Language::Church);
        define_qenum_value_under(rb_cQLocaleLanguage, "Chuvash", QLocale::Language::Chuvash);
        define_qenum_value_under(rb_cQLocaleLanguage, "Colognian", QLocale::Language::Colognian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Coptic", QLocale::Language::Coptic);
        define_qenum_value_under(rb_cQLocaleLanguage, "Cornish", QLocale::Language::Cornish);
        define_qenum_value_under(rb_cQLocaleLanguage, "Corsican", QLocale::Language::Corsican);
        define_qenum_value_under(rb_cQLocaleLanguage, "Cree", QLocale::Language::Cree);
        define_qenum_value_under(rb_cQLocaleLanguage, "Croatian", QLocale::Language::Croatian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Czech", QLocale::Language::Czech);
        define_qenum_value_under(rb_cQLocaleLanguage, "Danish", QLocale::Language::Danish);
        define_qenum_value_under(rb_cQLocaleLanguage, "Divehi", QLocale::Language::Divehi);
        define_qenum_value_under(rb_cQLocaleLanguage, "Dogri", QLocale::Language::Dogri);
        define_qenum_value_under(rb_cQLocaleLanguage, "Duala", QLocale::Language::Duala);
        define_qenum_value_under(rb_cQLocaleLanguage, "Dutch", QLocale::Language::Dutch);
        define_qenum_value_under(rb_cQLocaleLanguage, "Dzongkha", QLocale::Language::Dzongkha);
        define_qenum_value_under(rb_cQLocaleLanguage, "Embu", QLocale::Language::Embu);
        define_qenum_value_under(rb_cQLocaleLanguage, "English", QLocale::Language::English);
        define_qenum_value_under(rb_cQLocaleLanguage, "Erzya", QLocale::Language::Erzya);
        define_qenum_value_under(rb_cQLocaleLanguage, "Esperanto", QLocale::Language::Esperanto);
        define_qenum_value_under(rb_cQLocaleLanguage, "Estonian", QLocale::Language::Estonian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Ewe", QLocale::Language::Ewe);
        define_qenum_value_under(rb_cQLocaleLanguage, "Ewondo", QLocale::Language::Ewondo);
        define_qenum_value_under(rb_cQLocaleLanguage, "Faroese", QLocale::Language::Faroese);
        define_qenum_value_under(rb_cQLocaleLanguage, "Fijian", QLocale::Language::Fijian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Filipino", QLocale::Language::Filipino);
        define_qenum_value_under(rb_cQLocaleLanguage, "Finnish", QLocale::Language::Finnish);
        define_qenum_value_under(rb_cQLocaleLanguage, "French", QLocale::Language::French);
        define_qenum_value_under(rb_cQLocaleLanguage, "Friulian", QLocale::Language::Friulian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Fulah", QLocale::Language::Fulah);
        define_qenum_value_under(rb_cQLocaleLanguage, "Gaelic", QLocale::Language::Gaelic);
        define_qenum_value_under(rb_cQLocaleLanguage, "Ga", QLocale::Language::Ga);
        define_qenum_value_under(rb_cQLocaleLanguage, "Galician", QLocale::Language::Galician);
        define_qenum_value_under(rb_cQLocaleLanguage, "Ganda", QLocale::Language::Ganda);
        define_qenum_value_under(rb_cQLocaleLanguage, "Geez", QLocale::Language::Geez);
        define_qenum_value_under(rb_cQLocaleLanguage, "Georgian", QLocale::Language::Georgian);
        define_qenum_value_under(rb_cQLocaleLanguage, "German", QLocale::Language::German);
        define_qenum_value_under(rb_cQLocaleLanguage, "Gothic", QLocale::Language::Gothic);
        define_qenum_value_under(rb_cQLocaleLanguage, "Greek", QLocale::Language::Greek);
        define_qenum_value_under(rb_cQLocaleLanguage, "Guarani", QLocale::Language::Guarani);
        define_qenum_value_under(rb_cQLocaleLanguage, "Gujarati", QLocale::Language::Gujarati);
        define_qenum_value_under(rb_cQLocaleLanguage, "Gusii", QLocale::Language::Gusii);
        define_qenum_value_under(rb_cQLocaleLanguage, "Haitian", QLocale::Language::Haitian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Hausa", QLocale::Language::Hausa);
        define_qenum_value_under(rb_cQLocaleLanguage, "Hawaiian", QLocale::Language::Hawaiian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Hebrew", QLocale::Language::Hebrew);
        define_qenum_value_under(rb_cQLocaleLanguage, "Herero", QLocale::Language::Herero);
        define_qenum_value_under(rb_cQLocaleLanguage, "Hindi", QLocale::Language::Hindi);
        define_qenum_value_under(rb_cQLocaleLanguage, "HiriMotu", QLocale::Language::HiriMotu);
        define_qenum_value_under(rb_cQLocaleLanguage, "Hungarian", QLocale::Language::Hungarian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Icelandic", QLocale::Language::Icelandic);
        define_qenum_value_under(rb_cQLocaleLanguage, "Ido", QLocale::Language::Ido);
        define_qenum_value_under(rb_cQLocaleLanguage, "Igbo", QLocale::Language::Igbo);
        define_qenum_value_under(rb_cQLocaleLanguage, "InariSami", QLocale::Language::InariSami);
        define_qenum_value_under(rb_cQLocaleLanguage, "Indonesian", QLocale::Language::Indonesian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Ingush", QLocale::Language::Ingush);
        define_qenum_value_under(rb_cQLocaleLanguage, "Interlingua", QLocale::Language::Interlingua);
        define_qenum_value_under(rb_cQLocaleLanguage, "Interlingue", QLocale::Language::Interlingue);
        define_qenum_value_under(rb_cQLocaleLanguage, "Inuktitut", QLocale::Language::Inuktitut);
        define_qenum_value_under(rb_cQLocaleLanguage, "Inupiaq", QLocale::Language::Inupiaq);
        define_qenum_value_under(rb_cQLocaleLanguage, "Irish", QLocale::Language::Irish);
        define_qenum_value_under(rb_cQLocaleLanguage, "Italian", QLocale::Language::Italian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Japanese", QLocale::Language::Japanese);
        define_qenum_value_under(rb_cQLocaleLanguage, "Javanese", QLocale::Language::Javanese);
        define_qenum_value_under(rb_cQLocaleLanguage, "Jju", QLocale::Language::Jju);
        define_qenum_value_under(rb_cQLocaleLanguage, "JolaFonyi", QLocale::Language::JolaFonyi);
        define_qenum_value_under(rb_cQLocaleLanguage, "Kabuverdianu", QLocale::Language::Kabuverdianu);
        define_qenum_value_under(rb_cQLocaleLanguage, "Kabyle", QLocale::Language::Kabyle);
        define_qenum_value_under(rb_cQLocaleLanguage, "Kako", QLocale::Language::Kako);
        define_qenum_value_under(rb_cQLocaleLanguage, "Kalaallisut", QLocale::Language::Kalaallisut);
        define_qenum_value_under(rb_cQLocaleLanguage, "Kalenjin", QLocale::Language::Kalenjin);
        define_qenum_value_under(rb_cQLocaleLanguage, "Kamba", QLocale::Language::Kamba);
        define_qenum_value_under(rb_cQLocaleLanguage, "Kannada", QLocale::Language::Kannada);
        define_qenum_value_under(rb_cQLocaleLanguage, "Kanuri", QLocale::Language::Kanuri);
        define_qenum_value_under(rb_cQLocaleLanguage, "Kashmiri", QLocale::Language::Kashmiri);
        define_qenum_value_under(rb_cQLocaleLanguage, "Kazakh", QLocale::Language::Kazakh);
        define_qenum_value_under(rb_cQLocaleLanguage, "Kenyang", QLocale::Language::Kenyang);
        define_qenum_value_under(rb_cQLocaleLanguage, "Khmer", QLocale::Language::Khmer);
        define_qenum_value_under(rb_cQLocaleLanguage, "Kiche", QLocale::Language::Kiche);
        define_qenum_value_under(rb_cQLocaleLanguage, "Kikuyu", QLocale::Language::Kikuyu);
        define_qenum_value_under(rb_cQLocaleLanguage, "Kinyarwanda", QLocale::Language::Kinyarwanda);
        define_qenum_value_under(rb_cQLocaleLanguage, "Komi", QLocale::Language::Komi);
        define_qenum_value_under(rb_cQLocaleLanguage, "Kongo", QLocale::Language::Kongo);
        define_qenum_value_under(rb_cQLocaleLanguage, "Konkani", QLocale::Language::Konkani);
        define_qenum_value_under(rb_cQLocaleLanguage, "Korean", QLocale::Language::Korean);
        define_qenum_value_under(rb_cQLocaleLanguage, "Koro", QLocale::Language::Koro);
        define_qenum_value_under(rb_cQLocaleLanguage, "KoyraboroSenni", QLocale::Language::KoyraboroSenni);
        define_qenum_value_under(rb_cQLocaleLanguage, "KoyraChiini", QLocale::Language::KoyraChiini);
        define_qenum_value_under(rb_cQLocaleLanguage, "Kpelle", QLocale::Language::Kpelle);
        define_qenum_value_under(rb_cQLocaleLanguage, "Kuanyama", QLocale::Language::Kuanyama);
        define_qenum_value_under(rb_cQLocaleLanguage, "Kurdish", QLocale::Language::Kurdish);
        define_qenum_value_under(rb_cQLocaleLanguage, "Kwasio", QLocale::Language::Kwasio);
        define_qenum_value_under(rb_cQLocaleLanguage, "Kyrgyz", QLocale::Language::Kyrgyz);
        define_qenum_value_under(rb_cQLocaleLanguage, "Lakota", QLocale::Language::Lakota);
        define_qenum_value_under(rb_cQLocaleLanguage, "Langi", QLocale::Language::Langi);
        define_qenum_value_under(rb_cQLocaleLanguage, "Lao", QLocale::Language::Lao);
        define_qenum_value_under(rb_cQLocaleLanguage, "Latin", QLocale::Language::Latin);
        define_qenum_value_under(rb_cQLocaleLanguage, "Latvian", QLocale::Language::Latvian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Lezghian", QLocale::Language::Lezghian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Limburgish", QLocale::Language::Limburgish);
        define_qenum_value_under(rb_cQLocaleLanguage, "Lingala", QLocale::Language::Lingala);
        define_qenum_value_under(rb_cQLocaleLanguage, "LiteraryChinese", QLocale::Language::LiteraryChinese);
        define_qenum_value_under(rb_cQLocaleLanguage, "Lithuanian", QLocale::Language::Lithuanian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Lojban", QLocale::Language::Lojban);
        define_qenum_value_under(rb_cQLocaleLanguage, "LowerSorbian", QLocale::Language::LowerSorbian);
        define_qenum_value_under(rb_cQLocaleLanguage, "LowGerman", QLocale::Language::LowGerman);
        define_qenum_value_under(rb_cQLocaleLanguage, "LubaKatanga", QLocale::Language::LubaKatanga);
        define_qenum_value_under(rb_cQLocaleLanguage, "LuleSami", QLocale::Language::LuleSami);
        define_qenum_value_under(rb_cQLocaleLanguage, "Luo", QLocale::Language::Luo);
        define_qenum_value_under(rb_cQLocaleLanguage, "Luxembourgish", QLocale::Language::Luxembourgish);
        define_qenum_value_under(rb_cQLocaleLanguage, "Luyia", QLocale::Language::Luyia);
        define_qenum_value_under(rb_cQLocaleLanguage, "Macedonian", QLocale::Language::Macedonian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Machame", QLocale::Language::Machame);
        define_qenum_value_under(rb_cQLocaleLanguage, "Maithili", QLocale::Language::Maithili);
        define_qenum_value_under(rb_cQLocaleLanguage, "MakhuwaMeetto", QLocale::Language::MakhuwaMeetto);
        define_qenum_value_under(rb_cQLocaleLanguage, "Makonde", QLocale::Language::Makonde);
        define_qenum_value_under(rb_cQLocaleLanguage, "Malagasy", QLocale::Language::Malagasy);
        define_qenum_value_under(rb_cQLocaleLanguage, "Malayalam", QLocale::Language::Malayalam);
        define_qenum_value_under(rb_cQLocaleLanguage, "Malay", QLocale::Language::Malay);
        define_qenum_value_under(rb_cQLocaleLanguage, "Maltese", QLocale::Language::Maltese);
        define_qenum_value_under(rb_cQLocaleLanguage, "Mandingo", QLocale::Language::Mandingo);
        define_qenum_value_under(rb_cQLocaleLanguage, "Manipuri", QLocale::Language::Manipuri);
        define_qenum_value_under(rb_cQLocaleLanguage, "Manx", QLocale::Language::Manx);
        define_qenum_value_under(rb_cQLocaleLanguage, "Maori", QLocale::Language::Maori);
        define_qenum_value_under(rb_cQLocaleLanguage, "Mapuche", QLocale::Language::Mapuche);
        define_qenum_value_under(rb_cQLocaleLanguage, "Marathi", QLocale::Language::Marathi);
        define_qenum_value_under(rb_cQLocaleLanguage, "Marshallese", QLocale::Language::Marshallese);
        define_qenum_value_under(rb_cQLocaleLanguage, "Masai", QLocale::Language::Masai);
        define_qenum_value_under(rb_cQLocaleLanguage, "Mazanderani", QLocale::Language::Mazanderani);
        define_qenum_value_under(rb_cQLocaleLanguage, "Mende", QLocale::Language::Mende);
        define_qenum_value_under(rb_cQLocaleLanguage, "Meru", QLocale::Language::Meru);
        define_qenum_value_under(rb_cQLocaleLanguage, "Meta", QLocale::Language::Meta);
        define_qenum_value_under(rb_cQLocaleLanguage, "Mohawk", QLocale::Language::Mohawk);
        define_qenum_value_under(rb_cQLocaleLanguage, "Mongolian", QLocale::Language::Mongolian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Morisyen", QLocale::Language::Morisyen);
        define_qenum_value_under(rb_cQLocaleLanguage, "Mundang", QLocale::Language::Mundang);
        define_qenum_value_under(rb_cQLocaleLanguage, "Muscogee", QLocale::Language::Muscogee);
        define_qenum_value_under(rb_cQLocaleLanguage, "Nama", QLocale::Language::Nama);
        define_qenum_value_under(rb_cQLocaleLanguage, "NauruLanguage", QLocale::Language::NauruLanguage);
        define_qenum_value_under(rb_cQLocaleLanguage, "Navajo", QLocale::Language::Navajo);
        define_qenum_value_under(rb_cQLocaleLanguage, "Ndonga", QLocale::Language::Ndonga);
        define_qenum_value_under(rb_cQLocaleLanguage, "Nepali", QLocale::Language::Nepali);
        define_qenum_value_under(rb_cQLocaleLanguage, "Newari", QLocale::Language::Newari);
        define_qenum_value_under(rb_cQLocaleLanguage, "Ngiemboon", QLocale::Language::Ngiemboon);
        define_qenum_value_under(rb_cQLocaleLanguage, "Ngomba", QLocale::Language::Ngomba);
        define_qenum_value_under(rb_cQLocaleLanguage, "NigerianPidgin", QLocale::Language::NigerianPidgin);
        define_qenum_value_under(rb_cQLocaleLanguage, "Nko", QLocale::Language::Nko);
        define_qenum_value_under(rb_cQLocaleLanguage, "NorthernLuri", QLocale::Language::NorthernLuri);
        define_qenum_value_under(rb_cQLocaleLanguage, "NorthernSami", QLocale::Language::NorthernSami);
        define_qenum_value_under(rb_cQLocaleLanguage, "NorthernSotho", QLocale::Language::NorthernSotho);
        define_qenum_value_under(rb_cQLocaleLanguage, "NorthNdebele", QLocale::Language::NorthNdebele);
        define_qenum_value_under(rb_cQLocaleLanguage, "NorwegianBokmal", QLocale::Language::NorwegianBokmal);
        define_qenum_value_under(rb_cQLocaleLanguage, "NorwegianNynorsk", QLocale::Language::NorwegianNynorsk);
        define_qenum_value_under(rb_cQLocaleLanguage, "Nuer", QLocale::Language::Nuer);
        define_qenum_value_under(rb_cQLocaleLanguage, "Nyanja", QLocale::Language::Nyanja);
        define_qenum_value_under(rb_cQLocaleLanguage, "Nyankole", QLocale::Language::Nyankole);
        define_qenum_value_under(rb_cQLocaleLanguage, "Occitan", QLocale::Language::Occitan);
        define_qenum_value_under(rb_cQLocaleLanguage, "Odia", QLocale::Language::Odia);
        define_qenum_value_under(rb_cQLocaleLanguage, "Ojibwa", QLocale::Language::Ojibwa);
        define_qenum_value_under(rb_cQLocaleLanguage, "OldIrish", QLocale::Language::OldIrish);
        define_qenum_value_under(rb_cQLocaleLanguage, "OldNorse", QLocale::Language::OldNorse);
        define_qenum_value_under(rb_cQLocaleLanguage, "OldPersian", QLocale::Language::OldPersian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Oromo", QLocale::Language::Oromo);
        define_qenum_value_under(rb_cQLocaleLanguage, "Osage", QLocale::Language::Osage);
        define_qenum_value_under(rb_cQLocaleLanguage, "Ossetic", QLocale::Language::Ossetic);
        define_qenum_value_under(rb_cQLocaleLanguage, "Pahlavi", QLocale::Language::Pahlavi);
        define_qenum_value_under(rb_cQLocaleLanguage, "Palauan", QLocale::Language::Palauan);
        define_qenum_value_under(rb_cQLocaleLanguage, "Pali", QLocale::Language::Pali);
        define_qenum_value_under(rb_cQLocaleLanguage, "Papiamento", QLocale::Language::Papiamento);
        define_qenum_value_under(rb_cQLocaleLanguage, "Pashto", QLocale::Language::Pashto);
        define_qenum_value_under(rb_cQLocaleLanguage, "Persian", QLocale::Language::Persian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Phoenician", QLocale::Language::Phoenician);
        define_qenum_value_under(rb_cQLocaleLanguage, "Polish", QLocale::Language::Polish);
        define_qenum_value_under(rb_cQLocaleLanguage, "Portuguese", QLocale::Language::Portuguese);
        define_qenum_value_under(rb_cQLocaleLanguage, "Prussian", QLocale::Language::Prussian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Punjabi", QLocale::Language::Punjabi);
        define_qenum_value_under(rb_cQLocaleLanguage, "Quechua", QLocale::Language::Quechua);
        define_qenum_value_under(rb_cQLocaleLanguage, "Romanian", QLocale::Language::Romanian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Romansh", QLocale::Language::Romansh);
        define_qenum_value_under(rb_cQLocaleLanguage, "Rombo", QLocale::Language::Rombo);
        define_qenum_value_under(rb_cQLocaleLanguage, "Rundi", QLocale::Language::Rundi);
        define_qenum_value_under(rb_cQLocaleLanguage, "Russian", QLocale::Language::Russian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Rwa", QLocale::Language::Rwa);
        define_qenum_value_under(rb_cQLocaleLanguage, "Saho", QLocale::Language::Saho);
        define_qenum_value_under(rb_cQLocaleLanguage, "Sakha", QLocale::Language::Sakha);
        define_qenum_value_under(rb_cQLocaleLanguage, "Samburu", QLocale::Language::Samburu);
        define_qenum_value_under(rb_cQLocaleLanguage, "Samoan", QLocale::Language::Samoan);
        define_qenum_value_under(rb_cQLocaleLanguage, "Sango", QLocale::Language::Sango);
        define_qenum_value_under(rb_cQLocaleLanguage, "Sangu", QLocale::Language::Sangu);
        define_qenum_value_under(rb_cQLocaleLanguage, "Sanskrit", QLocale::Language::Sanskrit);
        define_qenum_value_under(rb_cQLocaleLanguage, "Santali", QLocale::Language::Santali);
        define_qenum_value_under(rb_cQLocaleLanguage, "Sardinian", QLocale::Language::Sardinian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Saurashtra", QLocale::Language::Saurashtra);
        define_qenum_value_under(rb_cQLocaleLanguage, "Sena", QLocale::Language::Sena);
        define_qenum_value_under(rb_cQLocaleLanguage, "Serbian", QLocale::Language::Serbian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Shambala", QLocale::Language::Shambala);
        define_qenum_value_under(rb_cQLocaleLanguage, "Shona", QLocale::Language::Shona);
        define_qenum_value_under(rb_cQLocaleLanguage, "SichuanYi", QLocale::Language::SichuanYi);
        define_qenum_value_under(rb_cQLocaleLanguage, "Sicilian", QLocale::Language::Sicilian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Sidamo", QLocale::Language::Sidamo);
        define_qenum_value_under(rb_cQLocaleLanguage, "Silesian", QLocale::Language::Silesian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Sindhi", QLocale::Language::Sindhi);
        define_qenum_value_under(rb_cQLocaleLanguage, "Sinhala", QLocale::Language::Sinhala);
        define_qenum_value_under(rb_cQLocaleLanguage, "SkoltSami", QLocale::Language::SkoltSami);
        define_qenum_value_under(rb_cQLocaleLanguage, "Slovak", QLocale::Language::Slovak);
        define_qenum_value_under(rb_cQLocaleLanguage, "Slovenian", QLocale::Language::Slovenian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Soga", QLocale::Language::Soga);
        define_qenum_value_under(rb_cQLocaleLanguage, "Somali", QLocale::Language::Somali);
        define_qenum_value_under(rb_cQLocaleLanguage, "SouthernKurdish", QLocale::Language::SouthernKurdish);
        define_qenum_value_under(rb_cQLocaleLanguage, "SouthernSami", QLocale::Language::SouthernSami);
        define_qenum_value_under(rb_cQLocaleLanguage, "SouthernSotho", QLocale::Language::SouthernSotho);
        define_qenum_value_under(rb_cQLocaleLanguage, "SouthNdebele", QLocale::Language::SouthNdebele);
        define_qenum_value_under(rb_cQLocaleLanguage, "Spanish", QLocale::Language::Spanish);
        define_qenum_value_under(rb_cQLocaleLanguage, "StandardMoroccanTamazight", QLocale::Language::StandardMoroccanTamazight);
        define_qenum_value_under(rb_cQLocaleLanguage, "Sundanese", QLocale::Language::Sundanese);
        define_qenum_value_under(rb_cQLocaleLanguage, "Swahili", QLocale::Language::Swahili);
        define_qenum_value_under(rb_cQLocaleLanguage, "Swati", QLocale::Language::Swati);
        define_qenum_value_under(rb_cQLocaleLanguage, "Swedish", QLocale::Language::Swedish);
        define_qenum_value_under(rb_cQLocaleLanguage, "SwissGerman", QLocale::Language::SwissGerman);
        define_qenum_value_under(rb_cQLocaleLanguage, "Syriac", QLocale::Language::Syriac);
        define_qenum_value_under(rb_cQLocaleLanguage, "Tachelhit", QLocale::Language::Tachelhit);
        define_qenum_value_under(rb_cQLocaleLanguage, "Tahitian", QLocale::Language::Tahitian);
        define_qenum_value_under(rb_cQLocaleLanguage, "TaiDam", QLocale::Language::TaiDam);
        define_qenum_value_under(rb_cQLocaleLanguage, "Taita", QLocale::Language::Taita);
        define_qenum_value_under(rb_cQLocaleLanguage, "Tajik", QLocale::Language::Tajik);
        define_qenum_value_under(rb_cQLocaleLanguage, "Tamil", QLocale::Language::Tamil);
        define_qenum_value_under(rb_cQLocaleLanguage, "Taroko", QLocale::Language::Taroko);
        define_qenum_value_under(rb_cQLocaleLanguage, "Tasawaq", QLocale::Language::Tasawaq);
        define_qenum_value_under(rb_cQLocaleLanguage, "Tatar", QLocale::Language::Tatar);
        define_qenum_value_under(rb_cQLocaleLanguage, "Telugu", QLocale::Language::Telugu);
        define_qenum_value_under(rb_cQLocaleLanguage, "Teso", QLocale::Language::Teso);
        define_qenum_value_under(rb_cQLocaleLanguage, "Thai", QLocale::Language::Thai);
        define_qenum_value_under(rb_cQLocaleLanguage, "Tibetan", QLocale::Language::Tibetan);
        define_qenum_value_under(rb_cQLocaleLanguage, "Tigre", QLocale::Language::Tigre);
        define_qenum_value_under(rb_cQLocaleLanguage, "Tigrinya", QLocale::Language::Tigrinya);
        define_qenum_value_under(rb_cQLocaleLanguage, "TokelauLanguage", QLocale::Language::TokelauLanguage);
        define_qenum_value_under(rb_cQLocaleLanguage, "TokPisin", QLocale::Language::TokPisin);
        define_qenum_value_under(rb_cQLocaleLanguage, "Tongan", QLocale::Language::Tongan);
        define_qenum_value_under(rb_cQLocaleLanguage, "Tsonga", QLocale::Language::Tsonga);
        define_qenum_value_under(rb_cQLocaleLanguage, "Tswana", QLocale::Language::Tswana);
        define_qenum_value_under(rb_cQLocaleLanguage, "Turkish", QLocale::Language::Turkish);
        define_qenum_value_under(rb_cQLocaleLanguage, "Turkmen", QLocale::Language::Turkmen);
        define_qenum_value_under(rb_cQLocaleLanguage, "TuvaluLanguage", QLocale::Language::TuvaluLanguage);
        define_qenum_value_under(rb_cQLocaleLanguage, "Tyap", QLocale::Language::Tyap);
        define_qenum_value_under(rb_cQLocaleLanguage, "Ugaritic", QLocale::Language::Ugaritic);
        define_qenum_value_under(rb_cQLocaleLanguage, "Ukrainian", QLocale::Language::Ukrainian);
        define_qenum_value_under(rb_cQLocaleLanguage, "UpperSorbian", QLocale::Language::UpperSorbian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Urdu", QLocale::Language::Urdu);
        define_qenum_value_under(rb_cQLocaleLanguage, "Uyghur", QLocale::Language::Uyghur);
        define_qenum_value_under(rb_cQLocaleLanguage, "Uzbek", QLocale::Language::Uzbek);
        define_qenum_value_under(rb_cQLocaleLanguage, "Vai", QLocale::Language::Vai);
        define_qenum_value_under(rb_cQLocaleLanguage, "Venda", QLocale::Language::Venda);
        define_qenum_value_under(rb_cQLocaleLanguage, "Vietnamese", QLocale::Language::Vietnamese);
        define_qenum_value_under(rb_cQLocaleLanguage, "Volapuk", QLocale::Language::Volapuk);
        define_qenum_value_under(rb_cQLocaleLanguage, "Vunjo", QLocale::Language::Vunjo);
        define_qenum_value_under(rb_cQLocaleLanguage, "Walloon", QLocale::Language::Walloon);
        define_qenum_value_under(rb_cQLocaleLanguage, "Walser", QLocale::Language::Walser);
        define_qenum_value_under(rb_cQLocaleLanguage, "Warlpiri", QLocale::Language::Warlpiri);
        define_qenum_value_under(rb_cQLocaleLanguage, "Welsh", QLocale::Language::Welsh);
        define_qenum_value_under(rb_cQLocaleLanguage, "WesternBalochi", QLocale::Language::WesternBalochi);
        define_qenum_value_under(rb_cQLocaleLanguage, "WesternFrisian", QLocale::Language::WesternFrisian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Wolaytta", QLocale::Language::Wolaytta);
        define_qenum_value_under(rb_cQLocaleLanguage, "Wolof", QLocale::Language::Wolof);
        define_qenum_value_under(rb_cQLocaleLanguage, "Xhosa", QLocale::Language::Xhosa);
        define_qenum_value_under(rb_cQLocaleLanguage, "Yangben", QLocale::Language::Yangben);
        define_qenum_value_under(rb_cQLocaleLanguage, "Yiddish", QLocale::Language::Yiddish);
        define_qenum_value_under(rb_cQLocaleLanguage, "Yoruba", QLocale::Language::Yoruba);
        define_qenum_value_under(rb_cQLocaleLanguage, "Zarma", QLocale::Language::Zarma);
        define_qenum_value_under(rb_cQLocaleLanguage, "Zhuang", QLocale::Language::Zhuang);
        define_qenum_value_under(rb_cQLocaleLanguage, "Zulu", QLocale::Language::Zulu);
        define_qenum_value_under(rb_cQLocaleLanguage, "Kaingang", QLocale::Language::Kaingang);
        define_qenum_value_under(rb_cQLocaleLanguage, "Nheengatu", QLocale::Language::Nheengatu);
        define_qenum_value_under(rb_cQLocaleLanguage, "Haryanvi", QLocale::Language::Haryanvi);
        define_qenum_value_under(rb_cQLocaleLanguage, "NorthernFrisian", QLocale::Language::NorthernFrisian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Rajasthani", QLocale::Language::Rajasthani);
        define_qenum_value_under(rb_cQLocaleLanguage, "Moksha", QLocale::Language::Moksha);
        define_qenum_value_under(rb_cQLocaleLanguage, "TokiPona", QLocale::Language::TokiPona);
        define_qenum_value_under(rb_cQLocaleLanguage, "Pijin", QLocale::Language::Pijin);
        define_qenum_value_under(rb_cQLocaleLanguage, "Obolo", QLocale::Language::Obolo);
        define_qenum_value_under(rb_cQLocaleLanguage, "Baluchi", QLocale::Language::Baluchi);
        define_qenum_value_under(rb_cQLocaleLanguage, "Ligurian", QLocale::Language::Ligurian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Rohingya", QLocale::Language::Rohingya);
        define_qenum_value_under(rb_cQLocaleLanguage, "Torwali", QLocale::Language::Torwali);
        define_qenum_value_under(rb_cQLocaleLanguage, "Anii", QLocale::Language::Anii);
        define_qenum_value_under(rb_cQLocaleLanguage, "Kangri", QLocale::Language::Kangri);
        define_qenum_value_under(rb_cQLocaleLanguage, "Venetian", QLocale::Language::Venetian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Kuvi", QLocale::Language::Kuvi);
        define_qenum_value_under(rb_cQLocaleLanguage, "KaraKalpak", QLocale::Language::KaraKalpak);
        define_qenum_value_under(rb_cQLocaleLanguage, "SwampyCree", QLocale::Language::SwampyCree);
        define_qenum_value_under(rb_cQLocaleLanguage, "Afan", QLocale::Language::Afan);
        define_qenum_value_under(rb_cQLocaleLanguage, "Bengali", QLocale::Language::Bengali);
        define_qenum_value_under(rb_cQLocaleLanguage, "Bhutani", QLocale::Language::Bhutani);
        define_qenum_value_under(rb_cQLocaleLanguage, "Byelorussian", QLocale::Language::Byelorussian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Cambodian", QLocale::Language::Cambodian);
        define_qenum_value_under(rb_cQLocaleLanguage, "CentralMoroccoTamazight", QLocale::Language::CentralMoroccoTamazight);
        define_qenum_value_under(rb_cQLocaleLanguage, "Chewa", QLocale::Language::Chewa);
        define_qenum_value_under(rb_cQLocaleLanguage, "Frisian", QLocale::Language::Frisian);
        define_qenum_value_under(rb_cQLocaleLanguage, "Greenlandic", QLocale::Language::Greenlandic);
        define_qenum_value_under(rb_cQLocaleLanguage, "Inupiak", QLocale::Language::Inupiak);
        define_qenum_value_under(rb_cQLocaleLanguage, "Kirghiz", QLocale::Language::Kirghiz);
        define_qenum_value_under(rb_cQLocaleLanguage, "Kurundi", QLocale::Language::Kurundi);
        define_qenum_value_under(rb_cQLocaleLanguage, "Kwanyama", QLocale::Language::Kwanyama);
        define_qenum_value_under(rb_cQLocaleLanguage, "Navaho", QLocale::Language::Navaho);
        define_qenum_value_under(rb_cQLocaleLanguage, "Oriya", QLocale::Language::Oriya);
        define_qenum_value_under(rb_cQLocaleLanguage, "RhaetoRomance", QLocale::Language::RhaetoRomance);
        define_qenum_value_under(rb_cQLocaleLanguage, "Uighur", QLocale::Language::Uighur);
        define_qenum_value_under(rb_cQLocaleLanguage, "Uigur", QLocale::Language::Uigur);
        define_qenum_value_under(rb_cQLocaleLanguage, "Walamo", QLocale::Language::Walamo);
        define_qenum_value_under(rb_cQLocaleLanguage, "LastLanguage", QLocale::Language::LastLanguage);

    Data_Type<QLocale::Script> rb_cQLocaleScript =
        // RubyQt6::QtCore::QLocale::Script
        define_qenum_under<QLocale::Script>(rb_cQLocale, "Script");
        define_qenum_value_under(rb_cQLocaleScript, "AnyScript", QLocale::Script::AnyScript);
        define_qenum_value_under(rb_cQLocaleScript, "AdlamScript", QLocale::Script::AdlamScript);
        define_qenum_value_under(rb_cQLocaleScript, "AhomScript", QLocale::Script::AhomScript);
        define_qenum_value_under(rb_cQLocaleScript, "AnatolianHieroglyphsScript", QLocale::Script::AnatolianHieroglyphsScript);
        define_qenum_value_under(rb_cQLocaleScript, "ArabicScript", QLocale::Script::ArabicScript);
        define_qenum_value_under(rb_cQLocaleScript, "ArmenianScript", QLocale::Script::ArmenianScript);
        define_qenum_value_under(rb_cQLocaleScript, "AvestanScript", QLocale::Script::AvestanScript);
        define_qenum_value_under(rb_cQLocaleScript, "BalineseScript", QLocale::Script::BalineseScript);
        define_qenum_value_under(rb_cQLocaleScript, "BamumScript", QLocale::Script::BamumScript);
        define_qenum_value_under(rb_cQLocaleScript, "BanglaScript", QLocale::Script::BanglaScript);
        define_qenum_value_under(rb_cQLocaleScript, "BassaVahScript", QLocale::Script::BassaVahScript);
        define_qenum_value_under(rb_cQLocaleScript, "BatakScript", QLocale::Script::BatakScript);
        define_qenum_value_under(rb_cQLocaleScript, "BhaiksukiScript", QLocale::Script::BhaiksukiScript);
        define_qenum_value_under(rb_cQLocaleScript, "BopomofoScript", QLocale::Script::BopomofoScript);
        define_qenum_value_under(rb_cQLocaleScript, "BrahmiScript", QLocale::Script::BrahmiScript);
        define_qenum_value_under(rb_cQLocaleScript, "BrailleScript", QLocale::Script::BrailleScript);
        define_qenum_value_under(rb_cQLocaleScript, "BugineseScript", QLocale::Script::BugineseScript);
        define_qenum_value_under(rb_cQLocaleScript, "BuhidScript", QLocale::Script::BuhidScript);
        define_qenum_value_under(rb_cQLocaleScript, "CanadianAboriginalScript", QLocale::Script::CanadianAboriginalScript);
        define_qenum_value_under(rb_cQLocaleScript, "CarianScript", QLocale::Script::CarianScript);
        define_qenum_value_under(rb_cQLocaleScript, "CaucasianAlbanianScript", QLocale::Script::CaucasianAlbanianScript);
        define_qenum_value_under(rb_cQLocaleScript, "ChakmaScript", QLocale::Script::ChakmaScript);
        define_qenum_value_under(rb_cQLocaleScript, "ChamScript", QLocale::Script::ChamScript);
        define_qenum_value_under(rb_cQLocaleScript, "CherokeeScript", QLocale::Script::CherokeeScript);
        define_qenum_value_under(rb_cQLocaleScript, "CopticScript", QLocale::Script::CopticScript);
        define_qenum_value_under(rb_cQLocaleScript, "CuneiformScript", QLocale::Script::CuneiformScript);
        define_qenum_value_under(rb_cQLocaleScript, "CypriotScript", QLocale::Script::CypriotScript);
        define_qenum_value_under(rb_cQLocaleScript, "CyrillicScript", QLocale::Script::CyrillicScript);
        define_qenum_value_under(rb_cQLocaleScript, "DeseretScript", QLocale::Script::DeseretScript);
        define_qenum_value_under(rb_cQLocaleScript, "DevanagariScript", QLocale::Script::DevanagariScript);
        define_qenum_value_under(rb_cQLocaleScript, "DuployanScript", QLocale::Script::DuployanScript);
        define_qenum_value_under(rb_cQLocaleScript, "EgyptianHieroglyphsScript", QLocale::Script::EgyptianHieroglyphsScript);
        define_qenum_value_under(rb_cQLocaleScript, "ElbasanScript", QLocale::Script::ElbasanScript);
        define_qenum_value_under(rb_cQLocaleScript, "EthiopicScript", QLocale::Script::EthiopicScript);
        define_qenum_value_under(rb_cQLocaleScript, "FraserScript", QLocale::Script::FraserScript);
        define_qenum_value_under(rb_cQLocaleScript, "GeorgianScript", QLocale::Script::GeorgianScript);
        define_qenum_value_under(rb_cQLocaleScript, "GlagoliticScript", QLocale::Script::GlagoliticScript);
        define_qenum_value_under(rb_cQLocaleScript, "GothicScript", QLocale::Script::GothicScript);
        define_qenum_value_under(rb_cQLocaleScript, "GranthaScript", QLocale::Script::GranthaScript);
        define_qenum_value_under(rb_cQLocaleScript, "GreekScript", QLocale::Script::GreekScript);
        define_qenum_value_under(rb_cQLocaleScript, "GujaratiScript", QLocale::Script::GujaratiScript);
        define_qenum_value_under(rb_cQLocaleScript, "GurmukhiScript", QLocale::Script::GurmukhiScript);
        define_qenum_value_under(rb_cQLocaleScript, "HangulScript", QLocale::Script::HangulScript);
        define_qenum_value_under(rb_cQLocaleScript, "HanScript", QLocale::Script::HanScript);
        define_qenum_value_under(rb_cQLocaleScript, "HanunooScript", QLocale::Script::HanunooScript);
        define_qenum_value_under(rb_cQLocaleScript, "HanWithBopomofoScript", QLocale::Script::HanWithBopomofoScript);
        define_qenum_value_under(rb_cQLocaleScript, "HatranScript", QLocale::Script::HatranScript);
        define_qenum_value_under(rb_cQLocaleScript, "HebrewScript", QLocale::Script::HebrewScript);
        define_qenum_value_under(rb_cQLocaleScript, "HiraganaScript", QLocale::Script::HiraganaScript);
        define_qenum_value_under(rb_cQLocaleScript, "ImperialAramaicScript", QLocale::Script::ImperialAramaicScript);
        define_qenum_value_under(rb_cQLocaleScript, "InscriptionalPahlaviScript", QLocale::Script::InscriptionalPahlaviScript);
        define_qenum_value_under(rb_cQLocaleScript, "InscriptionalParthianScript", QLocale::Script::InscriptionalParthianScript);
        define_qenum_value_under(rb_cQLocaleScript, "JamoScript", QLocale::Script::JamoScript);
        define_qenum_value_under(rb_cQLocaleScript, "JapaneseScript", QLocale::Script::JapaneseScript);
        define_qenum_value_under(rb_cQLocaleScript, "JavaneseScript", QLocale::Script::JavaneseScript);
        define_qenum_value_under(rb_cQLocaleScript, "KaithiScript", QLocale::Script::KaithiScript);
        define_qenum_value_under(rb_cQLocaleScript, "KannadaScript", QLocale::Script::KannadaScript);
        define_qenum_value_under(rb_cQLocaleScript, "KatakanaScript", QLocale::Script::KatakanaScript);
        define_qenum_value_under(rb_cQLocaleScript, "KayahLiScript", QLocale::Script::KayahLiScript);
        define_qenum_value_under(rb_cQLocaleScript, "KharoshthiScript", QLocale::Script::KharoshthiScript);
        define_qenum_value_under(rb_cQLocaleScript, "KhmerScript", QLocale::Script::KhmerScript);
        define_qenum_value_under(rb_cQLocaleScript, "KhojkiScript", QLocale::Script::KhojkiScript);
        define_qenum_value_under(rb_cQLocaleScript, "KhudawadiScript", QLocale::Script::KhudawadiScript);
        define_qenum_value_under(rb_cQLocaleScript, "KoreanScript", QLocale::Script::KoreanScript);
        define_qenum_value_under(rb_cQLocaleScript, "LannaScript", QLocale::Script::LannaScript);
        define_qenum_value_under(rb_cQLocaleScript, "LaoScript", QLocale::Script::LaoScript);
        define_qenum_value_under(rb_cQLocaleScript, "LatinScript", QLocale::Script::LatinScript);
        define_qenum_value_under(rb_cQLocaleScript, "LepchaScript", QLocale::Script::LepchaScript);
        define_qenum_value_under(rb_cQLocaleScript, "LimbuScript", QLocale::Script::LimbuScript);
        define_qenum_value_under(rb_cQLocaleScript, "LinearAScript", QLocale::Script::LinearAScript);
        define_qenum_value_under(rb_cQLocaleScript, "LinearBScript", QLocale::Script::LinearBScript);
        define_qenum_value_under(rb_cQLocaleScript, "LycianScript", QLocale::Script::LycianScript);
        define_qenum_value_under(rb_cQLocaleScript, "LydianScript", QLocale::Script::LydianScript);
        define_qenum_value_under(rb_cQLocaleScript, "MahajaniScript", QLocale::Script::MahajaniScript);
        define_qenum_value_under(rb_cQLocaleScript, "MalayalamScript", QLocale::Script::MalayalamScript);
        define_qenum_value_under(rb_cQLocaleScript, "MandaeanScript", QLocale::Script::MandaeanScript);
        define_qenum_value_under(rb_cQLocaleScript, "ManichaeanScript", QLocale::Script::ManichaeanScript);
        define_qenum_value_under(rb_cQLocaleScript, "MarchenScript", QLocale::Script::MarchenScript);
        define_qenum_value_under(rb_cQLocaleScript, "MeiteiMayekScript", QLocale::Script::MeiteiMayekScript);
        define_qenum_value_under(rb_cQLocaleScript, "MendeScript", QLocale::Script::MendeScript);
        define_qenum_value_under(rb_cQLocaleScript, "MeroiticCursiveScript", QLocale::Script::MeroiticCursiveScript);
        define_qenum_value_under(rb_cQLocaleScript, "MeroiticScript", QLocale::Script::MeroiticScript);
        define_qenum_value_under(rb_cQLocaleScript, "ModiScript", QLocale::Script::ModiScript);
        define_qenum_value_under(rb_cQLocaleScript, "MongolianScript", QLocale::Script::MongolianScript);
        define_qenum_value_under(rb_cQLocaleScript, "MroScript", QLocale::Script::MroScript);
        define_qenum_value_under(rb_cQLocaleScript, "MultaniScript", QLocale::Script::MultaniScript);
        define_qenum_value_under(rb_cQLocaleScript, "MyanmarScript", QLocale::Script::MyanmarScript);
        define_qenum_value_under(rb_cQLocaleScript, "NabataeanScript", QLocale::Script::NabataeanScript);
        define_qenum_value_under(rb_cQLocaleScript, "NewaScript", QLocale::Script::NewaScript);
        define_qenum_value_under(rb_cQLocaleScript, "NewTaiLueScript", QLocale::Script::NewTaiLueScript);
        define_qenum_value_under(rb_cQLocaleScript, "NkoScript", QLocale::Script::NkoScript);
        define_qenum_value_under(rb_cQLocaleScript, "OdiaScript", QLocale::Script::OdiaScript);
        define_qenum_value_under(rb_cQLocaleScript, "OghamScript", QLocale::Script::OghamScript);
        define_qenum_value_under(rb_cQLocaleScript, "OlChikiScript", QLocale::Script::OlChikiScript);
        define_qenum_value_under(rb_cQLocaleScript, "OldHungarianScript", QLocale::Script::OldHungarianScript);
        define_qenum_value_under(rb_cQLocaleScript, "OldItalicScript", QLocale::Script::OldItalicScript);
        define_qenum_value_under(rb_cQLocaleScript, "OldNorthArabianScript", QLocale::Script::OldNorthArabianScript);
        define_qenum_value_under(rb_cQLocaleScript, "OldPermicScript", QLocale::Script::OldPermicScript);
        define_qenum_value_under(rb_cQLocaleScript, "OldPersianScript", QLocale::Script::OldPersianScript);
        define_qenum_value_under(rb_cQLocaleScript, "OldSouthArabianScript", QLocale::Script::OldSouthArabianScript);
        define_qenum_value_under(rb_cQLocaleScript, "OrkhonScript", QLocale::Script::OrkhonScript);
        define_qenum_value_under(rb_cQLocaleScript, "OsageScript", QLocale::Script::OsageScript);
        define_qenum_value_under(rb_cQLocaleScript, "OsmanyaScript", QLocale::Script::OsmanyaScript);
        define_qenum_value_under(rb_cQLocaleScript, "PahawhHmongScript", QLocale::Script::PahawhHmongScript);
        define_qenum_value_under(rb_cQLocaleScript, "PalmyreneScript", QLocale::Script::PalmyreneScript);
        define_qenum_value_under(rb_cQLocaleScript, "PauCinHauScript", QLocale::Script::PauCinHauScript);
        define_qenum_value_under(rb_cQLocaleScript, "PhagsPaScript", QLocale::Script::PhagsPaScript);
        define_qenum_value_under(rb_cQLocaleScript, "PhoenicianScript", QLocale::Script::PhoenicianScript);
        define_qenum_value_under(rb_cQLocaleScript, "PollardPhoneticScript", QLocale::Script::PollardPhoneticScript);
        define_qenum_value_under(rb_cQLocaleScript, "PsalterPahlaviScript", QLocale::Script::PsalterPahlaviScript);
        define_qenum_value_under(rb_cQLocaleScript, "RejangScript", QLocale::Script::RejangScript);
        define_qenum_value_under(rb_cQLocaleScript, "RunicScript", QLocale::Script::RunicScript);
        define_qenum_value_under(rb_cQLocaleScript, "SamaritanScript", QLocale::Script::SamaritanScript);
        define_qenum_value_under(rb_cQLocaleScript, "SaurashtraScript", QLocale::Script::SaurashtraScript);
        define_qenum_value_under(rb_cQLocaleScript, "SharadaScript", QLocale::Script::SharadaScript);
        define_qenum_value_under(rb_cQLocaleScript, "ShavianScript", QLocale::Script::ShavianScript);
        define_qenum_value_under(rb_cQLocaleScript, "SiddhamScript", QLocale::Script::SiddhamScript);
        define_qenum_value_under(rb_cQLocaleScript, "SignWritingScript", QLocale::Script::SignWritingScript);
        define_qenum_value_under(rb_cQLocaleScript, "SimplifiedHanScript", QLocale::Script::SimplifiedHanScript);
        define_qenum_value_under(rb_cQLocaleScript, "SinhalaScript", QLocale::Script::SinhalaScript);
        define_qenum_value_under(rb_cQLocaleScript, "SoraSompengScript", QLocale::Script::SoraSompengScript);
        define_qenum_value_under(rb_cQLocaleScript, "SundaneseScript", QLocale::Script::SundaneseScript);
        define_qenum_value_under(rb_cQLocaleScript, "SylotiNagriScript", QLocale::Script::SylotiNagriScript);
        define_qenum_value_under(rb_cQLocaleScript, "SyriacScript", QLocale::Script::SyriacScript);
        define_qenum_value_under(rb_cQLocaleScript, "TagalogScript", QLocale::Script::TagalogScript);
        define_qenum_value_under(rb_cQLocaleScript, "TagbanwaScript", QLocale::Script::TagbanwaScript);
        define_qenum_value_under(rb_cQLocaleScript, "TaiLeScript", QLocale::Script::TaiLeScript);
        define_qenum_value_under(rb_cQLocaleScript, "TaiVietScript", QLocale::Script::TaiVietScript);
        define_qenum_value_under(rb_cQLocaleScript, "TakriScript", QLocale::Script::TakriScript);
        define_qenum_value_under(rb_cQLocaleScript, "TamilScript", QLocale::Script::TamilScript);
        define_qenum_value_under(rb_cQLocaleScript, "TangutScript", QLocale::Script::TangutScript);
        define_qenum_value_under(rb_cQLocaleScript, "TeluguScript", QLocale::Script::TeluguScript);
        define_qenum_value_under(rb_cQLocaleScript, "ThaanaScript", QLocale::Script::ThaanaScript);
        define_qenum_value_under(rb_cQLocaleScript, "ThaiScript", QLocale::Script::ThaiScript);
        define_qenum_value_under(rb_cQLocaleScript, "TibetanScript", QLocale::Script::TibetanScript);
        define_qenum_value_under(rb_cQLocaleScript, "TifinaghScript", QLocale::Script::TifinaghScript);
        define_qenum_value_under(rb_cQLocaleScript, "TirhutaScript", QLocale::Script::TirhutaScript);
        define_qenum_value_under(rb_cQLocaleScript, "TraditionalHanScript", QLocale::Script::TraditionalHanScript);
        define_qenum_value_under(rb_cQLocaleScript, "UgariticScript", QLocale::Script::UgariticScript);
        define_qenum_value_under(rb_cQLocaleScript, "VaiScript", QLocale::Script::VaiScript);
        define_qenum_value_under(rb_cQLocaleScript, "VarangKshitiScript", QLocale::Script::VarangKshitiScript);
        define_qenum_value_under(rb_cQLocaleScript, "YiScript", QLocale::Script::YiScript);
        define_qenum_value_under(rb_cQLocaleScript, "HanifiScript", QLocale::Script::HanifiScript);
        define_qenum_value_under(rb_cQLocaleScript, "BengaliScript", QLocale::Script::BengaliScript);
        define_qenum_value_under(rb_cQLocaleScript, "MendeKikakuiScript", QLocale::Script::MendeKikakuiScript);
        define_qenum_value_under(rb_cQLocaleScript, "OriyaScript", QLocale::Script::OriyaScript);
        define_qenum_value_under(rb_cQLocaleScript, "SimplifiedChineseScript", QLocale::Script::SimplifiedChineseScript);
        define_qenum_value_under(rb_cQLocaleScript, "TraditionalChineseScript", QLocale::Script::TraditionalChineseScript);
        define_qenum_value_under(rb_cQLocaleScript, "LastScript", QLocale::Script::LastScript);

    Data_Type<QLocale::Country> rb_cQLocaleCountry =
        // RubyQt6::QtCore::QLocale::Country
        define_qenum_under<QLocale::Country>(rb_cQLocale, "Country");
        define_qenum_value_under(rb_cQLocaleCountry, "AnyTerritory", QLocale::Country::AnyTerritory);
        define_qenum_value_under(rb_cQLocaleCountry, "Afghanistan", QLocale::Country::Afghanistan);
        define_qenum_value_under(rb_cQLocaleCountry, "AlandIslands", QLocale::Country::AlandIslands);
        define_qenum_value_under(rb_cQLocaleCountry, "Albania", QLocale::Country::Albania);
        define_qenum_value_under(rb_cQLocaleCountry, "Algeria", QLocale::Country::Algeria);
        define_qenum_value_under(rb_cQLocaleCountry, "AmericanSamoa", QLocale::Country::AmericanSamoa);
        define_qenum_value_under(rb_cQLocaleCountry, "Andorra", QLocale::Country::Andorra);
        define_qenum_value_under(rb_cQLocaleCountry, "Angola", QLocale::Country::Angola);
        define_qenum_value_under(rb_cQLocaleCountry, "Anguilla", QLocale::Country::Anguilla);
        define_qenum_value_under(rb_cQLocaleCountry, "Antarctica", QLocale::Country::Antarctica);
        define_qenum_value_under(rb_cQLocaleCountry, "AntiguaAndBarbuda", QLocale::Country::AntiguaAndBarbuda);
        define_qenum_value_under(rb_cQLocaleCountry, "Argentina", QLocale::Country::Argentina);
        define_qenum_value_under(rb_cQLocaleCountry, "Armenia", QLocale::Country::Armenia);
        define_qenum_value_under(rb_cQLocaleCountry, "Aruba", QLocale::Country::Aruba);
        define_qenum_value_under(rb_cQLocaleCountry, "AscensionIsland", QLocale::Country::AscensionIsland);
        define_qenum_value_under(rb_cQLocaleCountry, "Australia", QLocale::Country::Australia);
        define_qenum_value_under(rb_cQLocaleCountry, "Austria", QLocale::Country::Austria);
        define_qenum_value_under(rb_cQLocaleCountry, "Azerbaijan", QLocale::Country::Azerbaijan);
        define_qenum_value_under(rb_cQLocaleCountry, "Bahamas", QLocale::Country::Bahamas);
        define_qenum_value_under(rb_cQLocaleCountry, "Bahrain", QLocale::Country::Bahrain);
        define_qenum_value_under(rb_cQLocaleCountry, "Bangladesh", QLocale::Country::Bangladesh);
        define_qenum_value_under(rb_cQLocaleCountry, "Barbados", QLocale::Country::Barbados);
        define_qenum_value_under(rb_cQLocaleCountry, "Belarus", QLocale::Country::Belarus);
        define_qenum_value_under(rb_cQLocaleCountry, "Belgium", QLocale::Country::Belgium);
        define_qenum_value_under(rb_cQLocaleCountry, "Belize", QLocale::Country::Belize);
        define_qenum_value_under(rb_cQLocaleCountry, "Benin", QLocale::Country::Benin);
        define_qenum_value_under(rb_cQLocaleCountry, "Bermuda", QLocale::Country::Bermuda);
        define_qenum_value_under(rb_cQLocaleCountry, "Bhutan", QLocale::Country::Bhutan);
        define_qenum_value_under(rb_cQLocaleCountry, "Bolivia", QLocale::Country::Bolivia);
        define_qenum_value_under(rb_cQLocaleCountry, "BosniaAndHerzegovina", QLocale::Country::BosniaAndHerzegovina);
        define_qenum_value_under(rb_cQLocaleCountry, "Botswana", QLocale::Country::Botswana);
        define_qenum_value_under(rb_cQLocaleCountry, "BouvetIsland", QLocale::Country::BouvetIsland);
        define_qenum_value_under(rb_cQLocaleCountry, "Brazil", QLocale::Country::Brazil);
        define_qenum_value_under(rb_cQLocaleCountry, "BritishIndianOceanTerritory", QLocale::Country::BritishIndianOceanTerritory);
        define_qenum_value_under(rb_cQLocaleCountry, "BritishVirginIslands", QLocale::Country::BritishVirginIslands);
        define_qenum_value_under(rb_cQLocaleCountry, "Brunei", QLocale::Country::Brunei);
        define_qenum_value_under(rb_cQLocaleCountry, "Bulgaria", QLocale::Country::Bulgaria);
        define_qenum_value_under(rb_cQLocaleCountry, "BurkinaFaso", QLocale::Country::BurkinaFaso);
        define_qenum_value_under(rb_cQLocaleCountry, "Burundi", QLocale::Country::Burundi);
        define_qenum_value_under(rb_cQLocaleCountry, "Cambodia", QLocale::Country::Cambodia);
        define_qenum_value_under(rb_cQLocaleCountry, "Cameroon", QLocale::Country::Cameroon);
        define_qenum_value_under(rb_cQLocaleCountry, "Canada", QLocale::Country::Canada);
        define_qenum_value_under(rb_cQLocaleCountry, "CanaryIslands", QLocale::Country::CanaryIslands);
        define_qenum_value_under(rb_cQLocaleCountry, "CapeVerde", QLocale::Country::CapeVerde);
        define_qenum_value_under(rb_cQLocaleCountry, "CaribbeanNetherlands", QLocale::Country::CaribbeanNetherlands);
        define_qenum_value_under(rb_cQLocaleCountry, "CaymanIslands", QLocale::Country::CaymanIslands);
        define_qenum_value_under(rb_cQLocaleCountry, "CentralAfricanRepublic", QLocale::Country::CentralAfricanRepublic);
        define_qenum_value_under(rb_cQLocaleCountry, "CeutaAndMelilla", QLocale::Country::CeutaAndMelilla);
        define_qenum_value_under(rb_cQLocaleCountry, "Chad", QLocale::Country::Chad);
        define_qenum_value_under(rb_cQLocaleCountry, "Chile", QLocale::Country::Chile);
        define_qenum_value_under(rb_cQLocaleCountry, "China", QLocale::Country::China);
        define_qenum_value_under(rb_cQLocaleCountry, "ChristmasIsland", QLocale::Country::ChristmasIsland);
        define_qenum_value_under(rb_cQLocaleCountry, "ClippertonIsland", QLocale::Country::ClippertonIsland);
        define_qenum_value_under(rb_cQLocaleCountry, "CocosIslands", QLocale::Country::CocosIslands);
        define_qenum_value_under(rb_cQLocaleCountry, "Colombia", QLocale::Country::Colombia);
        define_qenum_value_under(rb_cQLocaleCountry, "Comoros", QLocale::Country::Comoros);
        define_qenum_value_under(rb_cQLocaleCountry, "CongoBrazzaville", QLocale::Country::CongoBrazzaville);
        define_qenum_value_under(rb_cQLocaleCountry, "CongoKinshasa", QLocale::Country::CongoKinshasa);
        define_qenum_value_under(rb_cQLocaleCountry, "CookIslands", QLocale::Country::CookIslands);
        define_qenum_value_under(rb_cQLocaleCountry, "CostaRica", QLocale::Country::CostaRica);
        define_qenum_value_under(rb_cQLocaleCountry, "Croatia", QLocale::Country::Croatia);
        define_qenum_value_under(rb_cQLocaleCountry, "Cuba", QLocale::Country::Cuba);
        define_qenum_value_under(rb_cQLocaleCountry, "Curacao", QLocale::Country::Curacao);
        define_qenum_value_under(rb_cQLocaleCountry, "Cyprus", QLocale::Country::Cyprus);
        define_qenum_value_under(rb_cQLocaleCountry, "Czechia", QLocale::Country::Czechia);
        define_qenum_value_under(rb_cQLocaleCountry, "Denmark", QLocale::Country::Denmark);
        define_qenum_value_under(rb_cQLocaleCountry, "DiegoGarcia", QLocale::Country::DiegoGarcia);
        define_qenum_value_under(rb_cQLocaleCountry, "Djibouti", QLocale::Country::Djibouti);
        define_qenum_value_under(rb_cQLocaleCountry, "Dominica", QLocale::Country::Dominica);
        define_qenum_value_under(rb_cQLocaleCountry, "DominicanRepublic", QLocale::Country::DominicanRepublic);
        define_qenum_value_under(rb_cQLocaleCountry, "Ecuador", QLocale::Country::Ecuador);
        define_qenum_value_under(rb_cQLocaleCountry, "Egypt", QLocale::Country::Egypt);
        define_qenum_value_under(rb_cQLocaleCountry, "ElSalvador", QLocale::Country::ElSalvador);
        define_qenum_value_under(rb_cQLocaleCountry, "EquatorialGuinea", QLocale::Country::EquatorialGuinea);
        define_qenum_value_under(rb_cQLocaleCountry, "Eritrea", QLocale::Country::Eritrea);
        define_qenum_value_under(rb_cQLocaleCountry, "Estonia", QLocale::Country::Estonia);
        define_qenum_value_under(rb_cQLocaleCountry, "Eswatini", QLocale::Country::Eswatini);
        define_qenum_value_under(rb_cQLocaleCountry, "Ethiopia", QLocale::Country::Ethiopia);
        define_qenum_value_under(rb_cQLocaleCountry, "Europe", QLocale::Country::Europe);
        define_qenum_value_under(rb_cQLocaleCountry, "EuropeanUnion", QLocale::Country::EuropeanUnion);
        define_qenum_value_under(rb_cQLocaleCountry, "FalklandIslands", QLocale::Country::FalklandIslands);
        define_qenum_value_under(rb_cQLocaleCountry, "FaroeIslands", QLocale::Country::FaroeIslands);
        define_qenum_value_under(rb_cQLocaleCountry, "Fiji", QLocale::Country::Fiji);
        define_qenum_value_under(rb_cQLocaleCountry, "Finland", QLocale::Country::Finland);
        define_qenum_value_under(rb_cQLocaleCountry, "France", QLocale::Country::France);
        define_qenum_value_under(rb_cQLocaleCountry, "FrenchGuiana", QLocale::Country::FrenchGuiana);
        define_qenum_value_under(rb_cQLocaleCountry, "FrenchPolynesia", QLocale::Country::FrenchPolynesia);
        define_qenum_value_under(rb_cQLocaleCountry, "FrenchSouthernTerritories", QLocale::Country::FrenchSouthernTerritories);
        define_qenum_value_under(rb_cQLocaleCountry, "Gabon", QLocale::Country::Gabon);
        define_qenum_value_under(rb_cQLocaleCountry, "Gambia", QLocale::Country::Gambia);
        define_qenum_value_under(rb_cQLocaleCountry, "Georgia", QLocale::Country::Georgia);
        define_qenum_value_under(rb_cQLocaleCountry, "Germany", QLocale::Country::Germany);
        define_qenum_value_under(rb_cQLocaleCountry, "Ghana", QLocale::Country::Ghana);
        define_qenum_value_under(rb_cQLocaleCountry, "Gibraltar", QLocale::Country::Gibraltar);
        define_qenum_value_under(rb_cQLocaleCountry, "Greece", QLocale::Country::Greece);
        define_qenum_value_under(rb_cQLocaleCountry, "Greenland", QLocale::Country::Greenland);
        define_qenum_value_under(rb_cQLocaleCountry, "Grenada", QLocale::Country::Grenada);
        define_qenum_value_under(rb_cQLocaleCountry, "Guadeloupe", QLocale::Country::Guadeloupe);
        define_qenum_value_under(rb_cQLocaleCountry, "Guam", QLocale::Country::Guam);
        define_qenum_value_under(rb_cQLocaleCountry, "Guatemala", QLocale::Country::Guatemala);
        define_qenum_value_under(rb_cQLocaleCountry, "Guernsey", QLocale::Country::Guernsey);
        define_qenum_value_under(rb_cQLocaleCountry, "GuineaBissau", QLocale::Country::GuineaBissau);
        define_qenum_value_under(rb_cQLocaleCountry, "Guinea", QLocale::Country::Guinea);
        define_qenum_value_under(rb_cQLocaleCountry, "Guyana", QLocale::Country::Guyana);
        define_qenum_value_under(rb_cQLocaleCountry, "Haiti", QLocale::Country::Haiti);
        define_qenum_value_under(rb_cQLocaleCountry, "HeardAndMcDonaldIslands", QLocale::Country::HeardAndMcDonaldIslands);
        define_qenum_value_under(rb_cQLocaleCountry, "Honduras", QLocale::Country::Honduras);
        define_qenum_value_under(rb_cQLocaleCountry, "HongKong", QLocale::Country::HongKong);
        define_qenum_value_under(rb_cQLocaleCountry, "Hungary", QLocale::Country::Hungary);
        define_qenum_value_under(rb_cQLocaleCountry, "Iceland", QLocale::Country::Iceland);
        define_qenum_value_under(rb_cQLocaleCountry, "India", QLocale::Country::India);
        define_qenum_value_under(rb_cQLocaleCountry, "Indonesia", QLocale::Country::Indonesia);
        define_qenum_value_under(rb_cQLocaleCountry, "Iran", QLocale::Country::Iran);
        define_qenum_value_under(rb_cQLocaleCountry, "Iraq", QLocale::Country::Iraq);
        define_qenum_value_under(rb_cQLocaleCountry, "Ireland", QLocale::Country::Ireland);
        define_qenum_value_under(rb_cQLocaleCountry, "IsleOfMan", QLocale::Country::IsleOfMan);
        define_qenum_value_under(rb_cQLocaleCountry, "Israel", QLocale::Country::Israel);
        define_qenum_value_under(rb_cQLocaleCountry, "Italy", QLocale::Country::Italy);
        define_qenum_value_under(rb_cQLocaleCountry, "IvoryCoast", QLocale::Country::IvoryCoast);
        define_qenum_value_under(rb_cQLocaleCountry, "Jamaica", QLocale::Country::Jamaica);
        define_qenum_value_under(rb_cQLocaleCountry, "Japan", QLocale::Country::Japan);
        define_qenum_value_under(rb_cQLocaleCountry, "Jersey", QLocale::Country::Jersey);
        define_qenum_value_under(rb_cQLocaleCountry, "Jordan", QLocale::Country::Jordan);
        define_qenum_value_under(rb_cQLocaleCountry, "Kazakhstan", QLocale::Country::Kazakhstan);
        define_qenum_value_under(rb_cQLocaleCountry, "Kenya", QLocale::Country::Kenya);
        define_qenum_value_under(rb_cQLocaleCountry, "Kiribati", QLocale::Country::Kiribati);
        define_qenum_value_under(rb_cQLocaleCountry, "Kosovo", QLocale::Country::Kosovo);
        define_qenum_value_under(rb_cQLocaleCountry, "Kuwait", QLocale::Country::Kuwait);
        define_qenum_value_under(rb_cQLocaleCountry, "Kyrgyzstan", QLocale::Country::Kyrgyzstan);
        define_qenum_value_under(rb_cQLocaleCountry, "Laos", QLocale::Country::Laos);
        define_qenum_value_under(rb_cQLocaleCountry, "LatinAmerica", QLocale::Country::LatinAmerica);
        define_qenum_value_under(rb_cQLocaleCountry, "Latvia", QLocale::Country::Latvia);
        define_qenum_value_under(rb_cQLocaleCountry, "Lebanon", QLocale::Country::Lebanon);
        define_qenum_value_under(rb_cQLocaleCountry, "Lesotho", QLocale::Country::Lesotho);
        define_qenum_value_under(rb_cQLocaleCountry, "Liberia", QLocale::Country::Liberia);
        define_qenum_value_under(rb_cQLocaleCountry, "Libya", QLocale::Country::Libya);
        define_qenum_value_under(rb_cQLocaleCountry, "Liechtenstein", QLocale::Country::Liechtenstein);
        define_qenum_value_under(rb_cQLocaleCountry, "Lithuania", QLocale::Country::Lithuania);
        define_qenum_value_under(rb_cQLocaleCountry, "Luxembourg", QLocale::Country::Luxembourg);
        define_qenum_value_under(rb_cQLocaleCountry, "Macao", QLocale::Country::Macao);
        define_qenum_value_under(rb_cQLocaleCountry, "Macedonia", QLocale::Country::Macedonia);
        define_qenum_value_under(rb_cQLocaleCountry, "Madagascar", QLocale::Country::Madagascar);
        define_qenum_value_under(rb_cQLocaleCountry, "Malawi", QLocale::Country::Malawi);
        define_qenum_value_under(rb_cQLocaleCountry, "Malaysia", QLocale::Country::Malaysia);
        define_qenum_value_under(rb_cQLocaleCountry, "Maldives", QLocale::Country::Maldives);
        define_qenum_value_under(rb_cQLocaleCountry, "Mali", QLocale::Country::Mali);
        define_qenum_value_under(rb_cQLocaleCountry, "Malta", QLocale::Country::Malta);
        define_qenum_value_under(rb_cQLocaleCountry, "MarshallIslands", QLocale::Country::MarshallIslands);
        define_qenum_value_under(rb_cQLocaleCountry, "Martinique", QLocale::Country::Martinique);
        define_qenum_value_under(rb_cQLocaleCountry, "Mauritania", QLocale::Country::Mauritania);
        define_qenum_value_under(rb_cQLocaleCountry, "Mauritius", QLocale::Country::Mauritius);
        define_qenum_value_under(rb_cQLocaleCountry, "Mayotte", QLocale::Country::Mayotte);
        define_qenum_value_under(rb_cQLocaleCountry, "Mexico", QLocale::Country::Mexico);
        define_qenum_value_under(rb_cQLocaleCountry, "Micronesia", QLocale::Country::Micronesia);
        define_qenum_value_under(rb_cQLocaleCountry, "Moldova", QLocale::Country::Moldova);
        define_qenum_value_under(rb_cQLocaleCountry, "Monaco", QLocale::Country::Monaco);
        define_qenum_value_under(rb_cQLocaleCountry, "Mongolia", QLocale::Country::Mongolia);
        define_qenum_value_under(rb_cQLocaleCountry, "Montenegro", QLocale::Country::Montenegro);
        define_qenum_value_under(rb_cQLocaleCountry, "Montserrat", QLocale::Country::Montserrat);
        define_qenum_value_under(rb_cQLocaleCountry, "Morocco", QLocale::Country::Morocco);
        define_qenum_value_under(rb_cQLocaleCountry, "Mozambique", QLocale::Country::Mozambique);
        define_qenum_value_under(rb_cQLocaleCountry, "Myanmar", QLocale::Country::Myanmar);
        define_qenum_value_under(rb_cQLocaleCountry, "Namibia", QLocale::Country::Namibia);
        define_qenum_value_under(rb_cQLocaleCountry, "NauruTerritory", QLocale::Country::NauruTerritory);
        define_qenum_value_under(rb_cQLocaleCountry, "Nepal", QLocale::Country::Nepal);
        define_qenum_value_under(rb_cQLocaleCountry, "Netherlands", QLocale::Country::Netherlands);
        define_qenum_value_under(rb_cQLocaleCountry, "NewCaledonia", QLocale::Country::NewCaledonia);
        define_qenum_value_under(rb_cQLocaleCountry, "NewZealand", QLocale::Country::NewZealand);
        define_qenum_value_under(rb_cQLocaleCountry, "Nicaragua", QLocale::Country::Nicaragua);
        define_qenum_value_under(rb_cQLocaleCountry, "Nigeria", QLocale::Country::Nigeria);
        define_qenum_value_under(rb_cQLocaleCountry, "Niger", QLocale::Country::Niger);
        define_qenum_value_under(rb_cQLocaleCountry, "Niue", QLocale::Country::Niue);
        define_qenum_value_under(rb_cQLocaleCountry, "NorfolkIsland", QLocale::Country::NorfolkIsland);
        define_qenum_value_under(rb_cQLocaleCountry, "NorthernMarianaIslands", QLocale::Country::NorthernMarianaIslands);
        define_qenum_value_under(rb_cQLocaleCountry, "NorthKorea", QLocale::Country::NorthKorea);
        define_qenum_value_under(rb_cQLocaleCountry, "Norway", QLocale::Country::Norway);
        define_qenum_value_under(rb_cQLocaleCountry, "Oman", QLocale::Country::Oman);
        define_qenum_value_under(rb_cQLocaleCountry, "OutlyingOceania", QLocale::Country::OutlyingOceania);
        define_qenum_value_under(rb_cQLocaleCountry, "Pakistan", QLocale::Country::Pakistan);
        define_qenum_value_under(rb_cQLocaleCountry, "Palau", QLocale::Country::Palau);
        define_qenum_value_under(rb_cQLocaleCountry, "PalestinianTerritories", QLocale::Country::PalestinianTerritories);
        define_qenum_value_under(rb_cQLocaleCountry, "Panama", QLocale::Country::Panama);
        define_qenum_value_under(rb_cQLocaleCountry, "PapuaNewGuinea", QLocale::Country::PapuaNewGuinea);
        define_qenum_value_under(rb_cQLocaleCountry, "Paraguay", QLocale::Country::Paraguay);
        define_qenum_value_under(rb_cQLocaleCountry, "Peru", QLocale::Country::Peru);
        define_qenum_value_under(rb_cQLocaleCountry, "Philippines", QLocale::Country::Philippines);
        define_qenum_value_under(rb_cQLocaleCountry, "Pitcairn", QLocale::Country::Pitcairn);
        define_qenum_value_under(rb_cQLocaleCountry, "Poland", QLocale::Country::Poland);
        define_qenum_value_under(rb_cQLocaleCountry, "Portugal", QLocale::Country::Portugal);
        define_qenum_value_under(rb_cQLocaleCountry, "PuertoRico", QLocale::Country::PuertoRico);
        define_qenum_value_under(rb_cQLocaleCountry, "Qatar", QLocale::Country::Qatar);
        define_qenum_value_under(rb_cQLocaleCountry, "Reunion", QLocale::Country::Reunion);
        define_qenum_value_under(rb_cQLocaleCountry, "Romania", QLocale::Country::Romania);
        define_qenum_value_under(rb_cQLocaleCountry, "Russia", QLocale::Country::Russia);
        define_qenum_value_under(rb_cQLocaleCountry, "Rwanda", QLocale::Country::Rwanda);
        define_qenum_value_under(rb_cQLocaleCountry, "SaintBarthelemy", QLocale::Country::SaintBarthelemy);
        define_qenum_value_under(rb_cQLocaleCountry, "SaintHelena", QLocale::Country::SaintHelena);
        define_qenum_value_under(rb_cQLocaleCountry, "SaintKittsAndNevis", QLocale::Country::SaintKittsAndNevis);
        define_qenum_value_under(rb_cQLocaleCountry, "SaintLucia", QLocale::Country::SaintLucia);
        define_qenum_value_under(rb_cQLocaleCountry, "SaintMartin", QLocale::Country::SaintMartin);
        define_qenum_value_under(rb_cQLocaleCountry, "SaintPierreAndMiquelon", QLocale::Country::SaintPierreAndMiquelon);
        define_qenum_value_under(rb_cQLocaleCountry, "SaintVincentAndGrenadines", QLocale::Country::SaintVincentAndGrenadines);
        define_qenum_value_under(rb_cQLocaleCountry, "Samoa", QLocale::Country::Samoa);
        define_qenum_value_under(rb_cQLocaleCountry, "SanMarino", QLocale::Country::SanMarino);
        define_qenum_value_under(rb_cQLocaleCountry, "SaoTomeAndPrincipe", QLocale::Country::SaoTomeAndPrincipe);
        define_qenum_value_under(rb_cQLocaleCountry, "SaudiArabia", QLocale::Country::SaudiArabia);
        define_qenum_value_under(rb_cQLocaleCountry, "Senegal", QLocale::Country::Senegal);
        define_qenum_value_under(rb_cQLocaleCountry, "Serbia", QLocale::Country::Serbia);
        define_qenum_value_under(rb_cQLocaleCountry, "Seychelles", QLocale::Country::Seychelles);
        define_qenum_value_under(rb_cQLocaleCountry, "SierraLeone", QLocale::Country::SierraLeone);
        define_qenum_value_under(rb_cQLocaleCountry, "Singapore", QLocale::Country::Singapore);
        define_qenum_value_under(rb_cQLocaleCountry, "SintMaarten", QLocale::Country::SintMaarten);
        define_qenum_value_under(rb_cQLocaleCountry, "Slovakia", QLocale::Country::Slovakia);
        define_qenum_value_under(rb_cQLocaleCountry, "Slovenia", QLocale::Country::Slovenia);
        define_qenum_value_under(rb_cQLocaleCountry, "SolomonIslands", QLocale::Country::SolomonIslands);
        define_qenum_value_under(rb_cQLocaleCountry, "Somalia", QLocale::Country::Somalia);
        define_qenum_value_under(rb_cQLocaleCountry, "SouthAfrica", QLocale::Country::SouthAfrica);
        define_qenum_value_under(rb_cQLocaleCountry, "SouthGeorgiaAndSouthSandwichIslands", QLocale::Country::SouthGeorgiaAndSouthSandwichIslands);
        define_qenum_value_under(rb_cQLocaleCountry, "SouthKorea", QLocale::Country::SouthKorea);
        define_qenum_value_under(rb_cQLocaleCountry, "SouthSudan", QLocale::Country::SouthSudan);
        define_qenum_value_under(rb_cQLocaleCountry, "Spain", QLocale::Country::Spain);
        define_qenum_value_under(rb_cQLocaleCountry, "SriLanka", QLocale::Country::SriLanka);
        define_qenum_value_under(rb_cQLocaleCountry, "Sudan", QLocale::Country::Sudan);
        define_qenum_value_under(rb_cQLocaleCountry, "Suriname", QLocale::Country::Suriname);
        define_qenum_value_under(rb_cQLocaleCountry, "SvalbardAndJanMayen", QLocale::Country::SvalbardAndJanMayen);
        define_qenum_value_under(rb_cQLocaleCountry, "Sweden", QLocale::Country::Sweden);
        define_qenum_value_under(rb_cQLocaleCountry, "Switzerland", QLocale::Country::Switzerland);
        define_qenum_value_under(rb_cQLocaleCountry, "Syria", QLocale::Country::Syria);
        define_qenum_value_under(rb_cQLocaleCountry, "Taiwan", QLocale::Country::Taiwan);
        define_qenum_value_under(rb_cQLocaleCountry, "Tajikistan", QLocale::Country::Tajikistan);
        define_qenum_value_under(rb_cQLocaleCountry, "Tanzania", QLocale::Country::Tanzania);
        define_qenum_value_under(rb_cQLocaleCountry, "Thailand", QLocale::Country::Thailand);
        define_qenum_value_under(rb_cQLocaleCountry, "TimorLeste", QLocale::Country::TimorLeste);
        define_qenum_value_under(rb_cQLocaleCountry, "Togo", QLocale::Country::Togo);
        define_qenum_value_under(rb_cQLocaleCountry, "TokelauTerritory", QLocale::Country::TokelauTerritory);
        define_qenum_value_under(rb_cQLocaleCountry, "Tonga", QLocale::Country::Tonga);
        define_qenum_value_under(rb_cQLocaleCountry, "TrinidadAndTobago", QLocale::Country::TrinidadAndTobago);
        define_qenum_value_under(rb_cQLocaleCountry, "TristanDaCunha", QLocale::Country::TristanDaCunha);
        define_qenum_value_under(rb_cQLocaleCountry, "Tunisia", QLocale::Country::Tunisia);
        define_qenum_value_under(rb_cQLocaleCountry, "Turkey", QLocale::Country::Turkey);
        define_qenum_value_under(rb_cQLocaleCountry, "Turkmenistan", QLocale::Country::Turkmenistan);
        define_qenum_value_under(rb_cQLocaleCountry, "TurksAndCaicosIslands", QLocale::Country::TurksAndCaicosIslands);
        define_qenum_value_under(rb_cQLocaleCountry, "TuvaluTerritory", QLocale::Country::TuvaluTerritory);
        define_qenum_value_under(rb_cQLocaleCountry, "Uganda", QLocale::Country::Uganda);
        define_qenum_value_under(rb_cQLocaleCountry, "Ukraine", QLocale::Country::Ukraine);
        define_qenum_value_under(rb_cQLocaleCountry, "UnitedArabEmirates", QLocale::Country::UnitedArabEmirates);
        define_qenum_value_under(rb_cQLocaleCountry, "UnitedKingdom", QLocale::Country::UnitedKingdom);
        define_qenum_value_under(rb_cQLocaleCountry, "UnitedStatesOutlyingIslands", QLocale::Country::UnitedStatesOutlyingIslands);
        define_qenum_value_under(rb_cQLocaleCountry, "UnitedStates", QLocale::Country::UnitedStates);
        define_qenum_value_under(rb_cQLocaleCountry, "UnitedStatesVirginIslands", QLocale::Country::UnitedStatesVirginIslands);
        define_qenum_value_under(rb_cQLocaleCountry, "Uruguay", QLocale::Country::Uruguay);
        define_qenum_value_under(rb_cQLocaleCountry, "Uzbekistan", QLocale::Country::Uzbekistan);
        define_qenum_value_under(rb_cQLocaleCountry, "Vanuatu", QLocale::Country::Vanuatu);
        define_qenum_value_under(rb_cQLocaleCountry, "VaticanCity", QLocale::Country::VaticanCity);
        define_qenum_value_under(rb_cQLocaleCountry, "Venezuela", QLocale::Country::Venezuela);
        define_qenum_value_under(rb_cQLocaleCountry, "Vietnam", QLocale::Country::Vietnam);
        define_qenum_value_under(rb_cQLocaleCountry, "WallisAndFutuna", QLocale::Country::WallisAndFutuna);
        define_qenum_value_under(rb_cQLocaleCountry, "WesternSahara", QLocale::Country::WesternSahara);
        define_qenum_value_under(rb_cQLocaleCountry, "World", QLocale::Country::World);
        define_qenum_value_under(rb_cQLocaleCountry, "Yemen", QLocale::Country::Yemen);
        define_qenum_value_under(rb_cQLocaleCountry, "Zambia", QLocale::Country::Zambia);
        define_qenum_value_under(rb_cQLocaleCountry, "Zimbabwe", QLocale::Country::Zimbabwe);
        define_qenum_value_under(rb_cQLocaleCountry, "AnyCountry", QLocale::Country::AnyCountry);
        define_qenum_value_under(rb_cQLocaleCountry, "Bonaire", QLocale::Country::Bonaire);
        define_qenum_value_under(rb_cQLocaleCountry, "BosniaAndHerzegowina", QLocale::Country::BosniaAndHerzegowina);
        define_qenum_value_under(rb_cQLocaleCountry, "CuraSao", QLocale::Country::CuraSao);
        define_qenum_value_under(rb_cQLocaleCountry, "CzechRepublic", QLocale::Country::CzechRepublic);
        define_qenum_value_under(rb_cQLocaleCountry, "DemocraticRepublicOfCongo", QLocale::Country::DemocraticRepublicOfCongo);
        define_qenum_value_under(rb_cQLocaleCountry, "DemocraticRepublicOfKorea", QLocale::Country::DemocraticRepublicOfKorea);
        define_qenum_value_under(rb_cQLocaleCountry, "EastTimor", QLocale::Country::EastTimor);
        define_qenum_value_under(rb_cQLocaleCountry, "LatinAmericaAndTheCaribbean", QLocale::Country::LatinAmericaAndTheCaribbean);
        define_qenum_value_under(rb_cQLocaleCountry, "Macau", QLocale::Country::Macau);
        define_qenum_value_under(rb_cQLocaleCountry, "NauruCountry", QLocale::Country::NauruCountry);
        define_qenum_value_under(rb_cQLocaleCountry, "PeoplesRepublicOfCongo", QLocale::Country::PeoplesRepublicOfCongo);
        define_qenum_value_under(rb_cQLocaleCountry, "RepublicOfKorea", QLocale::Country::RepublicOfKorea);
        define_qenum_value_under(rb_cQLocaleCountry, "RussianFederation", QLocale::Country::RussianFederation);
        define_qenum_value_under(rb_cQLocaleCountry, "SaintVincentAndTheGrenadines", QLocale::Country::SaintVincentAndTheGrenadines);
        define_qenum_value_under(rb_cQLocaleCountry, "SouthGeorgiaAndTheSouthSandwichIslands", QLocale::Country::SouthGeorgiaAndTheSouthSandwichIslands);
        define_qenum_value_under(rb_cQLocaleCountry, "SvalbardAndJanMayenIslands", QLocale::Country::SvalbardAndJanMayenIslands);
        define_qenum_value_under(rb_cQLocaleCountry, "Swaziland", QLocale::Country::Swaziland);
        define_qenum_value_under(rb_cQLocaleCountry, "SyrianArabRepublic", QLocale::Country::SyrianArabRepublic);
        define_qenum_value_under(rb_cQLocaleCountry, "TokelauCountry", QLocale::Country::TokelauCountry);
        define_qenum_value_under(rb_cQLocaleCountry, "TuvaluCountry", QLocale::Country::TuvaluCountry);
        define_qenum_value_under(rb_cQLocaleCountry, "UnitedStatesMinorOutlyingIslands", QLocale::Country::UnitedStatesMinorOutlyingIslands);
        define_qenum_value_under(rb_cQLocaleCountry, "VaticanCityState", QLocale::Country::VaticanCityState);
        define_qenum_value_under(rb_cQLocaleCountry, "WallisAndFutunaIslands", QLocale::Country::WallisAndFutunaIslands);
        define_qenum_value_under(rb_cQLocaleCountry, "LastTerritory", QLocale::Country::LastTerritory);
        define_qenum_value_under(rb_cQLocaleCountry, "LastCountry", QLocale::Country::LastCountry);

    Data_Type<QLocale::MeasurementSystem> rb_cQLocaleMeasurementSystem =
        // RubyQt6::QtCore::QLocale::MeasurementSystem
        define_qenum_under<QLocale::MeasurementSystem>(rb_cQLocale, "MeasurementSystem");
        define_qenum_value_under(rb_cQLocaleMeasurementSystem, "MetricSystem", QLocale::MeasurementSystem::MetricSystem);
        define_qenum_value_under(rb_cQLocaleMeasurementSystem, "ImperialUSSystem", QLocale::MeasurementSystem::ImperialUSSystem);
        define_qenum_value_under(rb_cQLocaleMeasurementSystem, "ImperialUKSystem", QLocale::MeasurementSystem::ImperialUKSystem);
        define_qenum_value_under(rb_cQLocaleMeasurementSystem, "ImperialSystem", QLocale::MeasurementSystem::ImperialSystem);

    Data_Type<QLocale::FormatType> rb_cQLocaleFormatType =
        // RubyQt6::QtCore::QLocale::FormatType
        define_qenum_under<QLocale::FormatType>(rb_cQLocale, "FormatType");
        define_qenum_value_under(rb_cQLocaleFormatType, "LongFormat", QLocale::FormatType::LongFormat);
        define_qenum_value_under(rb_cQLocaleFormatType, "ShortFormat", QLocale::FormatType::ShortFormat);
        define_qenum_value_under(rb_cQLocaleFormatType, "NarrowFormat", QLocale::FormatType::NarrowFormat);

    Data_Type<QLocale::NumberOption> rb_cQLocaleNumberOption =
        // RubyQt6::QtCore::QLocale::NumberOption
        define_qenum_under<QLocale::NumberOption>(rb_cQLocale, "NumberOption");
        define_qenum_value_under(rb_cQLocaleNumberOption, "DefaultNumberOptions", QLocale::NumberOption::DefaultNumberOptions);
        define_qenum_value_under(rb_cQLocaleNumberOption, "OmitGroupSeparator", QLocale::NumberOption::OmitGroupSeparator);
        define_qenum_value_under(rb_cQLocaleNumberOption, "RejectGroupSeparator", QLocale::NumberOption::RejectGroupSeparator);
        define_qenum_value_under(rb_cQLocaleNumberOption, "OmitLeadingZeroInExponent", QLocale::NumberOption::OmitLeadingZeroInExponent);
        define_qenum_value_under(rb_cQLocaleNumberOption, "RejectLeadingZeroInExponent", QLocale::NumberOption::RejectLeadingZeroInExponent);
        define_qenum_value_under(rb_cQLocaleNumberOption, "IncludeTrailingZeroesAfterDot", QLocale::NumberOption::IncludeTrailingZeroesAfterDot);
        define_qenum_value_under(rb_cQLocaleNumberOption, "RejectTrailingZeroesAfterDot", QLocale::NumberOption::RejectTrailingZeroesAfterDot);

    Data_Type<QLocale::FloatingPointPrecisionOption> rb_cQLocaleFloatingPointPrecisionOption =
        // RubyQt6::QtCore::QLocale::FloatingPointPrecisionOption
        define_qenum_under<QLocale::FloatingPointPrecisionOption>(rb_cQLocale, "FloatingPointPrecisionOption");
        define_qenum_value_under(rb_cQLocaleFloatingPointPrecisionOption, "FloatingPointShortest", QLocale::FloatingPointPrecisionOption::FloatingPointShortest);

    Data_Type<QLocale::TagSeparator> rb_cQLocaleTagSeparator =
        // RubyQt6::QtCore::QLocale::TagSeparator
        define_qenum_under<QLocale::TagSeparator>(rb_cQLocale, "TagSeparator");
        define_qenum_value_under(rb_cQLocaleTagSeparator, "Dash", QLocale::TagSeparator::Dash);
        define_qenum_value_under(rb_cQLocaleTagSeparator, "Underscore", QLocale::TagSeparator::Underscore);

    Data_Type<QLocale::CurrencySymbolFormat> rb_cQLocaleCurrencySymbolFormat =
        // RubyQt6::QtCore::QLocale::CurrencySymbolFormat
        define_qenum_under<QLocale::CurrencySymbolFormat>(rb_cQLocale, "CurrencySymbolFormat");
        define_qenum_value_under(rb_cQLocaleCurrencySymbolFormat, "CurrencyIsoCode", QLocale::CurrencySymbolFormat::CurrencyIsoCode);
        define_qenum_value_under(rb_cQLocaleCurrencySymbolFormat, "CurrencySymbol", QLocale::CurrencySymbolFormat::CurrencySymbol);
        define_qenum_value_under(rb_cQLocaleCurrencySymbolFormat, "CurrencyDisplayName", QLocale::CurrencySymbolFormat::CurrencyDisplayName);

    Data_Type<QLocale::DataSizeFormat> rb_cQLocaleDataSizeFormat =
        // RubyQt6::QtCore::QLocale::DataSizeFormat
        define_qenum_under<QLocale::DataSizeFormat>(rb_cQLocale, "DataSizeFormat");
        define_qenum_value_under(rb_cQLocaleDataSizeFormat, "DataSizeBase1000", QLocale::DataSizeFormat::DataSizeBase1000);
        define_qenum_value_under(rb_cQLocaleDataSizeFormat, "DataSizeSIQuantifiers", QLocale::DataSizeFormat::DataSizeSIQuantifiers);
        define_qenum_value_under(rb_cQLocaleDataSizeFormat, "DataSizeIecFormat", QLocale::DataSizeFormat::DataSizeIecFormat);
        define_qenum_value_under(rb_cQLocaleDataSizeFormat, "DataSizeTraditionalFormat", QLocale::DataSizeFormat::DataSizeTraditionalFormat);
        define_qenum_value_under(rb_cQLocaleDataSizeFormat, "DataSizeSIFormat", QLocale::DataSizeFormat::DataSizeSIFormat);

    Data_Type<QLocale::LanguageCodeType> rb_cQLocaleLanguageCodeType =
        // RubyQt6::QtCore::QLocale::LanguageCodeType
        define_qenum_under<QLocale::LanguageCodeType>(rb_cQLocale, "LanguageCodeType");
        define_qenum_value_under(rb_cQLocaleLanguageCodeType, "ISO639Part1", QLocale::LanguageCodeType::ISO639Part1);
        define_qenum_value_under(rb_cQLocaleLanguageCodeType, "ISO639Part2B", QLocale::LanguageCodeType::ISO639Part2B);
        define_qenum_value_under(rb_cQLocaleLanguageCodeType, "ISO639Part2T", QLocale::LanguageCodeType::ISO639Part2T);
        define_qenum_value_under(rb_cQLocaleLanguageCodeType, "ISO639Part3", QLocale::LanguageCodeType::ISO639Part3);
        define_qenum_value_under(rb_cQLocaleLanguageCodeType, "LegacyLanguageCode", QLocale::LanguageCodeType::LegacyLanguageCode);
        define_qenum_value_under(rb_cQLocaleLanguageCodeType, "ISO639Part2", QLocale::LanguageCodeType::ISO639Part2);
        define_qenum_value_under(rb_cQLocaleLanguageCodeType, "ISO639Alpha2", QLocale::LanguageCodeType::ISO639Alpha2);
        define_qenum_value_under(rb_cQLocaleLanguageCodeType, "ISO639Alpha3", QLocale::LanguageCodeType::ISO639Alpha3);
        define_qenum_value_under(rb_cQLocaleLanguageCodeType, "ISO639", QLocale::LanguageCodeType::ISO639);
        define_qenum_value_under(rb_cQLocaleLanguageCodeType, "AnyLanguageCode", QLocale::LanguageCodeType::AnyLanguageCode);

    Data_Type<QLocale::QuotationStyle> rb_cQLocaleQuotationStyle =
        // RubyQt6::QtCore::QLocale::QuotationStyle
        define_qenum_under<QLocale::QuotationStyle>(rb_cQLocale, "QuotationStyle");
        define_qenum_value_under(rb_cQLocaleQuotationStyle, "StandardQuotation", QLocale::QuotationStyle::StandardQuotation);
        define_qenum_value_under(rb_cQLocaleQuotationStyle, "AlternateQuotation", QLocale::QuotationStyle::AlternateQuotation);

    Data_Type<QFlags<QLocale::NumberOption>> rb_cQLocaleNumberOptions =
        // RubyQt6::QtCore::QLocale::NumberOptions
        define_qflags_under<QLocale::NumberOption>(rb_cQLocale, "NumberOptions");

    Data_Type<QFlags<QLocale::DataSizeFormat>> rb_cQLocaleDataSizeFormats =
        // RubyQt6::QtCore::QLocale::DataSizeFormats
        define_qflags_under<QLocale::DataSizeFormat>(rb_cQLocale, "DataSizeFormats");

    Data_Type<QFlags<QLocale::LanguageCodeType>> rb_cQLocaleLanguageCodeTypes =
        // RubyQt6::QtCore::QLocale::LanguageCodeTypes
        define_qflags_under<QLocale::LanguageCodeType>(rb_cQLocale, "LanguageCodeTypes");
}
