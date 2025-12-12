// This file is part of [RubyQt6](https://github.com/souk4711/ruby-qt6).
//
// It is licensed under the LGPLv3, included below.
//
// As a special exception to the GNU Lesser General Public License version 3
// ("LGPL3"), the copyright holders of this Library give you permission to
// convey to a third party a Combined Work that links statically or dynamically
// to this Library without providing any Minimal Corresponding Source or
// Minimal Application Code as set out in 4d or providing the installation
// information set out in section 4e, provided that you comply with the other
// provisions of LGPL3 and provided that you meet, for the Application the
// terms and conditions of the license(s) which apply to the Application.
//
// Except as stated in this special exception, the provisions of LGPL3 will
// continue to comply in full to this Library. If you modify this Library, you
// may apply this exception to your version of this Library, but you are not
// obliged to do so. If you do not wish to do so, delete this exception
// statement from your version. This exception does not (and cannot) modify any
// license terms which apply to the Application, with which you must still
// comply.

#ifndef BANDO_QWEBENGINEPAGE_HPP
#define BANDO_QWEBENGINEPAGE_HPP

#include <bando/common.hpp>
#include <QChildEvent>
#include <QEvent>
#include <QTimerEvent>
#include <QWebEnginePage>

RICE4RUBYQT6_USE_NAMESPACE

