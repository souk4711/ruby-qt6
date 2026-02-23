#include "qshortcut-rb.hpp"
#include <qshortcut.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQShortcut;

void Init_qshortcut(Module rb_mQt6QtGui)
{
    rb_cQShortcut =
        // RubyQt6::QtGui::QShortcut
        define_qlass_under<QShortcut, QObject>(rb_mQt6QtGui, "QShortcut")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QShortcut::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QShortcut, const QKeySequence &, QObject *>(), Arg("key"), Arg("parent"))
            // Public Functions
            .define_method("auto_repeat", &QShortcut::autoRepeat)
            .define_method("context", &QShortcut::context)
            .define_method("enabled?", &QShortcut::isEnabled)
            .define_method("key", &QShortcut::key)
            .define_method("keys", &QShortcut::keys)
            .define_method("set_auto_repeat", &QShortcut::setAutoRepeat, Arg("on"))
            .define_method("set_context", &QShortcut::setContext, Arg("context"))
            .define_method("set_enabled", &QShortcut::setEnabled, Arg("enable"))
            .define_method("set_key", &QShortcut::setKey, Arg("key"))
            .define_method<void (QShortcut::*)(QKeySequence::StandardKey)>("set_keys", &QShortcut::setKeys, Arg("key"))
            .define_method<void (QShortcut::*)(const QList<QKeySequence> &)>("set_keys", &QShortcut::setKeys, Arg("keys"))
            .define_method("set_whats_this", &QShortcut::setWhatsThis, Arg("text"))
            .define_method("whats_this", &QShortcut::whatsThis);
            // Signals
            // .define_method("activated", &QShortcut::activated)
            // .define_method("activated_ambiguously", &QShortcut::activatedAmbiguously);
}
