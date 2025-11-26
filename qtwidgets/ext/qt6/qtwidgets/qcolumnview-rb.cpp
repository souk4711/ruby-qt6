#include "qcolumnview-rb.hpp"
#include <qcolumnview.h>

using namespace Rice;

Rice::Class rb_cQColumnView;

void Init_qcolumnview(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQColumnView =
        // RubyQt6::QtWidgets::QColumnView
        define_class_under<QColumnView, QAbstractItemView>(rb_mQt6QtWidgets, "QColumnView")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QColumnView::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QColumnView, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("column_widths", &QColumnView::columnWidths)
            .define_method("index_at", &QColumnView::indexAt, Arg("point"))
            .define_method("preview_widget", &QColumnView::previewWidget)
            .define_method("resize_grips_visible", &QColumnView::resizeGripsVisible)
            .define_method("scroll_to", &QColumnView::scrollTo, Arg("index"), Arg("hint") = static_cast<QAbstractItemView::ScrollHint>(QAbstractItemView::ScrollHint::EnsureVisible))
            .define_method("select_all", &QColumnView::selectAll)
            .define_method("set_column_widths", &QColumnView::setColumnWidths, Arg("list"))
            .define_method("set_model", &QColumnView::setModel, Arg("model"))
            .define_method("set_preview_widget", &QColumnView::setPreviewWidget, Arg("widget"))
            .define_method("set_resize_grips_visible", &QColumnView::setResizeGripsVisible, Arg("visible"))
            .define_method("set_root_index", &QColumnView::setRootIndex, Arg("index"))
            .define_method("set_selection_model", &QColumnView::setSelectionModel, Arg("selection_model"))
            .define_method("visual_rect", &QColumnView::visualRect, Arg("index"));
            // Signals
            // .define_method("update_preview_widget", &QColumnView::updatePreviewWidget, Arg("index"));
}
