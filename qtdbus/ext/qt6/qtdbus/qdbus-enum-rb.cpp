#include "qdbus-enum-rb.hpp"
#include <qdbusconnection.h>
#include <rice/qenum.hpp>

using namespace Rice;

void Init_qdbus_enum(Rice::Module rb_mQt6QtDBus)
{
    Module rb_mQDBus =
        // RubyQt6::QtDBus::QDBus
        define_module_under(rb_mQt6QtDBus, "QDBus");

    Enum<QDBus::CallMode> rb_cQDBusCallMode =
        // RubyQt6::QtDBus::QDBus::CallMode
        define_qenum_under<QDBus::CallMode>("CallMode", rb_mQDBus)
            .define_value("NoBlock", QDBus::CallMode::NoBlock)
            .define_value("Block", QDBus::CallMode::Block)
            .define_value("BlockWithGui", QDBus::CallMode::BlockWithGui)
            .define_value("AutoDetect", QDBus::CallMode::AutoDetect);
}
