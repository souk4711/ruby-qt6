#include "bando-qtextdocument-rb.hpp"
#include <bando/qobject.hpp>

#include <QTextDocument>

using namespace Rice;

using Bando_QTextDocument = BandoQObject<QTextDocument, const QString &, QObject *>;

Rice::Class rb_mBando_cQTextDocument;

void Init_bando_qtextdocument(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQTextDocument =
        define_bando_qobject_under<Bando_QTextDocument, QTextDocument>(rb_mQt6Bando, "QTextDocument")
            .define_constructor(Constructor<Bando_QTextDocument, const QString &, QObject *>(), Arg("text"), Arg("parent"));
}
