#include "bando-rb.hpp"
#include <bando/common.hpp>
#include <rice/qenum.hpp>

void Init_bando(Rice::Module rb_mQt6Bando)
{
    Data_Type<bando_FunctionName> rb_cBandoFunctionName =
        define_qenum_under<bando_FunctionName>(rb_mQt6Bando, "FunctionName");
        define_qenum_value_under(rb_cBandoFunctionName, "ActionEvent", bando_FunctionName::actionEvent);
        define_qenum_value_under(rb_cBandoFunctionName, "ChangeEvent", bando_FunctionName::changeEvent);
        define_qenum_value_under(rb_cBandoFunctionName, "ChildEvent", bando_FunctionName::childEvent);
        define_qenum_value_under(rb_cBandoFunctionName, "CloseEvent", bando_FunctionName::closeEvent);
        define_qenum_value_under(rb_cBandoFunctionName, "ContextMenuEvent", bando_FunctionName::contextMenuEvent);
        define_qenum_value_under(rb_cBandoFunctionName, "DragEnterEvent", bando_FunctionName::dragEnterEvent);
        define_qenum_value_under(rb_cBandoFunctionName, "DragLeaveEvent", bando_FunctionName::dragLeaveEvent);
        define_qenum_value_under(rb_cBandoFunctionName, "DragMoveEvent", bando_FunctionName::dragMoveEvent);
        define_qenum_value_under(rb_cBandoFunctionName, "DropEvent", bando_FunctionName::dropEvent);
        define_qenum_value_under(rb_cBandoFunctionName, "EnterEvent", bando_FunctionName::enterEvent);
        define_qenum_value_under(rb_cBandoFunctionName, "FocusInEvent", bando_FunctionName::focusInEvent);
        define_qenum_value_under(rb_cBandoFunctionName, "FocusOutEvent", bando_FunctionName::focusOutEvent);
        define_qenum_value_under(rb_cBandoFunctionName, "HideEvent", bando_FunctionName::hideEvent);
        define_qenum_value_under(rb_cBandoFunctionName, "InputMethodEvent", bando_FunctionName::inputMethodEvent);
        define_qenum_value_under(rb_cBandoFunctionName, "KeyPressEvent", bando_FunctionName::keyPressEvent);
        define_qenum_value_under(rb_cBandoFunctionName, "KeyReleaseEvent", bando_FunctionName::keyReleaseEvent);
        define_qenum_value_under(rb_cBandoFunctionName, "LeaveEvent", bando_FunctionName::leaveEvent);
        define_qenum_value_under(rb_cBandoFunctionName, "MouseDoubleClickEvent", bando_FunctionName::mouseDoubleClickEvent);
        define_qenum_value_under(rb_cBandoFunctionName, "MouseMoveEvent", bando_FunctionName::mouseMoveEvent);
        define_qenum_value_under(rb_cBandoFunctionName, "MousePressEvent", bando_FunctionName::mousePressEvent);
        define_qenum_value_under(rb_cBandoFunctionName, "MouseReleaseEvent", bando_FunctionName::mouseReleaseEvent);
        define_qenum_value_under(rb_cBandoFunctionName, "MoveEvent", bando_FunctionName::moveEvent);
        define_qenum_value_under(rb_cBandoFunctionName, "PaintEvent", bando_FunctionName::paintEvent);
        define_qenum_value_under(rb_cBandoFunctionName, "ResizeEvent", bando_FunctionName::resizeEvent);
        define_qenum_value_under(rb_cBandoFunctionName, "ShowEvent", bando_FunctionName::showEvent);
        define_qenum_value_under(rb_cBandoFunctionName, "TabletEvent", bando_FunctionName::tabletEvent);
        define_qenum_value_under(rb_cBandoFunctionName, "TimerEvent", bando_FunctionName::timerEvent);
        define_qenum_value_under(rb_cBandoFunctionName, "WheelEvent", bando_FunctionName::wheelEvent);
}
