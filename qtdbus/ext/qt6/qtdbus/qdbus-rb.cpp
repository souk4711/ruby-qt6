#include "qdbus-rb.hpp"
#include <qdbusconnection.h>
#include <rice/qt6/qenum.hpp>

using namespace Rice;

void Init_qdbus(Rice::Module rb_mQt6QtDBus)
{
    Module rb_mQDBus =
        // RubyQt6::QtDBus::QDBus
        define_module_under(rb_mQt6QtDBus, "QDBus");

    Data_Type<QDBus::CallMode> rb_cQDBusCallMode =
        // RubyQt6::QtDBus::QDBus::CallMode
        define_qenum_under<QDBus::CallMode>(rb_mQDBus, "CallMode");
        define_qenum_value_under(rb_cQDBusCallMode, "NoBlock", QDBus::CallMode::NoBlock);
        define_qenum_value_under(rb_cQDBusCallMode, "Block", QDBus::CallMode::Block);
        define_qenum_value_under(rb_cQDBusCallMode, "BlockWithGui", QDBus::CallMode::BlockWithGui);
        define_qenum_value_under(rb_cQDBusCallMode, "AutoDetect", QDBus::CallMode::AutoDetect);
}
