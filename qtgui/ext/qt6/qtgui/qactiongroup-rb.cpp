#include "qactiongroup-rb.hpp"
#include <qactiongroup.h>
#include <rice/qt6/qenum.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQActionGroup;

void Init_qactiongroup(Module rb_mQt6QtGui)
{
    rb_cQActionGroup =
        // RubyQt6::QtGui::QActionGroup
        define_class_under<QActionGroup, QObject>(rb_mQt6QtGui, "QActionGroup")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QActionGroup::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QActionGroup, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("actions", &QActionGroup::actions)
            .define_method<QAction *(QActionGroup::*)(QAction *)>("add_action", &QActionGroup::addAction, Arg("a"))
            .define_method<QAction *(QActionGroup::*)(const QIcon &, const QString &)>("add_action", &QActionGroup::addAction, Arg("icon"), Arg("text"))
            .define_method<QAction *(QActionGroup::*)(const QString &)>("add_action", &QActionGroup::addAction, Arg("text"))
            .define_method("checked_action", &QActionGroup::checkedAction)
            .define_method("exclusion_policy", &QActionGroup::exclusionPolicy)
            .define_method("enabled?", &QActionGroup::isEnabled)
            .define_method("exclusive?", &QActionGroup::isExclusive)
            .define_method("visible?", &QActionGroup::isVisible)
            .define_method("remove_action", &QActionGroup::removeAction, Arg("a"))
            // Public Slots
            .define_method("set_disabled", &QActionGroup::setDisabled, Arg("b"))
            .define_method("set_enabled", &QActionGroup::setEnabled, Arg("b"))
            .define_method("set_exclusion_policy", &QActionGroup::setExclusionPolicy, Arg("policy"))
            .define_method("set_exclusive", &QActionGroup::setExclusive, Arg("b"))
            .define_method("set_visible", &QActionGroup::setVisible, Arg("b"));
            // Signals
            // .define_method("hovered", &QActionGroup::hovered, Arg("action"))
            // .define_method("triggered", &QActionGroup::triggered, Arg("action"));

    Data_Type<QActionGroup::ExclusionPolicy> rb_cQActionGroupExclusionPolicy =
        // RubyQt6::QtGui::QActionGroup::ExclusionPolicy
        define_qenum_under<QActionGroup::ExclusionPolicy>(rb_cQActionGroup, "ExclusionPolicy");
        define_qenum_value_under(rb_cQActionGroupExclusionPolicy, "None", QActionGroup::ExclusionPolicy::None);
        define_qenum_value_under(rb_cQActionGroupExclusionPolicy, "Exclusive", QActionGroup::ExclusionPolicy::Exclusive);
        define_qenum_value_under(rb_cQActionGroupExclusionPolicy, "ExclusiveOptional", QActionGroup::ExclusionPolicy::ExclusiveOptional);
}
