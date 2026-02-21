#include "qcursor-rb.hpp"
#include <qcursor.h>

#include <QScreen>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQCursor;

void Init_qcursor(Module rb_mQt6QtGui)
{
    rb_cQCursor =
        // RubyQt6::QtGui::QCursor
        define_qlass_under<QCursor>(rb_mQt6QtGui, "QCursor")
            // Constructor
            .define_constructor(Constructor<QCursor>())
            .define_constructor(Constructor<QCursor, Qt::CursorShape>(), Arg("shape"))
            // Public Functions
            .define_method<QBitmap (QCursor::*)() const>("bitmap", &QCursor::bitmap)
            .define_method("hot_spot", &QCursor::hotSpot)
            .define_method<QBitmap (QCursor::*)() const>("mask", &QCursor::mask)
            .define_method("pixmap", &QCursor::pixmap)
            .define_method("set_shape", &QCursor::setShape, Arg("new_shape"))
            .define_method("shape", &QCursor::shape)
            // Static Public Members
            .define_singleton_function<QPoint (*)()>("pos", &QCursor::pos)
            .define_singleton_function<QPoint (*)(const QScreen *)>("pos", &QCursor::pos, Arg("screen"))
            .define_singleton_function<void (*)(QScreen *, const QPoint &)>("set_pos", &QCursor::setPos, Arg("screen"), Arg("p"))
            .define_singleton_function<void (*)(QScreen *, int, int)>("set_pos", &QCursor::setPos, Arg("screen"), Arg("x"), Arg("y"))
            .define_singleton_function<void (*)(const QPoint &)>("set_pos", &QCursor::setPos, Arg("p"))
            .define_singleton_function<void (*)(int, int)>("set_pos", &QCursor::setPos, Arg("x"), Arg("y"));
}
