#include "t-qtwebenginecore-rb.hpp"

#include <QWebEngineNotification>

RICE4RUBYQT6_USE_NAMESPACE

void Init_t_qtwebenginecore(Module rb_mQt6T)
{
    // std::unique_ptr<QWebEngineNotification>
    define_unique_ptr<QWebEngineNotification>();
}
