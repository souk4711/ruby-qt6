#include "bando-qtgui-rb.hpp"
#include <bando/qobject.hpp>
#include <bando/qwindow.hpp>

#include <QAction>
#include <QActionGroup>
#include <QGuiApplication>
#include <QShortcut>
#include <QTextDocument>
#include <QWindow>

using namespace Rice;

using Bando_QAction = BandoQObject<QAction, const QIcon &, const QString &, QObject *>;
using Bando_QActionGroup = BandoQObject<QActionGroup, QObject *>;
using Bando_QGuiApplication = BandoQObject<QGuiApplication, int &, char **>;
using Bando_QShortcut = BandoQObject<QShortcut, const QKeySequence &, QObject *>;
using Bando_QTextDocument = BandoQObject<QTextDocument, const QString &, QObject *>;
using Bando_QWindow = BandoQWindow<QWindow, QWindow *>;

Rice::Class rb_mBando_cQAction;
Rice::Class rb_mBando_cQActionGroup;
Rice::Class rb_mBando_cQGuiApplication;
Rice::Class rb_mBando_cQShortcut;
Rice::Class rb_mBando_cQTextDocument;
Rice::Class rb_mBando_cQWindow;

void Init_bando_qtgui(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQAction =
        define_class_under<Bando_QAction, QAction>(rb_mQt6Bando, "QAction")
            .define_constructor(Constructor<Bando_QAction, const QIcon &, const QString &, QObject *>(), Arg("icon"), Arg("text"), Arg("parent"))
            .define_method("_initialize_value", &Bando_QAction::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQActionGroup =
        define_class_under<Bando_QActionGroup, QActionGroup>(rb_mQt6Bando, "QActionGroup")
            .define_constructor(Constructor<Bando_QActionGroup, QObject *>(), Arg("parent"))
            .define_method("_initialize_value", &Bando_QActionGroup::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQGuiApplication =
        define_class_under<Bando_QGuiApplication, QGuiApplication>(rb_mQt6Bando, "QGuiApplication")
            .define_constructor(Constructor<Bando_QGuiApplication, int &, char **>(), Arg("argc"), Arg("argv"))
            .define_method("_initialize_value", &Bando_QGuiApplication::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQShortcut =
        define_class_under<Bando_QShortcut, QShortcut>(rb_mQt6Bando, "QShortcut")
            .define_constructor(Constructor<Bando_QShortcut, const QKeySequence &, QObject *>(), Arg("key"), Arg("parent"))
            .define_method("_initialize_value", &Bando_QShortcut::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQTextDocument =
        define_class_under<Bando_QTextDocument, QTextDocument>(rb_mQt6Bando, "QTextDocument")
            .define_constructor(Constructor<Bando_QTextDocument, const QString &, QObject *>(), Arg("text"), Arg("parent"))
            .define_method("_initialize_value", &Bando_QTextDocument::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQWindow =
        define_class_under<Bando_QWindow, QWindow>(rb_mQt6Bando, "QWindow")
            .define_constructor(Constructor<Bando_QWindow, QWindow *>(), Arg("parent"))
            .define_method("_initialize_value", &Bando_QWindow::initializeValue, Arg("mo"), Arg("value"));
}
