#include "qstring-rb.hpp"
#include <qstring.h>

#include <QRegularExpression>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQString;

std::optional<QString> QString_slice(QString *self, qsizetype start, qsizetype length)
{
    if (start < 0) {
        start = start + self->size();
        if (start < 0) return std::nullopt;
    } else if (start >= self->size()) {
        return std::nullopt;
    }

    if (length < 0) {
        return std::nullopt;
    } else if (start + length > self->size()) {
        return self->sliced(start);
    } else {
        return self->sliced(start, length);
    }
}

QString QString_replace(QString *self, qsizetype start, const QString &after)
{
    if (start < 0) {
        start = start + self->size();
        if (start < 0) throw std::out_of_range("index " + std::to_string(start - self->size()) + " out of string");
    } else if (start > self->size()) {
        throw std::out_of_range("index " + std::to_string(start) + " out of string");
    }

    return self->replace(start, 1, after);
}

void Init_qstring(Module rb_mQt6QtCore)
{
    rb_cQString =
        // RubyQt6::QtCore::QString
        define_class_under<QString>(rb_mQt6QtCore, "QString")
            // RubyQt6-Defined Functions
            .define_method("downcase", [](QString *self) -> QString { return self->toLower(); })
            .define_method("upcase", [](QString *self) -> QString { return self->toUpper(); })
            .define_method("[]", QString_slice, Arg("start"), Arg("length") = static_cast<qsizetype>(1))
            .define_method("[]=", QString_replace, Arg("index"), Arg("after"))
            .define_method("[]=", [](QString *self, qsizetype index, const char *after) -> QString { return QString_replace(self, index, after); }, Arg("index"), Arg("after"))
            // Constructor
            .define_constructor(Constructor<QString, const char *>(), Arg("str"))
            .define_constructor(Constructor<QString, const QString &>(), Arg("other"))
            // Public Functions
            .define_method("capacity", &QString::capacity)
            .define_method("empty?", &QString::isEmpty)
            .define_method("length", &QString::length)
            .define_method("max_size", &QString::max_size)
            .define_method("reserve", &QString::reserve, Arg("size"))
            .define_method("shrink_to_fit", &QString::shrink_to_fit)
            .define_method("size", &QString::size)
            .define_method("to_std_string", &QString::toStdString)
            .define_method<bool (QString::*)(const QRegularExpression &, QRegularExpressionMatch *) const>("_contains", &QString::contains, Arg("re"), Arg("rmatch") = static_cast<QRegularExpressionMatch *>(nullptr))
            .define_method<bool (QString::*)(const QString &, Qt::CaseSensitivity) const>("_contains", &QString::contains, Arg("s"), Arg("cs") = static_cast<Qt::CaseSensitivity>(Qt::CaseSensitive))
            .define_method<qsizetype (QString::*)(const QString &, qsizetype, Qt::CaseSensitivity) const>("_index_of", &QString::indexOf, Arg("s"), Arg("from") = static_cast<qsizetype>(0), Arg("cs") = static_cast<Qt::CaseSensitivity>(Qt::CaseSensitive))
            .define_method<qsizetype (QString::*)(const QRegularExpression &, qsizetype, QRegularExpressionMatch *) const>("_index_of", &QString::indexOf, Arg("re"), Arg("from") = static_cast<qsizetype>(0), Arg("rmatch") = static_cast<QRegularExpressionMatch *>(nullptr))
            .define_method<QStringList (QString::*)(const QString &, Qt::SplitBehavior, Qt::CaseSensitivity) const>("_split", &QString::split, Arg("sep"), Arg("behavior") = static_cast<Qt::SplitBehavior>(Qt::KeepEmptyParts), Arg("cs") = static_cast<Qt::CaseSensitivity>(Qt::CaseSensitive))
            .define_method<QStringList (QString::*)(const QRegularExpression &, Qt::SplitBehavior) const>("_split", &QString::split, Arg("sep"), Arg("behavior") = static_cast<Qt::SplitBehavior>(Qt::KeepEmptyParts));
}
