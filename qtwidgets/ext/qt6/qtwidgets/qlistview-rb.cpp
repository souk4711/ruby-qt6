#include "qlistview-rb.hpp"
#include <qlistview.h>
#include <rice/qenum.hpp>

using namespace Rice;

Rice::Class rb_cQListView;

void Init_qlistview(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQListView =
        // RubyQt6::QtWidgets::QListView
        define_class_under<QListView, QAbstractItemView>(rb_mQt6QtWidgets, "QListView")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QListView::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QListView, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("batch_size", &QListView::batchSize)
            .define_method("clear_property_flags", &QListView::clearPropertyFlags)
            .define_method("do_items_layout", &QListView::doItemsLayout)
            .define_method("flow", &QListView::flow)
            .define_method("grid_size", &QListView::gridSize)
            .define_method("index_at", &QListView::indexAt, Arg("p"))
            .define_method("row_hidden?", &QListView::isRowHidden, Arg("row"))
            .define_method("selection_rect_visible?", &QListView::isSelectionRectVisible)
            .define_method("wrapping?", &QListView::isWrapping)
            .define_method("item_alignment", &QListView::itemAlignment)
            .define_method("layout_mode", &QListView::layoutMode)
            .define_method("model_column", &QListView::modelColumn)
            .define_method("movement", &QListView::movement)
            .define_method("reset", &QListView::reset)
            .define_method("resize_mode", &QListView::resizeMode)
            .define_method("scroll_to", &QListView::scrollTo, Arg("index"), Arg("hint") = static_cast<QAbstractItemView::ScrollHint>(QAbstractItemView::ScrollHint::EnsureVisible))
            .define_method("set_batch_size", &QListView::setBatchSize, Arg("batch_size"))
            .define_method("set_flow", &QListView::setFlow, Arg("flow"))
            .define_method("set_grid_size", &QListView::setGridSize, Arg("size"))
            .define_method("set_item_alignment", &QListView::setItemAlignment, Arg("alignment"))
            .define_method("set_layout_mode", &QListView::setLayoutMode, Arg("mode"))
            .define_method("set_model_column", &QListView::setModelColumn, Arg("column"))
            .define_method("set_movement", &QListView::setMovement, Arg("movement"))
            .define_method("set_resize_mode", &QListView::setResizeMode, Arg("mode"))
            .define_method("set_root_index", &QListView::setRootIndex, Arg("index"))
            .define_method("set_row_hidden", &QListView::setRowHidden, Arg("row"), Arg("hide"))
            .define_method("set_selection_rect_visible", &QListView::setSelectionRectVisible, Arg("show"))
            .define_method("set_spacing", &QListView::setSpacing, Arg("space"))
            .define_method("set_uniform_item_sizes", &QListView::setUniformItemSizes, Arg("enable"))
            .define_method("set_view_mode", &QListView::setViewMode, Arg("mode"))
            .define_method("set_word_wrap", &QListView::setWordWrap, Arg("on"))
            .define_method("set_wrapping", &QListView::setWrapping, Arg("enable"))
            .define_method("spacing", &QListView::spacing)
            .define_method("uniform_item_sizes", &QListView::uniformItemSizes)
            .define_method("view_mode", &QListView::viewMode)
            .define_method("visual_rect", &QListView::visualRect, Arg("index"))
            .define_method("word_wrap", &QListView::wordWrap)
            // Signals
            .define_method("indexes_moved", &QListView::indexesMoved, Arg("indexes"));

    Enum<QListView::Flow> rb_cQListViewFlow =
        // RubyQt6::QtWidgets::QListView::Flow
        define_qenum_under<QListView::Flow>("Flow", rb_cQListView)
            .define_value("LeftToRight", QListView::Flow::LeftToRight)
            .define_value("TopToBottom", QListView::Flow::TopToBottom);

    Enum<QListView::LayoutMode> rb_cQListViewLayoutMode =
        // RubyQt6::QtWidgets::QListView::LayoutMode
        define_qenum_under<QListView::LayoutMode>("LayoutMode", rb_cQListView)
            .define_value("SinglePass", QListView::LayoutMode::SinglePass)
            .define_value("Batched", QListView::LayoutMode::Batched);

    Enum<QListView::Movement> rb_cQListViewMovement =
        // RubyQt6::QtWidgets::QListView::Movement
        define_qenum_under<QListView::Movement>("Movement", rb_cQListView)
            .define_value("Static", QListView::Movement::Static)
            .define_value("Free", QListView::Movement::Free)
            .define_value("Snap", QListView::Movement::Snap);

    Enum<QListView::ResizeMode> rb_cQListViewResizeMode =
        // RubyQt6::QtWidgets::QListView::ResizeMode
        define_qenum_under<QListView::ResizeMode>("ResizeMode", rb_cQListView)
            .define_value("Fixed", QListView::ResizeMode::Fixed)
            .define_value("Adjust", QListView::ResizeMode::Adjust);

    Enum<QListView::ViewMode> rb_cQListViewViewMode =
        // RubyQt6::QtWidgets::QListView::ViewMode
        define_qenum_under<QListView::ViewMode>("ViewMode", rb_cQListView)
            .define_value("ListMode", QListView::ViewMode::ListMode)
            .define_value("IconMode", QListView::ViewMode::IconMode);
}
