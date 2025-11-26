#include "qgraphicsscene-rb.hpp"
#include <qgraphicsscene.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

#include <QGraphicsItem>
#include <QGraphicsWidget>
#include <QGraphicsProxyWidget>
#include <QPainterPath>
#include <QPainter>
#include <QStyle>
#include <QWidget>

using namespace Rice;

Rice::Class rb_cQGraphicsScene;

void Init_qgraphicsscene(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQGraphicsScene =
        // RubyQt6::QtWidgets::QGraphicsScene
        define_class_under<QGraphicsScene, QObject>(rb_mQt6QtWidgets, "QGraphicsScene")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QGraphicsScene::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QGraphicsScene, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("active_panel", &QGraphicsScene::activePanel)
            .define_method("active_window", &QGraphicsScene::activeWindow)
            .define_method<QGraphicsEllipseItem *(QGraphicsScene::*)(const QRectF &, const QPen &, const QBrush &)>("add_ellipse", &QGraphicsScene::addEllipse, Arg("rect"), Arg("pen") = static_cast<const QPen &>(QPen()), Arg("brush") = static_cast<const QBrush &>(QBrush()))
            .define_method<QGraphicsEllipseItem *(QGraphicsScene::*)(qreal, qreal, qreal, qreal, const QPen &, const QBrush &)>("add_ellipse", &QGraphicsScene::addEllipse, Arg("x"), Arg("y"), Arg("w"), Arg("h"), Arg("pen") = static_cast<const QPen &>(QPen()), Arg("brush") = static_cast<const QBrush &>(QBrush()))
            .define_method("add_item", &QGraphicsScene::addItem, Arg("item"))
            .define_method<QGraphicsLineItem *(QGraphicsScene::*)(const QLineF &, const QPen &)>("add_line", &QGraphicsScene::addLine, Arg("line"), Arg("pen") = static_cast<const QPen &>(QPen()))
            .define_method<QGraphicsLineItem *(QGraphicsScene::*)(qreal, qreal, qreal, qreal, const QPen &)>("add_line", &QGraphicsScene::addLine, Arg("x1"), Arg("y1"), Arg("x2"), Arg("y2"), Arg("pen") = static_cast<const QPen &>(QPen()))
            .define_method("add_path", &QGraphicsScene::addPath, Arg("path"), Arg("pen") = static_cast<const QPen &>(QPen()), Arg("brush") = static_cast<const QBrush &>(QBrush()))
            .define_method("add_pixmap", &QGraphicsScene::addPixmap, Arg("pixmap"))
            .define_method("add_polygon", &QGraphicsScene::addPolygon, Arg("polygon"), Arg("pen") = static_cast<const QPen &>(QPen()), Arg("brush") = static_cast<const QBrush &>(QBrush()))
            .define_method<QGraphicsRectItem *(QGraphicsScene::*)(const QRectF &, const QPen &, const QBrush &)>("add_rect", &QGraphicsScene::addRect, Arg("rect"), Arg("pen") = static_cast<const QPen &>(QPen()), Arg("brush") = static_cast<const QBrush &>(QBrush()))
            .define_method<QGraphicsRectItem *(QGraphicsScene::*)(qreal, qreal, qreal, qreal, const QPen &, const QBrush &)>("add_rect", &QGraphicsScene::addRect, Arg("x"), Arg("y"), Arg("w"), Arg("h"), Arg("pen") = static_cast<const QPen &>(QPen()), Arg("brush") = static_cast<const QBrush &>(QBrush()))
            .define_method("add_simple_text", &QGraphicsScene::addSimpleText, Arg("text"), Arg("font") = static_cast<const QFont &>(QFont()))
            .define_method("add_text", &QGraphicsScene::addText, Arg("text"), Arg("font") = static_cast<const QFont &>(QFont()))
            .define_method("add_widget", &QGraphicsScene::addWidget, Arg("widget"), Arg("w_flags") = static_cast<Qt::WindowFlags>(Qt::WindowFlags()))
            .define_method("background_brush", &QGraphicsScene::backgroundBrush)
            .define_method("bsp_tree_depth", &QGraphicsScene::bspTreeDepth)
            .define_method("clear_focus", &QGraphicsScene::clearFocus)
            .define_method("colliding_items", &QGraphicsScene::collidingItems, Arg("item"), Arg("mode") = static_cast<Qt::ItemSelectionMode>(Qt::IntersectsItemShape))
            .define_method("create_item_group", &QGraphicsScene::createItemGroup, Arg("items"))
            .define_method("destroy_item_group", &QGraphicsScene::destroyItemGroup, Arg("group"))
            .define_method("focus_item", &QGraphicsScene::focusItem)
            .define_method("focus_on_touch", &QGraphicsScene::focusOnTouch)
            .define_method("font", &QGraphicsScene::font)
            .define_method("foreground_brush", &QGraphicsScene::foregroundBrush)
            .define_method("has_focus", &QGraphicsScene::hasFocus)
            .define_method("height", &QGraphicsScene::height)
            .define_method<void (QGraphicsScene::*)(qreal, qreal, qreal, qreal, QGraphicsScene::SceneLayers)>("invalidate", &QGraphicsScene::invalidate, Arg("x"), Arg("y"), Arg("w"), Arg("h"), Arg("layers") = static_cast<QGraphicsScene::SceneLayers>(QGraphicsScene::SceneLayer::AllLayers))
            .define_method("active?", &QGraphicsScene::isActive)
            .define_method<QGraphicsItem *(QGraphicsScene::*)(const QPointF &, const QTransform &) const>("item_at", &QGraphicsScene::itemAt, Arg("pos"), Arg("device_transform"))
            .define_method<QGraphicsItem *(QGraphicsScene::*)(qreal, qreal, const QTransform &) const>("item_at", &QGraphicsScene::itemAt, Arg("x"), Arg("y"), Arg("device_transform"))
            .define_method("item_index_method", &QGraphicsScene::itemIndexMethod)
            .define_method<QList<QGraphicsItem *> (QGraphicsScene::*)(Qt::SortOrder) const>("items", &QGraphicsScene::items, Arg("order") = static_cast<Qt::SortOrder>(Qt::DescendingOrder))
            .define_method<QList<QGraphicsItem *> (QGraphicsScene::*)(const QPainterPath &, Qt::ItemSelectionMode, Qt::SortOrder, const QTransform &) const>("items", &QGraphicsScene::items, Arg("path"), Arg("mode") = static_cast<Qt::ItemSelectionMode>(Qt::IntersectsItemShape), Arg("order") = static_cast<Qt::SortOrder>(Qt::DescendingOrder), Arg("device_transform") = static_cast<const QTransform &>(QTransform()))
            .define_method<QList<QGraphicsItem *> (QGraphicsScene::*)(const QPointF &, Qt::ItemSelectionMode, Qt::SortOrder, const QTransform &) const>("items", &QGraphicsScene::items, Arg("pos"), Arg("mode") = static_cast<Qt::ItemSelectionMode>(Qt::IntersectsItemShape), Arg("order") = static_cast<Qt::SortOrder>(Qt::DescendingOrder), Arg("device_transform") = static_cast<const QTransform &>(QTransform()))
            .define_method<QList<QGraphicsItem *> (QGraphicsScene::*)(const QPolygonF &, Qt::ItemSelectionMode, Qt::SortOrder, const QTransform &) const>("items", &QGraphicsScene::items, Arg("polygon"), Arg("mode") = static_cast<Qt::ItemSelectionMode>(Qt::IntersectsItemShape), Arg("order") = static_cast<Qt::SortOrder>(Qt::DescendingOrder), Arg("device_transform") = static_cast<const QTransform &>(QTransform()))
            .define_method<QList<QGraphicsItem *> (QGraphicsScene::*)(const QRectF &, Qt::ItemSelectionMode, Qt::SortOrder, const QTransform &) const>("items", &QGraphicsScene::items, Arg("rect"), Arg("mode") = static_cast<Qt::ItemSelectionMode>(Qt::IntersectsItemShape), Arg("order") = static_cast<Qt::SortOrder>(Qt::DescendingOrder), Arg("device_transform") = static_cast<const QTransform &>(QTransform()))
            .define_method<QList<QGraphicsItem *> (QGraphicsScene::*)(qreal, qreal, qreal, qreal, Qt::ItemSelectionMode, Qt::SortOrder, const QTransform &) const>("items", &QGraphicsScene::items, Arg("x"), Arg("y"), Arg("w"), Arg("h"), Arg("mode"), Arg("order"), Arg("device_transform") = static_cast<const QTransform &>(QTransform()))
            .define_method("items_bounding_rect", &QGraphicsScene::itemsBoundingRect)
            .define_method("minimum_render_size", &QGraphicsScene::minimumRenderSize)
            .define_method("mouse_grabber_item", &QGraphicsScene::mouseGrabberItem)
            .define_method("palette", &QGraphicsScene::palette)
            .define_method("remove_item", &QGraphicsScene::removeItem, Arg("item"))
            .define_method("render", &QGraphicsScene::render, Arg("painter"), Arg("target") = static_cast<const QRectF &>(QRectF()), Arg("source") = static_cast<const QRectF &>(QRectF()), Arg("aspect_ratio_mode") = static_cast<Qt::AspectRatioMode>(Qt::KeepAspectRatio))
            .define_method("scene_rect", &QGraphicsScene::sceneRect)
            .define_method("selected_items", &QGraphicsScene::selectedItems)
            .define_method("selection_area", &QGraphicsScene::selectionArea)
            .define_method("set_active_panel", &QGraphicsScene::setActivePanel, Arg("item"))
            .define_method("set_active_window", &QGraphicsScene::setActiveWindow, Arg("widget"))
            .define_method("set_background_brush", &QGraphicsScene::setBackgroundBrush, Arg("brush"))
            .define_method("set_bsp_tree_depth", &QGraphicsScene::setBspTreeDepth, Arg("depth"))
            .define_method("set_focus", &QGraphicsScene::setFocus, Arg("focus_reason") = static_cast<Qt::FocusReason>(Qt::OtherFocusReason))
            .define_method("set_focus_item", &QGraphicsScene::setFocusItem, Arg("item"), Arg("focus_reason") = static_cast<Qt::FocusReason>(Qt::OtherFocusReason))
            .define_method("set_focus_on_touch", &QGraphicsScene::setFocusOnTouch, Arg("enabled"))
            .define_method("set_font", &QGraphicsScene::setFont, Arg("font"))
            .define_method("set_foreground_brush", &QGraphicsScene::setForegroundBrush, Arg("brush"))
            .define_method("set_item_index_method", &QGraphicsScene::setItemIndexMethod, Arg("method"))
            .define_method("set_minimum_render_size", &QGraphicsScene::setMinimumRenderSize, Arg("min_size"))
            .define_method("set_palette", &QGraphicsScene::setPalette, Arg("palette"))
            .define_method<void (QGraphicsScene::*)(const QRectF &)>("set_scene_rect", &QGraphicsScene::setSceneRect, Arg("rect"))
            .define_method<void (QGraphicsScene::*)(qreal, qreal, qreal, qreal)>("set_scene_rect", &QGraphicsScene::setSceneRect, Arg("x"), Arg("y"), Arg("w"), Arg("h"))
            .define_method<void (QGraphicsScene::*)(const QPainterPath &, Qt::ItemSelectionOperation, Qt::ItemSelectionMode, const QTransform &)>("set_selection_area", &QGraphicsScene::setSelectionArea, Arg("path"), Arg("selection_operation") = static_cast<Qt::ItemSelectionOperation>(Qt::ReplaceSelection), Arg("mode") = static_cast<Qt::ItemSelectionMode>(Qt::IntersectsItemShape), Arg("device_transform") = static_cast<const QTransform &>(QTransform()))
            .define_method<void (QGraphicsScene::*)(const QPainterPath &, const QTransform &)>("set_selection_area", &QGraphicsScene::setSelectionArea, Arg("path"), Arg("device_transform"))
            .define_method("set_sticky_focus", &QGraphicsScene::setStickyFocus, Arg("enabled"))
            .define_method("set_style", &QGraphicsScene::setStyle, Arg("style"))
            .define_method("sticky_focus", &QGraphicsScene::stickyFocus)
            .define_method("style", &QGraphicsScene::style)
            .define_method<void (QGraphicsScene::*)(qreal, qreal, qreal, qreal)>("update", &QGraphicsScene::update, Arg("x"), Arg("y"), Arg("w"), Arg("h"))
            .define_method("views", &QGraphicsScene::views)
            .define_method("width", &QGraphicsScene::width)
            // Public Slots
            .define_method("advance", &QGraphicsScene::advance)
            .define_method("clear", &QGraphicsScene::clear)
            .define_method("clear_selection", &QGraphicsScene::clearSelection)
            .define_method<void (QGraphicsScene::*)(const QRectF &, QGraphicsScene::SceneLayers)>("invalidate", &QGraphicsScene::invalidate, Arg("rect") = static_cast<const QRectF &>(QRectF()), Arg("layers") = static_cast<QGraphicsScene::SceneLayers>(QGraphicsScene::SceneLayer::AllLayers))
            .define_method<void (QGraphicsScene::*)(const QRectF &)>("update", &QGraphicsScene::update, Arg("rect") = static_cast<const QRectF &>(QRectF()));
            // Signals
            // .define_method("changed", &QGraphicsScene::changed, Arg("region"))
            // .define_method("focus_item_changed", &QGraphicsScene::focusItemChanged, Arg("new_focus"), Arg("old_focus"), Arg("reason"))
            // .define_method("scene_rect_changed", &QGraphicsScene::sceneRectChanged, Arg("rect"))
            // .define_method("selection_changed", &QGraphicsScene::selectionChanged);

    Data_Type<QGraphicsScene::ItemIndexMethod> rb_cQGraphicsSceneItemIndexMethod =
        // RubyQt6::QtWidgets::QGraphicsScene::ItemIndexMethod
        define_qenum_under<QGraphicsScene::ItemIndexMethod>(rb_cQGraphicsScene, "ItemIndexMethod");
        define_qenum_value_under(rb_cQGraphicsSceneItemIndexMethod, "BspTreeIndex", QGraphicsScene::ItemIndexMethod::BspTreeIndex);
        define_qenum_value_under(rb_cQGraphicsSceneItemIndexMethod, "NoIndex", QGraphicsScene::ItemIndexMethod::NoIndex);

    Data_Type<QGraphicsScene::SceneLayer> rb_cQGraphicsSceneSceneLayer =
        // RubyQt6::QtWidgets::QGraphicsScene::SceneLayer
        define_qenum_under<QGraphicsScene::SceneLayer>(rb_cQGraphicsScene, "SceneLayer");
        define_qenum_value_under(rb_cQGraphicsSceneSceneLayer, "ItemLayer", QGraphicsScene::SceneLayer::ItemLayer);
        define_qenum_value_under(rb_cQGraphicsSceneSceneLayer, "BackgroundLayer", QGraphicsScene::SceneLayer::BackgroundLayer);
        define_qenum_value_under(rb_cQGraphicsSceneSceneLayer, "ForegroundLayer", QGraphicsScene::SceneLayer::ForegroundLayer);
        define_qenum_value_under(rb_cQGraphicsSceneSceneLayer, "AllLayers", QGraphicsScene::SceneLayer::AllLayers);

    Data_Type<QFlags<QGraphicsScene::SceneLayer>> rb_cQGraphicsSceneSceneLayers =
        // RubyQt6::QtWidgets::QGraphicsScene::SceneLayers
        define_qflags_under<QGraphicsScene::SceneLayer>(rb_cQGraphicsScene, "SceneLayers");
}