template <typename Class_T, typename... Arg_Ts> class BandoQWebEnginePage : public Class_T
{
  public:
    BandoQWebEnginePage(Arg_Ts... args) : Class_T(args...), value_(Qnil), value_address_(nullptr), mo_(nullptr) {};
    BandoQWebEnginePage(const BandoQWebEnginePage &) = delete;
    BandoQWebEnginePage &operator=(const BandoQWebEnginePage &) = delete;
    BandoQWebEnginePage(BandoQWebEnginePage &&) = delete;
    BandoQWebEnginePage &operator=(BandoQWebEnginePage &&) = delete;
    ~BandoQWebEnginePage() override { bando_finalizer<BandoQWebEnginePage>(this); };

    void initializeValue(Object value, QMetaObject *mo) { bando_initializeValue<BandoQWebEnginePage>(this, value, mo); };
    Object value() { return this->value_; };

    const QMetaObject *metaObject() const override { return bando_metaObject<BandoQWebEnginePage, Class_T>(this); };
    int qt_metacall(QMetaObject::Call call, int id, void **args) override { return bando_qt_metacall<BandoQWebEnginePage>(this, call, id, args); };

    bool event(QEvent *event) override { return bando_handleQObjectEvent<BandoQWebEnginePage>(this, event); };
    bool eventFilter(QObject *watched, QEvent *event) override { return bando_handleQObjectEventFilter<BandoQWebEnginePage>(this, watched, event); };

    void childEvent(QChildEvent *event) override { bando_handleEvent<BandoQWebEnginePage>(this, event, bando_FunctionName::childEvent); };
    void timerEvent(QTimerEvent *event) override { bando_handleEvent<BandoQWebEnginePage>(this, event, bando_FunctionName::timerEvent); };
    QObject *sender() const { return this->Class_T::sender(); }

    void triggerAction(QWebEnginePage::WebAction action, bool checked = false) override {
        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_name = Identifier("trigger_action");
        this->value_.call(rb_name, Object(detail::to_ruby(action)), Object(detail::to_ruby(checked)));
    };

    bool acceptNavigationRequest(const QUrl &url, QWebEnginePage::NavigationType type, bool isMainFrame) override {
        auto rb_name = Identifier("accept_navigation_request");
        if (!this->value_.respond_to(rb_name))
            return this->Class_T::acceptNavigationRequest(url, type, isMainFrame);

        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_return = this->value_.call(rb_name, Object(detail::to_ruby(url)), Object(detail::to_ruby(type)), Object(detail::to_ruby(isMainFrame)));
        return detail::From_Ruby<bool>().convert(rb_return);
    };

    QStringList chooseFiles(QWebEnginePage::FileSelectionMode mode, const QStringList &oldFiles, const QStringList &acceptedMimeTypes) override {
        auto rb_name = Identifier("choose_files");
        if (!this->value_.respond_to(rb_name))
            return this->Class_T::chooseFiles(mode, oldFiles, acceptedMimeTypes);

        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_return = this->value_.call(rb_name, Object(detail::to_ruby(mode)), Object(detail::to_ruby(oldFiles)), Object(detail::to_ruby(acceptedMimeTypes)));
        return detail::From_Ruby<QStringList>().convert(rb_return);
    };

    QWebEnginePage *createWindow(QWebEnginePage::WebWindowType type) override {
        auto rb_name = Identifier("create_window");
        if (!this->value_.respond_to(rb_name))
            return this->Class_T::createWindow(type);

        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_return = this->value_.call(rb_name, Object(detail::to_ruby(type)));
        return detail::From_Ruby<QWebEnginePage *>().convert(rb_return);
    };

    void javaScriptAlert(const QUrl &securityOrigin, const QString &msg) override {
        auto rb_name = Identifier("java_script_alert");
        if (!this->value_.respond_to(rb_name))
            return this->Class_T::javaScriptAlert(securityOrigin, msg);

        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        this->value_.call(rb_name, Object(detail::to_ruby(securityOrigin)), Object(detail::to_ruby(msg)));
    };

    bool javaScriptConfirm(const QUrl &securityOrigin, const QString &msg) override {
        auto rb_name = Identifier("java_script_confirm");
        if (!this->value_.respond_to(rb_name))
            return this->Class_T::javaScriptConfirm(securityOrigin, msg);

        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_return = this->value_.call(rb_name, Object(detail::to_ruby(securityOrigin)), Object(detail::to_ruby(msg)));
        return detail::From_Ruby<bool>().convert(rb_return);
    };

    void javaScriptConsoleMessage(QWebEnginePage::JavaScriptConsoleMessageLevel level, const QString &message, int lineNumber, const QString &sourceID) override {
        auto rb_name = Identifier("java_script_console_message");
        if (!this->value_.respond_to(rb_name))
            return this->Class_T::javaScriptConsoleMessage(level, message, lineNumber, sourceID);

        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        this->value_.call(rb_name, Object(detail::to_ruby(level)), Object(detail::to_ruby(message)), Object(detail::to_ruby(lineNumber)), Object(detail::to_ruby(sourceID)));
    };

    bool javaScriptPrompt(const QUrl &securityOrigin, const QString &msg, const QString &defaultValue, QString *result) override {
        auto rb_name = Identifier("java_script_prompt");
        if (!this->value_.respond_to(rb_name))
            return this->Class_T::javaScriptPrompt(securityOrigin, msg, defaultValue, result);

        Q_ASSERT(this->value_.rb_type() != RUBY_T_NONE);
        auto rb_return = this->value_.call(rb_name, Object(detail::to_ruby(securityOrigin)), Object(detail::to_ruby(msg)), Object(detail::to_ruby(defaultValue)), Object(detail::to_ruby(result)));
        return detail::From_Ruby<bool>().convert(rb_return);
    };

  public:
    bool Class_T_handleQObjectEvent(QEvent *event) { return this->Class_T::event(event); };
    bool Class_T_handleQObjectEventFilter(QObject *watched, QEvent *event) { return this->Class_T::eventFilter(watched, event); };

    void Class_T_handleEvent(bando_FunctionName name, QEvent *event) {
        switch (name)
        {
        case bando_FunctionName::childEvent: return this->Class_T::childEvent(static_cast<QChildEvent *>(event));
        case bando_FunctionName::timerEvent: return this->Class_T::timerEvent(static_cast<QTimerEvent *>(event));
        default: Q_UNREACHABLE(); break;
        }
    };

  public:
    template <typename BC_T, typename C_T> friend const QMetaObject *bando_metaObject(const BC_T *self);

    Object value_;
    VALUE *value_address_;

    QMetaObject *mo_;
};

template <typename BC_T, typename C_T>
Data_Type<BC_T> define_bando_qwebenginepage_under(Module module, char const *name)
{
    Data_Type<BC_T> bando_qlass =
        define_class_under<BC_T, C_T>(module, name)
            .define_method("_initialize_ruby_value", &BC_T::initializeValue, Arg("value"), Arg("mo"))
            .define_method("_ruby_value", &BC_T::value)
            .define_method("_ruby_value_handle_event", &BC_T::Class_T_handleEvent, Arg("name"), Arg("event"))
            .define_method("_event", &BC_T::Class_T_handleQObjectEvent, Arg("event"))
            .define_method("_event_filter", &BC_T::Class_T_handleQObjectEventFilter, Arg("watched"), Arg("event"))
            .define_method("sender", &BC_T::sender);

    bando_qlass
        .define_method("trigger_action", [](BC_T *self, QWebEnginePage::WebAction action, bool checked) -> void { return self->C_T::triggerAction(action, checked); }, Arg("action"), Arg("checked") = static_cast<bool>(false));

    return bando_qlass;
}

#endif
