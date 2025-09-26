#include "qshortcut-rb.hpp"
#include <qshortcut.h>

using namespace Rice;

Rice::Class rb_cQShortcut;

void Init_qshortcut(Rice::Module rb_mQt6QtGui)
{
    rb_cQShortcut =
        // RubyQt6::QtGui::QShortcut
        define_class_under<QShortcut, QObject>(rb_mQt6QtGui, "QShortcut")
            // Constructor
            .define_constructor(Constructor<QShortcut, QObject *>(), Arg("parent"))
            .define_constructor(Constructor<QShortcut, QKeySequence::StandardKey, QObject *, const char *, const char *, Qt::ShortcutContext>(), Arg("key"), Arg("parent"), Arg("member") = static_cast<const char *>(nullptr), Arg("ambiguous_member") = static_cast<const char *>(nullptr), Arg("context") = static_cast<Qt::ShortcutContext>(Qt::WindowShortcut))
            .define_constructor(Constructor<QShortcut, const QKeySequence &, QObject *, const char *, const char *, Qt::ShortcutContext>(), Arg("key"), Arg("parent"), Arg("member") = static_cast<const char *>(nullptr), Arg("ambiguous_member") = static_cast<const char *>(nullptr), Arg("context") = static_cast<Qt::ShortcutContext>(Qt::WindowShortcut))
            // Public Functions
            .define_method("activated", &QShortcut::activated)
            .define_method("activated_ambiguously", &QShortcut::activatedAmbiguously)
            .define_method("auto_repeat", &QShortcut::autoRepeat)
            .define_method("context", &QShortcut::context)
            .define_method("id", &QShortcut::id)
            .define_method("enabled?", &QShortcut::isEnabled)
            .define_method("key", &QShortcut::key)
            .define_method("keys", &QShortcut::keys)
            .define_method("set_auto_repeat", &QShortcut::setAutoRepeat, Arg("on"))
            .define_method("set_context", &QShortcut::setContext, Arg("context"))
            .define_method("set_enabled", &QShortcut::setEnabled, Arg("enable"))
            .define_method("set_key", &QShortcut::setKey, Arg("key"))
            .define_method<void (QShortcut::*)(QKeySequence::StandardKey)>("set_keys", &QShortcut::setKeys, Arg("key"))
            .define_method<void (QShortcut::*)(const QList &)>("set_keys", &QShortcut::setKeys, Arg("keys"))
            .define_method("set_whats_this", &QShortcut::setWhatsThis, Arg("text"))
            .define_method("whats_this", &QShortcut::whatsThis);
}
